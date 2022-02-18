/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoriah <amoriah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:15:15 by amoriah           #+#    #+#             */
/*   Updated: 2021/11/12 15:16:12 by amoriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*subs;
	char	*p;
	size_t	len_sub;

	i = 0;
	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	p = (char *)s;
	len_sub = ft_strlen(p) - start;
	if (len_sub > len)
		len_sub = len;
	subs = ft_calloc((len_sub + 1), sizeof(char));
	if (!subs)
		return (NULL);
	while (len_sub--)
		subs[i++] = p[start++];
	return (subs);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen((char *)s1);
	len_s2 = ft_strlen((char *)s2);
	newstr = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (*s1)
		newstr[i++] = *s1++;
	while (*s2)
		newstr[i++] = *s2++;
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strdup(char *s1)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = ((char *)malloc(sizeof(char) * (i + 1)));
	if (!p)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	mult;
	unsigned int	i;

	mult = count * size;
	p = malloc(mult);
	if (!p)
		return (NULL);
	i = 0;
	while (mult)
	{
		p[i] = 0;
		i++;
		mult--;
	}
	return ((void *)p);
}
