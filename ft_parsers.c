/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 02:21:41 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:30:54 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (**s == '0' && !flags->zero && !flags->pad && !flags->dotpad)
		flags->zero = 1;
	else if (**s == '.' && !flags->dot)
		flags->dot = 1;
	else if (ft_isdigit(**s) && flags->dot)
		flags->dotpad = flags->dotpad * 10 + **s - '0';
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
	flags->dotpad = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->dot= 0;
	flags->hash= 0;
	flags->hashprefix= NULL;
	flags->plus= 0;
	flags->space= 0;
}
