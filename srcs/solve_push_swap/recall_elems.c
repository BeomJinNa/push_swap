/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recall_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:36:35 by bena              #+#    #+#             */
/*   Updated: 2023/04/09 23:33:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "rules.h"

void	divide_chunk(t_status *stat, int number_of_elems_to_divide);

void	recall_elems(t_status *stat, int min, int pivot)
{
	int	mid_of_pushed_elems;
	int	number_of_least;
	int	number_of_middle;
	int	count;

	mid_of_pushed_elems = (int)((pivot - 1 + min) / 2);
	number_of_least = mid_of_pushed_elems - min + 1;
	number_of_middle = pivot - 1 - mid_of_pushed_elems;
	count = number_of_least;
	while (--count >= 0)
		do_pb(stat);
	divide_chunk(stat, number_of_least);
	count = number_of_middle;
	while (--count >= 0)
		do_rra(stat);
	count = number_of_middle;
	while (--count >= 0)
		do_pb(stat);
	divide_chunk(stat, number_of_middle);
}
