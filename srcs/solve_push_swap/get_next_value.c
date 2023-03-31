/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 06:08:53 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 08:48:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

int	get_next_value_forward(t_status *stat, int max)
{
	t_elem	*ptr;

	ptr = stat->a->gate;
	while (ptr->value > max)
		ptr = ptr->next;
	return (ptr->value);
}

int	get_next_value_backward(t_status *stat, int max)
{
	t_elem	*ptr;

	ptr = stat->a->gate;
	while (ptr->value > max)
		ptr = ptr->before;
	return (ptr->value);
}
