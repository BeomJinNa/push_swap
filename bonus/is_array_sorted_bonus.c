/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_array_sorted_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 05:08:21 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:52:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"

int	is_array_sorted(t_status *stat)
{
	t_elem	*ptr;

	if (stat->b->gate != (void *)0)
		return (0);
	ptr = stat->a->gate;
	while (ptr->next != stat->a->gate)
	{
		if (ptr->value > ptr->next->value)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
