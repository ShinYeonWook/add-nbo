#include<stdio.h>
#include<stdint.h>


uint32_t my_n(uint32_t n){
	return (n&0xFF000000) >> 24 | (n&0x00FF0000) >> 8 | (n&0x0000FF00) << 8 | (n&0x000000FF)<<24;
}

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
	
	uint8_t ra = fread(rab, sizeof(uint8_t),4,fpt);
	uint32_t* p = reinterpret_cast<uint32_t*>(rab);
	uint32_t n = my_n(*p);
	printf("%d", n);

	uint8_t rb = fread(rbb, sizeof(int),4,fpfh);
	uint32_t* p2 = reinterpret_cast<uint32_t*>(rbb);
	uint32_t n2 = my_n(*p2);
	printf("%d", n2);


	fclose(fpt);
	fclose(fpfh);

}

