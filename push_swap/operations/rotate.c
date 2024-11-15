/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:59:44 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/11 18:54:17 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(node **stack)
{
	node	*head;

	head = *stack;   // stack point to the 1st node and head points to the original 1st node
	if (!(*stack) || !((*stack)->next))
		return ;
	*stack = head->next;    // stack now point to the 2n noede, while head still points to the 1st
	head->next = NULL;      // the original 1st node should no longer point to the 2nd node
	ft_lstlast(*stack)->next = head;
}

void	ra(node **stack1)
{
	rotate(stack1);
	write(1, "ra\n", 3);
}

void	rb(node **stack2)
{
	rotate(stack2);
	write(1, "rb\n", 3);
}

void	rr(node **stack1, node **stack2)
{
	rotate(stack1);
	rotate(stack2);
	write(1, "rr\n", 3);
}