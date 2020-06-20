# Simple crc32 implementation in C99

This is a simple crc32 implementation in C99.

The only two files you really need are in `src/`

I have a sanity test in `tests/`, but it was really just for me to quickly check if it worked.
I also have the performance reporting code in there too.
To run the test yourself, simply run `make`, then the `test` exectuable that is built.

## Performance

These tests were performed on an Intel Core 2 Duo E8400 @ 3GHz, running the test
a handful of times, then getting the average results.
The rate is calculated by timing how long it takes to crc32 "hello-world" 1 000 000 times at various optimization levels on gcc.

| Rate (Mb/sec) | Optimization level |
| ------------- | ------------------ |
| 26.252932     | -O0                |
| 62.216239     | -O2                |
| 61.405990     | -Ofast             |

Testing the variant without the branch removed (See crc32.c):

| Rate (Mb/sec) | Optimization level |
| ------------- | ------------------ |
| 20.439034     | -O0                |
| 51.968760     | -O2                |
| 58.866903     | -Ofast             |

## License

    crc32 - calculate crc32 checksums of data

    Written in 2020 by Ayman El Didi

    To the extent possible under law, the author(s) have dedicated all
    domain worldwide. This software is distributed without any warranty.

    You should have received a copy of the CC0 Public Domain Dedication along
    with this software. If not, see http://creativecommons.org/publicdomain/zero/1.0/.
