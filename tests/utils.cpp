#include "tests.hpp"
#include <string>
#include <iostream>

char	rand_lo(void)
{
	char c = rand() % (122 + 1 - 97) + 97;
	return (c);
}

char	rand_up(void)
{
	char c = rand() % (90 + 1 - 65) + 65;
	return (c);
}

std::string	rand_str_gen(void)
{
	std::string	ret;
	char		c;
	int			r;
	int	str_len = (rand() % 50) + 1;
	for (int i = 0; i < str_len; i++)
	{
		r = rand() % 3;
		if (r % 3 == 0)
			c = rand_lo();
		else if (r % 3 == 1)
			c = rand_up();
		else
			c = 95;
		ret += c;
	}
	return (ret);
}
