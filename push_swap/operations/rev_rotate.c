/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:59:37 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/11 16:13:20 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate(node **stack)
{
	node	*temp;
	node	*end;

	if (!(*stack) || !((*stack)->next))
		return ;
	temp = *stack;                  // temp set to the og node1
	end = ft_lstlast(*stack);       // end set to the last node
	while ((*stack)->next->next)    // loop moves *stack to point to the second-to-last node
		*stack = (*stack)->next;    
	end->next = temp;               // the next pointer of the last node is updated to temp (node1). The last node points to the start of the list
	(*stack)->next = NULL;          // makes the second-to-last node point to NULL, making it the last node
	*stack = end;                   // *stack now points to the new node1
}

void	rra(node **stack1)
{
	rev_rotate(stack1);
	write(1, "rra\n", 4);
}

void	rrb(node **stack2)
{
	rev_rotate(stack2);
	write(1, "rrb\n", 4);
}