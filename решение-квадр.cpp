#include <stdio.h>
#include <math.h>
#include <locale.h>

#define INF_ROOTS -1

int solve(double, double, double, double * ad1, double * ad2);

int main()
{
    setlocale(LC_ALL, "");

    double a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    scanf("%lf %lf %lf", &a, &b, &c);

    int count_results = solve (a, b, c, &x1, &x2);
    switch(count_results)
    {
        case 0:
            printf("нет корней");
            break;

        case 1:
            printf("1 корень: %lf", x1);
            break;

        case 2:
            printf("2 корня: %lf, %lf", x1, x2);
            break;

        case INF_ROOTS:
            printf("бесконечное число корней");
            break;

        default:
            printf("Ошибка, неизвестное число корней %d\n", count_results);

    }

    return 0;
 }

int solve(double a, double b, double c, double * ad1, double * ad2)
{
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
            {
                return INF_ROOTS;
            }
            else
            {
                return 0;
            }

        }
        else
        {
            *ad1 = (-1) * c / b;
            return 0;
        }
    }
    else
    {
        double d = b * b - 4 * a * c;

        if (d < 0)
        {
            return 0;
        }
        else if (d == 0)
        {
            *ad1 = (-1) * b / (2 * a);
            return 1;
        }
        else
        {
            *ad1 = ( (-1) * b - sqrt(d) ) / (2 * a);
            *ad2 = ( (-1) * b + sqrt(d) ) / (2 * a);
            return 2;
        }

    }
}
