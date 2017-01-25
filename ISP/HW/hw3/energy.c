// Justin Chao
// EID: jc55395
// energy.c finds energy (E) that is equivalent to a given mass (m) of a body.

// Assignment:
// E = mc^2, assuming any mass in kg
// speed of light = 299,792,458 m/s
// print calculated energy in joules

#include <stdio.h>
#include <math.h>

int main()
{
    // define variables
    float m, E, c;
    c = 299792458;

    // prompt for mass
    printf("Enter mass: \n");
    scanf("%f" , &m);

    // calculate energy
    float t = pow(c,2);
    E = m*t;

    // print energy
    printf("Energy = %.4e joules" , E);

    return 0;
}
