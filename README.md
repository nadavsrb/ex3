# ex3 - Cache Manager
**Authors -** [nadavsrb](https://github.com/nadavsrb) & [tseela](https://github.com/tseela)
## About the project
Our project is a mini-program that supports 7 operations using a cache manager that we created.
# Structure
We support 4 different kinds of operations:

1. `Matrices` - multiply matrices & add two matrices.
2. `Bmp files` - rotate an image in 90 degrees & convert an image to grayscale.
3. `Hash algorithem` - [crc32 algorithem](https://en.wikipedia.org/wiki/Cyclic_redundancy_check#CRC-32_algorithm).
4. `Cache operations` - search operation in cache & clear cache.

All of the files in `branch master` were taken from [nadav's last project](https://github.com/RoyTamir/ex2). These files are suitable of making the matrices operation (after minor changes) and the bmp files operations.

In addition we added the `crc32` module from the helpful files that were given to us in order to complete the assigment. We added a `crc32FileReader` module that uses crc32 algorithm on files.
# Cache Manager
For our cache, we created two modules- an object module that symbolizes one operation in the cache and another module that responsible about the file handling in the cache.
## How does it work?
For each run of the program, we will be asked to do an operation. Each operation will be saved in two ways:
- a line in the cache file
- a file of the result inside the cache files directory
## Cache file format
Our cache file format is:

**\<operation code> <result's hash code>,<date>|<cache backup file's name>**
- operation code - a number by the folowing struct:
```
typedef enum {
    MATRIX_MULT = 0,
    MATRIX_ADD = 1,
    IMAGE_ROTATE = 2,
    IMAGE_CONVERT = 3,
    HASH_CRC32 = 4,
    CLEAR = 5,
    SEARCH = 6
} CacheOperationCode;
```
- result's hash code - the crc32 hash of the result string
- date
- cache backup file's name - the names of the backup files are counting numbers (starting with 0) like `3.txt` or `99.bmp`.

When searching an operation we will search it's code and hash. If we find it on the cache file we will copy the backup file's content to the operation's result file and update the line's date instead of adding the cache a new line and making the calculations again.

This way, the cache reduces the program's running time and its' complexity.


## HERE ARE SOME SONGS FOR YOU MICHAEL:
[Two is better than one - Boys Likes Girls ft. Taylor Swift](https://www.youtube.com/watch?v=4mE3ETiMXrE)

[Fun - Selena Gomez](https://www.youtube.com/watch?v=ze3XnfkDlAE&list=PLenjelHCUmvFaRzwNu4_irQ1CsmJupPIy&index=20) | Although we hate her...

[God is a woman - Ariana Grande](https://www.youtube.com/watch?v=kHLHSlExFis) | cause tseela is **the god**