/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:59:28 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/11 15:59:31 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_index(node **a_stack, node **b_stack)
{
    node	*current_a;
    node	*current_b;

	if (!a_stack || !(*a_stack) || !b_stack || !(*b_stack))
		return ;
	current_a = (*a_stack);
	while (current_a)
	{
		current_a->i--;
		current_a = current_a->next;
	}
	if ((*b_stack)->next) // if there's more than 1 node
	{
		current_b = (*b_stack); // current_b = (*b_stack)->next;??
		while (current_b)
		{
			current_b->i++;
			current_b = current_b->next;
		}
	}
}

static void	push(node **src, node **dest)
{
	node	*temp_src;
	node	*temp_dest;

	if (!src || !(*src) || !dest)
		return ;
	temp_src = (*src);
	(*src) = (*src)->next;
	if (*src)
		(*src)->prev = NULL; // if the updated src (node2) is not NULL, the prev should be NULL to indicate it is the new head
	temp_src->prev = NULL;
	if (!(*dest)) // if dest is empty
	{
		(*dest) = temp_src;
		(*dest)->next = NULL;
	}
	else
	{
		temp_dest = (*dest);
		(*dest) = temp_src;
		(*dest)->next = temp_dest;
		temp_dest->prev = temp_src;
	}
	update_push_index(src, dest);
}
void	pb(node **a_stack, node **b_stack)
{
	push(a_stack, b_stack);
	ft_printf("pb\n");
}

void	pa(node **b_stack, node **a_stack)
{
	push(b_stack, a_stack);
	ft_printf("pa\n");
}