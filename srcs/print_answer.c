/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 07:08:32 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 10:18:15 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "m_rules.h"

static void	put_answer(char answer);

void	print_answer(char *answer_sheet)
{
	while (*answer_sheet)
	{
		put_answer(*answer_sheet);
		answer_sheet++;
	}
}

static void	put_answer(char answer)
{
	if (answer == SA)
		write(1, "sa\n", 3);
	else if (answer == SB)
		write(1, "sb\n", 3);
	else if (answer == SS)
		write(1, "ss\n", 3);
	else if (answer == PA)
		write(1, "pa\n", 3);
	else if (answer == PB)
		write(1, "pb\n", 3);
	else if (answer == FRA)
		write(1, "ra\n", 3);
	else if (answer == FRB)
		write(1, "rb\n", 3);
	else if (answer == FRR)
		write(1, "rr\n", 3);
	else if (answer == RRA)
		write(1, "rra\n", 4);
	else if (answer == RRB)
		write(1, "rrb\n", 4);
	else if (answer == RRR)
		write(1, "rrr\n", 4);
}
