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

	count_char = 0;
	if (n <= 0)
		count_char++;
	while (n != 0)
	{
		count_char++;
		n = n / 10;
	}
	return (count_char);
}

int	negative_to_positive(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	int		count_char;
	char	*ptr;

	count_char = ft_len_int(n);
	ptr = malloc (sizeof(char) * (count_char + 1));
	if (!ptr)
		return (NULL);
	ptr[count_char--] = '\0';
	if (n < 0)
		ptr[0] = '-';
	else if (n == 0)
		ptr[0] = '0';
	while (n != 0)
	{
		ptr[count_char] = negative_to_positive(n % 10) + '0';
		count_char--;
		n = n / 10;
	}
	return (ptr);
}
