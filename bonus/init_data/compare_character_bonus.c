/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_character_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:42 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:58:50 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_this_wrong_character(int c)
{
	if (c == 32 || (9 <= c && c <= 13) || ('0' <= c && c <= '9')
		|| c == '+' || c == '-')
		return (0);
	return (1);
}

int	is_this_space(int c)
{
	return (c == 32 || (9 <= c && c <= 13));
}

int	is_this_sign(int c)
{
	return (c == '+' || c == '-');
}