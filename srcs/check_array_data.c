/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 10:05:37 by bena              #+#    #+#             */
/*   Updated: 2023/03/13 11:05:41 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "s_array.h"

int	does_exist_same_number(t_array *array)
{
	int	i;

	i = -1;
	while (++i < array->number_of_parameters)
		if (array->array[i] == array->array[i + 1])
			return (there_are_duplicates(array));
	return (0);
}

static int	there_are_duplicates(t_array *array)
{
	free(array->array);
	return (1);
}
