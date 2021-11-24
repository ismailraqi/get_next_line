/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:35 by iraqi             #+#    #+#             */
/*   Updated: 2021/11/24 12:31:33 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*str;
	static char	c;
	int		j;
	int		r;


	j = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (j < BUFFER_SIZE || c != '\n')
	{
		r = read(fd, &c, 1);
		if (r == 0)
			break ;
		if (r == -1)
			return (free(str), NULL);
		str[j++] = c;	
		if (c == '\n')
			break ;
	}
	if (r == 0 && j == 0)
		return (NULL);
	str[j] = '\0';
	return (str);	
}

int main(void)
{
	char	*str;
	int	fd;
	int	fd1;

	fd = open("test.txt",O_RDONLY);
	fd1 = open("titi.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	// while (str)
	// {
	// 	str = get_next_line(fd);

	// }
	return (0);
}