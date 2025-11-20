/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoto-su <ssoto-su@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 20:39:06 by ssoto-su          #+#    #+#             */
/*   Updated: 2025/05/23 16:39:23 by ssoto-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_pf_putchar(int c);
int	ft_pf_putnbr(long int n);
int	ft_pf_putunbr(unsigned int n);
int	ft_pf_putstr(char *s);
int	ft_pf_putint(int n);
int	ft_pf_putuint(unsigned int n);
int	ft_pf_putptr(void *p);
int	ft_pf_puthexalow(unsigned long long int p);
int	ft_pf_puthexaup(unsigned int p);
int	ft_format(char ch, va_list ap);
int	ft_printf(const char *format, ...);

#endif