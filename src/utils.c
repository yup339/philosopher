/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 06:24:05 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/15 16:55:12 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	iswhitespace(char c)
{
	if (c == 32 || c == '\f' || c == '\n'
		|| c == '\t' || c == '\v' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	nbr;
	int	i;
	int	sign;

	if (!nptr)
		return (0);
	i = 0;
	nbr = 0;
	sign = 1;
	while (iswhitespace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nbr = (nbr * 10) + (nptr[i] - 48);
		i++;
	}
	return (nbr * sign);
}

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 < *s2)
		return (-1);
	if (*s1 > *s2)
		return (1);
	return (0);
}

int	is_str_int(char *str)
{
	int	len;

	if (!str)
		return (0);
	if (*str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*(++str) != '\0')
		if (!(*str >= '0' && *str <= '9'))
			return (0);
	len = (int)(str - 1 - (str[0] == '-'));
	if (len > 10)
		return (0);
	if (len == 10)
	{
		if (str[0] != '-' && ft_strcmp(str, "2147483647") > 0)
			return (0);
		if (str[0] == '-' && ft_strcmp(str, "-2147483648") > 0)
			return (0);
	}
	return (1);
}

void	free_double_array(void	**ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return ;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
}
