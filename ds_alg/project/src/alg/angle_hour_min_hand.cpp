#include <iostream>
#include <math.h>

/*
    Let say point of reference is 12 on the clock
    hour hand moves 360 degress in 12 hours or 360/12 = 30 degrees in 1 hour or 30/60 = 0.5 degrees in 1 min. 
    min hand moves 360 degrees in 60 mins or 360/60 = 6 degrees in 1 min. 
*/


double calculate_angle(int h, int m) {

    if (h == 12) h = 0;
    if (m == 60) m = 0;


    double hourAngle = (h*60 + m) * 0.5;
    double minAngle = 6*m;

    double angle = abs(hourAngle - minAngle);

    return std::min(360 - angle, angle);
}

int main() {

    std::cout << " angle between 12 h, 45 m: " << calculate_angle(12, 45) << '\n';
}