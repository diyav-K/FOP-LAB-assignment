#include <stdio.h>

int main() {
     float basic, hra, ta, gross, professional_tax, net;

    // Input basic pay
    printf("Enter the basic pay of the employee: ");
    scanf("%f", &basic);

    // Calculate HRA and TA
    hra = 0.10 * basic;   // 10% of basic
    ta = 0.05 * basic;    // 5% of basic

    // Calculate gross salary
    gross = basic + hra + ta;

    // Calculate professional tax (2% of gross)
    professional_tax = 0.02 * gross;

    // Calculate net salary
    net = gross - professional_tax;

    // Output
    printf("\nBasic Pay: %.2f\n", basic);
    printf("HRA (10%%): %.2f\n", hra);
    printf("TA (5%%): %.2f\n", ta);
    printf("Gross Salary: %.2f\n", gross);
    printf("Professional Tax (2%%): %.2f\n", professional_tax);
    printf("Net Salary Payable: %.2f\n", net);

    return 0;
}