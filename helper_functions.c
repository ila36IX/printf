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
#include <stdio.h>

void	print_parsed_flags(flags_t *flags);

int ft_nbrlen(long int n, int b)
{
	if (n < 0)
		return (ft_nbrlen(n*-1, b) + 1);
	if (n < b)
		return (1);
	return (ft_nbrlen(n / b, b) + 1);
}

void ft_putnchar(char c, int n, int *count)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
		(*count)++;
	}
}

/*
 * ft_putchar - Hondler of the c flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putchar(int *count, va_list args, flags_t *flags)
{
	char c;

	if (flags->pad && !flags->minus)
		ft_putnchar(' ', flags->pad - 1, count);
	c = (char)va_arg(args, int);
	write(1, &c, 1);
	++*count;
	if (flags->pad && flags->minus)
		ft_putnchar(' ', flags->pad - 1, count);
}

/*
 * ft_putstr - Hondler of the s flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putstr(int *count, va_list args, flags_t *flags)
{
	char	*s;
	int		len;

	s = va_arg(args, char *);
	if (!s)
	{
		if (flags->dot && (!flags->dotpad || flags->dotpad < 5))
		{
			ft_putnchar(' ', flags->pad, count);
			return;
		}
		s = "(null)";
	}
	len = ft_strlen(s);
	if (flags->dot && flags->dotpad < len)
		len = flags->dotpad;
	if (!flags->minus)
		ft_putnchar(' ', flags->pad - len, count);
	*count += write(1, s++, len);
	if (flags->minus)
		ft_putnchar(' ', flags->pad - len, count);
}

/* this function does not hondle the case where the number is negative*/
void ft_putnbrb_rec(long int n, int *count, char *base, int b)
{
	++*count;
	if (n < b)
		write(1, &base[n], 1);
	else
	{
		ft_putnbrb_rec(n / b, count, base, b);
		write(1, &base[n % b], 1);
	}
}

/*
 * ft_putnbr_base - Print any number in range of
 * UINTMAX<>-UINTMAX+1 using any base.
 * @n: The number to be printed
 * @count: Pointer to the counter that keeps track of
 * many printed characters, that varaible that will be
 * returned later from printf body
 * @base: String contains the charcters of the base to print with
 * @b: The base size, ex: In hex you should call with b=16
 *
 * Return: None
 * - Note it can't hondle the pointer type as ptr can be grow
 * to the unisgned long long int, that will cause an overflew
 * so that's why we needed a custom function (look: ft_putnbr_base_big)
 */
void ft_putnbr_base(long int n, int *count, char *base, flags_t *flags)
{
	int nbrsize;
	if (flags->hash && n)
		*count += write(1, flags->hashprefix, ft_strlen(flags->hashprefix));
	nbrsize = ft_nbrlen(n, ft_strlen(base));
	if (n < 0)
	{
		(*count) += write(1, "-", 1);
		n *= -1;
		if (flags->dotpad)
			nbrsize--;
	}
	else if (flags->plus)
		*count += write(1, "+", 1);
	else if (flags->space)
		*count += write(1, " ", 1);
	if (flags->pad || flags->dotpad)
	{
		if (flags->dot)
			ft_putnchar('0', flags->dotpad - nbrsize , count);
		else if (flags->zero)
			ft_putnchar('0', flags->pad - nbrsize , count);
	}
	if (flags->dot && !flags->dotpad && !n)
		return ;
	ft_putnbrb_rec(n, count, base, ft_strlen(base));
}

/*
 * ft_putnbr_base_big - this functions is needed to
 * hondle the case where UINTPTR_MAX is giving you 
 * can't use the basic putnbr_base that is because
 * you need to change it's prototype wich will cause
 * losing some types that are not unsigned
 *
 * @n:Big nuber that can hondle into ptr max value 
 * @count: Pointer to the counter that keeps track of
 * many printed characters, that varaible that will be
 * returned later from printf
 * @base: String contains the charcters of the base to print with
 * @b: The base size, ex: In hex you should call with b=16
 *
 * Return: None
 */
