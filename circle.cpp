#include <iostream>
#include <cmath>

int main() {
    int radius;

    // Ask the user to enter the radius of the circle
    std::cout << "Enter the radius of the circle (whole number): ";
    std::cin >> radius;

    // Check if the input is valid (a positive whole number)
    if (radius <= 0) {
        std::cerr << "Invalid input. Please enter a positive whole number for the radius." << std::endl;
        return 1; // Exit with an error code
    }

    // Calculate and print the area of the circle
    double area = M_PI * std::pow(radius, 2);
    std::cout << "Area of the circle: " << area << std::endl;

    // Calculate and print the circumference of the circle
    double circumference = 2 * M_PI * radius;
    std::cout << "Circumference of the circle: " << circumference << std::endl;

    // Calculate and print the volume of a sphere with the given radius
    double volume = (4.0 / 3.0) * M_PI * std::pow(radius, 3);
    std::cout << "Volume of a sphere with radius " << radius << ": " << volume << std::endl;

    return 0; // Exit successfully
}
