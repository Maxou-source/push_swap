/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparisse <mparisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 21:49:03 by mparisse          #+#    #+#             */
/*   Updated: 2022/12/02 12:15:23 by mparisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strdup2(char *s);
char	*ft_strchr2(char *s, int c);
char	*get_next_line(int fd);
void	get_buffer(char *ptr, char *ligne);
char	*get_final_line(char *ligne, char *buffer);
void	cut_line(char **str);
void	ft_strjoin2(char **s1, char *s2);
size_t	ft_strlen(char const *s);

#endif
