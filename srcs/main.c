/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/03/16 13:09:10 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "s_array.h"

void		initialize_data(t_array *array, int ac, char **av);
static int	terminate_current_program(int output);

int	main(int ac, char **av)
{
	t_array	array;

	if (ac == 1)
		return (terminate_current_program(0));
	array.array = NULL;
	initialize_data(&array, ac, av);
	if (array.array == NULL)
		return (terminate_current_program(0));
	free(array.array);
	return (0);
}

static int	terminate_current_program(int output)
{
	write(2, "Error\n", 6);
	return (output);
}
