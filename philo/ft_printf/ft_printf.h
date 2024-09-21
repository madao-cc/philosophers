/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madao-da <madao-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:52:59 by madao-da          #+#    #+#             */
/*   Updated: 2023/10/16 12:41:23 by madao-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

char	*ft_createptr(unsigned long long n);
int		ft_getdigits(int n);
char	*ft_htoa(unsigned int n);
char	*ft_bightoa(unsigned int n);
char	*ft_itoa(int n);
int		ft_printchar(int c);
int		ft_printf(const char *format, ...);
int		ft_printhex(unsigned int n);
int		ft_printbighex(unsigned int n);
int		ft_printnbr(int n);
int		ft_printpercent(void);
int		ft_printstr(char *str);
int		ft_strlen(char *str);
int		ft_printptr(unsigned long long n);
int		ft_printunsigned(unsigned int n);
void	ft_putunsigned(unsigned int n);

#endif