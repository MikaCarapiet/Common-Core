/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarapie <mcarapie@student.42singapore.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 16:09:17 by mcarapie          #+#    #+#             */
/*   Updated: 2026/01/14 13:08:36 by mcarapie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *string, ...);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
void	ft_printchar(char c, int *count);
void	ft_printstr(char *s, int *count);
void	ft_printnbr(int n, int *count);
void	ft_printunsignedint(unsigned int n, int *count);
void	ft_printhexaupper(unsigned int n, int *count);
void	ft_printhexalower(unsigned int n, int *count);
void	ft_printpointer(void *ptr, int *count);
void	ft_printspecifier(const char string, va_list *args, int *count);

#endif