void ft_putnbr_base_big(unsigned long long int n, int *count, char *base, int b)
{
	++*count;
	if (n < (unsigned long long int)b)
		write(1, &base[n], 1);
	else
	{
		ft_putnbr_base_big(n / b, count, base, b);
		write(1, &base[n % b], 1);
	}
}

int ft_ptrlen(unsigned long long int n, int b)
{
	if (n < (unsigned long long int) b)
		return (1);
	return (ft_ptrlen(n / b, b) + 1);
}

/*
 * ft_putnbr_base - Hondler of the p flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putptr(int *count, va_list args, flags_t *flags)
{
	unsigned long long int p;
	int len;

	p = (unsigned long long int)va_arg(args, void *);
	if (!p)
	{
		if (!flags->minus)
			ft_putnchar(' ', flags->pad - 5, count);
		*count += write(1, "(nil)", 5);
		if (flags->minus)
			ft_putnchar(' ', flags->pad - 5, count);
	}
	else
	{
		len = ft_ptrlen(p, 16) + 2;
		if (!flags->minus)
			ft_putnchar(' ', flags->pad - len, count);
		*count += write(1, "0x", 2);
		ft_putnbr_base_big((unsigned long long int)p, count, BASE16_LOWER, 16);
		if (flags->minus)
			ft_putnchar(' ', flags->pad - len, count);
	}
}


void addition_flags(long int n, int *count,flags_t *flags, char *base)
{
	int nbrsize;

	nbrsize = ft_nbrlen(n, ft_strlen(base));
	if (flags->dotpad >= nbrsize)
	{
		nbrsize = flags->dotpad;
		if (n < 0)
			nbrsize++;
	}
	if (flags->pad > 0)
	{
		if (flags->dot && !flags->dotpad && !n)
			nbrsize = 0;
		if (flags->minus)
		{
			ft_putnbr_base(n, count, base, flags);
			ft_putnchar(' ', flags->pad - nbrsize, count);
		}
		else if ((!flags->minus && !flags->zero) || flags->dot)
		{
			ft_putnchar(' ', flags->pad - nbrsize, count);
			ft_putnbr_base(n, count, base, flags);
		}
		else
			ft_putnbr_base(n, count, base, flags);

	}
	else
		ft_putnbr_base(n, count, base, flags);
}

/*
 * ft_putnbr - Hondler of the i flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with the flag
 *
 * Return: None
 */
void ft_putnbr(int *count, va_list args, flags_t *flags)
{
	int	n;

	n = (int) va_arg(args, int);
	addition_flags(n, count, flags, BASE10);
}

/*
 * ft_putunbr - Hondler of the [u]nsigned flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putunbr(int *count, va_list args, flags_t *flags)
{
	unsigned int	n;
	(void) flags;

	n = va_arg(args, int);
	addition_flags(n, count, flags, BASE10);
}

/*
 * ft_putunbr - Hondler of the x flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putnbrX(int *count, va_list args, flags_t *flags)
{
	int	n;
	(void) flags;

	n = va_arg(args, int);
	if (flags->hash)
		flags->hashprefix = "0X";
	addition_flags((unsigned int)n, count, flags, BASE16_UPPER);
}

/*
 * ft_putunbr - Hondler of the X flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putnbrx(int *count, va_list args, flags_t *flags)
{
	int	n;
	(void) flags;

	n = va_arg(args, int);
	if (flags->hash)
		flags->hashprefix = "0x";
	addition_flags((unsigned int)n, count, flags, BASE16_LOWER);
}


/*
 * ft_putpersent - Hondler of the % flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putpersent(int *count, va_list args, flags_t *flags)
{
	(void) flags;
	(void) args;

	write(1, "%", 1);
	(*count)++;
}

/*
 * get_handler - Search through the hondled spesifiers using
 * the flag charachter
 * @c: The spesifier character (charachter next to % sign) 
 *
 * Return: Pointer of the function the will proprely hondle the giving flag
 * Or NULL if not hondler founded
 * The struct contains {0, NULL} just to give while the stop point
 */
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
		{'%', ft_putpersent},
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
