//Not for compiling

/* Declarations of functions implementing operations bis and bic */
int bis(int x, int m); //set bits in x to 1 where m has bit 1  (set)
int bic(int x, int m); //set bits in x to 0  where m has bit 1 (clear)

/* Compute x|y using only calls to functions bis and bic */
int bool_or(int x, int y) {
int result = bits(x,y); //set x with m = y is the same as OR
return result;
}


/* Compute x^y using only calls to functions bis and bic */
int bool_xor(int x, int y) {
//x XOR y = (x set y) clear (x AND y): x set y is close to XOR but wrong at where x and y both have bit 1
//                         x AND y = x clear (111...111 - y) 
//        = (x set y) clear (x clear (111...111 - y))



int result = bisc(bis(x,y), bisc(x, 0xFFFFFFFF - y));
return result;
}