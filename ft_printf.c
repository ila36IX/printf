/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:36:40 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/20 18:26:52 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char parse_flags(const char **s, flags_t *flags)
{
	char *valid_specs;

	valid_specs = "cspdiuxX%";
	if (ft_strchr(valid_specs, **s))
		return (*(*s)++);
	if (**s == '-')
		flags->minus = 1;
	else if (**s == '+')
		flags->plus = 1;
	else if (**s == ' ')
		flags->space = 1;
	else if (**s == '0' && !flags->zero && !flags->pad)
		flags->zero = 1;
	else if (**s == '.' && !flags->dot)
		flags->dot = 1;
	else if (ft_isdigit(**s))
		flags->pad = flags->pad * 10 + **s - '0';
	else if (**s == '#')
		flags->hash = 1;
	else
		return (0);
	(*s)++;
	return (parse_flags(s, flags));
}

void init_flags(flags_t *flags)
{
	flags->pad = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot= 0;
	flags->hash= 0;
	flags->plus= 0;
	flags->space= 0;
}

void	print_parsed_flags(flags_t *flags)
{
	printf("^^^^^^^^^^^^\n");
	printf("pad    %d\n", flags->pad);
	printf("-      %d\n", flags->minus);
	printf("0      %d\n", flags->zero);
	printf(".      %d\n", flags->dot);
	printf("hash   %d\n", flags->hash);
	printf("+      %d\n", flags->plus);
	printf("space  %d\n", flags->space);
	printf("^^^^^^^^^^^^\n");
}

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
			// print_parsed_flags(&flags);
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
