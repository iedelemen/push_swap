/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 15:44:56 by idelemen          #+#    #+#             */
/*   Updated: 2024/04/26 16:30:07 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	char	**tmp;
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	char	*ptr;
}	t_stack;

void	index_stack(int *stack, int size, t_stack *s);
void	radix_sort(t_stack *stack);
void	main_ps(char **tmp, t_stack *stack);

void	ft_free(char **str);
void	ft_error(t_stack *stack);
void	ft_check_repeat(t_stack *stack, int size);
int		ft_ps_atoi(char *str, t_stack *stack, int i, unsigned long int k);
int		ft_ps_strlen(char **str);
int		find_min(int *array, int size);

int		ft_checked_sorted(int *stack_a, int size);
int		ft_sort(t_stack *stack, int size);
void	ft_sort_three(t_stack *s);
void	ft_sort_four(t_stack *s);
void	ft_sort_five(t_stack *s);

void	sa(t_stack *stack);
void	rra(t_stack *stack);
void	ra(t_stack *stack);
void	pa(t_stack *stack);

void	pb(t_stack *stack);
void	rb(t_stack	*stack);

#endif
