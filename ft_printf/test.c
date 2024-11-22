/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:47:46 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/22 10:17:59 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

void	test_alpha(void)
{
	int		x;
	int		y;
	char	*s;

	x = 0;
	y = 0;
	printf("\n----------- TEST: %%c -----------\n\n");
	printf("Testing: (\"\\t%%c\\n\", 'a')\n");
	x += printf("  Original\t:\t%c\n", 'a');
	y += ft_printf("  Ft_printf\t:\t%c\n", 'a');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%s -----------\n\n");
	printf("Testing: (\"\\t%%s\\n\", \"coucou, ca va?\")\n");
	x += printf("  Original\t:\t%s\n", "coucou, ca va?");
	y += ft_printf("  Ft_printf\t:\t%s\n", "coucou, ca va?");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	s = NULL;
	if (s == NULL)
		write(1, "(null)\n", 7);
	printf("Testing: (\"\\tNULL %%s NULL.\\n\", NULL)\n");
	x += printf("  Original\t:\tNULL %s NULL.\n", s);
	y += ft_printf("  Ft_printf\t:\tNULL %s NULL.\n", s);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_num(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n----------- TEST: %%d -----------\n\n");
	printf("Testing: (\"\\t%%d\\n\", 42)\n");
	x += printf("  Original\t:\t%d\n", 42);
	y += ft_printf("  Ft_printf\t:\t%d\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%d\\n\", INT_MAX)\n");
	x += printf("  Original\t:\t%d\n", INT_MAX);
	y += ft_printf("  Ft_printf\t:\t%d\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("\n----------- TEST: %%i -----------\n\n");
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", 4422)\n");
	x += printf("  Original\t:\t%i\n", 4422);
	y += ft_printf("  Ft_printf\t:\t%i\n", 4422);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%i\\n\", INT_MIN)\n");
	x += printf("  Original\t:\t%i\n", INT_MIN);
	y += ft_printf("  Ft_printf\t:\t%i\n", INT_MIN);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_x(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n----------- TEST: %%x/X -----------\n\n");
	printf("Testing: (\"\\t%%x\\n\", 42)\n");
	x += printf("  Original\t:\t%x\n", 42);
	y += ft_printf("  Ft_printf\t:\t%x\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%X\\n\", INT_MAX)\n");
	x += printf("  Original\t:\t%X\n", INT_MAX);
	y += ft_printf("  Ft_printf\t:\t%X\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%x\\n\", -42)\n");
	x += printf("  Original\t:\t%x\n", -42);
	y += ft_printf("  Ft_printf\t:\t%x\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_u(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n----------- TEST: %%u -----------\n\n");
	printf("Testing: (\"\\t%%u\\n\", 42)\n");
	x += printf("  Original\t:\t%u\n", 42);
	y += ft_printf("  Ft_printf\t:\t%u\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", INT_MAX)\n");
	x += printf("  Original\t:\t%u\n", INT_MAX);
	y += ft_printf("  Ft_printf\t:\t%u\n", INT_MAX);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%u\\n\", -42)\n");
	x += printf("  Original\t:\t%u\n", -42);
	y += ft_printf("  Ft_printf\t:\t%u\n", -42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
}

void	test_p(void)
{
	int		x;
	int		y;
	int		n;
	char	c;
	void	*p;

	x = 0;
	y = 0;
	n = 50;
	c = 'a';
	p = NULL;
	printf("\n----------- TEST: %%p -----------\n\n");
	printf("Testing: (\"\\t%%p\\n\", (void *)&n)\n");
	x += printf("  Original\t:\t%p\n", (void *)&n);
	y += ft_printf("  Ft_printf\t:\t%p\n", (void *)&n);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%p\\n\", (void *)&c)\n");
	x += printf("  Original\t:\t%p\n", (void *)&c);
	y += ft_printf("  Ft_printf\t:\t%p\n", (void *)&c);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	x = 0;
	y = 0;
	printf("Testing: (\"\\t%%p\\n\", p)\n");
	x += printf("  Original\t:\t%p\n", p);
	y += ft_printf("  Ft_printf\t:\t%p\n", p);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_mix(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n----------- TEST: MIX -----------\n\n");
	printf("Testing: (\"\\tThe int is %%i or %%d, the char is %%c, the string is \\\"%%s\\\", the hex is %%x or %%X, the unsigned is %%u and the percent is %%%%.\\n\", 42, -42, 's', \"Hello\", 42, 42, 242)\n");
	x += printf("  Original\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
	y += ft_printf("  Ft_printf\t:\tThe int is %i or %d, the char is %c, the string is \"%s\", the hex is %x or %X, the unsigned is %u and the percent is %%.\n", 42, -42, 's', "Hello", 42, 42, 242);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

void	test_bonus(void)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	printf("\n----------- TEST: WIDTH CHAR -----------\n\n");
	x = printf("  Original:\tChar [%20c]\n", 'x');
	y = ft_printf("  Ft_printf:\tChar [%20c]\n", 'x');
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	printf("\n----------- TEST: WIDTH STR -----------\n\n");
	x = printf("  Original:\tString [%-25s]\n", "Hello!");
	y = ft_printf("  Ft_printf:\tString [%-25s]\n", "Hello!");
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	printf("\n----------- TEST: WIDTH HEX -----------\n\n");
	x = printf("  Original:\tNumber [%*x]\n", 10, 42);
	y = ft_printf("  Ft_printf:\tNumber [%*x]\n",10, 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	printf("\n----------- TEST: WIDTH UNSIGNED -----------\n\n");
	x = printf("  Original:\tNumber [%20u]\n", 42);
	y = ft_printf("  Ft_printf:\tNumber [%20u]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
	printf("\n----------- TEST: WIDTH INT -----------\n\n");
	x = printf("  Original:\tNumber [%20i]\n", 42);
	y = ft_printf("  Ft_printf:\tNumber [%20i]\n", 42);
	printf("Printf = %d, ft_printf = %d\n\n", x, y);
}

int	main()
{
	printf("---------- MAIN TESTS ----------\n");
	test_alpha();
	test_num();
	test_u();
	test_x();
	test_p();
	test_mix();
	printf("---------- BONUS TESTS ----------\n");
	test_bonus();
	return (0);
}
