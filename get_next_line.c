/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:53:23 by ichoukri          #+#    #+#             */
/*   Updated: 2021/11/15 18:28:02 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>
char	*change_text(char *result)
{
	char	*newtext;
	size_t	len;
	size_t	i;

	len = 0;
	while (result[len] != '\n' && result[len] != '\0')
		len++;
	if (result[len] == '\0')
	{
		free(result);
		return (NULL);
	}
	i = 0;
	newtext = (char *)malloc(sizeof(char) * (ft_strlen(result) - len + 1));
	if (newtext == NULL)
		return (NULL);
	while (result[++len] != '\0')
		newtext[i++] = result[len];
	newtext[i] = '\0';
	free(result);
	return (newtext);
}

char	*ft_read(char *text, int fd)
{
	char	*buff;
	int		n;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	n = 1;
	while (ft_strchr(text, '\n') == NULL && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		text = ft_strjoin(text, buff);
	}
	free(buff);
	return (text);
}

char	*get_line(char *text)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	if (text[0] == '\0')
		return (NULL);
	while (text[len] != '\n' && text[len] != '\0')
		len++;
	if (text[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = text[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = ft_read(text, fd);
	if (text == NULL)
		return (NULL);
	line = get_line(text);
	text = change_text(text);
	return (line);
}
int main ()
{
	int fd;
	fd = open("test.txt",O_RDONLY, S_IRUSR | S_IWUSR);
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}
