/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunczer <agunczer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 14:32:15 by agunczer          #+#    #+#             */
/*   Updated: 2021/07/10 13:53:28 by agunczer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <string.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printf(const char *str, ...);
void	ft_puthexlower_fd(unsigned int n, int fd);
void	ft_puthexupper_fd(unsigned int n, int fd);
void	ft_puthexpointer_fd(unsigned long n, int fd);
void	ft_putunsnbr_fd(unsigned int n, int fd);
void	ft_handletype(char *str, void *arg);
char	ft_detertype(char *str);
int		ft_widthcounter(char *str, void *arg);
char	*ft_itoa_long(long n);
char	*ft_itoa_hex(unsigned int n);
char	*ft_itoa_ptr(unsigned long n);

#endif
