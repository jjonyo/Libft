/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonghpar <jonghpar@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 14:05:45 by jonghpar          #+#    #+#             */
/*   Updated: 2021/06/26 15:17:28 by jonghpar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t count;
	size_t i;

	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while(*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static void		free_memory(char **ret, int i)
{
	while (i >= 0)
	{
		free(ret[i]);
		ret[i] = NULL;
		i--;
	}
	free(ret);
	ret = NULL;
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*tmp;
	int		i;

	if (!s || !(ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1))))
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			tmp = (char *)s;
			while(*s && *s != c)
				s++;
			if (!(ret[i++] = ft_substr(tmp, 0, s - tmp)))
			{
				free_memory(ret, i - 1);
				return (NULL);
			}
		}
		else
			s++;
	}
	ret[i] = NULL;
	return (ret);
}

#include <stdio.h>

int main()
{
	char **ret = ft_split("hello,world,bye,world,good",',');
	for (int i=0;i<5;i++)
	{
		printf("[%d]%s",i,ret[i]);
	}
}