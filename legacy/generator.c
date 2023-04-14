#include <stdio.h>
#include <stdlib.h>

#ifndef M_RULES_H
# define M_RULES_H

# define SA 101
# define SB 102
# define SS 103
# define PA	104
# define PB 105
# define FRA 106
# define FRB 107
# define FRR 108
# define RRA 109
# define RRB 110
# define RRR 111
#endif

int	main(void)
{
	int		index = 0;
	char	*from[1024];
	char	*to[1024];

	from[index] = "PB_PA";
	to[index] = (char []){PB, PA, 0};
	index++;

	from[index] = "PA_PB";
	to[index] = (char []){PA, PB, 0};
	index++;

	from[index] = "RA_RRA";
	to[index] = (char []){FRA, RRA, 0};
	index++;

	from[index] = "RB_RRB";
	to[index] = (char []){FRB, RRB, 0};
	index++;

	from[index] = "RRA_RA";
	to[index] = (char []){RRA, FRA, 0};
	index++;

	from[index] = "RRB_RB";
	to[index] = (char []){RRB, FRB, 0};
	index++;

	from[index] = "OO";
	to[index] = (char []){' ', ' ', 0};
	index++;

	from[index] = "RA_RB";
	to[index] = (char []){FRA, FRB, 0};
	index++;

	from[index] = "RB_RA";
	to[index] = (char []){FRB, FRA, 0};
	index++;

	from[index] = "RR_O";
	to[index] = (char []){FRR, ' ', 0};
	index++;

	from[index] = "RRA_RRB";
	to[index] = (char []){RRA, RRB, 0};
	index++;

	from[index] = "RRB_RRA";
	to[index] = (char []){RRB, RRA, 0};
	index++;

	from[index] = "RRR_O";
	to[index] = (char []){RRR, ' ', 0};
	index++;

	from[index] = "RA_PB_RRA";
	to[index] = (char []){FRA, PB, RRA, 0};
	index++;

	from[index] = "SA_PB_O";
	to[index] = (char []){SA, PB, ' ', 0};
	index++;

	from[index] = "RB_PA_RRB";
	to[index] = (char []){FRB, PA, RRB, 0};
	index++;

	from[index] = "SB_PA_O";
	to[index] = (char []){SB, PA, ' ', 0};
	index++;

	from[index] = "SB_PA_PA_SB";
	to[index] = (char []){SB, PA, PA, SB, 0};
	index++;

	from[index] = "PA_PA_SS_O";
	to[index] = (char []){PA, PA, SS, ' ', 0};
	index++;

	from[index] = "SA_PB_PB_SA";
	to[index] = (char []){SA, PB, PB, SA, 0};
	index++;

	from[index] = "PB_PB_SS_O";
	to[index] = (char []){PB, PB, SS, ' ', 0};
	index++;

	int i = 0;
	while (i < index)
	{
		printf("# define %s \"%s\"\n", from[i], to[i]);
		i++;
	}
}
