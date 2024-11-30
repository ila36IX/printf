/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljbari <aljbari@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:24:53 by aljbari           #+#    #+#             */
/*   Updated: 2024/11/20 18:23:47 by aljbari          ###   ########.fr       */
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

int	ft_isdigit(int c);
#define BASE16_LOWER "0123456789abcdef"
#define BASE16_UPPER "0123456789ABCDEF"
#define BASE10 "0123456789"

#endif
