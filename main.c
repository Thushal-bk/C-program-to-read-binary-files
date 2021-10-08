
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

// Intialized to unsigned int to make it four bytes
typedef unsigned int fourbool;
#define TRUE 1
#define FALSE 0


// Initialized to unsigned char to make it one byte
typedef unsigned char onebool;
#define TRUE 1
#define FALSE 0

// Initialized to unsigned short int to make it two bytes
typedef unsigned short int twbool;
#define TRUE 1
#define FALSE 0


// Intialize number of elements in struct
#define sizeStruct 67

// Defining struct as per specifications
struct Random {

  short int heart;
  twbool lizards;
  onebool crime;
  fourbool pancake;
  char art;
  unsigned long int brothers;
  char morning[9];
  fourbool thumb;
  twbool system;
  int pain;
  double girls;
  float carpenter;
  unsigned int scarecrow;
  char driving;
  float produce;
  unsigned long int flight;
  char  increase;
}var;



/* compare function */


int compareMarks(const void *pa, const void *pb){

	/*cast void pointer to struct*/
	struct Random *const *p1 = pa;
	struct Random *const *p2 = pb;
	
	int diff = ((*p1)->driving > (*p2)->driving) - ((*p1)->driving < (*p2)->driving);
	if(diff == 1 || diff == -1) return diff;	
	
	else diff = ((*p1)->produce > (*p2)->produce) - ((*p1)->produce < (*p2)->produce);
	if(diff == 1 || diff == -1) return diff;	
	
	else diff = ((*p1)->flight < (*p2)->flight) - ((*p1)->flight > (*p2)->flight);
	if(diff == 1 || diff == -1) return diff;	
	

	else diff = ((*p1)->thumb > (*p2)->thumb) - ((*p1)->thumb <  (*p2)->thumb);
	if(diff== 1 || diff == -1) return diff;


	else diff = ((*p1)->pain < (*p2)->pain) - ((*p1)->pain > (*p2)->pain);
	if(diff == 1 || diff == -1) return diff;

	else diff = ((*p1)->art > (*p2)->art) - ((*p1)->art < (*p2)->art);
	if(diff == 1 || diff == -1) return diff;

	else diff = ((*p1)->pancake > (*p2)->pancake) - ((*p1)->pancake < (*p2)->pancake);
	if(diff == 1 || diff == -1) return diff;

	else diff = ((*p1)->lizards < (*p2)->lizards) - ((*p1)->lizards > (*p2)->lizards);
	if(diff == 1 || diff == -1) return diff;

	else diff = ((*p1)->carpenter < (*p2)->carpenter) - ((*p1)->carpenter > (*p2)->carpenter);
	if(diff == 1 || diff == -1) return diff;

	else diff = ((*p1)->girls < (*p2)->girls) - ((*p1)->girls > (*p2)->girls);
        if(diff == 1 || diff == -1) return diff;
	
	else diff = ((*p1)->increase > (*p2)->increase) - ((*p1)->increase < (*p2)->increase);
        if(diff == 1 || diff == -1) return diff;
	
	else diff = ((*p1)->brothers > (*p2)->brothers) - ((*p1)->brothers < (*p2)->brothers);
        if(diff == 1 || diff == -1) return diff;
	
	else diff = strcmp((*p2)->morning, (*p1)->morning);
        if(diff != 0 ) return diff;
	
	else diff = ((*p1)->system < (*p2)->system) - ((*p1)->system > (*p2)->system);
        if(diff == 1 || diff == -1) return diff;
	
	else diff = ((*p1)->crime > (*p2)->crime) - ((*p1)->crime < (*p2)->crime);
        if(diff == 1 || diff == -1) return diff;
	
	
	else diff = ((*p1)->heart < (*p2)->heart) - ((*p1)->heart > (*p2)->heart);
        if(diff == 1 || diff == -1) return diff;
	
	else diff = ((*p1)->scarecrow < (*p2)->scarecrow) - ((*p1)->scarecrow > (*p2)->scarecrow);
        if(diff == 1 || diff == -1) return diff;
	

}




