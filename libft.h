/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbui <hbui@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:57:25 by hbui              #+#    #+#             */
/*   Updated: 2021/10/31 09:57:13 by hbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
void	ft_putnbr(int nb);
int		ft_strcmp(char *s1, char *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);

#endif
