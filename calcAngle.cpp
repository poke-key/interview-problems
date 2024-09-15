//problem: calculate the acute angle of the hands on clock

#include <iostream>
#include <cmath>

using namespace std; 
int calcAngle(int hour, int minute ) {

    if(hour >= 12)
        hour -= 12;
    
    double hour_angle = (hour * 30) + (minute * 0.5);

    double minute_angle = minute * 6;

    double angle = abs(hour_angle - minute_angle);

    return min(angle, 360 - angle);

}

int main() {

    int hour = 9;
    int minute = 15;

    cout << "Angle: " << calcAngle(hour, minute) << " degrees." << endl;

    return 0;
}