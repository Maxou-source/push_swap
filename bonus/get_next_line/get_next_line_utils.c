/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:53:07 by mparisse          #+#    #+#             */
/*   Updated: 2022/11/26 21:53:35 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup2(char *s)
{
	int		i;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (str == NULL)
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_strjoin2(char **s1, char *s2)
{
	char		*str;
	int			i;

	if (!*s1)
	{
		free(*s1);
		*s1 = ft_strdup2(s2);
		return ;
	}
	str = malloc(sizeof(char) * (ft_strlen(*s1) + BUFFER_SIZE + 1));
	if (!str)
	{
		free(str);
		return ;
	}
	i = -1;
	while ((*s1)[++i])
		str[i] = (*s1)[i];
	i = -1;
	while (s2[++i])
		str[ft_strlen(*s1) + i] = s2[i];
	str[ft_strlen(*s1) + i] = 0;
	free(*s1);
	(*s1) = str;
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr2(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return (s + i);
	return (NULL);
}
