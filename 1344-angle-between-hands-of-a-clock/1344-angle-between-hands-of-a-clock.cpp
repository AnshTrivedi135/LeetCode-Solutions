#include <cmath>
#include <algorithm>

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes * 6.0;
        double hourAngle = (hour % 12) * 30.0 + minutes * 0.5;
        
        double diff = std::abs(hourAngle - minuteAngle);
        return std::min(diff, 360.0 - diff);
    }
};