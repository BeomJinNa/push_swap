/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:54:01 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"
#include "m_rules_bonus.h"

void	r_rotate(t_stack *stack);

void	do_rra(t_status *stat)
{
	r_rotate(stat->a);
}

void	do_rrb(t_status *stat)
{
	r_rotate(stat->b);
}

void	do_rrr(t_status *stat)
{
	r_rotate(stat->a);
	r_rotate(stat->b);
}
