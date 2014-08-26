#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>
#include "simplex.h"
#include "sort.h"

typedef struct Point
  {
    int x;
    int y;
  } Point;

void run_test();
static void test_quick_sort_int();
static void test_quick_sort_float();
static void test_quick_sort_double();
static int int_compare(const void*,const void*);
static int float_compare(const void*,const void*);
static int double_compare(const void*,const void*);
static int struct_compare(const void*, const void*);

static void test_quick_sort_int(){
  int a[] ={1,3,2};
  int expect[] = {1,2,3};
  quick_sort(a, len(a),sizeof(int), int_compare);  
  assert(memcmp(a,expect,sizeof(a)) ==0);  
  printf("test int array quick_sort......OK\n");
}

static void test_quick_sort_float(){
  float a[] ={1,3.1,2.1};
  float expect[] = {1,2.1,3.1};
  quick_sort(a, len(a),sizeof(float), float_compare);  
  assert(memcmp(a,expect,sizeof(a)) ==0);   
  printf("test float array quick_sort......OK\n");
}

static void test_quick_sort_double(){
  double a[] ={1,3.1,2.1};
  double expect[] = {1,2.1,3.1};
  quick_sort(a, len(a),sizeof(double), double_compare);  
  assert(memcmp(a,expect,sizeof(a)) ==0);   
  printf("test double array quick_sort......OK\n");
}

static void test_quick_sort_struct_type(){  
  Point p1 = {1,1};
  Point p2 = {2,2};
  Point p3 = {3,3};
  Point points[3] = {p1,p3,p2};
  Point expect[3] = {p1,p2,p3};
  quick_sort(points, len(points),sizeof(Point), struct_compare);  
  assert(memcmp(points,expect,sizeof(points)) ==0);    
  printf("test struct array quick_sort......OK\n");
}

static int int_compare(const void* a, const void* b)
{
   int int_a = * ((int*)a);
   int int_b = * ((int*)b);
   if ( int_a == int_b ) return 0;
   else if ( int_a < int_b ) return -1;
   else return 1;
}
static int float_compare(const void* a, const void* b)
{
   float int_a = * ((float*)a);
   float int_b = * ((float*)b);
   if ( int_a == int_b ) return 0;
   else if ( int_a < int_b ) return -1;
   else return 1;
}

static int double_compare(const void* a, const void* b)
{
   double int_a = * ((double*)a);
   double int_b = * ((double*)b);
   if ( int_a == int_b ) return 0;
   else if ( int_a < int_b ) return -1;
   else return 1;
}

static int struct_compare(const void* a, const void* b)
{
   Point* point_a = (Point*)a;
   Point* point_b = (Point*)b;
   if ( point_a->x == point_b->x ) return 0;
   else if ( point_a->x < point_b->x ) return -1;
   else return 1;
}


void run_test(){
  test_quick_sort_int();
  test_quick_sort_float();
  test_quick_sort_double();
  test_quick_sort_struct_type();
  printf("Completed, everything is OK\n");
}

int  main(){
	run_test();
	return 0;
}


