
/*******************************************************************************
* font
* filename: D:/wojch/Downloads/lcd-image-converter-20161012/zecton12bold.xml
* name: zecton12
* family: Zekton Rg
* size: 14
* style: Normal
* included characters:  !"#$%&'()*+,-./0123456789:;<=>?\x0040ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~\x007f
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


#ifndef __FONT_zecton12b14_H
#define __FONT_zecton12b14_H

#define zekton12font_bold &zecton12b14

static const Font_TypeDef zecton12b14 = {
		9,           // Font width
		14,           // Font height
		28,           // Bytes per character => height * round(width to full byte) / 8
		FONT_H,      // Vertical font scan lines
		32,          // First character: ' '
		127,          // Last character: ' '
		35,          // Unknown character: '0'
		{

          /* 0x20 ' ' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x21 '!' */
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x22 '"' */
          0x14, 0x00,
          0x14, 0x00,
          0x14, 0x00,
          0x14, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x23 '#' */
          0x24, 0x00,
          0x24, 0x00,
          0x24, 0x00,
          0xff, 0x00,
          0x24, 0x00,
          0x24, 0x00,
          0x24, 0x00,
          0xff, 0x00,
          0x24, 0x00,
          0x24, 0x00,
          0x24, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x24 '$' */
          0x10, 0x00,
          0x7c, 0x00,
          0x82, 0x00,
          0x80, 0x00,
          0x7c, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x82, 0x00,
          0x7c, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x25 '%' */
          0x02, 0x00,
          0x42, 0x00,
          0xa4, 0x00,
          0xa4, 0x00,
          0xa8, 0x00,
          0x48, 0x00,
          0x12, 0x00,
          0x15, 0x00,
          0x25, 0x00,
          0x25, 0x00,
          0x42, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x26 '&' */
          0x78, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x3f, 0x00,
          0x42, 0x00,
          0x42, 0x00,
          0x42, 0x00,
          0x42, 0x00,
          0x42, 0x00,
          0x7f, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x27 ''' */
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x28 '(' */
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x02, 0x00,

          /* 0x29 ')' */
          0x08, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x10, 0x00,
          0x10, 0x00,

          /* 0x2a '*' */
          0x08, 0x00,
          0x08, 0x00,
          0x6b, 0x00,
          0x1c, 0x00,
          0x14, 0x00,
          0x22, 0x00,
          0x22, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x2b '+' */
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x7f, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x2c ',' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,

          /* 0x2d '-' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x3c, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x2e '.' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x2f '/' */
          0x02, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x00, 0x00,

          /* 0x30 '0' */
          0x3e, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x31 '1' */
          0x30, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x32 '2' */
          0x7e, 0x00,
          0x02, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x02, 0x00,
          0x3e, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x7f, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x33 '3' */
          0x7c, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x7c, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x7c, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x34 '4' */
          0x12, 0x00,
          0x12, 0x00,
          0x22, 0x00,
          0x22, 0x00,
          0x42, 0x00,
          0x42, 0x00,
          0x82, 0x00,
          0xff, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x35 '5' */
          0x7e, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x7e, 0x00,
          0x02, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x02, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x36 '6' */
          0x3e, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x5e, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x37 '7' */
          0x7f, 0x00,
          0x01, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x0c, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x38 '8' */
          0x3e, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3e, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x39 '9' */
          0x3e, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3d, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x3a ':' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x3b ';' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x3c '<' */
          0x00, 0x00,
          0x01, 0x00,
          0x02, 0x00,
          0x0c, 0x00,
          0x30, 0x00,
          0x40, 0x00,
          0x30, 0x00,
          0x0c, 0x00,
          0x02, 0x00,
          0x01, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x3d '=' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x7f, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x7f, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x3e '>' */
          0x00, 0x00,
          0x40, 0x00,
          0x20, 0x00,
          0x18, 0x00,
          0x06, 0x00,
          0x01, 0x00,
          0x06, 0x00,
          0x18, 0x00,
          0x20, 0x00,
          0x40, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x3f '?' */
          0x7e, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x1e, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x00, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x40 '\x0040' */
          0x00, 0x00,
          0x3e, 0x00,
          0x41, 0x00,
          0x40, 0x80,
          0x40, 0x80,
          0x4e, 0x80,
          0x50, 0x80,
          0x50, 0x80,
          0x50, 0x80,
          0x4f, 0x00,
          0x20, 0x00,
          0x1f, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x41 'A' */
          0x1c, 0x00,
          0x1c, 0x00,
          0x36, 0x00,
          0x36, 0x00,
          0x36, 0x00,
          0x63, 0x00,
          0x7f, 0x00,
          0x7f, 0x00,
          0xc1, 0x80,
          0xc1, 0x80,
          0xc1, 0x80,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x42 'B' */
          0x7e, 0x00,
          0x7f, 0x00,
          0x61, 0x80,
          0x61, 0x80,
          0x7f, 0x00,
          0x7f, 0x00,
          0x61, 0x80,
          0x61, 0x80,
          0x61, 0x80,
          0x7f, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x43 'C' */
          0x3e, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x7e, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x44 'D' */
          0xfe, 0x00,
          0xff, 0x00,
          0xc3, 0x80,
          0xc1, 0x80,
          0xc1, 0x80,
          0xc1, 0x80,
          0xc1, 0x80,
          0xc1, 0x80,
          0xc3, 0x80,
          0xff, 0x00,
          0xfe, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x45 'E' */
          0x7e, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x7e, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x7e, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x46 'F' */
          0x7e, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x7e, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x47 'G' */
          0x3e, 0x00,
          0x7f, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x6e, 0x00,
          0x6f, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x7f, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x48 'H' */
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xff, 0x00,
          0xff, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x49 'I' */
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x4a 'J' */
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x0c, 0x00,
          0x78, 0x00,
          0x70, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x4b 'K' */
          0x63, 0x00,
          0x66, 0x00,
          0x6c, 0x00,
          0x78, 0x00,
          0x7e, 0x00,
          0x7f, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x4c 'L' */
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x7e, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x4d 'M' */
          0x80, 0x80,
          0xc0, 0x80,
          0xc1, 0x80,
          0xc1, 0x80,
          0xe1, 0x80,
          0xe3, 0x80,
          0xe3, 0x80,
          0xf7, 0x80,
          0xd5, 0x80,
          0xdd, 0x80,
          0xc9, 0x80,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x4e 'N' */
          0x83, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xe3, 0x00,
          0xf3, 0x00,
          0xdb, 0x00,
          0xcf, 0x00,
          0xc7, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc1, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x4f 'O' */
          0x7e, 0x00,
          0xff, 0x00,
          0xe7, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xe7, 0x00,
          0xff, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x50 'P' */
          0x7e, 0x00,
          0x7f, 0x00,
          0x61, 0x80,
          0x61, 0x80,
          0x61, 0x80,
          0x7f, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x51 'Q' */
          0x7e, 0x00,
          0xff, 0x00,
          0xe7, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xe7, 0x00,
          0xff, 0x00,
          0x7e, 0x00,
          0x18, 0x00,
          0x0e, 0x00,
          0x00, 0x00,

          /* 0x52 'R' */
          0x7e, 0x00,
          0x7f, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x63, 0x00,
          0x7f, 0x00,
          0x7e, 0x00,
          0x78, 0x00,
          0x6c, 0x00,
          0x66, 0x00,
          0x63, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x53 'S' */
          0x3e, 0x00,
          0x7e, 0x00,
          0x60, 0x00,
          0x60, 0x00,
          0x7e, 0x00,
          0x3f, 0x00,
          0x03, 0x00,
          0x03, 0x00,
          0x03, 0x00,
          0x7f, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x54 'T' */
          0xff, 0x00,
          0xff, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x55 'U' */
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xc3, 0x00,
          0xff, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x56 'V' */
          0xc1, 0x80,
          0xc1, 0x80,
          0x41, 0x00,
          0x63, 0x00,
          0x62, 0x00,
          0x36, 0x00,
          0x36, 0x00,
          0x14, 0x00,
          0x1c, 0x00,
          0x1c, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x57 'W' */
          0xc9, 0x80,
          0xc9, 0x80,
          0xdd, 0x80,
          0xdd, 0x80,
          0xdd, 0x80,
          0xd5, 0x80,
          0xd5, 0x80,
          0xf7, 0x80,
          0xf7, 0x80,
          0x63, 0x00,
          0x63, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x58 'X' */
          0xc1, 0x80,
          0x63, 0x00,
          0x22, 0x00,
          0x3e, 0x00,
          0x1c, 0x00,
          0x08, 0x00,
          0x1c, 0x00,
          0x3e, 0x00,
          0x63, 0x00,
          0x41, 0x00,
          0xc1, 0x80,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x59 'Y' */
          0x80, 0x80,
          0xc1, 0x80,
          0x63, 0x00,
          0x22, 0x00,
          0x36, 0x00,
          0x1c, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x5a 'Z' */
          0x7f, 0x00,
          0x7f, 0x00,
          0x02, 0x00,
          0x06, 0x00,
          0x0c, 0x00,
          0x18, 0x00,
          0x10, 0x00,
          0x30, 0x00,
          0x20, 0x00,
          0x7f, 0x00,
          0x7f, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x5b '[' */
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x1e, 0x00,

          /* 0x5c '\' */
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x00, 0x00,

          /* 0x5d ']' */
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x04, 0x00,
          0x3c, 0x00,

          /* 0x5e '^' */
          0x14, 0x00,
          0x14, 0x00,
          0x12, 0x00,
          0x22, 0x00,
          0x21, 0x00,
          0x41, 0x00,
          0x41, 0x80,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x5f '_' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0xff, 0x00,
          0x00, 0x00,

          /* 0x60 '`' */
          0x18, 0x00,
          0x0c, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x61 'a' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x7e, 0x00,
          0x02, 0x00,
          0x01, 0x00,
          0x7d, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x42, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x62 'b' */
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x5e, 0x00,
          0x43, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x43, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x63 'c' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x1e, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x1e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x64 'd' */
          0x01, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x3d, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x43, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x65 'e' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x7e, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x7e, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x66 'f' */
          0x0c, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x18, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x67 'g' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x3e, 0x00,
          0x43, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3d, 0x00,
          0x01, 0x00,
          0x03, 0x00,
          0x3e, 0x00,

          /* 0x68 'h' */
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x7e, 0x00,
          0x43, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x69 'i' */
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x6a 'j' */
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x18, 0x00,
          0x30, 0x00,

          /* 0x6b 'k' */
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x46, 0x00,
          0x48, 0x00,
          0x50, 0x00,
          0x7e, 0x00,
          0x42, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x6c 'l' */
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x0c, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x6d 'm' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0xff, 0x00,
          0x89, 0x00,
          0x88, 0x80,
          0x88, 0x80,
          0x88, 0x80,
          0x88, 0x80,
          0x88, 0x80,
          0x88, 0x80,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x6e 'n' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x7e, 0x00,
          0x43, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x6f 'o' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x3e, 0x00,
          0x63, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x63, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x70 'p' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x3e, 0x00,
          0x43, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x43, 0x00,
          0x7e, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x40, 0x00,

          /* 0x71 'q' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x3f, 0x00,
          0x61, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x61, 0x00,
          0x3d, 0x00,
          0x01, 0x00,
          0x01, 0x00,
          0x01, 0x00,

          /* 0x72 'r' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x1c, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x20, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x73 's' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x3e, 0x00,
          0x40, 0x00,
          0x40, 0x00,
          0x3c, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x02, 0x00,
          0x7c, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x74 't' */
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x3e, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x75 'u' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x43, 0x00,
          0x3e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x76 'v' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x41, 0x00,
          0x22, 0x00,
          0x22, 0x00,
          0x22, 0x00,
          0x14, 0x00,
          0x14, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x77 'w' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x88, 0x80,
          0x88, 0x80,
          0x88, 0x80,
          0x94, 0x80,
          0x55, 0x00,
          0x55, 0x00,
          0x63, 0x00,
          0x22, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x78 'x' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0xc1, 0x00,
          0x22, 0x00,
          0x34, 0x00,
          0x18, 0x00,
          0x18, 0x00,
          0x24, 0x00,
          0x62, 0x00,
          0xc1, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x79 'y' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x41, 0x00,
          0x3f, 0x00,
          0x01, 0x00,
          0x03, 0x00,
          0x3e, 0x00,

          /* 0x7a 'z' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x7e, 0x00,
          0x02, 0x00,
          0x04, 0x00,
          0x08, 0x00,
          0x10, 0x00,
          0x20, 0x00,
          0x40, 0x00,
          0x7e, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x7b '{' */
          0x06, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x30, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x06, 0x00,
          0x00, 0x00,

          /* 0x7c '|' */
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,
          0x10, 0x00,

          /* 0x7d '}' */
          0x30, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x06, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x08, 0x00,
          0x30, 0x00,
          0x00, 0x00,

          /* 0x7e '~' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x39, 0x00,
          0x46, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

          /* 0x7f '\x007f' */
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,
          0x00, 0x00,

		}
};

#endif // __FONT_zecton1214_H
