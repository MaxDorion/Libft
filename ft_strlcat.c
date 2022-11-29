/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:03:13 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:03:14 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_src;
	size_t	len_dst;
	size_t	i;
	size_t	j;

	len_dst = 0;
	len_src = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size < len_dst)
		return (len_src + size);
	i = 0;
	j = len_dst;
	if (len_dst < size - 1 && size > 0)
	{
		while (src[i] && len_dst + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		while (dst[j])
			dst[j] = '\0';
	}
	return (len_dst + len_src);
}
