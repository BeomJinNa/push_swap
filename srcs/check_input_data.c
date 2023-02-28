/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:42 by bena              #+#    #+#             */
/*   Updated: 2023/02/28 17:45:54 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_input.h"
#include <stdlib.h>

int			is_this_wrong_character_ps(int c);
int			is_this_space_ps(int c);
int			is_this_sign_ps(int c);
int			ft_isdigit(int c);
static int	is_there_wrong_character(t_input *memory);
static int	is_there_bad_position_of_sign(t_input *memory);
static int	check_the_bad_sign(const char **ptr);

int	does_input_error_exist_ps(t_input *memory)
{
	if (memory->number_of_parameters == 0)
		return (1);
	if (is_there_wrong_character(memory))
		return (1);
	if (is_there_bad_position_of_sign(memory))
		return (1);
	return (0);
}

static int	is_there_wrong_character(t_input *memory)
{
	char	*str;
	char	*ptr;

	str = memory->input;
	ptr = str;
	while (*ptr)
		if (is_this_wrong_character_ps(*ptr++))
			return (1);
	return (0);
}

static int	is_there_bad_position_of_sign(t_input *memory)
{
	const char	*str;
	const char	*ptr;

	str = memory->input;
	ptr = str;
	while (is_this_space_ps(*ptr))
		ptr++;
	while (*ptr)
	{
		if (check_the_bad_sign(&ptr))
			return (1);
		while (is_this_space_ps(*ptr))
			ptr++;
	}
	return (0);
}

static int	check_the_bad_sign(const char **ptr)
{
	int	sign_stack;

	sign_stack = 0;
	while (is_this_sign_ps(**ptr))
	{
		sign_stack++;
		*ptr += 1;
	}
	if (sign_stack > 1 || ft_isdigit(**ptr) == 0)
		return (1);
	while (**ptr && is_this_space_ps(**ptr) == 0)
	{
		if (is_this_sign_ps(**ptr))
			return (1);
		*ptr += 1;
	}
	return (0);
}
