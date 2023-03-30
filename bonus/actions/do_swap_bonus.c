/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:54:17 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"
#include "m_rules_bonus.h"

void	swap(t_stack *stack);

void	do_sa(t_status *stat)
{
	swap(stat->a);
}

void	do_sb(t_status *stat)
{
	swap(stat->b);
}

void	do_ss(t_status *stat)
{
	swap(stat->a);
	swap(stat->b);
}
