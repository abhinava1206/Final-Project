# Final Project
## Project - Compression Widget

I have created a program that can compress and decompress files using Run Length Encoding and Lempel-Ziv-Welch (LZW) compression algorithms. I will implement a GUI using Qt in which the user will be able to input a file of his choice and compress/ decompress it using either algorithm.

RLE is better suited for files that have repeated instances of letters. The string "aaaabbb" is compressed as "a4b3", so it is especially well suited for .txt files/ other files that have repeating data or letter sequences.

LZW maps input characters into codes and assigns codes to patterns in the input characters. It uses a lookup table (implemented in my program with std::map) to compress the input stream. It is therefore better suited for files where a specific pattern (like a word or a name) is likely to appear multiple times.

Both algorithms are lossless and work best in text compression, so I have included sample .txt files that would be well suited to RLE and LZW compression respectively.

Wikipedia entries:
https://en.wikipedia.org/wiki/Run-length_encoding
https://en.wikipedia.org/wiki/Lempel%E2%80%93Ziv%E2%80%93Welch

