/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array_data_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:05:37 by bena              #+#    #+#             */
/*   Updated: 2023/03/31 05:58:47 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array_bonus.h"

static int	there_are_duplicates(t_array *index_table);

int	does_exist_same_number(t_array *index_table)
{
	int	i;

	if (index_table->array == NULL)
		return (1);
	i = -1;
	while (++i < index_table->number_of_parameters - 1)
		if (index_table->array[i] == index_table->array[i + 1])
			return (there_are_duplicates(index_table));
	return (0);
}

static int	there_are_duplicates(t_array *index_table)
{
	free(index_table->array);
	return (1);
}
