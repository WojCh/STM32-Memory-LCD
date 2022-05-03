
/*******************************************************************************
* font
* filename: D:/wojch/Downloads/SmallestFont.xml
* name: SmallestFont
* family: MS PGothic
* size: 12
* style: Normal
* included characters:  !"#$%&'()*+,-./0123456789:;<=>?\x0040ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~
* antialiasing: no
* type: monospaced
* encoding: ASMO-708
* unicode bom: no
*
* preset name: Monochrome
* data block size: 8 bit(s), uint8_t
* RLE compression enabled: no
* conversion type: Monochrome, Edge 128
* bits per pixel: 1
*******************************************************************************/


#ifndef __FONT_SmallestFont12_H
#define __FONT_SmallestFont12_H

#define smallestFont &SmallestFont12

static const Font_TypeDef SmallestFont12 = {
		8,           // Font width
		12,           // Font height
		12,           // Bytes per character => height * round(width to full byte) / 8
		FONT_H,      // Vertical font scan lines
		32,          // First character: ' '
		127,          // Last character: ' '
		35,          // Unknown character: '0'
		{
				
          /* 0x20 ' ' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x21 '!' */
          0x00, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x00, 
          0x00, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x22 '"' */
          0x00, 
          0x28, 
          0x28, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x23 '#' */
          0x00, 
          0x28, 
          0x28, 
          0x7c, 
          0x28, 
          0x28, 
          0x28, 
          0x7c, 
          0x28, 
          0x28, 
          0x00, 
          0x00,
          
          /* 0x24 '$' */
          0x10, 
          0x38, 
          0x54, 
          0x50, 
          0x30, 
          0x18, 
          0x14, 
          0x54, 
          0x54, 
          0x38, 
          0x10, 
          0x00,
          
          /* 0x25 '%' */
          0x00, 
          0x62, 
          0x92, 
          0x94, 
          0x68, 
          0x10, 
          0x2c, 
          0x52, 
          0x92, 
          0x8c, 
          0x00, 
          0x00,
          
          /* 0x26 '&' */
          0x00, 
          0x30, 
          0x48, 
          0x48, 
          0x30, 
          0x50, 
          0x8a, 
          0x84, 
          0x84, 
          0x7a, 
          0x00, 
          0x00,
          
          /* 0x27 ''' */
          0x00, 
          0x10, 
          0x10, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x28 '(' */
          0x08, 
          0x10, 
          0x10, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x10, 
          0x10, 
          0x08, 
          0x00,
          
          /* 0x29 ')' */
          0x20, 
          0x10, 
          0x10, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x10, 
          0x10, 
          0x20, 
          0x00,
          
          /* 0x2a '*' */
          0x00, 
          0x10, 
          0x54, 
          0x38, 
          0x54, 
          0x10, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x2b '+' */
          0x00, 
          0x00, 
          0x00, 
          0x10, 
          0x10, 
          0x7c, 
          0x10, 
          0x10, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x2c ',' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x08, 
          0x08, 
          0x10, 
          0x00,
          
          /* 0x2d '-' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x7c, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x2e '.' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x2f '/' */
          0x00, 
          0x04, 
          0x04, 
          0x08, 
          0x08, 
          0x10, 
          0x10, 
          0x20, 
          0x20, 
          0x40, 
          0x40, 
          0x00,
          
          /* 0x30 '0' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x44, 
          0x54, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x31 '1' */
          0x00, 
          0x10, 
          0x30, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x32 '2' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x04, 
          0x04, 
          0x18, 
          0x20, 
          0x40, 
          0x7c, 
          0x00, 
          0x00,
          
          /* 0x33 '3' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x04, 
          0x18, 
          0x04, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x34 '4' */
          0x00, 
          0x18, 
          0x28, 
          0x28, 
          0x28, 
          0x48, 
          0x48, 
          0x7c, 
          0x08, 
          0x08, 
          0x00, 
          0x00,
          
          /* 0x35 '5' */
          0x00, 
          0x7c, 
          0x40, 
          0x40, 
          0x78, 
          0x04, 
          0x04, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x36 '6' */
          0x00, 
          0x38, 
          0x44, 
          0x40, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x37 '7' */
          0x00, 
          0x7c, 
          0x04, 
          0x08, 
          0x08, 
          0x10, 
          0x10, 
          0x10, 
          0x20, 
          0x20, 
          0x00, 
          0x00,
          
          /* 0x38 '8' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x38, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x39 '9' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x44, 
          0x3c, 
          0x04, 
          0x04, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x3a ':' */
          0x00, 
          0x00, 
          0x00, 
          0x10, 
          0x00, 
          0x00, 
          0x00, 
          0x10, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x3b ';' */
          0x00, 
          0x00, 
          0x00, 
          0x10, 
          0x00, 
          0x00, 
          0x00, 
          0x10, 
          0x10, 
          0x20, 
          0x00, 
          0x00,
          
          /* 0x3c '<' */
          0x00, 
          0x04, 
          0x08, 
          0x10, 
          0x20, 
          0x40, 
          0x20, 
          0x10, 
          0x08, 
          0x04, 
          0x00, 
          0x00,
          
          /* 0x3d '=' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x7c, 
          0x00, 
          0x00, 
          0x7c, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x3e '>' */
          0x00, 
          0x40, 
          0x20, 
          0x10, 
          0x08, 
          0x04, 
          0x08, 
          0x10, 
          0x20, 
          0x40, 
          0x00, 
          0x00,
          
          /* 0x3f '?' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x08, 
          0x10, 
          0x10, 
          0x00, 
          0x00, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x40 '\x0040' */
          0x00, 
          0x38, 
          0x44, 
          0x82, 
          0x9a, 
          0xaa, 
          0xaa, 
          0x9c, 
          0x40, 
          0x3c, 
          0x00, 
          0x00,
          
          /* 0x41 'A' */
          0x00, 
          0x10, 
          0x28, 
          0x28, 
          0x44, 
          0x44, 
          0x7c, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x42 'B' */
          0x00, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x00, 
          0x00,
          
          /* 0x43 'C' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x40, 
          0x40, 
          0x40, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x44 'D' */
          0x00, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x00, 
          0x00,
          
          /* 0x45 'E' */
          0x00, 
          0x7c, 
          0x40, 
          0x40, 
          0x40, 
          0x70, 
          0x40, 
          0x40, 
          0x40, 
          0x7c, 
          0x00, 
          0x00,
          
          /* 0x46 'F' */
          0x00, 
          0x7c, 
          0x40, 
          0x40, 
          0x40, 
          0x70, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x00, 
          0x00,
          
          /* 0x47 'G' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x40, 
          0x4c, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x48 'H' */
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x7c, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x49 'I' */
          0x00, 
          0x7c, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x7c, 
          0x00, 
          0x00,
          
          /* 0x4a 'J' */
          0x00, 
          0x04, 
          0x04, 
          0x04, 
          0x04, 
          0x04, 
          0x04, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x4b 'K' */
          0x00, 
          0x44, 
          0x44, 
          0x48, 
          0x50, 
          0x60, 
          0x50, 
          0x48, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x4c 'L' */
          0x00, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x7c, 
          0x00, 
          0x00,
          
          /* 0x4d 'M' */
          0x00, 
          0x44, 
          0x6c, 
          0x54, 
          0x54, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x4e 'N' */
          0x00, 
          0x44, 
          0x44, 
          0x64, 
          0x54, 
          0x54, 
          0x54, 
          0x4c, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x4f 'O' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x50 'P' */
          0x00, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x40, 
          0x40, 
          0x40, 
          0x40, 
          0x00, 
          0x00,
          
          /* 0x51 'Q' */
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x54, 
          0x48, 
          0x34, 
          0x00, 
          0x00,
          
          /* 0x52 'R' */
          0x00, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x53 'S' */
          0x00, 
          0x38, 
          0x44, 
          0x40, 
          0x40, 
          0x38, 
          0x04, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x54 'T' */
          0x00, 
          0x7c, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x55 'U' */
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x56 'V' */
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x28, 
          0x28, 
          0x28, 
          0x10, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x57 'W' */
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x54, 
          0x54, 
          0x54, 
          0x54, 
          0x28, 
          0x28, 
          0x00, 
          0x00,
          
          /* 0x58 'X' */
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x28, 
          0x10, 
          0x28, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x59 'Y' */
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x28, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x5a 'Z' */
          0x00, 
          0x7c, 
          0x04, 
          0x08, 
          0x08, 
          0x10, 
          0x20, 
          0x20, 
          0x40, 
          0x7c, 
          0x00, 
          0x00,
          
          /* 0x5b '[' */
          0x38, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x38, 
          0x00,
          
          /* 0x5c '\' */
          0x00, 
          0x20, 
          0x20, 
          0x10, 
          0x10, 
          0x10, 
          0x08, 
          0x08, 
          0x08, 
          0x04, 
          0x04, 
          0x00,
          
          /* 0x5d ']' */
          0x38, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x38, 
          0x00,
          
          /* 0x5e '^' */
          0x00, 
          0x10, 
          0x28, 
          0x44, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x5f '_' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x7c,
          
          /* 0x60 '`' */
          0x00, 
          0x10, 
          0x08, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
          /* 0x61 'a' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x38, 
          0x04, 
          0x3c, 
          0x44, 
          0x44, 
          0x3c, 
          0x00, 
          0x00,
          
          /* 0x62 'b' */
          0x00, 
          0x40, 
          0x40, 
          0x40, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x00, 
          0x00,
          
          /* 0x63 'c' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x38, 
          0x44, 
          0x40, 
          0x40, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x64 'd' */
          0x00, 
          0x04, 
          0x04, 
          0x04, 
          0x3c, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x3c, 
          0x00, 
          0x00,
          
          /* 0x65 'e' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x38, 
          0x44, 
          0x7c, 
          0x40, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x66 'f' */
          0x00, 
          0x08, 
          0x10, 
          0x10, 
          0x38, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x67 'g' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x3c, 
          0x44, 
          0x44, 
          0x3c, 
          0x04, 
          0x04, 
          0x04, 
          0x38,
          
          /* 0x68 'h' */
          0x00, 
          0x40, 
          0x40, 
          0x40, 
          0x58, 
          0x64, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x69 'i' */
          0x00, 
          0x10, 
          0x00, 
          0x00, 
          0x30, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x0c, 
          0x00, 
          0x00,
          
          /* 0x6a 'j' */
          0x00, 
          0x08, 
          0x00, 
          0x00, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x08, 
          0x30,
          
          /* 0x6b 'k' */
          0x00, 
          0x40, 
          0x40, 
          0x40, 
          0x48, 
          0x50, 
          0x60, 
          0x50, 
          0x48, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x6c 'l' */
          0x00, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x18, 
          0x00, 
          0x00,
          
          /* 0x6d 'm' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x74, 
          0x4a, 
          0x4a, 
          0x4a, 
          0x4a, 
          0x4a, 
          0x00, 
          0x00,
          
          /* 0x6e 'n' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x58, 
          0x64, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x6f 'o' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x38, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x70 'p' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x78, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x78, 
          0x40, 
          0x40,
          
          /* 0x71 'q' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x3c, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x3c, 
          0x04, 
          0x04,
          
          /* 0x72 'r' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x2c, 
          0x30, 
          0x20, 
          0x20, 
          0x20, 
          0x20, 
          0x00, 
          0x00,
          
          /* 0x73 's' */
          0x00, 
          0x00, 
          0x00, 
          0x38, 
          0x44, 
          0x40, 
          0x38, 
          0x04, 
          0x44, 
          0x38, 
          0x00, 
          0x00,
          
          /* 0x74 't' */
          0x00, 
          0x00, 
          0x10, 
          0x10, 
          0x3c, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x0c, 
          0x00, 
          0x00,
          
          /* 0x75 'u' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x44, 
          0x44, 
          0x44, 
          0x44, 
          0x4c, 
          0x34, 
          0x00, 
          0x00,
          
          /* 0x76 'v' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x44, 
          0x44, 
          0x28, 
          0x28, 
          0x10, 
          0x10, 
          0x00, 
          0x00,
          
          /* 0x77 'w' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x44, 
          0x54, 
          0x54, 
          0x54, 
          0x28, 
          0x28, 
          0x00, 
          0x00,
          
          /* 0x78 'x' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x44, 
          0x28, 
          0x10, 
          0x10, 
          0x28, 
          0x44, 
          0x00, 
          0x00,
          
          /* 0x79 'y' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x44, 
          0x44, 
          0x28, 
          0x28, 
          0x10, 
          0x10, 
          0x20, 
          0x40,
          
          /* 0x7a 'z' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x7c, 
          0x08, 
          0x10, 
          0x20, 
          0x40, 
          0x7c, 
          0x00, 
          0x00,
          
          /* 0x7b '{' */
          0x0c, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x60, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x0c, 
          0x00,
          
          /* 0x7c '|' */
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x10,
          
          /* 0x7d '}' */
          0x60, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x0c, 
          0x10, 
          0x10, 
          0x10, 
          0x10, 
          0x60, 
          0x00,
          
          /* 0x7e '~' */
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x32, 
          0x4c, 
          0x00, 
          0x00, 
          0x00, 
          0x00, 
          0x00,
          
		}
};

#endif // __FONT_SmallestFont12_H
