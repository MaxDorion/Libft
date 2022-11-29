/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:04:14 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:04:15 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	value_of_malloc(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	j = 0;
	cpt = 0;
	while (s1[j])
	{
		while (set[i])
		{
			if (set[i] == s1[j])
				cpt++;
			i++;
		}
		i = 0;
		j++;
	}
	return (ft_strlen(s1) - cpt);
}

char	*trim_str(char const *s1, char const *set, char *new_str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s1)
	{
		while (set[j])
		{
			if (*s1 == set[j])
			{
				s1++;
				j = -1;
			}
			j++;
		}
		new_str[i] = *s1;
		i++;
		s1++;
		j = 0;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;

	new_str = malloc (sizeof(char) * (value_of_malloc(s1, set) + 1));
	if (!new_str)
		return (NULL);
	new_str = trim_str(s1, set, new_str);
	return (new_str);
}
