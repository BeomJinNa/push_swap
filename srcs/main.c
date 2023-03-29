/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/03/30 04:37:52 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "s_array.h"

void		initialize_data(t_array *array, int ac, char **av);
char		*solve_push_swap(t_array *array);
void		print_answer(char *answer_sheet);
static int	terminate_current_program(int output);

int	main(int ac, char **av)
{
	t_array	array;
	char	*answer_sheet;

	if (ac == 1)
		return (terminate_current_program(0));
	array.array = NULL;
	initialize_data(&array, ac, av);
	if (array.array == NULL)
		return (terminate_current_program(0));
	answer_sheet = solve_push_swap(&array);
	if (answer_sheet == NULL)
	{
		free(array.array);
		return (terminate_current_program(0));
	}
//	optimize_the_answer(answer_sheet);
	print_answer(answer_sheet);
	free(answer_sheet);
	free(array.array);
	return (0);
}

static int	terminate_current_program(int output)
{
	write(2, "Error\n", 6);
	return (output);
}
