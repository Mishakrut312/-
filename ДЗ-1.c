#include <stdio.h>
#include <assert.h>
#include <float.h>
#include <math.h>

// ====================================================================
//! Function, which solves a square equation
//!
//! @param [in] a - the 1-st coefficient
//! @param [in] b - the 2-nd coefficient
//! @param [in] c - the 3-rd coefficient
//! @param [in] x1 - Pointer of the 1-st root
//! @param [in] x2 - Pointer of the 2-nd root
// ====================================================================

int SolveSquare(double, double, double, double*, double*);

// ====================================================================
//! Function for checking the correctness of the input
//!
//! @param [in] coef - Pointer of the coefficient
// ====================================================================

double get_double(const char*);

const int SS_INF_ROOTS = -1;

int main()
{
    double a = 0, b = 0, c = 0;

    printf("This is a program that solves equations of the form : a*x^2 + b*x + c = 0\n\n   Enter coefficients a, b and c:\n\n");


    a = get_double("Enter a: ");
    b = get_double("Enter b: ");
    c = get_double("Enter c: ");

    printf("\nSolution of equation:\n\n");

    double x1 = 0, x2 = 0;
    int nRoots = SolveSquare (a, b, c, &x1, &x2);

    switch(nRoots)
    {
        case 0: printf("No roots\n");
        break;

        case 1: printf("x = %lg\n", x1);
        break;

        case 2: printf("x1 = %lg, x2 = %lg", x1, x2);
        break;

        case SS_INF_ROOTS: printf("Any number");
        break;

        default: printf("main(): ERROR: nRoots = %d\n", nRoots);
        return 1;
    }
}

int SolveSquare(double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite(a));
    assert (isfinite(b));
    assert (isfinite(c));

    assert (x1 != NULL);
    assert (x2 != NULL);
    assert (x1 != x2);


    if (a == 0)
    {
        if (b == 0)
        {
            return (c == 0) ? SS_INF_ROOTS : 0;
        }
        else /* if (b != 0) */
        {
            *x1 = -c/b;
            return 1;
        }
    }
    else /* if (a != 0) */
    {
        double d = b*b - 4*a*c;

        if (d == 0)
        {
            *x1 = *x2 = -b / (2 * a);
            return 1;
        }
        if (d > 0)
        {
            double sqrt_d = sqrt(d);

            *x1 = (-b - sqrt_d) / (2 * a);
            *x2 = (-b + sqrt_d) / (2 * a);

            return 2;
        }
        if (d < 0)
        {
            return 0;
        }

    }
}

double get_double(const char *msg) {
    char answer[256];
    double x;

    printf("%s", msg);
    fgets(answer, sizeof(answer), stdin);

    while (sscanf(answer, "%lf", &x) != 1) {
        printf("Incorrect input. Try again: ");
        fgets(answer, sizeof(answer), stdin);
    }

    return x;
}







