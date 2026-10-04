#ifndef CANVAS_H
#define CANVAS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================
// Canvas.h — Fixed by Beta Tester #1
// ============================================================
// FIX 1: Đổi tên hàm `fill` -> `canvas_fill`, `background` -> `canvas_background`
//        Lý do: `fill` và `background` vừa là hàm vừa là macro -> không thể
//        viết implementation (macro sẽ expand, gây lỗi biên dịch).
// FIX 2: Macro `box` viết lại bằng `for` với init/cond/update — an toàn khi
//        đặt trong `if`/`else` không có ngoặc nhọn.
// ============================================================

void setup(void);
void draw(void);

void size(int w, int h);

void canvas_background(int r, int g, int b);
void canvas_fill(int r, int g, int b);
void no_fill(void);

void circle(int x, int y, int r);
void line(int x1, int y1, int x2, int y2);
void canvas_box_begin(int x, int y, int w, int h);
void canvas_box_end(void);

#ifdef __cplusplus
}
#endif

// ---- fill() : 1 tham số (xám) hoặc 3 tham số (RGB) ----
#define CANVAS_FILL_1(a)         canvas_fill((a),(a),(a))
#define CANVAS_FILL_3(a,b,c)     canvas_fill((a),(b),(c))
#define CANVAS_PICK_F(_1,_2,_3,N,...) N
#define fill(...) \
    CANVAS_PICK_F(__VA_ARGS__, CANVAS_FILL_3, CANVAS_FILL_3, CANVAS_FILL_1)(__VA_ARGS__)

// ---- background() : 1 tham số (xám) hoặc 3 tham số (RGB) ----
#define CANVAS_BG_1(a)           canvas_background((a),(a),(a))
#define CANVAS_BG_3(a,b,c)       canvas_background((a),(b),(c))
#define CANVAS_PICK_B(_1,_2,_3,N,...) N
#define background(...) \
    CANVAS_PICK_B(__VA_ARGS__, CANVAS_BG_3, CANVAS_BG_3, CANVAS_BG_1)(__VA_ARGS__)

// ---- box() : an toàn trong if/else không ngoặc ----
#define box(x, y, w, h) \
    for (int _cb_ = (canvas_box_begin((x),(y),(w),(h)), 1); \
         _cb_; \
         _cb_ = (canvas_box_end(), 0))

#endif // CANVAS_H