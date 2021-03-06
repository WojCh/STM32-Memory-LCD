#ifndef __DIGITS8x16_H
#define __DIGITS8x16_H
//#include "lcd.h"

#define dig8x16 &Digits8x16

static const Font_TypeDef Digits8x16 = {
		8,           // Font width
		14,          // Font height
		14,          // Bytes per character
		FONT_H,      // Vertical font scan lines
		32,          // First character: '0'
		128,          // Last character: '9'
		35,          // Unknown character: '0'
		{
				0x00, //
				0x00, //     #
				0x00, //     #
				0x00, //     #
				0x00, //     #
				0x00, //     #
				0x00, //     #
				0x00, //     #
				0x00, //     #
				0x00, //
				0x00, //     #
				0x00, //
				0x00, //
				0x00, //
				// @0 '!' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @14 '"' (8 pixels wide)
				0x00, //
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @28 '#' (8 pixels wide)
				0x00, //
				0x0A, //     # #
				0x0A, //     # #
				0x3E, //   #####
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x3E, //   #####
				0x28, //   # #
				0x28, //   # #
				0x00, //
				0x00, //
				0x00, //

				// @42 '$' (8 pixels wide)
				0x08, //     #
				0x1C, //    ###
				0x2A, //   # # #
				0x2A, //   # # #
				0x38, //   ###
				0x18, //    ##
				0x0C, //     ##
				0x0E, //     ###
				0x2A, //   # # #
				0x2A, //   # # #
				0x1C, //    ###
				0x08, //     #
				0x00, //
				0x00, //

				// @56 '%' (8 pixels wide)
				0x00, //
				0x62, //  ##   #
				0x94, // #  # #
				0x94, // #  # #
				0x98, // #  ##
				0x68, //  ## #
				0x16, //    # ##
				0x19, //    ##  #
				0x29, //   # #  #
				0x29, //   # #  #
				0x46, //  #   ##
				0x00, //
				0x00, //
				0x00, //

				// @70 '&' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x20, //   #
				0x1E, //    ####
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x1C, //    ###
				0x00, //
				0x00, //
				0x00, //

				// @84 ''' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @98 '(' (8 pixels wide)
				0x00, //
				0x04, //      #
				0x04, //      #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x04, //      #
				0x04, //      #
				0x00, //
				0x00, //

				// @112 ')' (8 pixels wide)
				0x00, //
				0x10, //    #
				0x10, //    #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x00, //

				// @126 '*' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x2A, //   # # #
				0x1C, //    ###
				0x2A, //   # # #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @140 '+' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x08, //     #
				0x3E, //   #####
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @154 ',' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //

				// @168 '-' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x0C, //     ##
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @182 '.' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @196 '/' (8 pixels wide)
				0x00, //
				0x02, //       #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x20, //   #
				0x20, //   #
				0x00, //
				0x00, //
				0x00, //

				// @210 '0' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @224 '1' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x18, //    ##
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @238 '2' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x04, //      #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x20, //   #
				0x3C, //   ####
				0x00, //
				0x00, //
				0x00, //

				// @252 '3' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x0C, //     ##
				0x10, //    #
				0x0C, //     ##
				0x04, //      #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @266 '4' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x14, //    # #
				0x14, //    # #
				0x24, //   #  #
				0x3E, //   #####
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x00, //
				0x00, //
				0x00, //

				// @280 '5' (8 pixels wide)
				0x00, //
				0x3C, //   ####
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x38, //   ###
				0x04, //      #
				0x04, //      #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @294 '6' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x20, //   #
				0x20, //   #
				0x38, //   ###
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @308 '7' (8 pixels wide)
				0x00, //
				0x3C, //   ####
				0x24, //   #  #
				0x04, //      #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @322 '8' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @336 '9' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x1C, //    ###
				0x04, //      #
				0x04, //      #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @350 ':' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @364 ';' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //

				// @378 '<' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x04, //      #
				0x08, //     #
				0x10, //    #
				0x08, //     #
				0x04, //      #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @392 '=' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x1E, //    ####
				0x00, //
				0x1E, //    ####
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @406 '>' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x04, //      #
				0x02, //       #
				0x04, //      #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @420 '?' (8 pixels wide)
				0x00, //
				0x10, //    #
				0x28, //   # #
				0x28, //   # #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @434 '@' (8 pixels wide)
				0x00, //
				0x3E, //   #####
				0x41, //  #     #
				0x5D, //  # ### #
				0x55, //  # # # #
				0x45, //  #   # #
				0x5D, //  # ### #
				0x55, //  # # # #
				0x5E, //  # ####
				0x40, //  #
				0x3F, //   ######
				0x00, //
				0x00, //
				0x00, //

				// @448 'A' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x3E, //   #####
				0x22, //   #   #
				0x22, //   #   #
				0x00, //
				0x00, //
				0x00, //

				// @462 'B' (8 pixels wide)
				0x00, //
				0x3C, //   ####
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x38, //   ###
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x3C, //   ####
				0x00, //
				0x00, //
				0x00, //

				// @476 'C' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @490 'D' (8 pixels wide)
				0x00, //
				0x38, //   ###
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x38, //   ###
				0x00, //
				0x00, //
				0x00, //

				// @504 'E' (8 pixels wide)
				0x00, //
				0x1C, //    ###
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x1C, //    ###
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x1C, //    ###
				0x00, //
				0x00, //
				0x00, //

				// @518 'F' (8 pixels wide)
				0x00, //
				0x1C, //    ###
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x1C, //    ###
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @532 'G' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x20, //   #
				0x20, //   #
				0x2C, //   # ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @546 'H' (8 pixels wide)
				0x00, //
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x3C, //   ####
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x00, //
				0x00, //
				0x00, //

				// @560 'I' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @574 'J' (8 pixels wide)
				0x00, //
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @588 'K' (8 pixels wide)
				0x00, //
				0x24, //   #  #
				0x28, //   # #
				0x28, //   # #
				0x30, //   ##
				0x30, //   ##
				0x30, //   ##
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x24, //   #  #
				0x00, //
				0x00, //
				0x00, //

				// @602 'L' (8 pixels wide)
				0x00, //
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x1C, //    ###
				0x00, //
				0x00, //
				0x00, //

				// @616 'M' (8 pixels wide)
				0x00, //
				0x22, //   #   #
				0x22, //   #   #
				0x36, //   ## ##
				0x36, //   ## ##
				0x36, //   ## ##
				0x2A, //   # # #
				0x2A, //   # # #
				0x2A, //   # # #
				0x2A, //   # # #
				0x22, //   #   #
				0x00, //
				0x00, //
				0x00, //

				// @630 'N' (8 pixels wide)
				0x00, //
				0x24, //   #  #
				0x24, //   #  #
				0x34, //   ## #
				0x34, //   ## #
				0x34, //   ## #
				0x34, //   ## #
				0x2C, //   # ##
				0x2C, //   # ##
				0x24, //   #  #
				0x24, //   #  #
				0x00, //
				0x00, //
				0x00, //

				// @644 'O' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @658 'P' (8 pixels wide)
				0x00, //
				0x38, //   ###
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x38, //   ###
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x00, //
				0x00, //
				0x00, //

				// @672 'Q' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x2C, //   # ##
				0x24, //   #  #
				0x1E, //    ####
				0x00, //
				0x00, //
				0x00, //

				// @686 'R' (8 pixels wide)
				0x00, //
				0x3C, //   ####
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x2C, //   # ##
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x24, //   #  #
				0x24, //   #  #
				0x00, //
				0x00, //
				0x00, //

				// @700 'S' (8 pixels wide)
				0x00, //
				0x18, //    ##
				0x24, //   #  #
				0x24, //   #  #
				0x10, //    #
				0x18, //    ##
				0x08, //     #
				0x04, //      #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @714 'T' (8 pixels wide)
				0x00, //
				0x3E, //   #####
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @728 'U' (8 pixels wide)
				0x00, //
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x24, //   #  #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @742 'V' (8 pixels wide)
				0x00, //
				0x22, //   #   #
				0x22, //   #   #
				0x22, //   #   #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @756 'W' (8 pixels wide)
				0x00, //
				0x54, //  # # #
				0x54, //  # # #
				0x54, //  # # #
				0x54, //  # # #
				0x6C, //  ## ##
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x00, //
				0x00, //
				0x00, //

				// @770 'X' (8 pixels wide)
				0x00, //
				0x22, //   #   #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x08, //     #
				0x08, //     #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x22, //   #   #
				0x00, //
				0x00, //
				0x00, //

				// @784 'Y' (8 pixels wide)
				0x00, //
				0x22, //   #   #
				0x22, //   #   #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @798 'Z' (8 pixels wide)
				0x00, //
				0x3C, //   ####
				0x04, //      #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x20, //   #
				0x3C, //   ####
				0x00, //
				0x00, //
				0x00, //

				// @812 '[' (8 pixels wide)
				0x00, //
				0x0E, //     ###
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x0E, //     ###
				0x00, //

				// @826 '\' (8 pixels wide)
				0x00, //
				0x20, //   #
				0x20, //   #
				0x10, //    #
				0x10, //    #
				0x08, //     #
				0x08, //     #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x02, //       #
				0x00, //
				0x00, //
				0x00, //

				// @840 ']' (8 pixels wide)
				0x00, //
				0x1C, //    ###
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x04, //      #
				0x1C, //    ###
				0x00, //

				// @854 '^' (8 pixels wide)
				0x00, //
				0x0C, //     ##
				0x0C, //     ##
				0x0C, //     ##
				0x12, //    #  #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @868 '_' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x3E, //   #####

				// @882 '`' (8 pixels wide)
				0x00, //
				0x00, //
				0x08, //     #
				0x04, //      #
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //

				// @896 'a' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x10, //    #
				0x08, //     #
				0x18, //    ##
				0x28, //   # #
				0x28, //   # #
				0x38, //   ###
				0x00, //
				0x00, //
				0x00, //

				// @910 'b' (8 pixels wide)
				0x00, //
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x28, //   # #
				0x38, //   ###
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x30, //   ##
				0x00, //
				0x00, //
				0x00, //

				// @924 'c' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x14, //    # #
				0x10, //    #
				0x10, //    #
				0x14, //    # #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @938 'd' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x18, //    ##
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x18, //    ##
				0x00, //
				0x00, //
				0x00, //

				// @952 'e' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x14, //    # #
				0x1C, //    ###
				0x10, //    #
				0x14, //    # #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @966 'f' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x38, //   ###
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @980 'g' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x18, //    ##
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x18, //    ##
				0x08, //     #
				0x10, //    #
				0x00, //

				// @994 'h' (8 pixels wide)
				0x00, //
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x28, //   # #
				0x38, //   ###
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x00, //
				0x00, //
				0x00, //

				// @1008 'i' (8 pixels wide)
				0x00, //
				0x00, //
				0x10, //    #
				0x10, //    #
				0x00, //
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @1022 'j' (8 pixels wide)
				0x00, //
				0x00, //
				0x10, //    #
				0x10, //    #
				0x00, //
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x20, //   #
				0x00, //

				// @1036 'k' (8 pixels wide)
				0x00, //
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x24, //   #  #
				0x28, //   # #
				0x30, //   ##
				0x30, //   ##
				0x28, //   # #
				0x24, //   #  #
				0x00, //
				0x00, //
				0x00, //

				// @1050 'l' (8 pixels wide)
				0x00, //
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @1064 'm' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x2A, //   # # #
				0x3E, //   #####
				0x2A, //   # # #
				0x2A, //   # # #
				0x2A, //   # # #
				0x2A, //   # # #
				0x00, //
				0x00, //
				0x00, //

				// @1078 'n' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x28, //   # #
				0x38, //   ###
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x00, //
				0x00, //
				0x00, //

				// @1092 'o' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x10, //    #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x10, //    #
				0x00, //
				0x00, //
				0x00, //

				// @1106 'p' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x28, //   # #
				0x38, //   ###
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x30, //   ##
				0x20, //   #
				0x20, //   #
				0x00, //

				// @1120 'q' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x18, //    ##
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x18, //    ##
				0x08, //     #
				0x08, //     #
				0x00, //

				// @1134 'r' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x28, //   # #
				0x38, //   ###
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x20, //   #
				0x00, //
				0x00, //
				0x00, //

				// @1148 's' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x08, //     #
				0x14, //    # #
				0x18, //    ##
				0x0C, //     ##
				0x14, //    # #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @1162 't' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x10, //    #
				0x10, //    #
				0x38, //   ###
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x10, //    #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @1176 'u' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x28, //   # #
				0x38, //   ###
				0x00, //
				0x00, //
				0x00, //

				// @1190 'v' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //
				0x00, //
				0x00, //

				// @1204 'w' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x2A, //   # # #
				0x2A, //   # # #
				0x2A, //   # # #
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x00, //
				0x00, //
				0x00, //

				// @1218 'x' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x24, //   #  #
				0x18, //    ##
				0x18, //    ##
				0x18, //    ##
				0x18, //    ##
				0x24, //   #  #
				0x00, //
				0x00, //
				0x00, //

				// @1232 'y' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x14, //    # #
				0x14, //    # #
				0x14, //    # #
				0x18, //    ##
				0x18, //    ##
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x00, //

				// @1246 'z' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x38, //   ###
				0x08, //     #
				0x10, //    #
				0x10, //    #
				0x20, //   #
				0x38, //   ###
				0x00, //
				0x00, //
				0x00, //

				// @1260 '{' (8 pixels wide)
				0x00, //
				0x0E, //     ###
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x10, //    #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x0E, //     ###
				0x00, //

				// @1274 '|' (8 pixels wide)
				0x00, //
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x00, //

				// @1288 '}' (8 pixels wide)
				0x00, //
				0x38, //   ###
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x04, //      #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x08, //     #
				0x38, //   ###
				0x00, //

				// @1302 '~' (8 pixels wide)
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x34, //   ## #
				0x2C, //   # ##
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
				0x00, //
			}


				//				0x7E,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E, // 0
//				0x08,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x08, // 1
//				0x7E,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xFE,0x7F,0x03,0x03,0x03,0x03,0x03,0xFF,0x7E, // 2
//				0x7E,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xFC,0xFC,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0x7E, // 3
//				0x42,0xC3,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0xFE,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x40, // 4
//				0x7E,0xFF,0x03,0x03,0x03,0x03,0x03,0x7F,0xFE,0xC0,0xC0,0xC0,0xC0,0xC0,0xFF,0x7E, // 5
//				0x7E,0xFF,0x03,0x03,0x03,0x03,0x03,0x7F,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E, // 6
//				0x7E,0xFF,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x40, // 7
//				0x7E,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0x7E, // 8
//				0x7E,0xFF,0xC3,0xC3,0xC3,0xC3,0xC3,0xFF,0xFE,0xC0,0xC0,0xC0,0xC0,0xC0,0xC0,0x40, // 9
//		}
};

#endif // __DIGITS8x16_H
