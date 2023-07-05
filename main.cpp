#include<stdio.h>
#include<stdint.h>
#include<arpa/inet.h>


int main(){

	FILE* fpt, *fpfh;

	uint8_t rab[4];
	uint8_t rbb[4];

	fpt = fopen("t.bin","rb");
	fpfh = fopen("fh.bin","rb");

	if(fpt == NULL)
	{
		printf("NO FILE.");
		return 0;
	}

	if(fpfh == NULL)
	{
		printf("NO FILE.");
	}

	char str[10];
	
	fread(rab, sizeof(uint8_t),4,fpt);
	uint32_t* p = reinterpret_cast<uint32_t*>(rab);
	uint32_t n = htonl(*p);
	printf("%d\n", n);

	fread(rbb, sizeof(int),4,fpfh);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(rbb);
	uint32_t n2 = htonl(*p2);
	printf("%d\n", n2);

	printf("%d + %d = %d",n , n2 ,n+n2);




	fclose(fpt);
	fclose(fpfh);

}

