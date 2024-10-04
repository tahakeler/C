#include <stdio.h>

int main() {
    double income, tax = 0.0, deductions = 0.0;
    double insurance_deduction = 0.0, charity_deduction = 0.0;

    printf("Enter your annual income in baht: ");
    scanf("%lf", &income);

    printf("Enter the amount spent on life insurance premiums in baht (up to 50,000 baht): ");
    scanf("%lf", &insurance_deduction);
    printf("Enter the amount donated to charity in baht (up to 10,000 baht): ");
    scanf("%lf", &charity_deduction);

    insurance_deduction = (insurance_deduction > 50000) ? 50000 : insurance_deduction;
    charity_deduction = (charity_deduction > 10000) ? 10000 : charity_deduction;

    income -= (insurance_deduction + charity_deduction);

    if (income > 800000) {
        tax += (income - 800000) * 0.25; 
        income = 800000; 
    }
    if (income > 300000) {
        tax += (income - 300000) * 0.20; 
        income = 300000; 
    }
    if (income > 100000) {
        tax += (income - 100000) * 0.10;
    }

    printf("Your income tax is: %.2lf baht\n", tax);

    return 0;
}
