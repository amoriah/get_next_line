/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:15:08 by amoriah           #+#    #+#             */
/*   Updated: 2022/02/18 12:33:22 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while ((*s) && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *) NULL);
}

static char	*make_line_and_rem(char **rem)
{
	size_t	i;
	char	*tmp;
	char	*line;

	if (!(*rem))
		return (NULL);
	i = 0;
	while ((*rem)[i] != '\n' && (*rem)[i])
		i++;
	if (i < ft_strlen(*rem))
	{
		tmp = *rem;
		line = ft_substr(*rem, 0, ++i);
		*rem = ft_substr(*rem, i, ft_strlen(*rem));
		free(tmp);
	}
	else
	{
		line = *rem;
		*rem = NULL;
	}
	return (line);
}

static char	*save_or_concatenation_rem(char	*buffer, char *rem)
{
	char	*tmp;

	if (rem)
	{
		tmp = rem;
		rem = ft_strjoin(rem, buffer);
		free(tmp);
	}
	else
		rem = ft_strdup(buffer);
	return (rem);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;
	int			byte_was_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	byte_was_read = read(fd, buffer, BUFFER_SIZE);
	while (byte_was_read > 0)
	{
		buffer[byte_was_read] = '\0';
		rem = save_or_concatenation_rem(buffer, rem);
		if (ft_strchr(buffer, '\n'))
			break ;
		byte_was_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_was_read < 0)
			return (NULL);
	}
	free(buffer);
	return (make_line_and_rem(&rem));
}

/*int	main()
{
	int	fd;
	char *line;
	line = NULL;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	// printf("%s", get_next_line(fd));
	// close(fd);
}*/
