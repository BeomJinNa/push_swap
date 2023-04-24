/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/04/24 17:12:20 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "s_array_bonus.h"

void		initialize_data(t_array *array, int ac, char **av);
int			check_result(t_array *array);
static int	terminate_current_program(int output);

int	main(int ac, char **av)
{
	t_array	array;
	int		result;

	if (ac == 1)
		return (0);
	array.array = NULL;
	initialize_data(&array, ac, av);
	if (array.array == NULL)
		return (terminate_current_program(0));
	result = check_result(&array);
	if (result == -1)
	{
		free(array.array);
		return (terminate_current_program(0));
	}
	if (result == 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(array.array);
	return (0);
}

static int	terminate_current_program(int output)
{
	write(2, "Error\n", 6);
	return (output);
}
