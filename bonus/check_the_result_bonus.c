/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_the_result_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:54:12 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 07:19:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"
#include "s_array_bonus.h"
#include "s_stack_bonus.h"

void			do_action(t_status *stat, char *buffer);
t_stack			*init_stack(t_array *array);
t_stack			*release_stack(t_stack *stack);
char			get_value_of_action(char *action);
int				is_array_sorted(t_status *stat);
static t_status	*get_status(t_array *array);
static int		is_input_error(char *input);
static int		quit_checking_with_error(t_status *stat, char *buffer);
static void		release_status(t_status *stat);

int	check_result(t_array *array)
{
	char		*buffer;
	int			output;
	t_status	*stat;

	stat = get_status(array);
	if (stat == NULL)
		return (-1);
	buffer = get_next_line(0);
	while (buffer != NULL)
	{
		if (is_input_error(buffer))
			return (quit_checking_with_error(stat, buffer));
		do_action(stat, buffer);
		free(buffer);
		buffer = get_next_line(0);
	}
	if (is_array_sorted(stat))
		output = 1;
	else
		output = 0;
	release_status(stat);
	return (output);
}

static t_status	*get_status(t_array *array)
{
	t_status	*output;

	output = (t_status *)malloc(sizeof(t_status));
	if (output == NULL)
		return (NULL);
	output->a = init_stack(array);
	if (output->a == NULL)
	{
		free(output);
		return (NULL);
	}
	output->b = init_stack(NULL);
	if (output->b == NULL)
	{
		free(output);
		release_stack(output->a);
		return (NULL);
	}
	return (output);
}

static int	is_input_error(char *input)
{
	if (get_value_of_action(input) == 0)
		return (1);
	return (0);
}

static int	quit_checking_with_error(t_status *stat, char *buffer)
{
	release_status(stat);
	free(buffer);
	return (-1);
}

static void	release_status(t_status *stat)
{
	release_stack(stat->a);
	release_stack(stat->b);
	free(stat);
}
