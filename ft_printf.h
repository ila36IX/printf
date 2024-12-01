/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:24:53 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 04:44:00 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>

typedef struct flags_t
{
	int		minus;
	int		zero;
	int		dot;
	int		dotpad;
	int		hash;
	char	*hashprefix;
	int		space;
	int		plus;
	int		pad;
}			t_flags;

typedef struct flag_to_func_t
{
	char	c;
	void	(*f)(int *count, va_list args, t_flags *flags);
}			t_ftf;

int			ft_printf(const char *s, ...);
void	(*get_func(char c))(int *count, va_list args, t_flags flags);
void		ft_putcharC(int *count, va_list args, t_flags flags);
void	(*get_handler(char c))(int *count, va_list args, t_flags *flags);

void		addition_flags(long int n, int *count, t_flags *flags, char *base);
int			ft_nbrlen(long int n, int b);
void		ft_putnchar(char c, int n, int *count);
int			ft_nbrlen(long int n, int b);
void		ft_putnchar(char c, int n, int *count);
void		ft_putchar(int *count, va_list args, t_flags *flags);
void		ft_putstr(int *count, va_list args, t_flags *flags);
void		ft_putnbrb_rec(long int n, int *count, char *base, int b);
void		ft_putnbr_base(long int n, int *count, char *base, t_flags *flags);
void		ft_putnbr_base_big(unsigned long long int n, int *count, char *base,
				int b);
int			ft_ptrlen(unsigned long long int n, int b);
void		ft_putptr(int *count, va_list args, t_flags *flags);
void		ft_putnbr(int *count, va_list args, t_flags *flags);
void		ft_putunbr(int *count, va_list args, t_flags *flags);
void		ft_putpersent(int *count, va_list args, t_flags *flags);
char		parse_flags(const char **s, t_flags *flags);
void		init_flags(t_flags *flags);
void		ft_putnbr16_upper(int *count, va_list args, t_flags *flags);
void		ft_putnbr16_lower(int *count, va_list args, t_flags *flags);

# define BASE16_LOWER "0123456789abcdef"
# define BASE16_UPPER "0123456789ABCDEF"
# define BASE10 "0123456789"

#endif
