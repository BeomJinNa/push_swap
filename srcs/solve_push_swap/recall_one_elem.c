/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recall_one_elem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:27:48 by bena              #+#    #+#             */
/*   Updated: 2023/03/30 00:03:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

static int	get_the_forward_distance(t_status *stat, int target);
static int	get_the_backward_distance(t_status *stat, int target);
static void	go_forward(t_status *stat, int target);
static void	go_backward(t_status *stat, int target);

void	recall_one_elem(t_status *stat)
{
	int	target_value;
	int	forward_distance;
	int	backward_distance;

	target_value = stat->number_of_elems - stat->residual_elems - 1;
	forward_distance = get_the_forward_distance(stat, target_value);
	backward_distance = get_the_backward_distance(stat, target_value);
	if (forward_distance < backward_distance)
		go_forward(stat, target_value);
	else
		go_backward(stat, target_value);
}

static int	get_the_forward_distance(t_status *stat, int target)
{
	int		distance;
	t_elem	*ptr;

	ptr = stat->b->gate;
	distance = 0;
	while (ptr->value != target)
	{
		ptr = ptr->next;
		distance++;
	}
	return (distance);
}

static int	get_the_backward_distance(t_status *stat, int target)
{
	int		distance;
	t_elem	*ptr;

	ptr = stat->b->gate;
	distance = 0;
	while (ptr->value != target)
	{
		ptr = ptr->before;
		distance++;
	}
	return (distance);
}

static void	go_forward(t_status *stat, int target)
{
	while (stat->b->gate->value != target)
		do_rb(stat);
	do_pa(stat);
}

static void	go_backward(t_status *stat, int target)
{
	while (stat->b->gate->value != target)
		do_rrb(stat);
	do_pa(stat);
}
