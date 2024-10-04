#include <stdio.h>

int main() {
    double income, tax = 0.0;
    double lifeInsuranceDeduction, charitableDeduction;

    printf("Enter your annual income in baht: ");
    scanf("%lf", &income);

    printf("Enter life insurance expenses in baht (up to 50,000): ");
    scanf("%lf", &lifeInsuranceDeduction);

    printf("Enter charitable donations in baht (up to 10,000): ");
    scanf("%lf", &charitableDeduction);

    income -= (lifeInsuranceDeduction > 50000.0) ? 50000.0 : lifeInsuranceDeduction;
    income -= (charitableDeduction > 10000.0) ? 10000.0 : charitableDeduction;

    if (income <= 100000) {
        tax = 0.0;
    } else if (income <= 300000) {
        tax = (income - 100000) * 0.10;
    } else if (income <= 800000) {
        tax = 20000.0;
        tax += (income - 300000) * 0.20;
    } else {
        tax = 20000.0;
        tax += 50000.0;
        tax += (income - 800000) * 0.25;
    }

    printf("Your income tax is: %.2lf baht\n", tax);

    return 0;
}
