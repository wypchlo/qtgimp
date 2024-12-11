#ifndef UTILS_BEZIER_H
#define UTILS_BEZIER_H

#include <cstdint>

class Point {
    public:
    uint8_t x;
    uint8_t y;

    Point(uint8_t _x, uint8_t _y) {
        x = _x;
        y = _y;
    }
};

class Bezier {
    public:
    static uint8_t* get_bezier_values(uint8_t range, uint8_t tilt);

    private:
    static Point* get_bezier_point(uint8_t x, uint8_t range, uint8_t tilt);
    static inline Point* lerp(Point* p1, Point* p2, double t);
};

#endif // UTILS_BEZIER_H
