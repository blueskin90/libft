/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:24:50 by toliver           #+#    #+#             */
/*   Updated: 2019/07/21 23:01:45 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			split_and_return(char **str, char **line)
{
	(void)str;
	(void)line;
	return (0);
}

static int			str_fill(char **str, const int fd)
{
	char			buf[BUFF_SIZE + 1];
	int				read_ret;
	char			*tmp;

	if (*str && ft_strchr(*str, '\n'))
		return (1);
	else
	{
		read_ret = read(fd, buf, BUFF_SIZE);
		if (read_ret == -1)
			return (-1);
		buf[read_ret] = '\0';
		if (!ft_strchr(buf, '\n'))
		{
			if (!*str && !(*str = ft_strdup(buf)))
				return (-1);
			while (!ft_strchr(buf, '\n'))
			{
				read_ret = read(fd, buf, BUFF_SIZE);
				if (read_ret == -1)
					return (-1);
				if (!(tmp = ft_strjoin(*str, buf)))
					return (-1);
				free(*str);
				*str = tmp;
				tmp = NULL;
			}
		}
	}
	return (0);
}

int					ft_gnl(const int fd, char **line)
{
	static char		*str = NULL;
	int				retval;

	retval = 0;
	if (fd < 0)
		return (-1);
	if (str == NULL && (retval = str_fill(&str, fd)) <= 0)
	{
		*line = NULL;
		return (retval);
	} // ici ma str est forcement remplie, car soit elle n'est pas null, soit si jai un retour de str_fill c'est que je l'ai remplie
	if (!ft_strchr(str, '\n') && (retval = str_fill(&str, fd)) <= 0)
	{
		if (retval < 0)
		{
			free(str);
			str = NULL;
			return (-1);
		}
		*line = str;
		str = NULL;
		return (0);
	}
	if (retval = split_and_return(&str, line) < 0)
	{
		free(str);
		str = NULL;
		*line = NULL;
		return (-1);
	}
	return (1);
}
