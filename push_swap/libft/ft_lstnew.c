/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:55:23 by dsteiger          #+#    #+#             */
/*   Updated: 2024/05/10 16:14:04 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

// 22 - the 2nd content is the parameter
// int main()
// {
//     t_list *node = ft_lstnew("Hello");

//     if (node == NULL) {
//         printf("Memory allocation failed.\n");
//         return (1);
//     }
//     printf("Content of the node: %s\n", (char *)node->content);
//     free(node);
//     return (0);
// }