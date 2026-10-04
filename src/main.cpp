#include "Canvas.h"
#include "InOut.h"

void setup(void) {
    out("hello IOS!!!");
}

void draw(void) {
    background(225);

    fill(100);
    box(10, 20, 30, 40);

    box(50, 60, 20, 20) {
        fill(255, 0, 0);
    }

    fill(0, 128, 255);
    circle(70, 70, 10);

    fill(0);
    line(0, 0, 99, 99);
}