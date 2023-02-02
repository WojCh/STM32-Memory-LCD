
/*******************************************************************************
* font
* filename: D:/wojch/Downloads/lcd-image-converter-20161012/circleLoader.xml
* name: circleLoader
* family: MS Shell Dlg 2
* size: 14
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


#ifndef __FONT_circleLoader12_H
#define __FONT_circleLoader12_H

#define circularLoader &circleLoader12

static const Font_TypeDef circleLoader12 = {
		12,           // Font width
		12,           // Font height
		24,           // Bytes per character => height * round(width to full byte) / 8
		FONT_H,      // Vertical font scan lines
		32,          // First character: ' '
		40,          // Last character: ' '
		32,          // Unknown character: '0'
		{
				
          /* 0x20 ' ' */
          0x03, 0x00, 
          0x03, 0xc0, 
          0x00, 0xe0, 
          0x00, 0x60, 
          0x00, 0x30, 
          0x00, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x60, 0x60, 
          0x70, 0xe0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
          
          /* 0x21 '!' */
          0x00, 0x00, 
          0x00, 0x00, 
          0x60, 0x60, 
          0x60, 0x60, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x60, 0x60, 
          0x70, 0xe0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
          
          /* 0x22 '"' */
          0x0c, 0x00, 
          0x3c, 0x00, 
          0x70, 0x00, 
          0x60, 0x00, 
          0xc0, 0x00, 
          0xc0, 0x00, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x60, 0x60, 
          0x70, 0xe0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
          
          /* 0x23 '#' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x70, 0xc0, 
          0x60, 0x00, 
          0xc0, 0x00, 
          0xc0, 0x00, 
          0xc0, 0x00, 
          0xc0, 0x00, 
          0x60, 0x00, 
          0x70, 0xc0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
          
          /* 0x24 '$' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x70, 0xe0, 
          0x60, 0x60, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x00, 
          0xc0, 0x00, 
          0x60, 0x00, 
          0x70, 0x00, 
          0x3c, 0x00, 
          0x0c, 0x00,
          
          /* 0x25 '%' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x70, 0xe0, 
          0x60, 0x60, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x60, 0x60, 
          0x60, 0x60, 
          0x00, 0x00, 
          0x00, 0x00,
          
          /* 0x26 '&' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x70, 0xe0, 
          0x60, 0x60, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x00, 0x30, 
          0x00, 0x30, 
          0x00, 0x60, 
          0x00, 0xe0, 
          0x03, 0xc0, 
          0x03, 0x00,
          
          /* 0x27 ''' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x30, 0xe0, 
          0x00, 0x60, 
          0x00, 0x30, 
          0x00, 0x30, 
          0x00, 0x30, 
          0x00, 0x30, 
          0x00, 0x60, 
          0x30, 0xe0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
          
          /* 0x28 '(' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x70, 0xe0, 
          0x60, 0x60, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x60, 0x60, 
          0x70, 0xe0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
          
          /* 0x29 ')' */
          0x0f, 0x00, 
          0x3f, 0xc0, 
          0x70, 0xe0, 
          0x60, 0x60, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0xc0, 0x30, 
          0x60, 0x60, 
          0x70, 0xe0, 
          0x3f, 0xc0, 
          0x0f, 0x00,
		}
};

#endif // __FONT_circleLoader12_H
