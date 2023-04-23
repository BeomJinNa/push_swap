/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:42:19 by bena              #+#    #+#             */
/*   Updated: 2023/04/23 21:43:48 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "m_rules.h"

static void	merge_f(char *ptr, char *mark, int *phase);
static void	merge_r(char *ptr, char *mark, int *phase);

void	merge_rr(char *ptr)
{
	int		phase;
	char	*mark;

	phase = 0;
	while (*ptr)
	{
		if (*ptr == FRB && phase == 1)
			phase = 2;
		else if (*ptr == FRA && phase == -1)
			phase = -2;
		if (*ptr != FRR && (phase == 1 || phase == -1))
			phase = 0;
		if (phase == 0 && (*ptr == FRA || *ptr == FRB))
			mark = ptr;
		if (phase == 0 && *ptr == FRA)
			phase = 1;
		else if (phase == 0 && *ptr == FRB)
			phase = -1;
		if (phase == 2 || phase == -2)
			merge_f(ptr, mark, &phase);
		ptr++;
	}
}

void	merge_rrr(char *ptr)
{
	int		phase;
	char	*mark;

	phase = 0;
	while (*ptr)
	{
		if (*ptr == RRB && phase == 1)
			phase = 2;
		else if (*ptr == RRA && phase == -1)
			phase = -2;
		if (*ptr != RRR && (phase == 1 || phase == -1))
			phase = 0;
		if (phase == 0 && (*ptr == RRA || *ptr == RRB))
			mark = ptr;
		if (phase == 0 && *ptr == RRA)
			phase = 1;
		else if (phase == 0 && *ptr == RRB)
			phase = -1;
		if (phase == 2 || phase == -2)
			merge_r(ptr, mark, &phase);
		ptr++;
	}
}

static void	merge_f(char *ptr, char *mark, int *phase)
{
	*mark = FRR;
	*ptr = ' ';
	*phase = 0;
}

static void	merge_r(char *ptr, char *mark, int *phase)
{
	*mark = RRR;
	*ptr = ' ';
	*phase = 0;
}
