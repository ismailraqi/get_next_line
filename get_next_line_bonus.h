/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:30 by iraqi             #+#    #+#             */
/*   Updated: 2021/12/04 23:45:55 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_args{
	char	*str;
	char	*tmp;
	int		j;
	int		r;
	int		bytes;
	int		flag;
}	t_args;

char	*get_next_line(int fd);
int		ft_cleaner(t_args *args, char *c);
int		ft_get_line(t_args *args, char *c, int fd);
char	*ft_joiner(char *buffer, int bytes);
int		ft_strlen(const char *s);
char	*ft_strdup(char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_checker(t_args *args);

#endif