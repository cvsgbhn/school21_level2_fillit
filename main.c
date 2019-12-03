int     main(int argc, char **argv)
{
	int     count;


	fd = open(argv[1], O_RDONLY);
	while (get_tetrominos(fd))
	{

	}

	return (1);
}
