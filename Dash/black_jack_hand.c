int 	black_jack_hand(char *mn)
{
	int i = -1;
	int tp = -1;
	int as = 0;

	while (mn[++i] != '\0')
	{
		if (mn[i] == 'A')
			as++;
	}

	i = 0;

	while (mn[++tp] != '\0')
	{
		if (mn[tp] == '2')
			i += 2;
		else if (mn[tp] == '3')
			i += 3;
		else if (mn[tp] == '4')
			i += 4;
		else if (mn[tp] == '5')
			i += 5;
		else if (mn[tp] == '6')
			i += 6;
		else if (mn[tp] == '7')
			i += 7;
		else if (mn[tp] == '8')
			i += 8;
		else if (mn[tp] == '9')
			i += 9;
		else if (mn[tp] == 'T')
			i += 10;
		else if (mn[tp] == 'J')
			i += 10;
		else if (mn[tp] == 'D')
			i += 10;
		else if (mn[tp] == 'K')
			i += 10;
	}

	if (as == 1 && i <= 10)
		i += 11;
	else if (as == 1 && i > 10)
		i += 1;
	else if (as == 2 && i <= 9)
		i += 12;
	else if (as == 2 && i > 9)
		i += 2;
	else if (as == 3 && i <= 8)
		i += 13;
	else if (as == 3 && i > 8)
		i += 3;
	else if (as == 4 && i <= 7)
		i += 14;
	else if (as == 4 && i > 7)
		i += 4;

	return (i);
}
