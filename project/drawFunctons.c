#include "drawFunctions.h"


//Draws BackGround 
void drawBg(){
    // for(int y = 0; y < 100; y++){
    //     for(int x = 0; x < 100; x++){
    //         int index = x + y * 100;
    //         if(c1[index] != 0) plot_pixel(x, y, c1[index]);
    //     }
    // }
    drawPic(320, 240, stadium);
}

//Draws character facing right
void drawCharacterFR(){
    for(int y = 0; y < 100; y++){
        for(int x = 0; x < 100; x++){
            int index = x + y * 100;
            if(c1[index] != 0) plot_pixel(x, y, c1[index]);
        }
    }
    //drawPic(100, 100, c1);
}

void drawPic(int x_d, int y_d, unsigned short *picArray){
    for(int y = 0; y < y_d; y++){
        for(int x = 0; x < x_d; x++){
            int index = x + y * x_d;
            plot_pixel(x, y, picArray[index]);
        }
    }
}

void drawFlipPic(int x_d, int y_d, unsigned short *picArray, int scaleF){
    for(int y = 0; y < y_d; y++){
        for(int x = 0; x < x_d; x++){
            int index = x + y * x_d;
            plot_pixel(x_d - 1 - x, y, picArray[index]);
        }
    }
}


void drawTransparentPic(int x_d, int y_d, unsigned short *picArray){
    for(int y = 0; y < y_d; y++){
        for(int x = 0; x < x_d; x++){
            int index = x + y * x_d;
            if(c1[index] != 0) 
                plot_pixel(x, y, picArray[index]);
        }
    }
}

void draw_box(int x, int y, int short line_color){
	plot_pixel(x, y, line_color);
	
	//corners
	plot_pixel(x+1, y+1, line_color);
	plot_pixel(x-1, y-1, line_color);
	plot_pixel(x+1, y-1, line_color);
	plot_pixel(x-1, y+1, line_color);
	
	//sides
	plot_pixel(x+1, y, line_color);
	plot_pixel(x-1, y, line_color);
	plot_pixel(x, y+1, line_color);
	plot_pixel(x, y-1, line_color);
}

void wait_for_vsync() {
    volatile int * pixel_ctrl_ptr = (int *)0xFF203020;
    *pixel_ctrl_ptr = 1;
    int status = *(pixel_ctrl_ptr + 3) & 0b1;

    while (status != 0x0) {
        status = *(pixel_ctrl_ptr + 3) & 0b1;
    }
}

int abs(int a) {
    if (a < 0) {
        return -a;
    }
    return a;
}

void clear_screen() {
    for (int x = 0; x < 320; ++x) {
        for (int y = 0; y < 240; ++y) {
            plot_pixel(x, y, 0);
        }
    }
}

void draw_line(int x0, int y0, int x1, int y1, int short color) {
    char steep = 0;
    if (abs(y1-y0) > abs(x1-x0)) {
        steep = 1;
    }

    if (steep == 1) {
        swap(&x0, &y0);
        swap(&x1, &y1);
    }
    if (x0 > x1) {
        swap(&x0, &x1);
        swap(&y0, &y1);
    }

    int dx = x1 - x0;
    int dy = abs(y1 - y0);
    int error = -(dx/2);
    int y = y0;

    int ystep = 1;
    if (y0 > y1) {
        ystep = -1;
    }

    for (int x = x0; x <= x1; ++x) {
        if (steep == 1) {
            plot_pixel(y, x, color);
        } else {
            plot_pixel(x, y, color);
        }
        error = error + dy;
        if (error > 0) {
            y = y + ystep;
            error = error - dx;
        }
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}


void plot_pixel(int x, int y, short int line_color)
{
    volatile short int *one_pixel_address;
    one_pixel_address = pixel_buffer_start + (y << 10) + (x << 1);
    *one_pixel_address = line_color;
}