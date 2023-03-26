/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_answer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 03:56:20 by bena              #+#    #+#             */
/*   Updated: 2023/03/29 04:29:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_stack.h"

static void	extend_sheet_size(t_status *stat);

void	put_answer(t_status *stat, char answer)
{
	if (stat->answer.sheet == NULL)
		return ;
	if (stat->answer.ptr - stat->answer.sheet == stat->answer.size - 1)
		extend_sheet_size(stat);
	if (stat->answer.sheet == NULL)
		return ;
	stat->answer.ptr++ = answer;
}

static void	extend_sheet_size(t_status *stat)
{
	char	*new_sheet;
	char	*from;
	char	*to;
	int		size;

	new_sheet = (char *)malloc(sizeof(char) * stat->answer.size * 2);
	if (new_sheet == NULL)
	{
		free(stat->answer.sheet);
		stat->answer.sheet = NULL;
		stat->answer.ptr = NULL;
	}
	size = stat->answer.ptr - stat->answer.sheet;
	from = stat->sheet;
	to = new_sheet;
	stat->answer.ptr = to + size;
	while (size-- > 0)
		*to++ = *from++;
	free(stat->answer.sheet);
	stat->answer.sheet = new_sheet;
}
