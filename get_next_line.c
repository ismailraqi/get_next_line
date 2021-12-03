/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iraqi <iraqi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:40:35 by iraqi             #+#    #+#             */
/*   Updated: 2021/12/03 19:45:06 by iraqi            ###   ########.fr       */
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
	static char	c;
	s_args args;
	
	if (BUFFER_SIZE <= 0)
		return (NULL);
	args.str = malloc(sizeof(char)*(BUFFER_SIZE + 1));
	if (!args.str)
		return (NULL);
	args.bytes = 0;
	args.j = 0;
	while (1)
	{
		while ((args.j < BUFFER_SIZE) && c != '\n')
		{
			args.r = read(fd, &c, 1);
			if (args.r == 0)
			{
				args.str = ft_checker(&args);
				if (args.str == NULL)
					return NULL;
				return args.str;
			}
			if (args.r == -1)
				return (free(args.str), NULL);
			args.str[args.bytes + args.j++] = c;
		}
		args.str[args.bytes + args.j] = '\0';
		if (c == '\n')
		{
			args.tmp = ft_strdup(args.str);
			c = 0;
			return (free(args.str),args.str = args.tmp, args.str);
		}
		args.bytes += args.j;
		args.j = 0;
		args.str = ft_joiner(args.str, args.bytes);
		if (!args.str)
			return (NULL);
	}
	args.str[args.j] = '\0';
	return (args.str);	
}

int main(void)
{
	char	*str;
	int	fd;
	//int fd1;

	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s|",str);
		free(str);
		str = get_next_line(fd);	
	}
	// fd1 = open("titi.txt", O_RDONLY);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd1);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// str = get_next_line(fd);
	// printf("%s", str);
	// free(str);
	// close(fd);
	// close(fd1);
	// while (str)
	// {
	// 	str = get_next_line(fd);

	// }
	return (0);
}
