// Liam May
// li649708
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printGlowworm(int tail, int body, int head, int maxLength, int status);
void count(int *a, int *b, int *length, int *head, int *tail);

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("Invalid input\nMust be entered in the form: maximum length of worm, string for worm to process\n");
		return 0;
	}

  printf("%s\n\n", argv[2]);
  printf("Glowworm appears! Hooray!\n");
	printf("~OG\n");

  // prints the platform with a length equal to argc
	int i;
  int length = atoi(argv[1]);
	for(i=0; i < length; i++)
	{
		printf("=");
	}
  printf("\n\n");

	// processing instructions
	int strLength = strlen(argv[2]);
	// int tail, body, and head tracks where segments are in relation to each other
	// on the platform
	// status 1 = alive, 0 = dead
	int j, tail = 0, body = 1, head = 2, status = 1;
	char instruction;
	for (j=0; j < strLength; j++)
	{
		instruction = (argv[2][j]);
		int a = 0, b = 1, c = 0;
		if (instruction == 'o' || instruction == 'O' || instruction == '@')
		{
			// if Glowworm is not wrapped
			if(head > tail)
			{
				// if Glowworm has reached maximum size, it cannot grow anymore
				if(length % ((head - tail) + 1) == 0)
				{
					printf("Glowworm chills:\n");
				}
				else
				printf("Glowworm grows:\n");
			}
			// if the Glowworm is wrapped
			else
			{
				if((head + 1) == tail)
				{
					printf("Glowworm chills:\n");
				}
				else
				printf("Glowworm grows:\n");
			}
			// counting length of Glowworm
			b = 0;
			if(tail != 0)
			{
				count(&a, &b, &length, &head, &tail);
			}
			else
			{
				count(&a, &b, &length, &head, &tail);
				b++;
			}
			// if Glowworm can grow
			if((b) != length)
			{
				body++;
				head++;
				if(body == length)
				body = 0;
				if(head == length)
				head = 0;
			}
			printGlowworm(tail, body, head, length, status);
		}
		else if (instruction == 's' || instruction == 'S')
		{
			// counting length of Glowworm
			for(a = head; a != tail; a--)
			{
				b++;
				if(a < 0)
				a = length;
			}
			// if Glowworm can shrink
			if((b) != 3)
			{
				printf("Glowworm shrinks:\n");
				body--;
				head--;
				if(body < 0)
				body = (length - 1);
				if(head < 0)
				head = (length - 1);
			}
			else
			{
				printf("Glowworm chills:\n");
			}
			printGlowworm(tail, body, head, length, status);
		}
		else if (instruction == '-' || instruction == '=')
		{
			printf("Glowworm inches forward:\n");
			tail++;
			body++;
			head++;
			if(tail == length)
			tail = 0;
			if(body == length)
			body = 0;
			if(head == length)
			head = 0;
			printGlowworm(tail, body, head, length, status);
		}
		else if (instruction == 'x' || instruction == 'X' || instruction == '%')
		{
			printf("Glowworm meets its demise. SAD.\n");
			j = strLength;
			status = 0;
			printGlowworm(tail, body, head, length, status);
		}
		else
		{
			printf("Glowworm chills:\n");
			printGlowworm(tail, body, head, length, status);
		}
	}

  return 0;
}

void printGlowworm(int tail, int body, int head, int maxLength, int status)
{
	int j, k;
	// if Glowworm is not wrapped
	if(head > tail)
	{
		// printing tail
		if(tail == 0)
		{
			printf("~");
		}
		else
		{
			for(k=0; k < tail; k++)
			{
				printf(" ");
			}
			printf("~");
		}
		// printing segments
		for(j=(tail + 1); j < body; j++)
		{
			printf("o");
		}
		if(status != 0)
		{
			printf("OG\n");
		}
		else
		{
			printf("Xx\n");
		}
  }
	else
	{
		// if exclusively head has been wrapped
		if(head < body)
		{
			if(status != 0)
			{
				printf("G");
			}
			else
			{
				printf("x");
			}
			for(k=head; k < (tail-1); k++)
			{
				printf(" ");
			}
			printf("~");
			// printing segments
			for(j=(tail + 1); j < body; j++)
			{
				printf("o");
			}
			if(status != 0)
			{
				printf("O\n");
			}
			else
			{
				printf("X\n");
			}
		}
		else
		{
			// if head and body have been wrapped
			if(body != 0)
			{
				for(j=0; j < (body); j++)
				{
					printf("o");
				}
			}
			if(status != 0)
			{
				printf("OG");
			}
			else
			{
				printf("Xx");
			}
			for(k=head; k < (tail-1); k++)
			{
				printf(" ");
			}
			printf("~");
			// printing segments
			for(j=(tail + 1); j < maxLength; j++)
			{
				printf("o");
			}
			printf("\n");
		}
	}

	// printing platform
	int i;
	for(i=0; i < maxLength; i++)
	{
		printf("=");
	}
  printf("\n\n");
}

void count(int *a, int *b, int *length, int *head, int *tail)
{
	for(*a = *head; *a != *tail; *a--)
	{
		*b++;
		if(*a < 0)
			*a = (*length);
	}
	return;
}
