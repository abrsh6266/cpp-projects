#include <iostream>
#include <graphics.h>  // Assuming you have a graphics library for drawing

// Function to perform 4-connected boundary fill
void boundaryFill4(int x, int y, int fill_color, int boundary_color) {
    // Check if the current pixel is not the boundary color or the fill color
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        // Set the current pixel to the fill color
        putpixel(x, y, fill_color);

        // Call the function recursively for the neighboring pixels
        boundaryFill4(x + 1, y, fill_color, boundary_color);
        boundaryFill4(x, y + 1, fill_color, boundary_color);
        boundaryFill4(x - 1, y, fill_color, boundary_color);
        boundaryFill4(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    // Initialize the graphics system (assuming you have a graphics library)
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set the boundary color and fill color
    int boundary_color = WHITE;
    int fill_color = RED;

    // Set the starting point inside the polygon to be filled
    int start_x = 100;
    int start_y = 100;

    // Call the boundary fill function
    boundaryFill4(start_x, start_y, fill_color, boundary_color);

    // Delay to view the result
    delay(5000);

    // Close the graphics system
    closegraph();

    return 0;
}
