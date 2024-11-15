/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:21:07 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/15 19:21:10 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
1st - this function helps me reverse rotate and push the last few nodes /
that are smaller than the pivot, before rotating the bigger ones that /
are on the top on the stack
*/

/*
2nd - *stack->rotated checks if a node has been rotated (0) and /
if it already has (1), the loop will break
*/
#include "push_swap.h"

void	handle_last_nodes(node **a_stack, node **b_stack, int pivot)
{
	node	*last;

	while (*a_stack && (*a_stack)->next)
	{
		last = lstlast(*a_stack);
		if (last->value < pivot)
		{
			rra(a_stack);
			pb(a_stack, b_stack);
		}
		else
			break ;
	}
}
void	sort_stack_a(node **a_stack, node **b_stack, int *pivot)
{
	int	len_a;

	len_a = ft_lstsize((node *)*a_stack);
	while (len_a > 3)
	{
		*pivot = ft_lstsize(*a_stack) / 2;
		while (*a_stack && (*a_stack)->value < *pivot)
			pb(a_stack, b_stack);
		handle_last_nodes(a_stack, b_stack, *pivot);
		while (*a_stack && (*a_stack)->value >= *pivot
			&& (*a_stack)->rotated == 0)
		{
			(*a_stack)->rotated = 1;
			ra(a_stack);
		}
		len_a = ft_lstsize(*a_stack);
	}
	sort_3(a_stack);
}

void	sort_stack_b(node **b_stack)
{
	int		len_b;
	node	*max;
	node	*current;

	len_b = ft_lstsize(*b_stack);
	while (len_b > 3)
	{
		max = *b_stack;
		current = *b_stack;
		while (current->next)
		{
			if (current->next->value > max->value)
			{
				max = current->next;
			}
			current = current->next;
		}
		while (lstlast(*b_stack) != max)
		{
			rrb(b_stack);
		}
		pa(b_stack, b_stack);
		len_b--;
	}
	sort_3(b_stack);
}

void	quick_sort(node **a_stack, node **b_stack)
{
	int	len_a;
	int	pivot;

	len_a = ft_lstsize((node *)*a_stack);
	pivot = len_a / 2;
	if (!a_stack || !(*a_stack))
		return ;
	sort_stack_a(a_stack, b_stack, &pivot);
	sort_stack_b(b_stack);
}
