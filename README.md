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
For our cache, we created two objects: a semi-abstract object (`Operation`) that symbolizes one operation in the cache and another object (`CacheManager`) that responsible of the file handling in the cache.
## How does it work?
For each run of the program, we will be asked to do an operation. Each operation will be saved in two ways:
- a line in the cache file
- a file of the result inside the cache files directory
## Cache file format
Our cache file format is:

**\<operation code> <inputs's hash code>,<date>|<cache backup file's name>**
- operation code - a unique string for every operation which is used to write the operation in the cache file.
- inputs's hash code - the crc32 hash of the input files (if there are more then one they will be divided by spaces).
- date
- cache backup file's name - the names of the backup files are counting numbers (starting with 0) like `3.txt` or `99.bmp`.

When searching an operation we will search it's code and hash. If we find it on the cache file we will copy the backup file of the operation's result file and update the line's date instead of adding the cache a new line and making the calculations again.

This way, the cache reduces the program's running time and its' complexity.

# Operation class
If tou want to add your own operations, you can inherit out `Operation` class and implement out methods:
```cpp
/**
 * @brief Get the type of the output file.
 * 
 * @return string 
 */
string getOutputFileType() const;

/**
 * @brief Get the Cache Code of the object (the begining of the CacheString).
 * 
 * @return string 
 */
string getCacheCode() const;

/**
 * @brief Get the Cache String of the object (what we write on our cache file).
 * 
 * @return string 
 */
string getCacheString() const;

/**
 * @brief Writes the result of the operation.
 * 
 * @param fileName - the name of the file we write to.
 */
void writeToFile(const string& fileName) const;
```
Note that the CacheManager will be able to work with any of your new "sub operations" and still have our search & clear methods.

## HERE ARE SOME SONGS FOR YOU MICHAEL:
[Two is better than one - Boys Likes Girls ft. Taylor Swift](https://www.youtube.com/watch?v=4mE3ETiMXrE)

[Fun - Selena Gomez](https://www.youtube.com/watch?v=ze3XnfkDlAE&list=PLenjelHCUmvFaRzwNu4_irQ1CsmJupPIy&index=20) | Although we hate her...

[God is a woman - Ariana Grande](https://www.youtube.com/watch?v=kHLHSlExFis) | cause tseela is **the god**