/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:44:56 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/26 13:50:23 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	pb(t_stack *stack)
{
	int	index;

	index = 0;
	if (stack->size_a)
	{
		stack->size_b++;
		index = stack->size_b;
		while (--index > 0)
			stack->b[index] = stack->b[index - 1];
		stack->b[0] = stack->a[0];
		index = -1;
		stack->size_a--;
		while (++index < stack->size_a)
			stack->a[index] = stack->a[index + 1];
		write(1, "pb\n", 3);
	}
}

void	rb(t_stack	*stack)
{
	int	tmp;
	int	index;

	index = 0;
	tmp = stack->b[index];
	index++;
	while (index < stack->size_b)
	{
		stack->b[index - 1] = stack->b[index];
		index++;
	}
	stack->b[index - 1] = tmp;
	write(1, "rb\n", 3);
}
