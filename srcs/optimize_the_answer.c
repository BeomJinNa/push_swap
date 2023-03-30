/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_the_answer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 00:42:19 by bena              #+#    #+#             */
/*   Updated: 2023/03/30 11:51:44 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "replace.h"

static void	replace(char *answer_sheet, const char *before, const char *after);
static void	trim_spaces_in_answers(char *answer_sheet);

void	optimize_the_answer(char *answer_sheet)
{
	size_t	pre_optimized_length;

	pre_optimized_length = 0;
	while (ft_strlen(answer_sheet) != pre_optimized_length)
	{
		pre_optimized_length = ft_strlen(answer_sheet);
		replace(answer_sheet, PB_PA, OO);
		replace(answer_sheet, RA_PB_RRA, SA_PB_O);
		replace(answer_sheet, RB_PA_RRB, SB_PA_O);
		replace(answer_sheet, SB_PA_PA_SB, PA_PA_SS_O);
		replace(answer_sheet, SA_PB_PB_SA, PB_PB_SS_O);
	}
}

static void	replace(char *answer_sheet, const char *before, const char *after)
{
	char			*ptr;
	const size_t	len = ft_strlen(answer_sheet);
	const size_t	copy_len = ft_strlen(after);

	ptr = ft_strnstr(answer_sheet, before, len);
	while (ptr != NULL)
	{
		ft_memcpy(ptr, after, copy_len);
		ptr = ft_strnstr(answer_sheet, before, len);
	}
	trim_spaces_in_answers(answer_sheet);
}

static void	trim_spaces_in_answers(char *answer_sheet)
{
	char	*give;
	char	*take;

	give = answer_sheet;
	take = answer_sheet;
	while (*give)
	{
		if (*take == ' ' && *give != ' ')
		{
			*take = *give;
			*give = ' ';
		}
		give++;
		if (*take != ' ')
			take++;
	}
	*take = '\0';
}
