/***************************************************************
File_IO.h
FILE operations
***************************************************************/
#ifndef __FILE_IO_H__
#define __FILE_IO_H__

#include <stdio.h>

/* write to file one by one char */
int readfile(const char * filename, char * buffer);

/* read from  file count chars per time */
unsigned int readfile_s(const char * filename, char * buffer, unsigned int count, char **p_pictures);

/* read from file one by one char */
int writefile(const char * filename, char * buffer);

/* write to file count chars per time */
int writefile_s(const char * filename, char * buffer, unsigned int count);

#endif //__FILE_IO_H__

