/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:08:32 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 07:21:53 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "m_rules.h"

void	print_answer(char *answer_sheet)
{
	while (*answer_sheet)
	{
		if (*answer_sheet == SA)
			write(1, "sa\n", 3);
		else if (*answer_sheet == SB)
			write(1, "sb\n", 3);
		else if (*answer_sheet == SS)
			write(1, "ss\n", 3);
		else if (*answer_sheet == PA)
			write(1, "pa\n", 3);
		else if (*answer_sheet == PB)
			write(1, "pb\n", 3);
		else if (*answer_sheet == FRA)
			write(1, "ra\n", 3);
		else if (*answer_sheet == FRB)
			write(1, "rb\n", 3);
		else if (*answer_sheet == FRR)
			write(1, "rr\n", 3);
		else if (*answer_sheet == RRA)
			write(1, "rra\n", 4);
		else if (*answer_sheet == RRB)
			write(1, "rrb\n", 4);
		else if (*answer_sheet == RRR)
			write(1, "rrr\n", 4);
		answer_sheet++;
	}
}
