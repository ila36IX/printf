/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:36:40 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:30:52 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * init_flags - Initialize a t_flags structure to its default state.
 * @flags: Pointer to the t_flags structure to initialize.
 *
 * Return: None
 */
void	init_flags(t_flags *flags)
{
	flags->pad = 0;
	flags->dotpad = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->hash = 0;
	flags->hashprefix = NULL;
	flags->plus = 0;
	flags->space = 0;
}

/*
 * ft_printf - A custom implementation of the printf function.
 *
 * @s: The format string containing directives and plain text.
 * @...: Variable arguments corresponding to the format specifiers in @s.
 * Return: The total number of characters printed.
 */
int	ft_printf(const char *s, ...)
{
	int		count;
	char	c;
	va_list	args;
	t_flags	flags;

	va_start(args, s);
	count = 0;
	while (s && *s)
	{
		if (*s == '%')
		{
			s++;
			init_flags(&flags);
			c = parse_flags(&s, &flags);
			if (c)
				get_handler(c)(&count, args, &flags);
		}
		else
		{
			write(1, s++, 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
