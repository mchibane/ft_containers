#include "tests.hpp"
#include <ctime>
#include <cstdlib>

int	main(int ac, char **av)
{
	int	seed = 42;
	if (ac > 1)
		seed = atoi(av[1]);
	srand(seed);
	std::cout << "SEED : " << seed << std::endl << std::endl;
	ft_map::constructors();
	ft_map::assignation();
	ft_map::iterators();
	ft_map::elem_acces();
	ft_map::ins_erase();
	ft_map::map_swap();
	ft_map::map_find_count();
	ft_map::bounds_range();


	ft_vector::copy_contruct();
	ft_vector::assignation();
	ft_vector::iterators();
	ft_vector::capacity();
	ft_vector::elem_access();
	ft_vector::assign();
	ft_vector::push_pop();
	ft_vector::ins_erase();
	ft_vector::vector_swap();

	ft_set::construct();
	ft_set::assignation();
	ft_set::iterators();
	ft_set::ins_erase();
	ft_set::set_swap();
	ft_set::set_find_count();

	ft_stack::constructor();
	ft_stack::push_pop();

	return (0);
}
