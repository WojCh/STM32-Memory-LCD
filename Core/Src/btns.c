/*
 * btns.c
 *
 *  Created on: 26 mar 2023
 *      Author: wojch
 */

#include "btns.h"
#define NUM_BUTTONS 6
GPIO_TypeDef* Button_Port[NUM_BUTTONS] = {BA_GPIO_Port, BB_GPIO_Port, BC_GPIO_Port, B1_GPIO_Port, B2_GPIO_Port, B3_GPIO_Port};
uint16_t Button_Pin[NUM_BUTTONS] = {BA_Pin, BB_Pin, BC_Pin, B1_Pin, B2_Pin, B3_Pin};



// Button state structure
typedef struct {
    uint8_t pressed;
    uint32_t press_time;
    uint8_t press_count;
    uint8_t debounce_counter;
} Button_State;

// Button callback function type
typedef void (*Button_Callback)(Button_Event event);

// Button event handlers structure
typedef struct {
    Button_Callback callback;
    void* context;
    uint32_t long_press_time;
} Button_Handler;

// Button states and handlers
Button_State button_states[NUM_BUTTONS];
Button_Handler button_handlers[NUM_BUTTONS];

// Set long press time for a button
void button_set_long_press_time(uint8_t button_num, uint32_t long_press_time) {
    if (button_num < NUM_BUTTONS) {
        button_handlers[button_num].long_press_time = long_press_time;
    }
}

// Button initialization
void button_init(void) {
    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
        button_states[i].pressed = 0;
        button_states[i].press_time = 0;
        button_states[i].press_count = 0;
        button_states[i].debounce_counter = 0;
    }
}

// Set button event handler
void button_set_handler(uint8_t button_num, Button_Callback callback, void* context) {
    if (button_num < NUM_BUTTONS) {
        button_handlers[button_num].callback = callback;
        button_handlers[button_num].context = context;
    }
}

/**
 * @brief Scans and processes button states, detects button events, and triggers corresponding callbacks.
 *
 * This function should be called periodically in the main loop. It handles debouncing, press, release, short press,
 * long press, and double press events for a defined set of buttons, and triggers their respective callback functions.
 */
void button_task(void) {
    uint8_t debounce_threshold = 8; // Amount of HAL ticks to wait for button to stop bouncing
    uint32_t double_press_timeout = 150; // Amount of HAL ticks to wait for a second press to be considered a double press

    for (uint8_t i = 0; i < NUM_BUTTONS; i++) {
        // Read the current state of the button (pressed or not pressed)
        uint8_t current_state = HAL_GPIO_ReadPin(Button_Port[i], Button_Pin[i]) == GPIO_PIN_RESET;

        // Check if the button state has changed
        if (current_state != button_states[i].pressed) {
            // Increment debounce counter
            button_states[i].debounce_counter++;

            // Check if the debounce counter has reached the threshold
            if (button_states[i].debounce_counter >= debounce_threshold) {

                // If the button has been released (state changed from pressed to not pressed)
                if (button_states[i].pressed) {
                    // Trigger the release event callback
                    button_handlers[i].callback(BUTTON_EVENT_RELEASE);

                    // Calculate the time since the button was last pressed
                    uint32_t time_since_press = HAL_GetTick() - button_states[i].press_time;

                    // Check if the button was pressed once and held longer than the long press time
                    if (button_states[i].press_count == 1 && time_since_press > button_handlers[i].long_press_time) {
                        // Trigger the long press event callback and reset the press count
                        button_handlers[i].callback(BUTTON_EVENT_LONG_PRESS);
                        button_states[i].press_count = 0;
                    }
                    // Check if the button was pressed once and released within the double press timeout
                    else if (button_states[i].press_count == 1 && time_since_press > double_press_timeout) {
                        // Trigger the short press event callback and reset the press count
                        button_handlers[i].callback(BUTTON_EVENT_SHORT_PRESS);
                        button_states[i].press_count = 0;
                    }
                    // Check if the button was pressed twice or more
                    else if (button_states[i].press_count >= 2) {
                        // Trigger the double press event callback and reset the press count
                        button_handlers[i].callback(BUTTON_EVENT_DOUBLE_PRESS);
                        button_states[i].press_count = 0;
                    }
                }

                // Update button state and reset debounce counter
                button_states[i].pressed = current_state;
                button_states[i].debounce_counter = 0;

                // If the button has been pressed
                if (current_state) {
                    // Update press time, trigger the press event callback, and increment the press count
                    button_states[i].press_time = HAL_GetTick();
                    button_handlers[i].callback(BUTTON_EVENT_DOWN);
                    button_states[i].press_count++;
                }
            }
        } else {
            // If the button was released after one press and double_press_timeout elapsed without press, trigger short_single_press
            if (!button_states[i].pressed && button_states[i].press_count == 1 && HAL_GetTick() - button_states[i].press_time > double_press_timeout) {
                // Trigger the short press event and reset the press count
                button_handlers[i].callback(BUTTON_EVENT_SHORT_PRESS);
                button_states[i].press_count = 0;
            }

            // Reset the debounce counter if the button state hasn't changed
            button_states[i].debounce_counter = 0;
        }
    }
}
