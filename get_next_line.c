/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:35 by iraqi             #+#    #+#             */
/*   Updated: 2021/11/23 17:02:52 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_next_line(int fd)
{
	char	*str;
	char 	*buf;
	char	c;
	int		j;
	int		r;

	j = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (j < BUFFER_SIZE)
	{
		r = read(fd, &c, 1);
		if (r == -1)
			return (free(str), NULL);
		str[j++] = c;	
		if (c == '\n' || r == 0)
			break ;
	}
	if (r == 0)
		return (NULL);
	str[j] = '\0';
	return (str);	
}

int main(void)
{
	int	fd;
	char	*str;
	
	fd = open("test.txt",O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s", str);
		printf("//");
		free(str);
		str = get_next_line(fd);
		
	}
	return (0);
}