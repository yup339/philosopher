/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbergero <pascaloubergeron@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 06:26:34 by pbergero          #+#    #+#             */
/*   Updated: 2023/03/14 15:42:56 by pbergero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_atoi(const char *nptr);
int		is_str_int(char *str);
void	*ft_calloc(size_t count, size_t size);
void	free_double_array(void	**ptr);

#endif
