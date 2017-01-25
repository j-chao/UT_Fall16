/* Justin Chao
 * rightTriangle.c determines if a given triangle is a right triangle, and
 * calculates the hypotenuse, angles, and area.
 */

#include <stdio.h> 
#include <math.h> 
#include <stdbool.h>

// define value for PI
#define PI 3.141592654

// define typedef struct rightTriangle with all attributes
typedef struct rightTriangle{
    double side_a, side_b, side_h, angle_a, angle_b, angle_h, area;
}
rightTriangle;

// create bool check for isRightTriangle
bool isRightTriangle (rightTriangle* t) {
    // check if any sides are <= 0
    if (t->side_a <= 0 || t->side_b <= 0 || t->side_h <= 0) 
        return false;
    // check if side_a^2 + side_b^2 = side_h^2
    return (t->side_a*t->side_a + t->side_b*t->side_b == t->side_h*t->side_h);
}

// calc_angles function computes the angles from side lengths of a right triangle
void calc_angles (rightTriangle* t) {
    t->angle_a = asin(t->side_a / t->side_h) * 180 / PI;
    t->angle_b = asin(t->side_b / t->side_h) * 180 / PI;
    t->angle_h = 90;
}

// print_triangle function prints out the sides, angles, and area of a right triangle
void print_triangle (rightTriangle* t) {
    printf("\n===== Right Triangle Attributes =====");
    printf("\n%-15s %.2f, %.2f \n", "Sides:", t->side_a, t->side_b);
    printf("%-15s %.2f \n", "Hypotenuse:", t->side_h);
    printf("%-15s %.2f, %.2f, %.2f \n", "Angles:", t->angle_a, t->angle_b, t->angle_h);
    printf("%-15s %.2f \n\n", "Area:", t->side_a * t->side_b / 2);
}

// calc_hypo function calculates the hypotenuse
double calc_hypo (rightTriangle* t){
    t->side_h = sqrt(pow(t->side_a, 2) + pow(t->side_b, 2));
    return t->side_h;
}

int main() {
    rightTriangle t;
    // prompt for user input
    printf("Enter a value for side 1: \n");
    scanf("%lf", &t.side_a);
    printf("\nEnter a value for side 2: \n");
    scanf("%lf", &t.side_b);
    printf("\nEnter a value for the hypotenuse (0 to calculate): \n");
    scanf("%lf", &t.side_h);

    // calculate hypotenuse if prompted 
    if (t.side_h == 0)
        t.side_h = calc_hypo(&t);
    
    // print if triangle is not a right triangle and return/end program
    if (!isRightTriangle(&t)) {
        printf("\n%.2f, %.2f, %.2f does not form a right triangle. \n", t.side_a, t.side_b, t.side_h);
        return 0;
    }

    // calculate angles and print right triangle attributes
    calc_angles(&t);
    print_triangle(&t);
    return 0;
}
