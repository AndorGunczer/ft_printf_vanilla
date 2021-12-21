/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:32:15 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/20 11:03:44 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

size_t	ft_strlen(const char *s);
int		num_count(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *str, ...);
void	ft_puthexlower_fd(unsigned int n, int fd);
void	ft_puthexupper_fd(unsigned int n, int fd);
void	ft_puthexpointer_fd(unsigned long n, int fd);
void	ft_putunsnbr_fd(unsigned int n, int fd);
int		ft_handletype(char *str, void *arg);
char	ft_detertype(char *str);
int		ft_widthcounter(char *str, void *arg);
int		num_count_long(long n);
int		num_count_hex(unsigned int n);
int		num_count_ptr(unsigned long n);
int		handlepercent(char *str);
void	ft_putchar_inc(char c, int *i);

#endif
