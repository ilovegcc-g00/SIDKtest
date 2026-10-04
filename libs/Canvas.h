#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* User-provided callbacks */
void setup(void);
void draw(void);

/* Logical resolution */
void size(int w, int h);

/* Background */
void background(int r, int g, int b);

/* Fill color */
void fill(int r, int g, int b);
void no_fill(void);

/* Shapes */
void circle(int x, int y, int r);
void line(int x1, int y1, int x2, int y2);
void canvas_box_begin(int x, int y, int w, int h);
void canvas_box_end(void);

#ifdef __cplusplus
}
#endif

/* fill(v) or fill(r,g,b) */
#define CANVAS_FILL_1(a)         fill((a),(a),(a))
#define CANVAS_FILL_3(a,b,c)     fill((a),(b),(c))
#define CANVAS_PICK_F(_1,_2,_3,N,...) N
#define fill(...) \
    CANVAS_PICK_F(__VA_ARGS__, CANVAS_FILL_3, CANVAS_FILL_3, CANVAS_FILL_1)(__VA_ARGS__)

/* background(v) or background(r,g,b) */
#define CANVAS_BG_1(a)           background((a),(a),(a))
#define CANVAS_BG_3(a,b,c)       background((a),(b),(c))
#define CANVAS_PICK_B(_1,_2,_3,N,...) N
#define background(...) \
    CANVAS_PICK_B(__VA_ARGS__, CANVAS_BG_3, CANVAS_BG_3, CANVAS_BG_1)(__VA_ARGS__)

/* box(x,y,w,h) or box(x,y,w,h) { ... } */
#define box(x, y, w, h) \
    canvas_box_begin((x),(y),(w),(h)); \
    for (int _cb_ = 1; _cb_; _cb_ = 0, canvas_box_end())

#endif