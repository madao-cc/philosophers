#include "philo.h"

int	main(int argc, char **argv)
{
	t_sim	table;

	if (argc == 5 || argc == 6)
	{
		ft_check_arguments(&table, argv); //TODO: Translate the arguments and check if they are valid
		ft_init(&table); //TODO: Initialize the structures.
		if (ft_create_threads(&table) == 1) // This means that something went wrong while creating the threads
			ft_nuke_all(&table); //! Check if this is the right way to handle this
		if (ft_joint_threads(&table) == 1) // This means that something went wrong while joining the threads
			ft_nuke_all(&table); //! Check if this is the right way to handle this
		ft_nuke_all(&table);
		return (0);
	}
	else
		ft_error_exit("Error\n Your arguments just don't make sense!\n");
}
