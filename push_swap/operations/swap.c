/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:59:47 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/11 15:59:48 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(node **stack)
{
    node    *temp;
    int     temp_index;

    if (!stack || !(*stack) || !(*stack)->next)  // stack pointer, 1st node, 2nd node
        return ;

    temp = (*stack); 

    (*stack) = (*stack)->next;  // Stack now points to Node2

    temp->next = (*stack)->next; // temp->next = node1->next is now pointing to node3
    (*stack)->next = temp; // stack->next now doesnt mean Node2->next but it sets up stack to temp1 (Node1)

    (*stack)->prev = NULL; // The second node (now the 1st node) should have no previous node
    temp->prev = (*stack); // The original first node (now the second) should point back to the new 1st node

    if (temp->next)
        temp->next->prev = temp; // temp is node1 (now the 2nd node). If there's a 3rd Node, its prev pointer need to point to temp (the node before)

    // Swap the index values of the two nodes
    temp_index = (*stack)->i;
    (*stack)->i = temp->i;
    temp->i = temp_index;
}

void	sa(node **a_stack)
{
	swap(a_stack);
	ft_printf("sa\n");
}

void	sb(node **b_stack)
{
	swap(b_stack);
	ft_printf("sb\n");
}

void	ss(node **a_stack, node **b_stack)
{
	swap(a_stack);
	swap(b_stack);
	ft_printf("ss\n");
}