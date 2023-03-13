/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/03/13 11:06:58 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_input.h"
#include "s_array.h"

void		get_input_data_ps(t_input *memory, int ac, char **av);
void		get_array_from_input(t_array *array, t_input *input);
int			does_exist_same_number(t_array *array);
static int	terminate_current_program(int output);

int	main(int ac, char **av)
{
	t_input	input;
	t_array	array;

	if (ac == 1)
		return (terminate_current_program(0));
	get_input_data_ps(&input, ac, av);
	if (input.input == NULL)
		return (terminate_current_program(0));
	get_array_from_input(&array, &input);
	free(input.input);
	if (array.array == NULL)
		return (terminate_current_program(0));
	sort_array(&array);
	if (does_exist_same_number(&array))
		return (terminate_current_program(0));
	return (0);
}

static int	terminate_current_program(int output)
{
	write(2, "Error\n", 6);
	return (output);
}
