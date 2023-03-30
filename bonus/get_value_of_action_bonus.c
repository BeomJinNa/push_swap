/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value_of_action_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 03:36:31 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 07:25:06 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "m_rules_bonus.h"

static char	action_in_case_of_two(char *action);
static char	action_in_case_of_three(char *action);

char	get_value_of_action(char *action)
{
	const size_t	len = ft_strlen(action);

	if (len == 3)
		return (action_in_case_of_two(action));
	if (len == 4)
		return (action_in_case_of_three(action));
	return (0);
}

static char	action_in_case_of_two(char *action)
{
	if (ft_memcmp(action, "pa\n", 3) == 0)
		return (PA);
	else if (ft_memcmp(action, "pb\n", 3) == 0)
		return (PB);
	else if (ft_memcmp(action, "sa\n", 3) == 0)
		return (SA);
	else if (ft_memcmp(action, "sb\n", 3) == 0)
		return (SB);
	else if (ft_memcmp(action, "ss\n", 3) == 0)
		return (SS);
	else if (ft_memcmp(action, "ra\n", 3) == 0)
		return (FRA);
	else if (ft_memcmp(action, "rb\n", 3) == 0)
		return (FRB);
	else if (ft_memcmp(action, "rr\n", 3) == 0)
		return (FRR);
	return (0);
}

static char	action_in_case_of_three(char *action)
{
	if (ft_memcmp(action, "rra\n", 4) == 0)
		return (RRA);
	else if (ft_memcmp(action, "rrb\n", 4) == 0)
		return (RRB);
	else if (ft_memcmp(action, "rrr\n", 4) == 0)
		return (RRR);
	return (0);
}
