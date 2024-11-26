/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:20:43 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/20 18:23:30 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(int *count, va_list args, flags_t *flags)
{
	char c;
	(void) flags;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	++*count;
}

void ft_putstr(int *count, va_list args, flags_t *flags)
{
	char *s;
	(void) flags;

	s = va_arg(args, char *);
	while (*s)
	{
		write(1, s++, 1);
		++*count;
	}
}

void ft_putnbr_base(long n, int *count, char *base, int b)
{
	if (n < 0)
	{
		write(1, "-", 1);
		++*count;
		n *= -1;
	}
	++*count;
	if (n < b)
		write(1, &base[n], 1);
	else
	{
		ft_putnbr_base(n / b, count, base, b);
		write(1, &base[n % b], 1);
	}
}

void ft_putptr(int *count, va_list args, flags_t *flags)
{
	void *p;
	(void) flags;

	p = va_arg(args, void *);
	if (!p)
	{
		write(1, "(nil)", 5);
		*count += 5;
		return ;
	}
	write(1, "0x", 2);
	*count = *count + 2;
	ft_putnbr_base((long)p, count, "0123456789abcdef", 16);
}

void ft_putnbr(int *count, va_list args, flags_t *flags)
{
	int	n;
	(void) flags;

	n = va_arg(args, int);
	ft_putnbr_base(n, count, "0123456789", 10);
}

void ft_putunbr(int *count, va_list args, flags_t *flags)
{
	unsigned int	n;
	(void) flags;

	n = va_arg(args, int);
	ft_putnbr_base(n, count, "0123456789", 10);
}

void ft_putnbrX(int *count, va_list args, flags_t *flags)
{
	int	n;
	(void) flags;

	n = va_arg(args, int);
	ft_putnbr_base((unsigned int)n, count, "0123456789ABCDEF", 16);
}

void ft_putnbrx(int *count, va_list args, flags_t *flags)
{
	int	n;
	(void) flags;

	n = va_arg(args, int);
	ft_putnbr_base((unsigned int)n, count, "0123456789abcdef", 16);
}


void (*get_handler(char c))(int *count, va_list args, flags_t *flags)
{
	int	i;
	ftf_t ctofunc[] = {
		{'c', ft_putchar},
		{'s', ft_putstr},
		{'p', ft_putptr},
		{'d', ft_putnbr},
		{'i', ft_putnbr},
		{'u', ft_putunbr},
		{'x', ft_putnbrx},
		{'X', ft_putnbrX},
		{0, NULL}
	};
	
	i = 0;
	while (ctofunc[i].f)
	{
		if (ctofunc[i].c == c)
			return (ctofunc[i].f);
		i++;
	}
	return (NULL);
}
