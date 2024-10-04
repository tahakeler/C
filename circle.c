#include <stdio.h>

int main() 
{
    int radius;
    
    printf("Enter the radius of the circle (a whole number): ");
    scanf("%d", &radius);

    if (radius < 0) 
    {
        printf("Please enter a non-negative integer radius.\n");
        return 1;
    }

    double area = 3.14159265359 * radius * radius;
    double circumference = 2 * 3.14159265359 * radius;
    double volume = (4.0 / 3.0) * 3.14159265359 * radius * radius * radius;

    printf("1) Area of the circle: %.2f\n", area);
    printf("2) Circumference of the circle: %.2f\n", circumference);
    printf("3) Volume of a sphere with radius %d: %.2f\n", radius, volume);

    return 0;
}