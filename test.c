#include <stdio.h>

typedef struct s_complex
{
    //  x (real number)
    double real;
    //  y (imaginary number)
    double imaginary;
} t_complex;

int main()
{
    t_complex z;
    //     point
    t_complex c;
    double tmp_real;

    z.real = 0;
    z.imaginary = 0;

    c.real = -1;
    c.imaginary = 0;

    int i = 0;
    while (i <= 42)
    {
        // Genaral formule
        // Z = Z^2 + C
        tmp_real = (z.real * z.real) - (z.imaginary * z.imaginary);
        z.imaginary = 2 * z.real *z.imaginary;
        z.real = tmp_real;

        // Adding the c value
        z.real += c.real;
        z.imaginary += c.imaginary;

        printf("iteration n -> %d -> real -> %.1f -> imaginary -> %.1f \n", i, z.real, z.imaginary);
        i++;
    }
}
