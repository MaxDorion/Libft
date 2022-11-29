/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:59:59 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:00:02 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	if (nmemb == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	p = malloc (nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb);
	return (p);
}
