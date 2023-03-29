/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_less_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:46:04 by bena              #+#    #+#             */
/*   Updated: 2023/03/30 00:09:59 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

static int	search_the_distance_in_forward(t_status *stat, int max_value);
static int	search_the_distance_in_backward(t_status *stat, int max_value);
static void	push_forward(t_status *stat, int distance, int max);
static void	push_backward(t_status *stat, int distance, int max);

void	push_less_elems(t_status *stat, int number_of_elems_to_push)
{
	int	min_value;
	int	max_value;
	int	forward_distance;
	int	backward_distance;

	if (number_of_elems_to_push == 0)
		return ;
	min_value = stat->number_of_elems - stat->residual_elems;
	max_value = min_value + (number_of_elems_to_push - 1);
	forward_distance = search_the_distance_in_forward(stat, max_value);
	backward_distance = search_the_distance_in_backward(stat, max_value);
	if (forward_distance < backward_distance + (number_of_elems_to_push - 1))
		push_forward(stat, forward_distance, max_value);
	else
		push_backward(stat, backward_distance, max_value);
}

static int	search_the_distance_in_forward(t_status *stat, int max_value)
{
	int		distance_record;
	int		distance_current;
	t_elem	*gate;
	t_elem	*ptr;

	distance_record = 0;
	distance_current = 0;
	gate = stat->a->gate;
	ptr = gate;
	while (ptr->next != gate)
	{
		ptr = ptr->next;
		distance_current++;
		if (ptr->value <= max_value)
			distance_record = distance_current;
	}
	return (distance_record);
}

static int	search_the_distance_in_backward(t_status *stat, int max_value)
{
	int		distance_record;
	int		distance_current;
	t_elem	*gate;
	t_elem	*ptr;

	distance_record = 0;
	distance_current = 0;
	gate = stat->a->gate;
	ptr = gate;
	while (ptr->before != gate)
	{
		ptr = ptr->before;
		distance_current++;
		if (ptr->value <= max_value)
			distance_record = distance_current;
	}
	return (distance_record);
}

static void	push_forward(t_status *stat, int distance, int max)
{
	while (distance > 0)
	{
		if (stat->a->gate->value <= max)
			do_pb(stat);
		else
			do_ra(stat);
		distance--;
	}
	if (stat->a->gate->value <= max)
		do_pb(stat);
}

static void	push_backward(t_status *stat, int distance, int max)
{
	while (distance > 0)
	{
		if (stat->a->gate->value <= max)
			do_pb(stat);
		do_rra(stat);
		distance--;
	}
	if (stat->a->gate->value <= max)
		do_pb(stat);
}
