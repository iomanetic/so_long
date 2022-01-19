/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyuuki <tyuuki@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:00:44 by tyuuki            #+#    #+#             */
/*   Updated: 2022/01/12 15:39:34 by tyuuki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../includes/so_long.h"

char	*ft_strdup(const char *s)
{
	char	*s_2;
	size_t	len_s;
	size_t	i;

	len_s = ft_strlen(s);
	i = 0;
	s_2 = (void *) malloc(sizeof(void) * len_s + 1);
	if (s_2 == NULL)
		return (NULL);
	while (i <= len_s)
	{
		s_2[i] = s[i];
		i++;
	}
	s_2[i] = '\0';
	return (s_2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*prov(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (ft_strlen(s) <= start || len == 0)
	{
		str = (char *) malloc(1);
		*str = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	str = prov(s, start, len);
	if (str)
		return (str);
	if (!len && !start)
		return (ft_strdup(s));
	if (len >= ft_strlen(s))
		return (ft_strdup(&s[start]));
	str = (char *) malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	while (i <= len - 1 && s[i])
	{
		str[k] = s[start + i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}
