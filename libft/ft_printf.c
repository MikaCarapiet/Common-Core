/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 12:21:54 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/19 12:22:03 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printspecifier(const char string, va_list *args, int *count)
{
	if (string == 'd' || string == 'i')
		ft_printnbr(va_arg(*args, int), count);
	else if (string == 'c')
		ft_printchar(va_arg(*args, int), count);
	else if (string == 's')
		ft_printstr(va_arg(*args, char *), count);
	else if (string == 'p')
		ft_printpointer(va_arg(*args, void *), count);
	else if (string == 'X')
		ft_printhexaupper(va_arg(*args, unsigned int), count);
	else if (string == 'x')
		ft_printhexalower(va_arg(*args, unsigned int), count);
	else if (string == 'u')
		ft_printunsignedint(va_arg(*args, unsigned int), count);
	else if (string == '%')
		ft_printchar('%', count);
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		count;
	int		index;

	va_start(args, string);
	count = 0;
	index = 0;
	if (!string)
		return (-1);
	while (string[index] != '\0')
	{
		if (string[index] == '%' && ft_strchr("cspdiuxX%", string[index + 1]))
		{
			ft_printspecifier(string[index + 1], &args, &count);
			index += 2;
		}
		else
		{
			ft_printchar(string[index], &count);
			index++;
		}
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	num;

// 	int r1, r2;
// 	num = 42;
// printf("=== %%c ===\n");
// r1 = printf("pf: [%c]\n", 'A');
// r2 = ft_printf("ft: [%c]\n", 'A');
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%c]\n", 0);
// r2 = ft_printf("ft: [%c]\n", 0);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%s ===\n");
// r1 = printf("pf: [%s]\n", "hello");
// r2 = ft_printf("ft: [%s]\n", "hello");
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%s]\n", "");
// r2 = ft_printf("ft: [%s]\n", "");
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%s]\n", (char *)NULL);
// r2 = ft_printf("ft: [%s]\n", (char *)NULL);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%p ===\n");
// r1 = printf("pf: [%p]\n", (void *)&num);
// r2 = ft_printf("ft: [%p]\n", (void *)&num);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%p]\n", (void *)NULL);
// r2 = ft_printf("ft: [%p]\n", (void *)NULL);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%d ===\n");
// r1 = printf("pf: [%d]\n", 42);
// r2 = ft_printf("ft: [%d]\n", 42);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%d]\n", -42);
// r2 = ft_printf("ft: [%d]\n", -42);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%d]\n", 0);
// r2 = ft_printf("ft: [%d]\n", 0);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%d]\n", INT_MAX);
// r2 = ft_printf("ft: [%d]\n", INT_MAX);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%d]\n", INT_MIN);
// r2 = ft_printf("ft: [%d]\n", INT_MIN);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%i ===\n");
// r1 = printf("pf: [%i]\n", -123);
// r2 = ft_printf("ft: [%i]\n", -123);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%u ===\n");
// r1 = printf("pf: [%u]\n", 42);
// r2 = ft_printf("ft: [%u]\n", 42);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%u]\n", UINT_MAX);
// r2 = ft_printf("ft: [%u]\n", UINT_MAX);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%u]\n", -1);
// r2 = ft_printf("ft: [%u]\n", -1);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%x ===\n");
// r1 = printf("pf: [%x]\n", 255);
// r2 = ft_printf("ft: [%x]\n", 255);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%x]\n", 0);
// r2 = ft_printf("ft: [%x]\n", 0);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%x]\n", 0xabcdef);
// r2 = ft_printf("ft: [%x]\n", 0xabcdef);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%X ===\n");
// r1 = printf("pf: [%X]\n", 255);
// r2 = ft_printf("ft: [%X]\n", 255);
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%X]\n", 0xabcdef);
// r2 = ft_printf("ft: [%X]\n", 0xabcdef);
// printf("ret: %d | %d\n\n", r1, r2);
// printf("=== %%%% ===\n");
// r1 = printf("pf: [%%]\n");
// r2 = ft_printf("ft: [%%]\n");
// printf("ret: %d | %d\n\n", r1, r2);
// r1 = printf("pf: [%%%%]\n");
// r2 = ft_printf("ft: [%%%%]\n");
// printf("ret: %d | %d\n\n", r1, r2);
// 	return (0);
// }
