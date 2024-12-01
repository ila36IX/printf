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

/*
 * padsize - Calculate the padding size for formatted output
 *
 * @n: The number to be padded
 * @flags: Structure containing the current flag settings
 * @base: The base string used for the number conversion
 *
 * Return: The size of padding needed for formatting.
 */
int	padsize(long int n, t_flags *flags, char *base)
{
	int	nbrsize;

	nbrsize = ft_nbrlen(n, ft_strlen(base));
	if (flags->dotpad >= nbrsize)
	{
		nbrsize = flags->dotpad;
		if (n < 0)
			nbrsize++;
	}
	return (nbrsize);
}

/*
 * addition_flags - Handle additional flags for formatting numbers
 * @n: The number to be formatted
 * @count: Pointer to the counter that keeps track of printed characters
 * @flags: Structure containing the current flag settings
 * @base: The base string to use for conversion (e.g., hex digits).
 *
 * Return: None
 */
void	addition_flags(long int n, int *count, t_flags *flags, char *base)
{
	int	nbrsize;

	nbrsize = padsize(n, flags, base);
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
 * search_by_flag - Search and return the corresponding function based
 * on the flag
 * @c: The flag character to search for
 * @ctofunc: Array of structures mapping flags to corresponding functions
 *
 * Return: A pointer to the function associated with the given flag
 */
void	(*search_by_flag(char c, t_ftf ctofunc[]))(int *count, va_list args,
	t_flags *flags)
{
	int	i;

	i = 0;
	while (ctofunc[i].f)
	{
		if (ctofunc[i].c == c)
			return (ctofunc[i].f);
		i++;
	}
	return (NULL);
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
void	(*get_handler(char c))(int *count, va_list args, t_flags *flags)
{
	t_ftf	ctofunc[9];

	ctofunc[0].c = 'c';
	ctofunc[0].f = ft_putchar;
	ctofunc[1].c = 's';
	ctofunc[1].f = ft_putstr;
	ctofunc[2].c = 'p';
	ctofunc[2].f = ft_putptr;
	ctofunc[3].c = 'd';
	ctofunc[3].f = ft_putnbr;
	ctofunc[4].c = 'i';
	ctofunc[4].f = ft_putnbr;
	ctofunc[5].c = 'u';
	ctofunc[5].f = ft_putunbr;
	ctofunc[6].c = 'x';
	ctofunc[6].f = ft_putnbr16_lower;
	ctofunc[7].c = 'X';
	ctofunc[7].f = ft_putnbr16_upper;
	ctofunc[8].c = '%';
	ctofunc[8].f = ft_putpersent;
	return (search_by_flag(c, ctofunc));
}

/*
 * parse_flags - Parse and set flags from the format string.
 * @s: Pointer to the format string, which is updated as flags are parsed.
 * @flags: Pointer to the structure holding the parsed flags.
 *
 * Return: The character immediately after the last parsed flag.
 */
char	parse_flags(const char **s, t_flags *flags)
{
	char	*valid_specs;

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
