/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:35 by iraqi             #+#    #+#             */
/*   Updated: 2021/11/27 00:16:23 by iraqi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joiner(char *str, int bytes)
{
	char	*tmp;
	
	tmp = (char *)malloc((bytes + BUFFER_SIZE + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, str, bytes);
	return (free(str), tmp);
}

char	*get_next_line(int fd)
{
	char	*str;
	char	*tmp;
	static char	c;
	int		j;
	int		r;
	int		bytes;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	str = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	bytes = 0;
	j = 0;
	while (1)
	{
		while ((j < BUFFER_SIZE) && c != '\n')
		{
			r = read(fd, &c, 1);
			if (r == 0)
			{
				if (j == 0)
					return (NULL);
				str[j + bytes] ='\0';
				tmp = ft_strdup(str);
				return (free(str),str = tmp, str);
			}
			if (r == -1)
				return (free(str), NULL);
			str[bytes + j++] = c;
		}
		str[bytes + j] = '\0';
		if (c == '\n')
		{
			tmp = ft_strdup(str);
			c = 0;
			return (free(str),str = tmp, str);
		}
		bytes += j;
		j = 0;
		str = ft_joiner(str, bytes);
		if (!str)
			return (NULL);
	}
	str[j] = '\0';
	return (str);	
}

// int main(void)
// {
// 	char	*str;
// 	int	fd;
// 	int fd1;

// 	fd = open("test.txt", O_RDONLY);
// 	// str = get_next_line(fd);
// 	// while (str)
// 	// {
// 	// 	printf("%s|",str);
// 	// 	free(str);
// 	// 	str = get_next_line(fd);	
// 	// }
// 	fd1 = open("titi.txt", O_RDONLY);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd1);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	str = get_next_line(fd);
// 	printf("%s", str);
// 	free(str);
// 	close(fd);
// 	close(fd1);
// 	// while (str)
// 	// {
// 	// 	str = get_next_line(fd);

// 	// }
// 	return (0);
// }