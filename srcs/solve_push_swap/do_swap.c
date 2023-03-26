/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 05:25:40 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 05:30:56 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "m_rules.h"

void	put_answer(t_status *stat, char answer);
void	swap(t_stack *stack);

void	do_sa(t_status *stat)
{
	swap(stat->a);
	put_answer(stat, SA);
}

void	do_sb(t_status *stat)
{
	swap(stat->b);
	put_answer(stat, SB);
}

void	do_ss(t_status *stat)
{
	swap(stat->a);
	swap(stat->b);
	put_answer(stat, SS);
}
