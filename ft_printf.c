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


int	ft_printf(const char *s, ...)
{
	int count;
	char c;
	va_list	args;
	flags_t flags;

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
	return (count);
}
