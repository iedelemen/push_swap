/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:10:43 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/26 16:25:29 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index(int *array, int size)
{
	int	i;
	int	index;
	int	min;

	i = 0;
	min = array[0];
	while (i < size)
	{
		if (array[i] < min)
		{
			min = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	ra_or_rra(t_stack *s)
{
	int	k;

	k = find_index(s->a, s->size_a);
	if (k > 3)
		rra(s);
	else
		ra(s);
}

void	ft_sort_three(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		sa(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		rra(s);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ra(s);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		sa(s);
		ra(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		rra(s);
}

void	ft_sort_four(t_stack *s)
{
	int	min;

	min = find_min(s->a, s->size_a);
	while (s->size_a > 3)
	{
		if (s->a[0] == min)
			pb(s);
		else
			ra(s);
	}
	ft_sort_three(s);
	while (s->size_b)
		pa(s);
}

void	ft_sort_five(t_stack *s)
{
	int	min;

	min = find_min(s->a, s->size_a);
	while (s->size_a > 4)
	{
		if (s->a[0] == min)
			pb(s);
		else
			ra_or_rra(s);
	}
	min = find_min(s->a, s->size_a);
	while (s->size_a > 3)
	{
		if (s->a[0] == min)
			pb(s);
		else
			ra_or_rra(s);
	}
	ft_sort_three(s);
	while (s->size_b)
		pa(s);
}
