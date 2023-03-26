/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 05:33:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "m_rules.h"

void	put_answer(t_status *stat, char answer);
void	r_rotate(t_stack *stack);

void	do_rra(t_status *stat)
{
	r_rotate(stat->a);
	put_answer(stat, RRA);
}

void	do_rrb(t_status *stat)
{
	r_rotate(stat->b);
	put_answer(stat, RRB);
}

void	do_rrr(t_status *stat)
{
	r_rotate(stat->a);
	r_rotate(stat->b);
	put_answer(stat, RRR);
}
