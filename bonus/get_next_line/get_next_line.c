/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:39:26 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/02 12:05:04 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	cut_line(char **str)
{
	int		i;
	int		j;
	char	*ligne;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{	
		ligne = malloc(sizeof(char) * i + 2);
		if (!ligne)
		{
			(*str) = NULL;
			return ;
		}
		i++;
	}
	else
		return ;
	j = -1;
	while (++j < i)
		ligne[j] = (*str)[j];
	ligne[j] = 0;
	free(*str);
	(*str) = ligne;
}

void	get_buffer(char *ptr, char *ligne)
{
	int		i;
	char	*str;

	i = 0;
	if (ft_strchr2(ligne, '\n'))
		str = ft_strchr2(ligne, '\n') + 1;
	else
		return ;
	while (str[i])
	{
		*ptr = str[i];
		i++;
		ptr++;
	}
	*ptr = 0;
	return ;
}

char	*get_final_line(char *ligne, char *buffer)
{
	if (ft_strchr2(ligne, '\n'))
	{
		get_buffer(buffer, ligne);
		return (ligne);
	}
	return (ligne);
}

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	char			*ligne;
	int				red;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	red = 1;
	ligne = NULL;
	if (buffer[0] != 0)
		ft_strjoin2(&ligne, buffer);
	while (red && !ft_strchr2(buffer, '\n'))
	{
		red = read(fd, buffer, BUFFER_SIZE);
		if (red < 0)
			return (NULL);
		buffer[red] = 0;
		if (red == 0)
			break ;
		ft_strjoin2(&ligne, buffer);
	}
	if (!get_final_line(ligne, buffer))
		return (NULL);
	return (ligne = get_final_line(ligne, buffer), cut_line(&ligne), ligne);
}

// //ligne buffer red 
// #include <stdio.h>

// int main(int ac, char **argv)
// {
// 	int fd = open(argv[1], O_RDONLY);
// 	if (fd < 0)
// 	{
// 		printf("pas ok");
// 		return (0);
// 	}
// 	char *str;
// 	while ((str = get_next_line(fd)))
// 	{
// 		printf("%s", str);
// 		str = get_next_line(fd);
// 		free(str);
// 	}
// }
