#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void compare_printf(const char *test_name, const char *format, ...)
{
	va_list args1, args2;
	int result1, result2;
	
	printf("%s\n", test_name);

	va_start(args1, format);
	va_copy(args2, args1);
    
	printf("ft_printf output: ");
	result1 = ft_printf(format, args1);  
	printf("\n");

	printf("printf output: ");
	result2 = vprintf(format, args2);  
	printf("\n");

	printf("ft_printf return: %d\n", result1);
	printf("printf return: %d\n", result2);

	va_end(args1);
	va_end(args2);
	printf("====================\n\n");
}

int	main()
{
	compare_printf("TEST for %5d with 42\n", "%5d", 42);
	compare_printf("TEST for %5i with 42\n", "%5i", 42);
	compare_printf("TEST for %-5i with -123\n", "%-5i", -123);
	printf("\n");
	compare_printf("TEST for %05i with 789\n", "%05i", 789);
	printf("\n");
	compare_printf("TEST for %+5i with 0\n", "%+5i", 0);
	printf("\n");
	compare_printf("TEST for % 5i with -42\n", "% 5i", -42);
	printf("\n");
	compare_printf("TEST for %5.3i with 1234\n", "%5.3i", 1234);
	printf("\n");
	compare_printf("TEST for %-+5i with 56\n", "%-+5i", 56);
	printf("\n");
	compare_printf("TEST for % 05i with -789\n", "% 05i", -789);
	printf("\n");
	compare_printf("TEST for %-5d with 42\n", "%-5d", 42);
	printf("\n");
	compare_printf("TEST for %05d with 42\n", "%05d", 42);
	printf("\n");
	compare_printf("TEST for %#x with 255\n", "%#x", 255);
	printf("\n");
	compare_printf("TEST for %#X with 255\n", "%#X", 255);
	printf("\n");
	compare_printf("TEST for %p with -1\n", "%p", (void *)-1);
	printf("\n");
	compare_printf("TEST for %10d with 1234567890\n", "%10d", 1234567890);
	printf("\n");
	compare_printf("TEST for %10s with \"Hello world!\"\n", "%10s", "Hello world!");
	printf("\n");
	compare_printf("TEST for %10.5f with 3.14159\n", "10.5f", 3.14159);
	printf("\n");
	compare_printf("TEST for %#o with 0\n", "%#o", 0);
	printf("\n");
	compare_printf("TEST for %s with NULL\n", "%s", NULL);
	return (0);
}

