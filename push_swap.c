/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:44:56 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/29 12:36:43 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "libft/libft.h"

void	main_ps(char **tmp, t_stack *stack)
{
	int		i;

	i = -1;
	stack->size_a = ft_ps_strlen(tmp);
	if (stack->size_a < 1)
		ft_error(stack);
	stack->a = malloc (sizeof(int) * stack->size_a);
	if (!stack->a)
		ft_error(stack);
	stack->b = malloc (sizeof(int) * stack->size_a);
	if (!stack->b)
		ft_error(stack);
	while (tmp[++i])
	{
		stack->ptr = ft_strtrim(tmp[i], " ");
		stack->a[i] = ft_ps_atoi(stack->ptr, stack, 0, 0);
		free (stack->ptr);
	}
	stack->ptr = NULL;
	ft_check_repeat(stack, stack->size_a);
	ft_sort(stack, stack->size_a);
	free(stack->a);
	free(stack->b);
}

void	init_data(t_stack *stack)
{
	stack->a = NULL;
	stack->b = NULL;
	stack->tmp = NULL;
	stack->ptr = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
}

int	main(int arc, char **arv)
{
	t_stack	stack;

	arv++;
	if (arc == 1)
		return (0);
	init_data(&stack);
	if (arc == 2)
	{
		stack.tmp = ft_split(*arv, ' ');
		if (!stack.tmp)
			ft_error(&stack);
		main_ps(stack.tmp, &stack);
		ft_free(stack.tmp);
	}
	else
		main_ps(arv, &stack);
}
