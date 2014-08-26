static void swap(char* l, char* r, int size){    
    if (r==l) return;
    while(size--) {    
      char t= *l;
      *l++ = *r;
      *r++ = t;      
    }
}

static char* part(char* l,char* r, int size, int(*compare)(const void*, const void*)){     
  swap(l, r, size);
  char* median  = l;
  for(int i =0;i<=r-l-size;i+=size){
    if(compare(l+i, r) <=0){
      swap(l+i, median, size);
      median+=size;
    }
  }
  swap(median, r,size);  
  return median;
}

static void qs(char* l, char* r, int size, int(*compare)(const void*, const void*)){
    if(r >l ){
      char* median = part(l, r, size ,compare);      
      qs(l,median-size,size,compare);      
      qs(median+size,r,size,compare);  
    }
    return;    
}

void quick_sort(void* arr, int len, int size,int(*compare)(const void*, const void*)){
  char* l= (char*)arr; 
  char* r = l + size*(len-1);
  qs(l,r, size, compare);  
}



