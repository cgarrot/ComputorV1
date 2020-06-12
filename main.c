#include "comput.h"

int 	pass_space(char *str, int i, int index)
{
	if (strlen(str) <= i)
		return (i - 1);
	if (index == 1)
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
			i++;
	else if (i > -1)
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		{
			i--;
			if (i == 0)
				return (i);
		}
	return (i);
}

int 	is_operator(char *str, int i)
{
	if (str[i] == '=' || str[i] == '+' || str[i] == '-' || str[i] == '^' || str[i] == '*')
	{
		printf("OPERATOR = [%c], index = [%d]\n", str[i], i);
		return (OPERATOR);
	}
	return (FAILURE);
}

int 	is_number(char *str, int i)
{
	if (str[i] >= '0' && str[i] <= '9')
	{
		printf("NUMBER = [%c], index = [%d]\n", str[i], i);
		return (NUMBER);
	}
	return (FAILURE);
}

int 	check_variable(char *str, int i, t_lex *lex)
{
	int 	j;

	j = pass_space(str, i - 1, 2);
	if ((is_operator(str, j) == OPERATOR) && str[j] != '^')
	{
		j = pass_space(str, i + 1, 1);
		if (str[j] == '^')
		{
			j = pass_space(str, j + 1, 1);
			if (str[j] >= '0' && str[j] <= '2')
			{
				j = pass_space(str, j + 1, 1);
				if (str[j + 1] == '\0' || ((is_operator(str, j) == OPERATOR) && str[j] != '^'))
					lex->compt = j;
				else
					return (FAILURE);
			}
			else
				return (FAILURE);
		}
		else
			return (FAILURE);
	}
	else
		return (FAILURE);
	return (SUCCESS);
}

int 	is_variable(char *str, int i)
{
	if (str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
	{
		printf("VARIABLE = [%c], index = [%d]\n", str[i], i);
		return (VARIABLE);
	}
	return (FAILURE);
}

int 	is_what(char *str, int i, t_lex *lex)
{
	int 	ret;

	if ((ret = is_variable(str, i)) != FAILURE)
		if ((ret = check_variable(str, i, lex)) != FAILURE)
			return (SUCCESS);
	if ((ret = is_number(str, i)) != FAILURE)
		return (SUCCESS);
	if ((ret = is_operator(str, i)) != FAILURE)
		return (SUCCESS);
	return (ret);
}

void 	print_error(char *str, int i)
{
	printf("%s\n", str);
	printf("%*s\n", i + 1, "^");
	if (i > 14)
		printf("%*s\n", i + 1, "error syntax _|");
	else
		printf("%*s%s\n", i, "","|_ error syntax");

}

int 	analyse(char *str)
{
	t_lex	lex;
	int i;

	i = -1;
	while (str[++i])
	{
		i = pass_space(str, i, 1);
		lex.compt = i;
		if ((is_what(str, i, &lex)) == FAILURE)
			print_error(str, i);
		i = lex.compt;
	}
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		printf("./computor \"polynome\"\n");
		return (FAILURE);
	}
	if (analyse(av[1]) == SUCCESS)
	{
		return (FAILURE);
	}
	return (SUCCESS);
}