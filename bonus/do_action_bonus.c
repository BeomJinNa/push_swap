/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 04:58:05 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 06:51:46 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack_bonus.h"
#include "m_rules_bonus.h"
#include "rules_bonus.h"

char	get_value_of_action(char *action);

void	do_action(t_status *stat, char *buffer)
{
	const char	action = get_value_of_action(buffer);

	if (action == PA)
		do_pa(stat);
	else if (action == PB)
		do_pb(stat);
	else if (action == SA)
		do_sa(stat);
	else if (action == SB)
		do_sb(stat);
	else if (action == SS)
		do_ss(stat);
	else if (action == FRA)
		do_ra(stat);
	else if (action == FRB)
		do_rb(stat);
	else if (action == FRR)
		do_rr(stat);
	else if (action == RRA)
		do_rra(stat);
	else if (action == RRB)
		do_rrb(stat);
	else if (action == RRR)
		do_rrr(stat);
}
