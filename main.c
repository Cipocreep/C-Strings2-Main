#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
char 	*ft_strncat(char *dest, char *src, unsigned int nb);
char 	*ft_strstr(char *str, char *to_find);
int		ft_atoi(char *str);

void	test_ex0(char* (*testex)(char*, char*))
{
	char source[] = "Bonsoir messieurs dames";
	char source2[] = "Au revoir messieurs dames";
    char destination[30];
	char ft_destination[30];
	char *malloced_destination;
	char *ft_malloced_destination;

	malloced_destination = malloc(30);
	ft_malloced_destination = malloc(30);

	printf("Testing without memory allocation;\n");

    testex(ft_destination, source);
	strcpy(destination, source);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_destination);
	printf("Destination string with the real strcpy: %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);

	printf("\nTesting with memory allocation;\n");

    testex(ft_malloced_destination, source);
	strcpy(malloced_destination, source);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strcpy: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting overwritting string;\n");

    testex(ft_malloced_destination, source2);
	strcpy(malloced_destination, source2);
	printf("Second source string: %s\n", source2);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strcpy: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	free(malloced_destination);
	free(ft_malloced_destination);
}

void	test_ex1(char* (*testex)(char*, char*, unsigned int))
{
	char source[] = "Bonsoir messieurs dames";
	char source2[] = "Au revoir messieurs dames";
	char source3[] = "Bye";
    char destination[30];
	char ft_destination[30];
	char *malloced_destination;
	char *ft_malloced_destination;

	malloced_destination = malloc(40);
	ft_malloced_destination = malloc(40);

	printf("Testing without memory allocation;\n");

    testex(ft_destination, source, 24);
	strncpy(destination, source, 24);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: (24 bytes) %s\n", ft_destination);
	printf("Destination string with the real strncpy: (24 bytes) %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);

	printf("\nTesting with memory allocation;\n");

    testex(ft_malloced_destination, source, 24);
	strncpy(malloced_destination, source, 24);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: (24 bytes) %s\n", ft_malloced_destination);
	printf("Destination string with the real strncpy: (24 bytes) %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting overwritting string;\n");

    testex(ft_malloced_destination, source2, 14);
	strncpy(malloced_destination, source2, 14);
	printf("Second source string: %s\n", source2);
    printf("Destination string with our function: (14 bytes) %s\n", ft_malloced_destination);
	printf("Destination string with the real strncpy: (14 bytes) %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting overwritting string with null bytes ('\\0');\n");

    testex(ft_malloced_destination, source3, 24);
	strncpy(malloced_destination, source3, 24);
	printf("Third source string: %s\n", source3);
    printf("Destination string with our function: (24 bytes and terminators made visible)\n");
	for (int i = 0; i < 24; i++)
	{
        if (ft_malloced_destination[i] == '\0')
            printf("[\\0]");
		else
            printf("%c", ft_malloced_destination[i]);
    }
	printf("\nDestination string with the real strncpy: (24 bytes and terminators made visible)\n");
	for (int i = 0; i < 24; i++)
	{
        if (malloced_destination[i] == '\0')
            printf("[\\0]");
		else
            printf("%c", malloced_destination[i]);
	}

	for (int i = 0; i < 24; i++)
	{
		assert(ft_malloced_destination[i] == malloced_destination[i]);
	}

	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	free(malloced_destination);
	free(ft_malloced_destination);
}


void	test_ex2(int (*testex)(char *, char *))
{
	printf("Note that the standard only guarantees that the result should be positive, negative, or 0\n depending on the comparison between s1 and s2, not that we should have a value \nprecisely corresponding to the difference between the two ascii values.\n\n");

	printf("Testing with ft_strcmp('ABC', 'ABC'), the result should be %i, and our result is %i\n", strcmp("ABC", "ABC"), testex("ABC", "ABC"));
	assert(testex("ABC", "ABC") == 0);

	printf("Testing with ft_strcmp('ABC', 'AB'), the result should be %i, and our result is %i\n", strcmp("ABC", "AB"), testex("ABC", "AB"));
	assert(testex("ABC", "AB") > 0);

	printf("Testing with ft_strcmp('ABA', 'ABZ'), the result should be %i, and our result is %i\n", strcmp("ABA", "ABZ"), testex("ABA", "ABZ"));
	assert(testex("ABA", "ABZ") < 0);

	printf("Testing with ft_strcmp('\\201', 'A'), the result should be %i, and our result is %i\n", strcmp("\201", "A"), testex("\201", "A"));
	assert(testex("\201", "A") > 0);
}

void	test_ex3(int (*testex)(char *, char *, unsigned int))
{
	printf("Note that the standard only guarantees that the result should be positive, negative, or 0\n depending on the comparison between s1 and s2, not that we should have a result \nprecisely corresponding to the difference between the two ascii values.\n\n");

	printf("Testing with ft_strcmp('ABC', 'ABC', 2), the result should be %i, and our result is %i\n", strncmp("ABC", "ABC", 2), testex("ABC", "ABC", 2));
	assert(testex("ABC", "ABC", 2) == 0);

	printf("Testing with ft_strcmp('ABC', 'AB', 2), the result should be %i, and our result is %i\n", strncmp("ABC", "AB", 2), testex("ABC", "AB", 2));
	assert(testex("ABC", "AB", 2) == 0);

	printf("Testing with ft_strcmp('ABA', 'ABZ', 2), the result should be %i, and our result is %i\n", strncmp("ABA", "ABZ", 2), testex("ABA", "ABZ", 2));
	assert(testex("ABA", "ABZ", 2) == 0);

	printf("Testing with ft_strcmp('\\201', 'A', 2), the result should be %i, and our result is %i\n", strncmp("\201B", "AB", 2), testex("\201B", "AB", 2));
	assert(testex("\201B", "AB", 2) > 0);

	printf("Testing with ft_strcmp('AAA', 'ZZZ', 0), the result should be %i, and our result is %i\n", strncmp("AAA", "ZZZ", 0), testex("AAA", "ZZZ", 0));
	assert(testex("AAA", "ZZZ", 0) == 0);

	printf("Testing with ft_strcmp('', '', 6), the result should be %i, and our result is %i\n", strncmp("", "", 6), testex("", "", 0));
	assert(testex("", "", 6) == 0);
}

void	test_ex4(char* (*testex)(char*, char*))
{
	char source[] = "Bonsoir messieurs dames";
	char source2[] = "Au revoir messieurs dames";
    char destination[60];
	char ft_destination[60];
	char *malloced_destination;
	char *ft_malloced_destination;

	destination[0] = '\0';
	ft_destination[0] = '\0';

	malloced_destination = malloc(60);
	ft_malloced_destination = malloc(60);

	malloced_destination[0] = '\0';
	ft_malloced_destination[0] = '\0';

	printf("Testing without memory allocation, empty destination;\n");

    testex(ft_destination, source);
	strcat(destination, source);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_destination);
	printf("Destination string with the real strcat: %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);

	printf("\nTesting without memory allocation, destination with a string in it;\n");

    testex(ft_destination, source2);
	strcat(destination, source2);
	printf("Source string: %s\n", source2);
    printf("Destination string with our function: %s\n", ft_destination);
	printf("Destination string with the real strcat: %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);


	printf("\nTesting with memory allocation, empty destination;\n");

    testex(ft_malloced_destination, source);
	strcat(malloced_destination, source);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strcat: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting with memory allocation, destination with a string in it;\n");

    testex(ft_malloced_destination, source2);
	strcat(malloced_destination, source2);
	printf("Source string: %s\n", source2);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strcat: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);


	free(malloced_destination);
	free(ft_malloced_destination);
}

void	test_ex5(char *(*testex)(char*, char*, unsigned int))
{
	char source[] = "Bonsoir messieurs dames\0";
	char source2[] = "Au revoir messieurs dames\0";
    char destination[60];
	char ft_destination[60];
	char *malloced_destination;
	char *ft_malloced_destination;

	destination[0] = '\0';
	ft_destination[0] = '\0';

	malloced_destination = malloc(100);
	ft_malloced_destination = malloc(100);

	malloced_destination[0] = '\0';
	ft_malloced_destination[0] = '\0';

	printf("Testing without memory allocation, empty destination, 15 bytes;\n");

    testex(ft_destination, source, 15);
	strncat(destination, source, 15);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_destination);
	printf("Destination string with the real strncat: %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);

	printf("\nTesting without memory allocation, destination with a string in it, 15 bytes;\n");

    testex(ft_destination, source2, 15);
	strncat(destination, source2, 15);
	printf("Source string: %s\n", source2);
    printf("Destination string with our function: %s\n", ft_destination);
	printf("Destination string with the real strncat: %s\n", destination);
	assert(strcmp(ft_destination, destination) == 0);


	printf("\nTesting with memory allocation, empty destination, 15 bytes;\n");

    testex(ft_malloced_destination, source, 15);
	strncat(malloced_destination, source, 15);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strncat: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting with memory allocation, destination with a string in it, 15 bytes;\n");

    testex(ft_malloced_destination, source2, 15);
	strncat(malloced_destination, source2, 15);
	printf("Source string: %s\n", source2);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strncat: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);

	printf("\nTesting if strncat stops correctly if it reaches end of source string, 100 bytes;\n");

    testex(ft_malloced_destination, "let's finish this", 100);
	strncat(malloced_destination, "let's finish this", 100);
	printf("Source string: %s\n", source);
    printf("Destination string with our function: %s\n", ft_malloced_destination);
	printf("Destination string with the real strncat: %s\n", malloced_destination);
	assert(strcmp(ft_malloced_destination, malloced_destination) == 0);


	free(malloced_destination);
	free(ft_malloced_destination);
}


