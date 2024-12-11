#include <cstdint>
#include "utils/bezier.h"

Point* Bezier::lerp(Point* p1, Point* p2, double t) {
    uint8_t x = (1 - t) * p1->x + t * p2->x;
    uint8_t y = (1 - t) * p1->y + t * p2->y;
    return new Point(x, y);
}

Point* Bezier::get_bezier_point(uint8_t x, uint8_t range, uint8_t tilt) { 
    Point *curve_tip = lerp(new Point(range / 2, range / 2), new Point(0, range), tilt / 100.0);

    uint8_t split = curve_tip->x;

    if(x < split) {
        Point *control_point;

        if(tilt <= 50) control_point = new Point(curve_tip->x - range / 4, curve_tip->y - range / 4);
        else control_point = new Point(0, tilt / 100.0 * range);

        double t = x / (split * 1.0);

        Point *p1 = lerp(new Point(0, 0), control_point, t);
        Point *p2 = lerp(control_point, curve_tip, t);

        return lerp(p1, p2, t);
    }
    Point *control_point;
    if(tilt <= 50) control_point = new Point(curve_tip->x + range / 4, curve_tip->y + range / 4);
    else control_point = new Point(range - tilt / 100.0 * range, range);

    double t = ((range - split) - (x - split)) * 1.0 / (range - split);

    Point *p1 = lerp(new Point(range, range), control_point, t);
    Point *p2 = lerp(control_point, curve_tip, t);   

    return lerp(p1, p2, t);
}

uint8_t* Bezier::get_bezier_values(uint8_t range, uint8_t tilt) {
    uint8_t* bezier_values = new uint8_t[range];

    for(uint8_t x = 1; x < range; x++) bezier_values[x] = 0;

    for(uint8_t x = 0; ; x++) {
        Point* bezier_point = get_bezier_point(x, range, tilt);
        bezier_values[bezier_point->x] = bezier_point->y;

        if(x == range) break;
    }

    for(uint8_t x = 0; ; x++) {
        if(bezier_values[x] == 0) {
            Point* interp = lerp(new Point(x - 1, bezier_values[x - 1]), new Point(x + 1, bezier_values[x + 1]), 0.5);
            bezier_values[x] = interp->y;
        }
        if(x == range) break;
    }

    return bezier_values;
}
