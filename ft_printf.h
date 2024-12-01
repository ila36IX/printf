/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:24:53 by aljbari           #+#    #+#             */
/*   Updated: 2024/12/01 02:31:05 by aljbari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"

#ifndef FT_LIBFT
#define FT_LIBFT

typedef struct flags_t {
	int minus;
	int zero;
	int dot;
	int dotpad;
	int hash;
	char *hashprefix;
	int space;
	int plus;
	int pad;
} flags_t;

typedef struct flag_to_func_t {
	char c;
	void (*f)(int *count, va_list args, flags_t *flags);
} ftf_t;

int	ft_printf(const char *s, ...);
void (*get_func(char c))(int *count, va_list args, flags_t flags);
void ft_putcharC(int *count, va_list args, flags_t flags);
void (*get_handler(char c))(int *count, va_list args, flags_t *flags);


void addition_flags(long int n, int *count,flags_t *flags, char *base);
int ft_nbrlen(long int n, int b);
void ft_putnchar(char c, int n, int *count);
int ft_nbrlen(long int n, int b);
void ft_putnchar(char c, int n, int *count);
void ft_putchar(int *count, va_list args, flags_t *flags);
void ft_putstr(int *count, va_list args, flags_t *flags);
void ft_putnbrb_rec(long int n, int *count, char *base, int b);
void ft_putnbr_base(long int n, int *count, char *base, flags_t *flags);
void ft_putnbr_base_big(unsigned long long int n, int *count, char *base, int b);
int ft_ptrlen(unsigned long long int n, int b);
void ft_putptr(int *count, va_list args, flags_t *flags);
void ft_putnbr(int *count, va_list args, flags_t *flags);
void ft_putunbr(int *count, va_list args, flags_t *flags);
void ft_putnbrX(int *count, va_list args, flags_t *flags);
void ft_putnbrx(int *count, va_list args, flags_t *flags);
void ft_putpersent(int *count, va_list args, flags_t *flags);
char parse_flags(const char **s, flags_t *flags);
void init_flags(flags_t *flags);

#define BASE16_LOWER "0123456789abcdef"
#define BASE16_UPPER "0123456789ABCDEF"
#define BASE10 "0123456789"

#endif
