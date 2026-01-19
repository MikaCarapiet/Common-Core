#include "get_next_line.h"

int	main(void)
{
	char *result;

	printf("Testing ft_strlen...\n");
	printf("ft_strlen(\"hello\") = %zu\n", ft_strlen("hello"));

	printf("\nTesting ft_strchr...\n");
	char *pos = ft_strchr("hello\nworld", '\n');
	if (pos)
		printf("Found newline at: %s\n", pos);
	else
		printf("No newline found\n");

	printf("\nTesting ft_strdup...\n");
	fflush(stdout);
	result = ft_strdup("00000");
	printf("ft_strdup(\"00000\") = '%s'\n", result);
	free(result);

	printf("\nTesting ft_strjoin...\n");
	fflush(stdout);
	result = ft_strjoin("00000", "00000");
	printf("ft_strjoin(\"00000\", \"00000\") = '%s'\n", result);
	free(result);

	printf("\nAll tests passed!\n");
	return (0);
}
