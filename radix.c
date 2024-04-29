/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 12:01:52 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/29 11:27:19 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	get_next_min_index(int *stack, int size, int *visited)
{
	int	min_index;
	int	min_value;
	int	i;

	min_index = -1;
	min_value = 0;
	i = 0;
	while (i < size)
	{
		if (!visited[i] && (min_index == -1 || stack[i] < min_value))
		{
			min_index = i;
			min_value = stack[i];
		}
		i++;
	}
	return (min_index);
}

void	index_stack(int *stack, int size, t_stack *s)
{
	int	*visited;
	int	index;
	int	min_index;

	index = 0;
	visited = ft_calloc(size, sizeof(int));
	if (!visited)
		ft_error(s);
	min_index = get_next_min_index(stack, size, visited);
	while (min_index != -1)
	{
		stack[min_index] = index++;
		visited[min_index] = 1;
		min_index = get_next_min_index(stack, size, visited);
	}
	free(visited);
}

int	get_max_bits(t_stack *stack)
{
	int	i;
	int	max_bits;
	int	max;

	max = stack->a[0];
	i = 1;
	while (i < stack->size_a)
	{
		if (stack->a[i] > max)
			max = stack->a[i];
		i++;
	}
	max_bits = 0;
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort_b(t_stack *stack, int i)
{
	int	j;
	int	size;

	size = stack->size_b;
	j = 0;
	while (j < size)
	{
		if (((stack->b[0] >> i) & 1) == 1)
			pa(stack);
		else
			rb(stack);
		j++;
	}
}

void	radix_sort(t_stack *stack)
{
	int	i;
	int	j;
	int	max_bits;
	int	size;

	max_bits = get_max_bits(stack);
	i = -1;
	while (++i < max_bits && ft_checked_sorted(stack->a, stack->size_a) == 0)
	{
		size = stack->size_a;
		j = -1;
		while (++j < size && ft_checked_sorted(stack->a, stack->size_a) == 0)
		{
			if (((stack->a[0] >> i) & 1) == 1)
				ra(stack);
			else
				pb(stack);
		}
		if (i + 1 <= max_bits)
			radix_sort_b(stack, i + 1);
	}
	while (stack->size_b > 0)
		pa(stack);
}