void	test_ex6(char* (*testex)(char*, char*))
{
	char haystack1[] = "Bonsoir messieurs dames";
	char needle1[] = "sieur";
    char destination[60];
	char ft_destination[60];

	destination[0] = '\0';
	ft_destination[0] = '\0';

	printf("\nTesting finding the needle;\n\n");    
	
	printf("Haysack: %s\n", haystack1);
	printf("Needle: %s\n", needle1);
    printf("Pointer to the start of the location of the needle with our function: %s\n", testex(haystack1, needle1));
	printf("Pointer to the start of the location of the needle with the real strstr: %s\n", strstr(haystack1, needle1));
	assert(testex(haystack1, needle1) == strstr(haystack1, needle1));

	printf("\nTesting not finding the needle;\n\n");    
	
	printf("Haysack: %s\n", haystack1);
	printf("Needle: %s\n", "houba houba");
    printf("Pointer to the start of the location of the needle with our function: %s\n", testex(haystack1, "houba houba"));
	printf("Pointer to the start of the location of the needle with the real strstr: %s\n", strstr(haystack1, "houba houba"));
	assert(testex(haystack1, "houba houba") == strstr(haystack1, "houba houba"));

	printf("\nTesting with an empty needle;\n\n");    
	
	printf("Haysack: %s\n", haystack1);
	printf("Needle: %s\n", destination);
    printf("Pointer to the start of the location of the needle with our function: %s\n", testex(haystack1, destination));
	printf("Pointer to the start of the location of the needle with the real strstr: %s\n", strstr(haystack1, destination));
	assert(testex(haystack1, destination) == strstr(haystack1, destination));

	printf("\nTesting with an empty haytack (I don't think that can count as an haystack);\n\n");    

	printf("Haysack: %s\n", ft_destination);
	printf("Needle: %s\n", needle1);
    printf("Pointer to the start of the location of the needle with our function: %s\n", testex(ft_destination, needle1));
	printf("Pointer to the start of the location of the needle with the real strstr: %s\n", strstr(ft_destination, needle1));
	assert(testex(ft_destination, needle1) == strstr(ft_destination, needle1));

	printf("\nTesting with an empty needle, and an empty haystack (what are we doing here, exactly?);\n\n");    
	
	printf("Haysack: %s\n", destination);
	printf("Needle: %s\n", ft_destination);
    printf("Pointer to the start of the location of the needle with our function: %s\n", testex(destination, ft_destination));
	printf("Pointer to the start of the location of the needle with the real strstr: %s\n", strstr(destination, ft_destination));
	assert(testex(destination, ft_destination) == strstr(destination, ft_destination));

}