int main(int argc, char **argv){

	struct Random var;
	struct Random *ptr;
	FILE *outfile;
	FILE *fp;

        fp = fopen(argv[1], "rb");


          if (fp == 0)
          {
                  fprintf(stderr, "\n Enter file name, %s file entered\n", argv[1]);
                  exit(1);
	  }

	
	outfile = fopen (argv[2], "wb");
    
	/* error if file is not given as input */
	if (outfile == NULL)
    	{
        	fprintf(stderr, "\nError opend file\n");
       	 	exit (1);
    	}

	
    
    
    
	/* https://stackoverflow.com/questions/238603/how-can-i-get-a-files-size-in-c */
	/* code to check the number of record in input file */
    
    	struct stat st;
	stat(argv[1], &st); 
	int size = st.st_size;
  	int n = size/sizeStruct;
	
	/* dynamic allocation of  an array to store structs for each record read */

    	ptr = (struct Random*)  malloc(n * sizeof(struct Random));
	if(!ptr){

                printf("Dynamic alloc failed!\n");

        }

 	for (int i = 0; i < n; i++){
    		fread( &(ptr+i)->heart, sizeof(short int), 1 , fp);
    		fread( &(ptr+i)->lizards, sizeof(twbool), 1 , fp);
    		fread( &(ptr+i)->crime, sizeof(onebool), 1, fp);
    		fread( &(ptr+i)->pancake, sizeof(fourbool), 1, fp);
                fread( &(ptr+i)->art, sizeof(char), 1, fp);
                fread( &(ptr+i)->brothers, sizeof(unsigned long int), 1, fp);
                fread( &(ptr+i)->morning, sizeof(char * var.morning), 1, fp);
                fread( &(ptr+i)->thumb, sizeof(fourbool), 1, fp);
                fread( &(ptr+i)->system, sizeof(twbool), 1, fp);
                fread( &(ptr+i)->pain, sizeof(int), 1, fp);
                fread( &(ptr+i)->girls, sizeof(double), 1, fp);
                fread( &(ptr+i)->carpenter, sizeof(float), 1, fp);
                fread( &(ptr+i)->scarecrow, sizeof(unsigned int), 1, fp);
                fread( &(ptr+i)->driving, sizeof(char), 1, fp);
                fread( &(ptr+i)->produce, sizeof(float), 1, fp);
                fread( &(ptr+i)->flight, sizeof(unsigned long int), 1, fp);
                fread( &(ptr+i)->increase, sizeof(char), 1, fp);

    	}



	/* dynamic allocation of an array of pointers that point to an array of struct */
    	struct Random **array = malloc(n * sizeof(struct Random));

	if(!array){

                printf("Dynamic alloc failed!\n");

        }


    	for(int i = 0; i < n; i++){
    
	    array[i] = &ptr[i];
    
    	}	
 	
  	/* sorting fucntion */
    	qsort( array, n, sizeof(*array), compareMarks);
    
  
    	for (int i = 0; i < n; i++){
   		fwrite( &(*(array+i))->heart, sizeof(var.heart), 1, outfile);
    		fwrite( &(*(array+i))->lizards, sizeof(var.lizards), 1, outfile);
    		fwrite( &(*(array+i))->crime, sizeof(var.crime), 1, outfile);
    		fwrite( &(*(array+i))->pancake, sizeof(var.pancake), 1, outfile);
              	fwrite( &(*(array+i))->art, sizeof(var.art), 1, outfile);
              	fwrite( &(*(array+i))->brothers, sizeof(var.brothers), 1, outfile);
              	fwrite( &(*(array+i))->morning, sizeof(var.morning), 1, outfile);
              	fwrite( &(*(array+i))->thumb, sizeof(var.thumb), 1, outfile);
              	fwrite( &(*(array+i))->system, sizeof(var.system), 1, outfile);
              	fwrite( &(*(array+i))->pain, sizeof(var.pain), 1, outfile);
              	fwrite( &(*(array+i))->girls, sizeof(var.girls), 1, outfile);
              	fwrite( &(*(array+i))->carpenter, sizeof(var.carpenter), 1, outfile);
              	fwrite( &(*(array+i))->scarecrow, sizeof(var.scarecrow), 1, outfile);
              	fwrite( &(*(array+i))->driving, sizeof(var.driving), 1, outfile);
              	fwrite( &(*(array+i))->produce, sizeof(var.produce), 1, outfile);
              	fwrite( &(*(array+i))->flight, sizeof(var.flight), 1, outfile);
              	fwrite( &(*(array+i))->increase, sizeof(var.increase), 1, outfile);

    	}		

	/* close file descriptors and free memory*/
  	free(ptr); 
  	free(array);
  	fclose(fp);
  	fclose(outfile);
  
   return 0;
}
