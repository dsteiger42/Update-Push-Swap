/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:04:14 by dsteiger          #+#    #+#             */
/*   Updated: 2024/04/22 17:49:08 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int i)
{
	if ((i >= 97) && (i <= 122))
		i -= 32;
	return (i);
}
// int	main(void)
// {
// 	printf("%c\n", ft_toupper('a'));
// }