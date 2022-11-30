/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:04:24 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:04:26 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	valueof_malloc(char const *s, unsigned int start, size_t len)
{
	size_t	cpt;

	if (len >= ft_strlen(s) && start < ft_strlen(s))
		cpt = ft_strlen(s) - start;
	else if (start >= ft_strlen(s))
		cpt = 0;
	else
		cpt = len;
	return (cpt);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	new_str = malloc ((valueof_malloc(s, start, len) + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < len && s[start])
		{
			new_str[i] = s[start];
			i++;
			start++;
		}
	}
	new_str[i] = '\0';
	return (new_str);
}
