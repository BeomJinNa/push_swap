/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:54:04 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"
#include "m_rules_bonus.h"

void	push(t_stack *from, t_stack *to);

void	do_pa(t_status *stat)
{
	push(stat->b, stat->a);
}

void	do_pb(t_status *stat)
{
	push(stat->a, stat->b);
}
