/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofdomin <sofdomin@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 17:19:37 by sofdomin          #+#    #+#             */
/*   Updated: 2026/11/05 18:01:30 by sofdomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <strings.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
void	ft_bzero(void *s, size_t n)
void *ft_calloc(size_t nmemb, size_t size)
int	ft_isalnum(int c)
int	isalpha(int c)
int	ft_isascii(int c)
int	ft_isdigit(int c)
int	ft_isprint(int c)
static size_t	num_len(unsigned int n)
void	ft_putchar_fd(char c, int fd)
void	ft_putendl_fd(char *s, int fd)
void	ft_putnbr_fd(int n, int fd)
void	ft_putstr_fd(char *s, int fd)
char	*ft_strchr(const char *s, int c)
char	*ft_strdup(const char *s)
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
size_t	ft_strlcat(char *dst, const char *src, size_t size)
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
size_t	strlen(const char *s)
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
int	ft_strncmp(const char *s1, const char *s2, size_t n)
char	*strrchr(const char *str, int c)
int	ft_tolower(int c)
int	ft_toupper(int c)




