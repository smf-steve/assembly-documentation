void * memcpy(char * dst, char *src, int length) {
  // Note: NO check is made if the strings overlap
  //       This is "mem" copy and not "string" copy

  char * original_dst;
  int c;

  // Written via the pointer approach
  original_dst = dst;
  for(c=0; c < length; c++) {
    (* dst) = (* src);
    dst++, src++;
    c++;
  }
  return original_dst;

  // Written via the array approach
  // for(c=0; c < length; c++) {
  //   dst[c] = src[c];
  //   if (src[c] == char_last) {
  //      ret_val = &dst + c;
  //      break;
  //   }
  //   c++;
  // }
  // 
  // return ret_val;
 }


void * memccpy(char * dst, char *src, char char_stop, int length) {
  // Note: NO checks are made for the NULL character
  //       This is "mem" copy and not "string" copy

  // If the "char_stop" is not within the string NULL is returned
  // If the "char_stop" is encountered during the operation
  //   -- the character is copied into dst
  //   -- the copy operation then stops 
  //   -- the address of the character after "char_stop" is returned
  //
  // From the man page:
  //     * If the character c (as converted to an unsigned char) occurs 
  //       in the string src,
  //     * the copy stops and a pointer to the byte 
  //     * "after the copy of c" in the string dst is returned.

  int c;
  int ret_val = NULL;

  // Written via the pointer approach
  for(c=0; c < length; c++) {
    (* dst) = (* src);
    if ( (* dst) == char_stop) {
       ret_val = dst + 1
       return;
    }
    dst++, src++;
    c++;
  }
  return ret_val;  

  // Written via the array approach
  // for(c=0; c < length; c++) {
  //   dst[c] = src[c];
  //   if (src[c] == char_stop) {
  //      ret_val = &dst + c;
  //      break;
  //   }
  //   c++;
  // }
  // 
  // return ret_val;
 }
 

void * memmove(byte * dst, byte *src, int length) {
  // Returns dst

  // Steps:
  //   1. Determine if the strings overlap.
  //   2. If overlap
  //      * allocate stack space
  //      * memcpy "src" onto the stack
  //      * reset the value of "src"
  //   3. memcpy "src" into "dst"
  //   4. If overlap
  //      * deallocate stack space

  byte overlap = FALSE;
  {
    byte * first;  // the address of the first string in memory
    byte * second;
    byte * end;

    // first, second = order(dst, src);
       first  = (dst < src) ? dst : src; // the "min" macro
       second = (dst < src) ? src : dst; // the "max" macro
    end = first + length;
    overlap = (end >= length);
  }
  if ( overlap ) {
    byte * temp;
    temp = alloca(length);
    src  = memcpy(temp, src, length);
  }
  dst = memcpy(dst, src, length);
  if ( overlap ) {
     ;  // deallocate stack space
  }
  return dst;
}



// memchr -- locate a byte in memory
void * memchr(void *src, unsigned char value, int max_length) {

  void * ret_val = NULL;

  for(c=0; c < length;) {
    if ( (* src) == value) {
       ret_val = src;
       break;
    }
    src++, 
    c++;
  }
  return ret_val; 
}


// memset - fill a byte string with a byte value
void *memset(void *dst, byte value, int length) {

  void * ret_val = dst;

  for(c=0; c < length; ) {
    ( * dst ) = value;
    dst++, 
    c++;
  }
  return ret_val; 
}




// memcmp -- compare byte string
int   memcmp(void *src1, void *src2, int length) {

  int ret_val = 0;

  // Special Cases:
  // 1. both strings are are the same -- return 0;
  // 2. only one string is empty -- return 1 or -1;
  // 3. search for the first difference


  if (src1 == src2)  return 0;   // both strings are the same
  if (src1 == NULL ) return 1;
  if (src2 == NULL ) return -1;

  for(c=0; c < length; c++) {
    if ( (*src1) != (*src))
       break;
    src1++; 
    src2++;
    c++;
  }
  return (* src1) - (* src2); 
}


int strlen(char * str) {
   int count = 0;
   while ( (*str) != '\0') {
    str++;
    count++;
   }
 return count;
}

int strnlen(char * str, int max_length) {
  int count;

  for (count=0; count < max_length; count++) {
    if ((*str) == '\0')
      break;
    str++;
  }
  return count;
}



int   strlcpy(char *  dst,  char *  src, int size){
  int count;

  if (size == 0) return 0;

  for (count=0; count < size - 1; count++) {
    if ((*str) == '\0')
      break;
    (* dst) = (* str);
    dst++;
    src++;
  }
  (* dst) = '\0';
  return count;
}


int  strlcat(char *  dst,  char *  src, int size) {

  if (size == 0) return 0;

  // first find the end of dst
  for (count=0; count < size -1; count ++) {
    if ((*dst) == '\0')
      break;
    dst ++;
  }
  if (dst == '\0') {
    count += strlcpy(dst, src, size-count);
    // bug:  count should be |dst| + |src|
    // here: count is max (|dst| + |src|, size);
  } 
  return count;
}


//// Debugging code

char A[20] = "Hello this is a string;"
char B[20] = "Hello this is a string;"
char C[20] = "Hello this is a string;"
char D[20] = "Hello this is a string;"
char E[20] = "Hello this is a string;"
char * p;
int value = 0;


int main(void) {
  memcpy(A, B, 12);
  memccpy(A, C, '!', 20);
  memmove(A, D, 20);
  p = memchr(A, '!', 20);
  memset(A, '!', 20);
  value = memcmp(D, E);
  value = strlen(A);
  value = strnlen(A, 20);

  strlcpy(A, "hello", 20);
  strlcat(A, "string", 20);

}


