#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex05/ft_sqrt.c"
#include "../../../utils/constants.h"

typedef struct s_test
{
    char *desc;
    int n;
    int expected;
} t_test;

int run_tests(t_test *tests, int count);

int main(void)
{
    t_test tests[] = {
        {
            .desc = "Square root of 16",
            .n = 16,
            .expected = 4,
        },
        {
            .desc = "Square root of 1073741824",
            .n = 1073741824,
            .expected = 32768,
        },
        {
            .desc = "Square root of 10000",
            .n = 10000,
            .expected = 100,
        },
        {
            .desc = "Square root of 2",
            .n = 2,
            .expected = 0,
        },
        {
            .desc = "Square root of a negative number",
            .n = -5,
            .expected = 0,
        },
        // Add more test cases here
    };
    int count = sizeof(tests) / sizeof(tests[0]);

    return run_tests(tests, count);
}

int run_tests(t_test *tests, int count)
{
    int i;
    int error = 0;
    int	result = 0;

    for (i = 0; i < count; i++)
    {
        result = ft_sqrt(tests[i].n);

        if (result != tests[i].expected)
        {
            printf("    " RED "[%d] %s Expected %d, got %d\n", i + 1, tests[i].desc, tests[i].expected, result);
            error -= 1;
        }
        else
        {
            printf("  " GREEN CHECKMARK GREY " [%d] %s Expected %d, got %d\n" DEFAULT, i + 1, tests[i].desc, tests[i].expected, result);
        }
    }

    return error;
}
