/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrbase_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:31:53 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:32:41 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ft_putnbr - Hondler of the i flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with the flag
 *
 * Return: None
 */
void	ft_putnbr(int *count, va_list args, t_flags *flags)
{
	int	n;

	n = (int)va_arg(args, int);
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
void	ft_putunbr(int *count, va_list args, t_flags *flags)
{
	unsigned int	n;

	(void)flags;
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
void	ft_putnbr16_upper(int *count, va_list args, t_flags *flags)
{
	int	n;

	(void)flags;
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
void	ft_putnbr16_lower(int *count, va_list args, t_flags *flags)
{
	int	n;

	(void)flags;
	n = va_arg(args, int);
	if (flags->hash)
		flags->hashprefix = "0x";
	addition_flags((unsigned int)n, count, flags, BASE16_LOWER);
}
