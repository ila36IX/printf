/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:21:46 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:30:54 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * ft_putnchar - Write a character to stdout n times
 * @c: Character to write
 * @n: Number of times to write
 * @count: Pointer to character count
 */
void	ft_putnchar(char c, int n, int *count)
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
void	ft_putchar(int *count, va_list args, t_flags *flags)
{
	char	c;

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
 * number of printed charachters
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */
void	ft_putstr(int *count, va_list args, t_flags *flags)
{
	char	*s;
	int		len;

	s = va_arg(args, char *);
	if (!s)
	{
		if (flags->dot && (!flags->dotpad || flags->dotpad < 5))
		{
			ft_putnchar(' ', flags->pad, count);
			return ;
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

/*
 * ft_putpersent - Hondler of the % flag
 * @count: Pointer to the conter that keeps track of
 * @args: Function varaidic arguments
 * @flags: Struct contains extra specifiers used with p flag
 *
 * Return: None
 */

void	ft_putpersent(int *count, va_list args, t_flags *flags)
{
	(void)flags;
	(void)args;
	write(1, "%", 1);
	(*count)++;
}
