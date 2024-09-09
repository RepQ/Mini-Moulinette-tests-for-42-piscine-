#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "../../../../ex08/ft_ten_queens_puzzle.c"
#include "../../../utils/constants.h"

typedef struct	s_test
{
	char	*desc;
	int	n;
	int	expected;
} t_test;

int test1(t_test *test, int count);

int main(void)
{
	t_test	tests[] = {
		{
			.desc = "Number of solution for ten queens puzzle",
			.expected = 724,
		}
	};
	int count = sizeof(tests) / sizeof(tests[0]);
	return (test1(tests, count));
}

int test1(t_test *tests, int count)
{	
	int	i;
	int	error;

	error = 0;
	for (i = 0; i < count; i++)
	{
		int	result = ft_ten_queens_puzzle();

		if (result != tests[i].expected)
		{
			printf("    " RED "[%d] %s Expected %d got %d\n" DEFAULT, i + 1, tests[i].desc, tests[i].expected, result);
			error -= 1;
		}
		else
		{
			printf("  " GREEN CHECKMARK GREY " [%d] %s Expected %d, got %d\n" DEFAULT, i + 1, tests[i].desc, tests[i].expected, result);
		}
	}
	return (error);
}