void	test_ex7(int (*testex)(char*))
{
	char num_in_ascii0[] = " --+-+1234ab567";
	char num_in_ascii0_special_chars[] = " --+-+1234ab567";

	char num_in_ascii1[] = "		\n		\n \n\n\n++-2202oooe";
	char num_in_ascii1_special_chars[] = "		\\n		\\n \\n\\n\\n++-2202oooe";

	char num_in_ascii2[] = "				\n\n\n\n+++--+2147483647oooe";
	char num_in_ascii2_special_chars[] = "				\\n\\n\\n\\n+++--+2147483647oooe";

	char num_in_ascii3[] = "				\n\n\n\n+-+++--+2147483648oooe";
	char num_in_ascii3_special_chars[] = "				\\n\\n\\n\\n+-+++--+2147483648oooe";

	char num_in_ascii4[] = "	\v \f\n \r\t\v+-+++--+8\vooe";
	char num_in_ascii4_special_chars[] = "	\\v \\f\\n \\r\\t\\v+-+++--+8\\vooe";

	char num_in_ascii5[] = "	\t	\r\t	\v\f	\n\n\n\n++-2147483648893#ooe\r\td";
	char num_in_ascii5_special_chars[] = "	\\t	\\r\\t	\\v\\f	\\n\\n\\n\\n++-2147483648#ooe\\r\\td";


	printf("\nTesting provided exemple;\n\n");
	
	printf("Our number in chars: \"%s\"\n", num_in_ascii0_special_chars);
    printf("Result with our function: %i\n", testex(num_in_ascii0));
	printf("Expected result: -1234\n");
	assert(testex(num_in_ascii0) == -1234);

	printf("\nTesting basic behavior;\n\n");
	
	printf("Our number in chars: \"%s\"\n", num_in_ascii1_special_chars);
    printf("Result with our function: %i\n", testex(num_in_ascii1));
	printf("Expected result: -2202\n");
	assert(testex(num_in_ascii1) == -2202);

	printf("\nTesting max positive int;\n\n");    
	
	printf("Our number in chars: \"%s\"\n", num_in_ascii2_special_chars);
    printf("Result with our function: %i\n", testex(num_in_ascii2));
	printf("Expected result: 2147483647\n");
	assert(testex(num_in_ascii2) == 2147483647);

	printf("\nTesting int positive int;\n\n");
	
	printf("Our number in chars: \"%s\"\n", num_in_ascii3_special_chars);
    printf("Result with our function: %i\n", testex(num_in_ascii3));
	printf("Expected result: -2147483648\n");
	assert(testex(num_in_ascii3) == -2147483648);

	printf("\nTesting all kinds of whitespaces;\n\n");
	
	printf("Our number in chars: \"%s\"\n", num_in_ascii4_special_chars);
    printf("Result with our function: %i\n", testex(num_in_ascii4));
	printf("Expected result: -8\n");
	assert(testex(num_in_ascii4) == -8);

	printf("\nTesting overflowing int for curiosity;\n\n");

	printf("Our number in chars: \"%s\"\n", num_in_ascii5_special_chars);
    printf("Result with our function: %i\n", testex(num_in_ascii5));
	printf("Expected result: undefined, so it can be anything\n");

}

