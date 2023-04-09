/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_chunk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 08:46:53 by bena              #+#    #+#             */
/*   Updated: 2023/04/09 23:46:39 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

void		recall_elems(t_status *stat, int min, int pivot);
static int	get_the_min_value(t_status *stat, int number_of_elems_to_divide);
static int	get_the_max_value(t_status *stat, int number_of_elems_to_divide);
static int	search_the_distance_in_forward(t_status *stat, int pivot);
static void	push_forward(t_status *stat, int distance, int max, int min);

void	divide_chunk(t_status *stat, int number_of_elems_to_divide)
{
	int	min_value;
	int	max_value;
	int	pivot;
	int	distance;
	int	count;

	if (number_of_elems_to_divide < 27)
		return ;
	min_value = get_the_min_value(stat, number_of_elems_to_divide);
	max_value = get_the_max_value(stat, number_of_elems_to_divide);
	pivot = max_value - (int)((max_value - min_value) / 3);
	count = pivot - min_value;
	while (--count >= 0)
	{
		distance = search_the_distance_in_forward(stat, pivot);
		push_forward(stat, distance, pivot - 1, min_value);
		number_of_elems_to_divide -= distance + 1;
	}
	while (--number_of_elems_to_divide >= 0)
		do_rb(stat);
	recall_elems(stat, min_value, pivot);
	count = max_value - pivot + 1;
	while (--count >= 0)
		do_rrb(stat);
	divide_chunk(stat, max_value - pivot + 1);
}

static int	get_the_min_value(t_status *stat, int number_of_elems_to_divide)
{
	t_elem	*ptr;
	int		min;

	ptr = stat->b->gate;
	min = ptr->value;
	while (--number_of_elems_to_divide > 0)
	{
		ptr = ptr->next;
		if (min > ptr->value)
			min = ptr->value;
	}
	return (min);
}

static int	get_the_max_value(t_status *stat, int number_of_elems_to_divide)
{
	t_elem	*ptr;
	int		max;

	ptr = stat->b->gate;
	max = ptr->value;
	while (--number_of_elems_to_divide > 0)
	{
		ptr = ptr->next;
		if (max < ptr->value)
			max = ptr->value;
	}
	return (max);
}

static int	search_the_distance_in_forward(t_status *stat, int pivot)
{
	int		distance;
	t_elem	*gate;
	t_elem	*ptr;

	distance = 0;
	gate = stat->b->gate;
	ptr = gate;
	if (ptr->value < pivot)
		return (distance);
	while (ptr->next != gate)
	{
		ptr = ptr->next;
		distance++;
		if (ptr->value < pivot)
			return (distance);
	}
	return (distance);
}

static void	push_forward(t_status *stat, int distance, int max, int min)
{
	const int	mid = (int)((min + max) / 2);
	int			gate;

	while (distance > 0)
	{
		if (stat->a->gate != (void *)0)
			gate = stat->a->gate->value;
		if (stat->a->gate != (void *)0 && max >= gate && gate > mid)
			do_rr(stat);
		else
			do_rb(stat);
		distance--;
	}
	do_pa(stat);
	if (stat->a->gate->value > mid)
		do_ra(stat);
}
