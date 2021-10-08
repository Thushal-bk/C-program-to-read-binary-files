

#include <stdio.h>
#include <stdlib.h>



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

};

typedef struct Random Records;


// Main function
int main(int argc, char **argv){

  	Records  var;  

// Declaring the file pointer
  	FILE *fp;
  	fp = fopen(argv[1], "rb");
  
 
// Stderr if filepointer is NULL
	  if (fp == 0)
	  { 
		  fprintf(stderr, "\n Enter file name, %s file entered\n", argv[1]);
		  exit(1);
	  }



  
/* Read all records until EOF, fread returns NULL or Zero till at EOF, hence we use the return value of fread in the while loop */    
    
	  
 	unsigned int c;
	printf("heart, lizards, crime, pancake, art, brothers, morning, thumb, system, pain, girls, carpenter, scarecrow, driving, produce, flight, increase\n");
    	c = fread(&var.heart, sizeof(var.heart), 1, fp);
    
	
	    while( c != 0)
	    {
		fread(&var.lizards, sizeof(var.lizards), 1, fp);
  		fread(&var.crime, sizeof(var.crime), 1, fp);
  		fread(&var.pancake, sizeof(var.pancake), 1, fp);
  		fread(&var.art, sizeof(var.art), 1, fp);
  		fread(&var.brothers, sizeof(var.brothers), 1, fp);
  		fread(&var.morning, sizeof(var.morning), 1, fp);
  		fread(&var.thumb, sizeof(var.thumb), 1, fp);
  		fread(&var.system, sizeof(var.system), 1, fp);
  		fread(&var.pain, sizeof(var.pain), 1, fp);
  		fread(&var.girls, sizeof(var.girls), 1, fp);
  		fread(&var.carpenter, sizeof(var.carpenter), 1, fp);
  		fread(&var.scarecrow, sizeof(var.scarecrow), 1, fp);
  		fread(&var.driving, sizeof(var.driving), 1, fp);
  		fread(&var.produce, sizeof(var.produce), 1, fp);
  		fread(&var.flight, sizeof(var.flight), 1, fp);
  		fread(&var.increase, sizeof(var.increase), 1, fp);
		printf("%d, %d, %d, %d, %c, %lu, %s, %d, %d, %x, %f, %f, %u, %c, %f, %lu, %d\n", var.heart, var.lizards,var.crime,var.pancake,var.art,var.brothers,var.morning,var.thumb,var.system,
		var.pain,var.girls,var.carpenter,var.scarecrow,var.driving,var.produce,var.flight,var.increase);
		c = fread(&var.heart, sizeof(var.heart), 1, fp);
	    }
	    
  
  	fclose(fp);
  	return 0;

}


