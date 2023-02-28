/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bena <bena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 12:43:45 by bena              #+#    #+#             */
/*   Updated: 2023/02/28 17:32:16 by bena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "s_input.h"

void		get_input_data_ps(t_input *memory, int ac, char **av);
static int	terminate_current_program(int output);

int	main(int ac, char **av)
{
	t_input	input;

	if (ac == 1)
		return (terminate_current_program(0));
	get_input_data_ps(&input, ac, av);
	if (input.input == NULL)
		return (terminate_current_program(0));
	ft_printf("SUCCESS!! input parameters has been read as\n%s", input.input);
	free(input.input);
	return (0);
}

static int	terminate_current_program(int output)
{
	write(2, "Error\n", 6);
	return (output);
}
