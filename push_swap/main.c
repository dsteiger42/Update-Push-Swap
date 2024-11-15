/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 16:00:09 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/15 19:12:53 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	node	*a_stack;
	node	*b_stack;
	node	*current;

	a_stack = NULL;
	b_stack = NULL;
	// Create some sample data for stack B
	pb(&a_stack, &b_stack);
	pb(&a_stack, &b_stack);
	pb(&a_stack, &b_stack);
	pb(&a_stack, &b_stack);
	pb(&a_stack, &b_stack);
	pb(&a_stack, &b_stack);
	printf("Stack B before sorting:\n");
	current = b_stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
	sort_stack_b(&b_stack);
	printf("Stack B after sorting:\n");
	current = b_stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
	// Push the sorted elements from stack B to stack A
	while (b_stack)
	{
		pa(&b_stack, &a_stack);
	}
	printf("Stack A after pushing sorted elements from stack B:\n");
	current = a_stack;
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
	return (0);
}
