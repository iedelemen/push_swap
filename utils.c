/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:44:56 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/29 12:21:22 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error(t_stack *stack)
{
	if (stack->tmp)
		ft_free(stack->tmp);
	if (stack->a != NULL)
		free(stack->a);
	if (stack->b != NULL)
		free(stack->b);
	if (stack->ptr != NULL)
		free(stack->ptr);
	write(2, "Error\n", 6);
	exit(-1);
}

int	ft_ps_atoi(char *str, t_stack *stack, int i, unsigned long int k)
{
	int	m;

	m = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		m *= -1;
	if ((str[i] == '-' || str[i] == '+') && !(str[++i] >= '0' && str[i] <= '9'))
		ft_error(stack);
	if (str[i] == 0)
		ft_error(stack);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			ft_error(stack);
		k = (str[i++] - 48) + (k * 10);
	}
	if ((k > 2147483647 && m == 1) || (k > 2147483648 && m == -1))
		ft_error(stack);
	return (k * m);
}

void	ft_check_repeat(t_stack *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				ft_error (stack);
			j++;
		}
		i++;
	}
}

int	ft_ps_strlen(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