int	main(void)
{
	printf("Ex0: ft_strcpy:\n\n");
	test_ex0(ft_strcpy);
	printf("\nTests Ex0 Passed!\n\n\n\n");

	printf("Ex1: ft_strncpy:\n\n");
	test_ex1(ft_strncpy);
	printf("\nTests Ex1 Passed!\n\n\n\n");

	printf("Ex2: ft_strcmp:\n\n");
	test_ex2(ft_strcmp);
	printf("\nTests Ex2 Passed!\n\n\n\n");

	printf("Ex3: ft_strncmp:\n\n");
	test_ex3(ft_strncmp);
	printf("\nTests Ex3 Passed!\n\n\n\n");

	printf("Ex4: ft_strcat:\n\n");
	test_ex4(ft_strcat);
	printf("\nTests Ex4 Passed!\n\n\n\n");

	printf("Ex5: ft_strncat:\n\n");
	test_ex5(ft_strncat);
	printf("\nTests Ex5 Passed!\n\n\n\n");

	printf("Ex6: ft_strstr:\n\n");
	test_ex6(ft_strstr);
	printf("\nTests Ex6 Passed!\n\n\n\n");

	printf("Ex7: ft_atoi:\n\n");
	test_ex7(ft_atoi);
	printf("\nTests Ex7 Passed!\n\n\n\n");
}
