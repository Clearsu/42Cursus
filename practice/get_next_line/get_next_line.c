/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 20:10:28 by jincpark          #+#    #+#             */
/*   Updated: 2022/11/17 21:28:38 by jincpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 10

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		len;
	char	*result;

	len = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

int	ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str++ == c)
			return (1);
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		len1;
	int		len2;
	char	*result;
	int		i;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	i = 0;
	while (*str1)
		result[i++] = *str1++;
	while (*str2)
		result[i++] = *str2++;
	result[i] = '\0';
	return (result);
}

char	*ft_substr(char *str, int start, int finish)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (finish - start + 2));
	i = 0;
	while (start <= finish)
		result[i++] = str[start++];
	result[i] = '\0';
	return (result);
}

char	*read_and_save(int fd, char *save, char *buffer)
{
	char	*temp;
	int		bytes;

	while (save && !ft_strchr(save, '\n'))
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == 0)
			return (save);
		buffer[bytes] = '\0';
		temp = save;
		save = ft_strjoin(temp, buffer);
		free(temp);
	}
	return (save);
}

char	*get_line_to_return(char *save)
{
	int		i;

	i = 0;
	while (save[i] != '\n' && save[i])
		i++;	
	return (ft_substr(save, 0, i));
}

char	*get_new_save(char *save)
{
	char	*temp;
	char	*new_save;

	temp = save;
	while (*temp && *temp != '\n' && temp)
		temp++;
	if (*temp == '\n' && *temp && temp)
	{
		temp++;
		new_save = ft_strdup(temp);
	}
	else
		new_save = NULL;
	free(save);
	return (new_save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!save)
		save = ft_strdup("");
	save = read_and_save(fd, save, buffer);
	line = get_line_to_return(save);
	save = get_new_save(save);
	return (line);
}

#include <stdio.h>

int	main()
{
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
	printf("%s", get_next_line(0));
}
