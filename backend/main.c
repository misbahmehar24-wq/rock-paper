#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

static const char *choice_name(int choice)
{
    switch (choice)
    {
        case 1:
            return "Rock";
        case 2:
            return "Paper";
        case 3:
            return "Scissors";
        default:
            return "Invalid";
    }
}

static int read_line(const char *prompt, char *line, size_t size)
{
    size_t length;

    fputs(prompt, stdout);
    if (fgets(line, (int)size, stdin) == NULL)
    {
        return 0;
    }

    length = strlen(line);
    if (length > 0 && line[length - 1] == '\n')
    {
        line[length - 1] = '\0';
    }
    else if (!feof(stdin))
    {
        int character;

        while ((character = getchar()) != '\n' && character != EOF)
        {
        }
        return -1;
    }

    return 1;
}

static int read_choice(int *choice)
{
    char line[128];
    char *end;
    long value;
    int status;

    for (;;)
    {
        status = read_line("Enter choice (1-3): ", line, sizeof(line));
        if (status == 0)
        {
            return 0;
        }
        if (status < 0)
        {
            puts("Input is too long. Please enter 1, 2, or 3.");
            continue;
        }

        errno = 0;
        value = strtol(line, &end, 10);
        while (isspace((unsigned char)*end))
        {
            end++;
        }

        if (line == end || errno == ERANGE || *end != '\0' ||
            value < 1 || value > 3)
        {
            puts("Invalid choice. Please enter 1, 2, or 3.");
            continue;
        }

        *choice = (int)value;
        return 1;
    }
}

static int read_play_again(void)
{
    char line[128];
    char *answer;
    int status;

    for (;;)
    {
        status = read_line("Do you want to play again? (y/n): ", line, sizeof(line));
        if (status == 0)
        {
            return 0;
        }
        if (status < 0)
        {
            puts("Input is too long. Please enter y or n.");
            continue;
        }

        answer = line;
        while (isspace((unsigned char)*answer))
        {
            answer++;
        }

        if (answer[0] != '\0')
        {
            char choice = (char)tolower((unsigned char)answer[0]);
            answer++;
            while (isspace((unsigned char)*answer))
            {
                answer++;
            }

            if (*answer == '\0' && (choice == 'y' || choice == 'n'))
            {
                return choice == 'y';
            }
        }

        puts("Invalid input. Please enter y or n.");
    }
}

int main(void)
{
    int user_choice;

    srand((unsigned int)time(NULL));

    puts("=================================");
    puts("     ROCK PAPER SCISSORS GAME    ");
    puts("=================================");

    for (;;)
    {
        int computer_choice;

        puts("\nChoose your move:");
        puts("1. Rock");
        puts("2. Paper");
        puts("3. Scissors");

        if (!read_choice(&user_choice))
        {
            break;
        }

        computer_choice = (rand() % 3) + 1;
        printf("\nYou chose: %s\n", choice_name(user_choice));
        printf("Computer chose: %s\n", choice_name(computer_choice));

        if (user_choice == computer_choice)
        {
            puts("Result: It's a draw!");
        }
        else if ((user_choice == 1 && computer_choice == 3) ||
                 (user_choice == 2 && computer_choice == 1) ||
                 (user_choice == 3 && computer_choice == 2))
        {
            puts("Result: You win!");
        }
        else
        {
            puts("Result: Computer wins!");
        }

        if (!read_play_again())
        {
            break;
        }
    }

    puts("\nThank you for playing!");
    return 0;
}
