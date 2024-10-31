/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-fran <ade-fran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:48:02 by ade-fran          #+#    #+#             */
/*   Updated: 2023/11/16 10:48:05 by ade-fran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_in_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_get_word(char const *s, char *charset, size_t *p)
{
	size_t		l;
	size_t		i;
	char		*word;

	l = 0;
	i = 0;
	while (s[*p] && ft_in_charset(charset, s[*p]))
		(*p)++;
	while (s[*p + l] && !ft_in_charset(charset, s[*p + l]))
		l++;
	word = malloc(sizeof (char) * (l + 1));
	if (!word)
		return (NULL);
	while (i < l && s[*p])
	{
		word[i] = s[*p];
		i++;
		(*p)++;
	}
	word[i] = '\0';
	return (word);
}

static void	ft_free_word(char **tab, size_t index_err)
{
	size_t	i;

	i = 0;
	while (i < index_err)
	{
		free(tab[i]);
		i++;
	}
}

static size_t	ft_fill_tab(char **tab, char const *s, size_t n, char *charset)
{
	size_t	i;
	size_t	z;

	i = 0;
	z = 0;
	while (i < n)
	{
		tab[i] = ft_get_word(s, charset, &z);
		if (!tab[i])
		{
			ft_free_word(tab, i);
			return (1);
		}
		i++;
	}
	tab[i] = NULL;
	return (0);
}

char	**ft_split(char const *s, char *charset)
{
	char	**tab;
	size_t	nb_word;
	size_t	err;

	if (!s)
		return (NULL);
	nb_word = ft_count_word(s, charset);
	if (nb_word == 0)
		return (NULL);
	tab = malloc(sizeof(char *) * (nb_word + 1));
	if (!tab)
		return (NULL);
	err = ft_fill_tab(tab, s, nb_word, charset);
	if (err)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}
