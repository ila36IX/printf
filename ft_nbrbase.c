/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:31:56 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:32:27 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ft_nbrlen - Calculate the length of a number in a given base
 *
 * @n: The number to calculate the length of
 * @b: The base for the number conversion
 *
 * Return: The length of the number in the given base
 */
int	ft_nbrlen(long int n, int b)
{
	if (n < 0)
		return (ft_nbrlen(n * -1, b) + 1);
	if (n < b)
		return (1);
	return (ft_nbrlen(n / b, b) + 1);
}

/*
 * prefix_zero - Add leading zeros to the printed number based on flags
 *
 * @nbrsize: The size of the number to be printed
 * @count: Pointer to the counter that tracks printed characters
 * @flags: Pointer to the flags structure containing formatting options
 *
 * Return: None
 */
void	prefix_zero(int nbrsize, int *count, t_flags *flags)
{
	if (flags->dot)
		ft_putnchar('0', flags->dotpad - nbrsize, count);
	else if (flags->zero)
		ft_putnchar('0', flags->pad - nbrsize, count);
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
void	ft_putnbr_base(long int n, int *count, char *base, t_flags *flags)
{
	int	nbrsize;

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
		prefix_zero(nbrsize, count, flags);
	if (flags->dot && !flags->dotpad && !n)
		return ;
	ft_putnbrb_rec(n, count, base, ft_strlen(base));
}

/*
 * ft_putnbrb_rec - Recursively prints a number in a given base
 *
 * @n: The number to print
 * @count: Pointer to the counter that tracks printed characters
 * @base: The base to use for printing (e.g., "0123456789ABCDEF")
 * @b: The base size (e.g., 16)
 *
 * Return: None
 */
void	ft_putnbrb_rec(long int n, int *count, char *base, int b)
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
