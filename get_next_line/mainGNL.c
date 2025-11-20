int main(void)
{
 	int fd;
 	char *line = NULL;

	fd = open("file.txt", O_RDONLY);
 	while ((line = get_next_line(fd))!= NULL)
 	{
 		printf("%s", line);
 		free(line);
 	}
 	free(line);
 	close(fd);
 	return (0);
}

int main(void)
{
	int fd1;
	int fd2;
	
	char *line1 = NULL;
	char *line2 = NULL;
	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if (line1)
		{
			printf("%s",line1);
			free(line1);
		}
		if (line2)
		{
			printf("%s",line2);
			free(line2);
		}
		if (!line1 && !line2)
			break;
	}
	close(fd1);
	close(fd2);
}
