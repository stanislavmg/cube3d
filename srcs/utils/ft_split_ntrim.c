/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ntrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sosokin <sosokin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:21:44 by defimova          #+#    #+#             */
/*   Updated: 2024/11/06 21:07:17 by sosokin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/cub3D.h"

static void	fill_str(char *p1, char *p2, char **arr, int count)
{
	int	len;
	int	i;

	i = 0;
	len = p2 - p1;
	arr[count] = (char *)malloc(sizeof(char) * (len + 1));
	while (p1 != p2)
	{
		arr[count][i] = *p1;
		p1++;
		i++;
	}
	arr[count][i] = 0;
}

static void	fill_arr(const char *str, char c, char **arr)
{
	size_t	count;
	char	*p1;
	char	*p2;

	count = 0;
	p1 = (char *)str;
	p2 = (char *)str;
	while (*p2)
	{
		p2 = ft_strchr(p2, c);
		if (p2)
			fill_str(p1, p2, arr, count);
		else
		{
			fill_str(p1, (char *)str + ft_strlen(str), arr, count);
			break ;
		}
		count++;
		p2++;
		p1 = p2;
	}
}

static size_t	count_words(const char *str, char c)
{
	char	*occ;
	size_t	count;

	count = 0;
	while (*str)
	{
		occ = ft_strchr(str, c);
		if (occ)
		{
			str = occ + 1;
			count++;
		}
		else
			break ;
	}
	if (count == 0)
		return (0);
	return (count + 1);
}

char	**ft_split_ntrim(char const *s, char c)
{
	size_t	count;
	char	**arr;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	arr = (char **)malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	fill_arr(s, c, arr);
	arr[count] = NULL;
	return (arr);
}
