/***************************************************************
	FILE OPERATES
***************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include "string.h"
#include "File_IO.h"

/*
standard version
read a file into buffer

#if 0
int readfile_s(const char * filename ,char * buffer, unsigned int count)
{
	FILE *ptr_file;

	if (filename == NULL) return 1;
	if (buffer == NULL) return 1;

	ptr_file = fopen(filename, "r");
	if (!ptr_file)
		return 1;

	while (fgets(buffer, count, ptr_file) != NULL)
		printf("%s", buffer);

	fclose(ptr_file);
	return 0;
}
#endif
*/
/* write to file one by one char */
int readfile(const char * filename, char * buffer)
{
	FILE *ptr_file;

	if (filename == NULL) return 1;
	if (buffer == NULL) return 1;

	ptr_file = fopen(filename, "r");
	if (!ptr_file)
		return 1;

	while (!feof(ptr_file))
	{
		*buffer = fgetc(ptr_file);
		buffer ++;
	}

	fclose(ptr_file);

	return(0);
}

/* 1. read count chars from a file per time ,
   2. fill line list.
   return: the lines of file quantity */
unsigned int readfile_s(const char * filename,	/* in: file name */
						char * buffer,			/* in: read file buffer */
						unsigned int count,		/* in: read file char count */
						char **p_pictures)		/* out: line list */
{
	FILE *ptr_file;
	unsigned int ret;
	char *word;

	if (filename == NULL) return 1;
	if (buffer == NULL) return 1;
	if (p_pictures == NULL) return 1;

	ret = 0;
	/* Open file for both reading and writing */
	ptr_file = fopen(filename, "r");
	if (!ptr_file)
		return 1;
	
	/* Seek to the beginning of the file */
	fseek(ptr_file, SEEK_SET, 0);

	/* Read data */
	fread(buffer, count + 1, 1, ptr_file);

	/* read lines and fill the linelist */
	char sep[] = "\n";
	for (word = strtok(buffer, sep);
		word != NULL;
		word = strtok(NULL, sep))
	{
		*p_pictures = word;
		//printf("new line : %s\n", *p_pictures);
		p_pictures++;
		/* increase the line quantity */
		ret++;
	}
	/* close file */
	fclose(ptr_file);

	/* return the line quantity */
	return(ret);
}

/* read from file one by one char */
int writefile(const char * filename, char * buffer)
{
	FILE *ptr_file;

	if (filename == NULL) return 1;
	if (buffer == NULL) return 1;

	ptr_file = fopen(filename, "w");
	if (!ptr_file)
		return 1;

	while (*buffer){
		fprintf(ptr_file, "%c\n", *buffer);
		buffer++;
	}

	fclose(ptr_file);
	return  0;
}
/* write to file count chars per time (append style) */
int writefile_s(const char * filename, char * buffer, unsigned int count)
{
	FILE *ptr_file;

	if (filename == NULL) return 1;
	if (buffer == NULL) return 1;

	ptr_file = fopen(filename, "a");
	if (!ptr_file)
		return 1;

	fwrite(buffer, 1, count, ptr_file);

	fclose(ptr_file);
	return  0;
}

