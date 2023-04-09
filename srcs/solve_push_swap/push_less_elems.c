/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_less_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:46:53 by bena              #+#    #+#             */
/*   Updated: 2023/04/09 23:12:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

void		divide_chunk(t_status *stat, int number_of_elems_to_divide);
static int	search_the_distance_in_forward(t_status *stat, int max_value);
static int	search_the_distance_in_backward(t_status *stat, int max_value);
static void	push_forward(t_status *stat, int distance, int max, int min);
static void	push_backward(t_status *stat, int distance, int max, int min);

void	push_less_elems(t_status *stat, int number_of_elems_to_push)
{
	int	min_value;
	int	max_value;
	int	forward_distance;
	int	backward_distance;
	int	mid_index;

	if (number_of_elems_to_push == 0)
		return ;
	min_value = stat->number_of_elems - stat->residual_elems;
	max_value = min_value + (number_of_elems_to_push - 1);
	mid_index = (int)(number_of_elems_to_push / 2);
	while (--number_of_elems_to_push >= 0)
	{
		forward_distance = search_the_distance_in_forward(stat, max_value);
		backward_distance = search_the_distance_in_backward(stat, max_value);
		if (forward_distance < backward_distance + 1)
			push_forward(stat, forward_distance, max_value, min_value);
		else
			push_backward(stat, backward_distance, max_value, min_value);
	}
	divide_chunk(stat, max_value - min_value + 1 - mid_index);
	while (--mid_index >= 0)
		do_rrb(stat);
	divide_chunk(stat, (int)((max_value - min_value + 1) / 2));
}

static int	search_the_distance_in_forward(t_status *stat, int max_value)
{
	int		distance;
	t_elem	*gate;
	t_elem	*ptr;

	distance = 0;
	gate = stat->a->gate;
	ptr = gate;
	if (ptr->value <= max_value)
		return (distance);
	while (ptr->next != gate)
	{
		ptr = ptr->next;
		distance++;
		if (ptr->value <= max_value)
			return (distance);
	}
	return (distance);
}

static int	search_the_distance_in_backward(t_status *stat, int max_value)
{
	int		distance;
	t_elem	*gate;
	t_elem	*ptr;

	distance = 0;
	gate = stat->a->gate;
	ptr = gate;
	if (ptr->value <= max_value)
		return (distance);
	while (ptr->before != gate)
	{
		ptr = ptr->before;
		distance++;
		if (ptr->value <= max_value)
			return (distance);
	}
	return (distance);
}

static void	push_forward(t_status *stat, int distance, int max, int min)
{
	const int	mid = (int)((min + max) / 2);

	while (distance > 0)
	{
		if (stat->b->gate != (void *)0 && stat->b->gate->value > mid)
			do_rr(stat);
		else
			do_ra(stat);
		distance--;
	}
	do_pb(stat);
	if (stat->b->gate->value > mid)
		do_rb(stat);
}

static void	push_backward(t_status *stat, int distance, int max, int min)
{
	const int	mid = (int)((min + max) / 2);

	while (distance > 0)
	{
		do_rra(stat);
		distance--;
	}
	do_pb(stat);
	if (stat->b->gate != (void *)0 && stat->b->gate->value > mid)
		do_rb(stat);
}
