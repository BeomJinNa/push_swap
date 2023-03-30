/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:53:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"
#include "m_rules_bonus.h"

void	rotate(t_stack *stack);

void	do_ra(t_status *stat)
{
	rotate(stat->a);
}

void	do_rb(t_status *stat)
{
	rotate(stat->b);
}

void	do_rr(t_status *stat)
{
	rotate(stat->a);
	rotate(stat->b);
}
