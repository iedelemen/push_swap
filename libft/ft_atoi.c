/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 15:54:50 by idelemen          #+#    #+#             */
/*   Updated: 2023/12/20 17:14:25 by idelemen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	k;

	i = 0;
	m = 1;
	k = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		m *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] <= '9' && str[i] >= '0')
	{
		k = (str[i] - 48) + (k * 10);
		i++;
	}
	return (k * m);
}
