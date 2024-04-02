#ifndef drawFunctions_H_   /* Include guard */
#define drawFunctions_H_

///////////////////////////////Function Declarations:
volatile int pixel_buffer_start; // global variable

void draw_box(int x, int y, int short line_color);
void plot_pixel(int x, int y, short int line_color);
void clear_screen();
void draw_line(int x0, int y0, int x1, int y1, int short color);
void swap(int *a, int *b);
int abs(int a);
void wait_for_vsync();
void drawCharacterFR();
void drawPic(int x_d, int y_d, unsigned short *picArray);
void drawTransparentPic(int x_d, int y_d, unsigned short *picArray);

short int rainbowColors[] = {
    0xFFFF, // White
    0xF800, // Red
    0xFFE0, // Yellow
    0x07FF, // Cyan
    0x001F, // Blue
    0xF81F, // Magenta
    0x7E0,  // Green
    0x4380, // Orange
    0x0384, // Purple
    0x8384  // Pink
};

/////////////////////////////////////////Initializing Buffers:
short int Buffer1[240][512]; // 240 rows, 512 (320 + padding) columns
short int Buffer2[240][512];


#endif // drawFunctions_H_