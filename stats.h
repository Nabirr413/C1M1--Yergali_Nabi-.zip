****************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * systems. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Header file declaring statistical analytics functions on an array of unsigned chars.
 *
 * This file provides function prototypes and documentation for analyzing
 * maximum, minimum, mean, median and sorting an unsigned char array.
 *
 * @author Nabi Yergali
 * @date 2026
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/**
 * @brief Prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * This function takes the results calculated from the array and displays them
 * in a clear, formatted presentation on the command line.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 */
void print_statistics(unsigned char *data, unsigned int length);

/**
 * @brief Given an array of data and a length, prints the array to the screen.
 *
 * Formats the output array neatly to standard output.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 */
void print_array(unsigned char *data, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the median value.
 *
 * The median is calculated after sorting the array. For an even number of elements,
 * the median is the average of the two middle elements rounded down to the nearest integer.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 *
 * @return An unsigned char result containing the median value
 */
unsigned char find_median(unsigned char *data, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the mean (average).
 *
 * Calculates the arithmetic mean rounded down to the nearest integer.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 *
 * @return An unsigned char result containing the mean value
 */
unsigned char find_mean(unsigned char *data, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the maximum value.
 *
 * Scans the array and returns the largest unsigned char element.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 *
 * @return An unsigned char result containing the maximum value
 */
unsigned char find_maximum(unsigned char *data, unsigned int length);

/**
 * @brief Given an array of data and a length, returns the minimum value.
 *
 * Scans the array and returns the smallest unsigned char element.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 *
 * @return An unsigned char result containing the minimum value
 */
unsigned char find_minimum(unsigned char *data, unsigned int length);

/**
 * @brief Given an array of data and a length, sorts the array from largest to smallest.
 *
 * Reorders the array so that index 0 is the maximum and index length - 1 is the minimum.
 *
 * @param data Pointer to an unsigned char array
 * @param length The size/number of elements in the array
 */
void sort_array(unsigned char *data, unsigned int length);

#endif /* __STATS_H__ */
