/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:44:56 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/29 12:53:11 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(int *array, int size)
{
	int	i;
	int	min;

	i = 1;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}

int	ft_checked_sorted(int *stack_a, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (stack_a[i - 1] > stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sort(t_stack *stack, int size)
{
	if (ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		if (size == 2)
			sa(stack);
		else if (size == 3)
			ft_sort_three(stack);
		else if (size == 4)
			ft_sort_four(stack);
		else if (size == 5)
			ft_sort_five(stack);
		else
		{
			index_stack(stack->a, stack->size_a, stack);
			radix_sort(stack);
		}
	}
	return (0);
}
