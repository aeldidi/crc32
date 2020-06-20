/*
 *    crc32_test_main.c - sanity test for crc32 function.
 *
 *    Written in 2020 by Ayman El Didi
 *
 *    To the extent possible under law, the author(s) have dedicated all
 *    domain worldwide. This software is distributed without any warranty.
 *
 *    You should have received a copy of the CC0 Public Domain Dedication along
 *    with this software. If not, see
 *    <http://creativecommons.org/publicdomain/zero/1.0/>.
 */
#include <assert.h>
#include <inttypes.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "crc32.h"

int
main(int argc, char **argv)
{
	uint32_t result = 0;
	int      i      = 0;
	clock_t  start, end;
	double   elapsed_time = 0;
	int      num_bytes    = sizeof("hello-world") - 1;
	double   rate         = 0;

	/* sanity checks */
	printf("NOTE: this is simply meant as a sanity test and is not at all "
	       "exaustive.\n");
	printf("======== test 1: \"hello-world\" ========\n");
	result = crc32("hello-world", num_bytes, &result);
	printf("result = %X\n", result);
	printf("zlib's result = B1D4025B\n");
	assert(result == 0xB1D4025B);
	printf("======== test passed ========\n");

	result = 0;
	printf("======== test 2: \"Lorem Ipsum dolor sit amet.\" ========\n");
	result = crc32("Lorem Ipsum dolor sit amet.",
			sizeof("Lorem Ipsum dolor sit amet.") - 1,
			&result);
	printf("result = %X\n", result);
	printf("zlib's result = AF3F6BF80\n");
	assert(result == 0xA3F6BF80);
	printf("======== test passed ========\n");
	printf("All tests passed.\n\n");

	/* performance report */
	printf("======== performance report ========\n");
	printf("crc32ing 'hello-world' 1 000 000 times.\n");
	start = clock();
	for (; i < 1000000; i++) {
		crc32("hello-world", num_bytes, &result);
	}
	end          = clock();
	elapsed_time = (double)(end - start) / (double)CLOCKS_PER_SEC;
	rate         = (num_bytes * 1000000) / elapsed_time;
	printf("Rate: %f Mb/sec\n", rate * pow(10, -6));
	return EXIT_SUCCESS;
}
