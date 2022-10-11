/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znogueir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 22:47:16 by znogueir          #+#    #+#             */
/*   Updated: 2022/05/10 16:10:59 by znogueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wlen(char const *substr, char c)
{
	int	i;

	i = 0;
	while (substr[i] && substr[i] != c)
		i++;
	return (i);
}

int	ft_wcount(char const *s, char c)
{
	int	i;
	int	wcount;

	i = 0;
	wcount = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			wcount++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wcount);
}

char	*ft_word(char const *substr, char c)
{
	int		i;
	char	*word;

	word = (char *)malloc(sizeof(char) * (ft_wlen(substr, c) + 1));
	if (!word)
		return (0);
	i = 0;
	while (i < ft_wlen(substr, c))
	{
		word[i] = substr[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		wcount;
	char	**result;

	wcount = ft_wcount(s, c);
	result = (char **)malloc(sizeof(char *) * (wcount + 1));
	if (!result)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			result[j] = ft_word((s + i), c);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	result[j] = 0;
	return (result);
}
