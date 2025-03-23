#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>

int main (int argc, char *argv[])
{

    if (argc == 1)
    {
        printf("Usage: %s -r <range> <value>\n", argv[0]);
        return 1;
    }

    int opt = 0;
    int min_value = 0;
    int max_value = 0;
    int input_value = 0;
    char *range_str = NULL;
    // char *value_str = NULL;

    while ((opt = getopt(argc, argv, "r:h")) != -1)
    {
        switch(opt)
        {
        case 'r':
            range_str = optarg;
            // printf("Argument '-r' detected, value = %s\n", range_str);
            if (strchr(range_str, '-') != NULL)
            {
                char *min_str = strtok(range_str, "-");
                char *max_str = strtok(NULL, "-");
                if (min_str && max_str)
                {
                    // printf("MIN str %s, MAX str %s\n", min_str, max_str);
                    // Convert strings to integers
                    min_value = atoi(min_str);
                    max_value = atoi(max_str);
                    // printf("MIN value %d, MAX valur %d\n", min_value, max_value);
                }
                else
                {
                    printf("Error for range\n");
                    return 1;
                }

            }
            break;
        case 'h':
            printf("Usage: %s -r <range> <value>\n", argv[0]);
            printf("  -r <range>: Specifies a range (e.g., 1-1024).\n");
            printf("  -h: Display this help message.\n");
            return 0;
        default:
            printf("Unknown arg\n");
            return 1;
        }
    }

    // Read the positional argument after '-r'
    if (optind < argc)
    {
        input_value = atoi(argv[optind]);
        // printf("Input value: %d\n", input_value);
        if (min_value <= input_value && input_value <= max_value)
        {
            return 0;
        }
        printf("The value %d is out of the range %d-%d\n", input_value, min_value, max_value);
        return 1;
    }
}
