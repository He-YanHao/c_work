#ifndef __SORT_H
#define __SORT_H

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int arr[], int n);//插入排序
void selection_sort(int arr[], int n);//选择排序
void bubble_sort(int arr[], int n);//冒泡排序
void quickSort(int arr[], int low, int high);

#endif