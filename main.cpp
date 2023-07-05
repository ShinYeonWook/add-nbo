#include<stdio.h>

int main(){

	FILE* fp_t;
	FILE* fp_fh
	int a=0;

	fp_t = fopen("t.bin","rb");
	fp_fh = fopen("fh.bin","rb");

	if(fp_t == NULL)
	{
		printf("NO FILE.");
		return 0;
	}

	if(fp_fh == NULL)
	{
		printf("NO FILE.");
	}

	char str[10];
	
	uint32_t r_a = fread(&a, sizeof(int),1,fp_t );
	uint32_t r_b = fread(&b, sizeof(int),1,fp_fh);

	      printf("%d %d",r_a,r_b);

	fclose(fp_t);
	fclose(fp_fh);

}

