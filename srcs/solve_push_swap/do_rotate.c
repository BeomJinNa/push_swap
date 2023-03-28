/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 07:14:29 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "m_rules.h"

void	put_answer(t_status *stat, char answer);
void	rotate(t_stack *stack);

void	do_ra(t_status *stat)
{
	rotate(stat->a);
	put_answer(stat, FRA);
}

void	do_rb(t_status *stat)
{
	rotate(stat->b);
	put_answer(stat, FRB);
}

void	do_rr(t_status *stat)
{
	rotate(stat->a);
	rotate(stat->b);
	put_answer(stat, FRR);
}
