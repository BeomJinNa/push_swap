/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_residual_elems.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 06:16:02 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 07:38:13 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

static void	sort_two(t_status *stat);
static void	sort_three(t_status *stat);
static int	do_these_have_inverted_order(int first, int second, int third);
static int	get_the_min_value_position(int first, int second, int third);

void	sort_residual_elems(t_status *stat)
{
	if (stat->residual_elems == 2)
		sort_two(stat);
	if (stat->residual_elems == 3)
		sort_three(stat);
}

static void	sort_two(t_status *stat)
{
	int	first;
	int	second;

	first = stat->a->gate->value;
	second = stat->a->gate->next->value;
	if (first > second)
		do_sa(stat);
}

static void	sort_three(t_status *stat)
{
	int	first;
	int	second;
	int	third;
	int	min_address;

	first = stat->a->gate->value;
	second = stat->a->gate->next->value;
	third = stat->a->gate->next->next->value;
	if (do_these_have_inverted_order(first, second, third))
		do_sa(stat);
	first = stat->a->gate->value;
	second = stat->a->gate->next->value;
	min_address = get_the_min_value_position(first, second, third);
	if (min_address == 1)
		do_ra(stat);
	if (min_address == 2)
		do_rra(stat);
}

static int	do_these_have_inverted_order(int first, int second, int third)
{
	int	count;

	count = 0;
	if (second > first)
		count++;
	if (third > second)
		count++;
	if (first > third)
		count++;
	if (count == 1)
		return (1);
	return (0);
}

static int	get_the_min_value_position(int first, int second, int third)
{
	int	min;

	min = first;
	if (min > second)
		min = second;
	if (min > third)
		min = third;
	if (min == first)
		return (0);
	if (min == second)
		return (1);
	return (2);
}
