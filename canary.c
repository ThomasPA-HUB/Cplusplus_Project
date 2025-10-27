#include <stdio.h>
#include <stdint.h>
#include <time.h>
#include <stdlib.h>

//Exemple of protected Buffer Overflown
int main()
{
	int x = 0x12345678;
	unsigned char*p = (unsigned char*)&x;

	printf("x = 0x%X\n",x);
	
	for(int i = 0; i < sizeof(x); x++)
	{
		printf("octet[%d] = 0x%X\n",i, p[i]);
	}
	

	srand(time(NULL));
	long random_number = random();
	uint32_t message;
	long canary = random_number;
	char holy_string[] = "HOLY";

	scanf("%s", (char *) &message);

	if (canary != random_number)
	{
		printf("Buffer Overflow Detected!\n");
		exit(-1);
	}
	printf("Input message: %s\n", (char *)&message);
	printf("Canary: %ld\n", canary);
	printf("Holy variable: %s\n", holy_string);
	
}
