#include "comput.h"

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

int 	is_variable(char *str, int i)
{
	if (str[i] == 'X' || str[i] == 'Y' || str[i] == 'Z')
	{
		printf("VARIABLE = [%c], index = [%d]\n", str[i], i);
		return (VARIABLE);
	}
	return (FAILURE);
}

int 	is_what(char *str, int i)
{
	int 	ret;

	if ((ret = is_variable(str, i)) != FAILURE)
		;
	else if ((ret = is_number(str, i)) != FAILURE)
		;
	else if ((ret = is_operator(str, i)) != FAILURE)
		;
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

int 	pass_space(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\0')
		i++;
	return (i);
}

int 	analyse(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		i = pass_space(str, i);
		if ((is_what(str, i)) == FAILURE)
			print_error(str, i);
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