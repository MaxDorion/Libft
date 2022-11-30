/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:02:30 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:02:31 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			j++;
			i++;
			while (s[j] != c && s[j] != '\0')
				j++;
		}
		else if (s[j] == c)
			j++;
	}
	return (i);
}

int	malloc_lines(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i + 1);
}

char	*ft_make_lines(const char *s, char c)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc (sizeof(char) * (malloc_lines(s, c)));
	if (!ptr)
		return (0);
	while (s[i] != c && s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	tab = malloc ((sizeof(char *)) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			tab[i] = ft_make_lines(s, c);
			i++;
		}
		while (*s != c && *s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
