/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toliver <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 19:48:24 by toliver           #+#    #+#             */
/*   Updated: 2019/07/21 22:24:03 by toliver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int		wordnumber(char *str, char *charset, int *words, int *size)
{
	if (!str || !charset)
		return (0);
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			(*words)++;
			while (!is_charset(*str, charset) && *str)
			{
				str++;
				(*size)++;
			}
		}
		else
		{
			while (is_charset(*str, charset))
				str++;
		}
	}
	return (1);
}

static int		fill_string(char *arrstr, char *str, int *c, char *charset)
{
	int	i;

	i = 0;
	while (!is_charset(*str, charset) && *str)
	{
		arrstr[i] = *str;
		i++;
		str++;
		(*c)++;
	}
	arrstr[i] = '\0';
	i++;
	(*c)++;
	return (i);
}

static int		fill_array(char ***arr, int words, char *str, char *charset)
{
	int		word;
	int		c;
	int		i;

	word = 0;
	c = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			i = 0;
			(*arr)[word] = (char*)((*arr) + sizeof(char*) * (words + 1)
					+ sizeof(char) * c);
			str += fill_string((*arr)[word], str, &c, charset);
			word++;
		}
		else
			while (is_charset(*str, charset))
				str++;
	}
	return (1);
}

char			**ft_split(char *str, char *charset)
{
	int			words;
	int			size;
	char		**arr;

	words = 0;
	size = 0;
	if (str && charset)
		wordnumber(str, charset, &words, &size);
	if (!charset)
	{
		words = 1;
		size = ft_strlen(str) + 1;
	}
	if (!(arr = (char**)malloc(sizeof(char*) * words + 1
					+ sizeof(char) * (size + words))))
		return (NULL);
	arr[words] = NULL;
	if (!charset)
	{
		arr[0] = (char*)arr + (sizeof(char*) * (words + 1));
		ft_strcpy(arr[0], str);
		return (arr);
	}
	fill_array(&arr, words, str, charset);
	return (arr);
}
