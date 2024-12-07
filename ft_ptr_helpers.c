/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:21:47 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:30:54 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ft_putnbr_base - Hondler of the p flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void	ft_putptr(int *count, va_list args, t_flags *flags)
{
	unsigned long long int	p;
	int						len;

	p = (unsigned long long int)va_arg(args, void *);
	if (!p)
	{
		if (!flags->minus)
			ft_putnchar(' ', flags->pad - 5, count);
		*count += write(1, "(nil)", 5);
		if (flags->minus)
			ft_putnchar(' ', flags->pad - 5, count);
		if (flags->plus)
			ft_putnchar('+', 1, count);
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

/*
 * ft_ptrlen - Calculate the number of digits needed to represent
 * a number in a given base (no sign).
 *
 * @n: The number to calculate the length for.
 * @b: The base to represent the number in (e.g., 10 for decimal,
 * 16 for hexadecimal).
 *
 * Return: The number of digits required.
 */
int	ft_ptrlen(unsigned long long int n, int b)
{
	if (n < (unsigned long long int)b)
		return (1);
	return (ft_ptrlen(n / b, b) + 1);
}

/*
 * ft_putnbr_base_big - this functions is needed to
 * hondle the case where UINTPTR_MAX is giving you
 * can't use the basic putnbr_base that is because
 * you need to change it's prototype wich will cause
 * losing some types that are not unsigned
 *
 * @n:Big number that can hondle into ptr max value
 * @count: Pointer to the counter that keeps track of
 * many printed characters, that varaible that will be
 * returned later from printf
 * @base: String contains the charcters of the base to print with
 * @b: The base size, ex: In hex you should call with b=16
 *
 * Return: None
 */
void	ft_putnbr_base_big(unsigned long long int n, int *count, char *base,
		int b)
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
