#include <axtls-lite/os_int.h>

#ifdef PIC32MZ

void *memcpy(void *dst, const void *src, uint32_t n)
{
  char *r1 = dst;
  const char *r2 = src;

  while (n--)
    *r1++ = *r2++;

  return dst;
}

void *memset(void *s, int32_t c, uint32_t n)
{
  char *p = (char *)s;

  while (n--)
    *p++ = (char)c;

  return s;
}

uint64_t __udivmoddi4(uint64_t num, uint64_t den, uint64_t *rem_p)
{
  uint64_t quot = 0, qbit = 1;
 
  if (den == 0){
    return 1 / ((uint32_t)den);
  }
 
  while ((int64_t)den >= 0){
    den <<= 1;
    qbit <<= 1;
  }
 
  while (qbit){ 
    if (den <= num){
      num -= den;
      quot += qbit;
    }
    den >>= 1;
    qbit >>= 1;
  }
 
  if (rem_p)
    *rem_p = num;
  
  return quot;
}

uint64_t __umoddi3(uint64_t num, uint64_t den)
{
  uint64_t v;
 
  (void) __udivmoddi4(num, den, &v);
  return v;
}

uint64_t __udivdi3(uint64_t num, uint64_t den)
{
  return __udivmoddi4(num, den, NULL);
}

#endif /* PIC32MZ */

