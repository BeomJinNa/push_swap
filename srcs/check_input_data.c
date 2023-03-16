/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:10:42 by bena              #+#    #+#             */
/*   Updated: 2023/03/16 12:04:28 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "s_input.h"

int			is_this_wrong_character(int c);
int			is_this_space(int c);
int			is_this_sign(int c);
static int	is_there_wrong_character(t_input *memory);
static int	is_there_bad_position_of_sign(t_input *memory);
static int	check_the_bad_sign(const char **ptr);
static int	does_any_overflow_occur(t_input *memory);

int	does_input_error_exist(t_input *memory)
{
	if (memory->number_of_parameters == 0)
		return (1);
	if (is_there_wrong_character(memory))
		return (1);
	if (is_there_bad_position_of_sign(memory))
		return (1);
	if (does_any_overflow_occur(memory))
		return (1);
	return (0);
}

static int	is_there_wrong_character(t_input *memory)
{
	const char	*ptr;

	ptr = memory->input;
	while (*ptr)
		if (is_this_wrong_character(*ptr++))
			return (1);
	return (0);
}

static int	is_there_bad_position_of_sign(t_input *memory)
{
	const char	*ptr;

	ptr = memory->input;
	while (is_this_space(*ptr))
		ptr++;
	while (*ptr)
	{
		if (check_the_bad_sign(&ptr))
			return (1);
		while (is_this_space(*ptr))
			ptr++;
	}
	return (0);
}

static int	check_the_bad_sign(const char **ptr)
{
	int	sign_stack;

	sign_stack = 0;
	while (is_this_sign(**ptr))
	{
		sign_stack++;
		*ptr += 1;
	}
	if (sign_stack > 1 || ft_isdigit(**ptr) == 0)
		return (1);
	while (**ptr && is_this_space(**ptr) == 0)
	{
		if (is_this_sign(**ptr))
			return (1);
		*ptr += 1;
	}
	return (0);
}

static int	does_any_overflow_occur(t_input *memory)
{
	int			count_digits;
	const char	*ptr;

	ptr = memory->input;
	while (*ptr)
	{
		count_digits = 0;
		while (*ptr && (is_this_sign(*ptr) || is_this_space(*ptr)))
			ptr++;
		while (ft_isdigit(*ptr))
		{
			count_digits++;
			ptr++;
			if (count_digits > 10)
				return (1);
		}
	}
	return (0);
}
