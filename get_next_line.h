/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahouari <ahouari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:53:27 by ichoukri          #+#    #+#             */
/*   Updated: 2021/11/20 08:26:23 by ahouari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_get_line(char *left_str);
char	*change_text(char *result);
char	*ft_strchr(char *str, int c);
char	*read_line(char *result, int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const	*s, unsigned int start, size_t len);
char	*ft_strdup(char *str);

#endif
