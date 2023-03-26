
/*******************************************************************************
* image
* filename: D:/wojch/STM32CubeIDE/workspace_1.7.0/memoryLcd/Core/Inc/icons/battery/battery.xml
* name: battery
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Edge 128
* bits per pixel: 1
*
* preprocess:
*  main scan direction: top_to_bottom
*  line scan direction: forward
*  inverse: yes
*******************************************************************************/

/*
 typedef struct {
     const uint8_t *data;
     uint16_t width;
     uint16_t height;
     uint8_t dataSize;
     } tImage;
*/
#include <stdint.h>



static const uint8_t image_data_battery[48] = {
    0x7f, 0xff, 0xfe, 0x00, 
    0x80, 0x00, 0x01, 0x00, 
    0xbf, 0xff, 0xfd, 0x00, 
    0xbf, 0xff, 0xfd, 0x80, 
    0xbf, 0xff, 0xfc, 0x40, 
    0xbf, 0xff, 0xfe, 0x40, 
    0xbf, 0xff, 0xfe, 0x40, 
    0xbf, 0xff, 0xfc, 0x40, 
    0xbf, 0xff, 0xfd, 0x80, 
    0xbf, 0xff, 0xfd, 0x00, 
    0x80, 0x00, 0x01, 0x00, 
    0x7f, 0xff, 0xfe, 0x00
};
const tImage battery = { image_data_battery, 26, 12,
    8 };

