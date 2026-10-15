/******************************************************************************
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
 * @file stats.c 
 * @brief Implementation file for statistical operations on an array of unsigned chars.
 *
 * @author Nabi Yergali
 * @date 2026
 *
 */

#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114,  88,   45,  76, 123,  87,  25,  23,
                              200, 122,  150, 90,   92,  87, 177, 244,
                              201,   6,   12,  60,   8,   2,   5,  67,
                                7,  87,  250, 230,  99,   3, 100,  90};

  printf("================== ORIGINAL ARRAY ==================\n");
  print_array(test, SIZE);

  printf("\n=================== STATISTICS =====================\n");
  print_statistics(test, SIZE);

  printf("\n================== SORTED ARRAY ====================\n");
  sort_array(test, SIZE);
  print_array(test, SIZE);
}

void print_statistics(unsigned char *data, unsigned int length) {
  if (data == NULL || length == 0) return;

  unsigned char min = find_minimum(data, length);
  unsigned char max = find_maximum(data, length);
  unsigned char mean = find_mean(data, length);
  unsigned char median = find_median(data, length);

  printf("------------------------------------\n");
  printf("  Minimum : %u\n", (unsigned int)min);
  printf("  Maximum : %u\n", (unsigned int)max);
  printf("  Mean    : %u\n", (unsigned int)mean);
  printf("  Median  : %u\n", (unsigned int)median);
  printf("------------------------------------\n");
}

void print_array(unsigned char *data, unsigned int length) {
  if (data == NULL) return;

  for (unsigned int i = 0; i < length; i++) {
    printf("%3u ", data[i]);
    if ((i + 1) % 8 == 0) {
      printf("\n");
    }
  }
  if (length % 8 != 0) {
    printf("\n");
  }
}

unsigned char find_maximum(unsigned char *data, unsigned int length) {
  if (data == NULL || length == 0) return 0;

  unsigned char max = data[0];
  for (unsigned int i = 1; i < length; i++) {
    if (data[i] > max) {
      max = data[i];
    }
  }
  return max;
}

unsigned char find_minimum(unsigned char *data, unsigned int length) {
  if (data == NULL || length == 0) return 0;

  unsigned char min = data[0];
  for (unsigned int i = 1; i < length; i++) {
    if (data[i] < min) {
      min = data[i];
    }
  }
  return min;
}

unsigned char find_mean(unsigned char *data, unsigned int length) {
  if (data == NULL || length == 0) return 0;

  unsigned int sum = 0;
  for (unsigned int i = 0; i < length; i++) {
    sum += data[i];
  }
  return (unsigned char)(sum / length);
}

void sort_array(unsigned char *data, unsigned int length) {
  if (data == NULL || length == 0) return;

  for (unsigned int i = 0; i < length - 1; i++) {
    for (unsigned int j = 0; j < length - i - 1; j++) {
      if (data[j] < data[j + 1]) {
        unsigned char temp = data[j];
        data[j] = data[j + 1];
        data[j + 1] = temp;
      }
    }
  }
}

unsigned char find_median(unsigned char *data, unsigned int length) {
  if (data == NULL || length == 0) return 0;

  /* Создаем локальную копию, чтобы не менять порядок элементов сразу */
  unsigned char copy[length];
  for (unsigned int i = 0; i < length; i++) {
    copy[i] = data[i];
  }

  sort_array(copy, length);

  if (length % 2 == 0) {
    return (unsigned char)((copy[length / 2 - 1] + copy[length / 2]) / 2);
  } else {
    return copy[length / 2];
  }
}
