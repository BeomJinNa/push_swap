/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_there_anything_to_overcome.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 09:24:58 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 10:52:49 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

int	are_there_any_larger_number(t_status *stat, int pivot, int block)
{
	t_elem	*ptr;

	if (stat->b->gate == (void *)0)
		return (0);
	ptr = stat->b->gate;
	while (1)
	{
		if (ptr->value < block)
			return (0);
		if (ptr->value > pivot)
			return (1);
		if (ptr->next == stat->b->gate)
			break ;
		ptr = ptr->next;
	}
	return (0);
}

int	are_there_any_smaller_number(t_status *stat, int pivot, int block)
{
	t_elem	*ptr;

	if (stat->b->gate == (void *)0)
		return (0);
	ptr = stat->b->gate->before;
	while (1)
	{
		if (ptr->value < block)
			return (0);
		if (ptr->value < pivot)
			return (1);
		if (ptr->before == stat->b->gate->before)
			break ;
		ptr = ptr->before;
	}
	return (0);
}

int	are_there_any_blocks(t_status *stat, int block)
{
	t_elem	*ptr;

	if (stat->b->gate == (void *)0)
		return (0);
	ptr = stat->b->gate;
	if (ptr->value < block)
		return (1);
	while (ptr->next != stat->b->gate)
	{
		ptr = ptr->next;
		if (ptr->value < block)
			return (1);
	}
	return (0);
}

void	put_over_largers(t_status *stat, int pivot, int block)
{
	if (are_there_any_blocks(stat, block))
		while (are_there_any_larger_number(stat, pivot, block))
			do_rb(stat);
	do_pb(stat);
}

void	put_over_smallers(t_status *stat, int pivot, int block)
{
	if (are_there_any_blocks(stat, block))
		while (are_there_any_smaller_number(stat, pivot, block))
			do_rrb(stat);
	do_pb(stat);
}
