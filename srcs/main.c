/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/03/14 16:39:34 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_input.h"
#include "s_array.h"

void		get_input_data(t_input *memory, int ac, char **av);
void		get_array_from_input(t_array *array, t_input *input);
int			does_exist_same_number(t_array *array, t_array *index_table);
void		get_index_table(t_array *index_table, t_array *array);
static int	terminate_current_program(int output);

int	main(int ac, char **av)
{
	t_input	input;
	t_array	array;
	t_array index_table;

	if (ac == 1)
		return (terminate_current_program(0));
	get_input_data(&input, ac, av);
	if (input.input == NULL)
		return (terminate_current_program(0));
	get_array_from_input(&array, &input);
	free(input.input);
	if (array.array == NULL)
		return (terminate_current_program(0));
	get_index_table(&index_table, &array);
	if (does_exist_same_number(&array, &index_table))
		return (terminate_current_program(0));
	int i = -1;
	while (++i < array.number_of_parameters)
		ft_printf("%d\n", index_table.array[i]);
	free(array.array);
	free(index_table.array);
	return (0);
}

static int	terminate_current_program(int output)
{
	write(2, "Error\n", 6);
	return (output);
}
