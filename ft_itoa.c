/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdorion <mdorion@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:01:01 by mdorion           #+#    #+#             */
/*   Updated: 2022/11/29 16:01:04 by mdorion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_len_int(int n)
{
	size_t	count_char;

	count_char = 1;
	while (n / 10)
	{
		count_char++;
		n = n / 10;
	}
	return (count_char);
}

char	*num_to_char(char *ptr, int count_char, long n2)
{
	ptr[count_char + 1] = '\0';
	if (n2 < 0)
	{
		ptr[0] = '-';
		count_char++;
		n2 = n2 * (-1);
	}
	count_char--;
	while (n2 / 10)
	{
		ptr[count_char] = (n2 % 10) + '0';
		n2 = n2 / 10;
		count_char--;
	}
	ptr[count_char] = (n2 + '0');
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		count_char;
	char	*ptr;
	long	n2;

	n2 = n;
	count_char = ft_len_int(n);
	if (n >= 0)
		ptr = malloc (sizeof(char) * (count_char + 1));
	if (n < 0)
		ptr = malloc (sizeof(char) * (count_char + 2));
	if (!ptr)
		return (NULL);
	ptr = num_to_char(ptr, count_char, n2);
	return (ptr);
}
