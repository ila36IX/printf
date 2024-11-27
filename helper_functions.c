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
	(void) flags;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	++*count;
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
	char *s;
	(void) flags;

	s = va_arg(args, char *);
	if (!s)
		*count += write(1, "(null)", 6);
	while (s && *s)
	{
		write(1, s++, 1);
		++*count;
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
void ft_putnbr_base(long int n, int *count, char *base, int b)
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

/*
 * ft_putnbr_base_big - this functions is needed to
 * hondle the case where UINTPTR_MAX is giving you 
 * can't use the basic putnbr_base that is because
 * you need to change it's prototype wich will cause
 * losing some types that are not unsigned
 *
 * @n: Pointer casted to ulli
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
		ft_putnbr_base_big(n / b, count, base, b);
		write(1, &base[n % b], 1);
	}
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
	ft_putnbr_base_big((unsigned long long int)p, count, "0123456789abcdef", 16);
}


/*
 * ft_putnbr - Hondler of the i flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void ft_putnbr(int *count, va_list args, flags_t *flags)
{
	int	n;
	(void) flags;

	n = va_arg(args, int);
	ft_putnbr_base(n, count, "0123456789", 10);
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
	ft_putnbr_base(n, count, "0123456789", 10);
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
	ft_putnbr_base((unsigned int)n, count, "0123456789ABCDEF", 16);
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
	ft_putnbr_base((unsigned int)n, count, "0123456789abcdef", 16);
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
	int	n;
	(void) flags;

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
