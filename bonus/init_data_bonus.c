/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:57:05 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_input_bonus.h"
#include "s_array_bonus.h"

void	get_input_data(t_input *memory, int ac, char **av);
void	get_array_from_input(t_array *array, t_input *input);
int		does_exist_same_number(t_array *index_table);
void	get_index_table(t_array *index_table, t_array *array);
void	normalize_the_array(t_array *array, t_array *index_table);

void	initialize_data(t_array *array, int ac, char **av)
{
	t_input	input;
	t_array	index_table;

	get_input_data(&input, ac, av);
	if (input.input == NULL)
		return ;
	get_array_from_input(array, &input);
	free(input.input);
	if (array->array == NULL)
		return ;
	get_index_table(&index_table, array);
	if (does_exist_same_number(&index_table))
	{
		free(array->array);
		array->array = NULL;
		return ;
	}
	normalize_the_array(array, &index_table);
	free(index_table.array);
}
