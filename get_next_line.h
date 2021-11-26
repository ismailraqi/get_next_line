/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:30 by iraqi             #+#    #+#             */
/*   Updated: 2021/11/27 00:14:06 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
char	*get_next_line(int fd);
int	ft_strlen(const char *s);
char	*ft_joiner(char *buffer, int bytes);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(char *src);



#endif