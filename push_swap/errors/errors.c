/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsteiger <dsteiger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:59:56 by dsteiger          #+#    #+#             */
/*   Updated: 2024/11/15 19:21:15 by dsteiger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	basic_errors(char *str)
{
	if (!str || *str == '\0')
		return (1);
	if (!((*str >= '0' && *str <= '9') || *str == '+' || *str == '-'))
		return (1);
	if ((*str == '+' || *str == '-') && (*(str + 1) < '0' || *(str + 1) > '9'))
		return (1);
	if (*str == '+' || *str == '-')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int	has_duplicates(node *stack)
{
	node	*current;
	node	*temp;

	current = stack;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				return (1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
