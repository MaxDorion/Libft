/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:02:49 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:02:51 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	while (s[i])
		i++;
	new_str = malloc ((i + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s)
	{
		new_str[i] = *s;
		s++;
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
