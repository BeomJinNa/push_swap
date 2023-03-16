/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:05:37 by bena              #+#    #+#             */
/*   Updated: 2023/03/16 10:57:51 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array.h"

static int	there_are_duplicates(t_array *array, t_array *index_table);

int	does_exist_same_number(t_array *array, t_array *index_table)
{
	int	i;

	if (index_table->array == NULL)
	{
		free(array->array);
		return (1);
	}
	i = -1;
	while (++i < array->number_of_parameters - 1)
	{
		if (array->array[i] == array->array[i + 1])
			return (there_are_duplicates(array, index_table));
	}
	return (0);
}

static int	there_are_duplicates(t_array *array, t_array *index_table)
{
	free(array->array);
	free(index_table->array);
	return (1);
}
