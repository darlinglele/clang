#define CAST_ARRAY_TO_ARRAYS(array,arrays,m,n) arrays= malloc(sizeof(*arrays) * m);if(arrays==NULL) exit(1);\
for (int i = 0; i < m; i++){\
    arrays[i] = &array[i*n];\
}

#define ALLOC_ARRAYS(MN, m, n) MN = malloc(sizeof(*MN)*m); \
if(MN == NULL) exit(1);\
for(int i=0;i<m;i++){\
  MN[i] = calloc(n,sizeof(**MN));\
  if(MN[i]==NULL){exit(1);}}

#define FREE_ARRAYS(MN,m) for(int i=0;i<m;i++){free(MN[i]); MN[i]=NULL;} free(MN); MN=NULL;

#define printf_array(array,len) for (int i = 0; i < len; ++i){printf("%d ", *(array+i));}

#define bool int
#define true 1
#define false 0  

#define len(array) (int)sizeof(array)/(int)sizeof(*array) 

#define printf_array(array,len) for (int i = 0; i < len; ++i){printf("%d ", *(array+i));}




