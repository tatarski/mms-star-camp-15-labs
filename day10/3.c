#include<stdio.h>
#include<math.h>
typedef struct Point {
    double x, y;
} Point;

/// double Arr[], int capacity, int N
/// void change_arr(double* arr, int capacity, int N)
/// struct my_arr {double* arr, int capacity, int N}
/// void change_arr(my_arr arr1)
typedef unsigned int CQLO_POLOJITELNO_CHISLO;
double distance(double x1, double y1,
                double x2, double y2)
{
    double xD = x1-x2, yD = y1-y2;
    return sqrt(xD*xD + yD*yD);
}
int isInCircle(Point center, double r,
        double x, double y) {
    return distance(center.x, center.y, x, y) < r;
    // if(distance(cX, cY, x, y) < r) {
    //     return 1;
    // } else {
    //     return 0;
    // }
}
int main() {
    Point center;   // double, double
    double r;
    // Point* pointer_to_center = &center;
    // (*pointer_to_center).x = 100;
    // pointer_to_center->x = 100; // SAME AS ABOVE
    // (*pointer_to_center).y = 200;
    // pointer_to_center->y = 200; // SAME AS ABOVE

    scanf("%lf %lf %lf", &center.x, &center.y, &r);
    CQLO_POLOJITELNO_CHISLO N;
    scanf("%d", &N);
    Point points[100];
    for(int i = 0; i < N; i++) {
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(isInCircle(center, r, points[i].x, points[i].y)) {
            count++;
        }
        // count += isInCircle(cX, cY, r, x[i], y[i]);
    }
}