/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:21:37 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/13 16:03:24 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(int *stack)
{
	if ((stack[0] < stack[1]) && (stack[1] > stack[2]) && (stack[0] < stack[2])) // 1, 3, 2
	{
		rra(stack);
		sa(stack);
	}
	if ((stack[0] > stack[1]) && (stack[1] < stack[2]) && (stack[0] < stack[2])) // 2, 1, 3
		sa(stack);
	if ((stack[0] < stack[1]) && (stack[1] > stack[2]) && (stack[0] > stack[2])) // 2, 3, 1
		rra(stack);
	if ((stack[0] > stack[1]) && (stack[1] > stack[2]))							 // 3, 2, 1
	{
		ra(stack);
		sa(stack);
	}
	if ((stack[0] > stack[1]) && (stack[1] < stack[2]) && (stack[0] > stack[2])) // 3, 1, 2
		ra(stack);
}