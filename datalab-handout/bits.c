/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2018 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/* We do not support C11 <threads.h>.  */
/* 
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    int n_shift = n << 3; // n * 8 비트
    int m_shift = m << 3; // m * 8 비트
    int nm_byte = ((x >> n_shift) ^ (x >> m_shift)) & 0xFF; // byte 추출하고 XOR 연산한 다음 0xFF와 AND 연산으로 교환할 byte를 남김
    return x ^ ((nm_byte << n_shift) | (nm_byte << m_shift)); // 다시  XOR 연산
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int count = 0x11 | (0x11 << 8); // 00010001을 저장
    int sum = 0;
    int mask = 0xF | (0xF << 8); // 00001111을 저장

    count = count | (count << 16);
    sum = x & count; // 첫 번째 비트 값을 저장
    sum = sum + ((x >> 1 )& count); // 두 번째 비트 값을 저장
    sum = sum + ((x >> 2) & count); // 세 번째 비트 값을 저장
    sum = sum + ((x >> 3) & count); // 네 번째 비트 값을 저장
    sum = sum + (sum >> 16); // 상위 16비트와 하위 16비트를 더함
    sum = (sum & mask) + ((sum >> 4) & mask); // 각 바이트의 비트 합 계산을 위해 4비트씩 더함

    return (sum & 0xFF) + (sum >> 8); // 최종 비트 개수 더하여 반환
}
/*
 * bitReverse - Reverse bits in a 32-bit word
 *   Examples: bitReverse(0x80000002) = 0x40000001
 *             bitReverse(0x89ABCDEF) = 0xF7C3D591
 *             
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int bitReverse(int x) {
  int mask;
  // 첫 16비트와 마지막 16비트를 교환하기 위한 마스크
  mask = (0xFF << 8) | 0xFF;
  x = (((x >> 16) & mask) | (x << 16)); 
  // 8비트 단위로 두 바이트를 교환하기 위한 마스크
  mask = mask^(mask << 8); 
  x = (((x >> 8) & mask) | ((x & mask) << 8)); 
  // 4비트 단위로 교환하기 위한 마스크
  mask = mask^(mask << 4);
  x = (((x >> 4) & mask) | ((x & mask) << 4));
 // 2비트 단위로 교환하기 위한 마스크 
  mask = mask^(mask << 2);
  x = (((x >> 2) & mask) | ((x & mask) << 2)); 
  // 1비트 단위로 교환하기 위한 마스크
  mask = mask^(mask << 1);
  x = (((x >> 1) & mask) | ((x & mask) << 1)); 

  return x;
}
/* 
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    return (x << 31) >> 31; //LSB가 1이면 전체 비트를 1로, LSB가 0이면 전체 비트를 0으로 설정
}
/* 
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) {
    int even = 0x55 | (0x55 << 8);  // 하위 16비트의 짝수 비트를 모두 1로 설정
    even = even | (even << 16);    // 상위 16비트에도 동일하게 적용하여  32비트 짝수 비트를 1로 설정
    return even;
}
/* 
 * isNegative - return 1 if x < 0, return 0 otherwise 
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
    return (x >> 31) & 1; // 오른쪽으로 31비트 이동 후 최상위 비트 추출한 다음 $ 연산으로 마지막 비트를 가져옴
}
/* 
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) {
    int mask = x >> 31; // 음수면 모든 비트가 1, 양수면 모든 비트가 0
    return (x + mask) ^ mask; // x가 음수면 -x 반환, 양수이면 x반
}
/* 환
 * sign - return 1 if positive, 0 if zero, and -1 if negative
 *  Examples: sign(130) = 1
 *            sign(-23) = -1
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 2
 */
int sign(int x) {
    // x가 음수면 x >> 31은 -1 , x가 양수면 !!x는 1, x가 0일 경우 !!x는 0
    return (x >> 31) | (!!x);
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
  int mask = ~(x >> 31);  // x가 음수면 모든 비트를 0으로
  int ifPower2 = (x & (x + mask)); // x가 2의 거듭제곱인지 확인
  return !(ifPower2 | !x); // x가 2의 거듭제곱이고 0이 아니면 1, 나머지는 0
}
/*
 * isTmin - returns 1 if x is the minimum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmin(int x) {
    return !(x + x) ^ !x;
}


/*
 * isPallindrome - Return 1 if bit pattern in x is equal to its mirror image
 *   Example: isPallindrome(0x01234567) = 0, isPallindrome(0x0123C480) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 45
 *   Rating: 4
 */
int isPallindrome(int x) {
  int y = x >> 16; // x의 상위 16비트를 저장 
  int mask = 0x55 | (0x55 << 8); // 0x5555생성

  y = ((y & mask) << 1) | ((y >> 1) & mask); // 인접 비트들을 교환하여 반전
  mask = 0x33 | (0x33 << 8); // 0x3333 생성
  y = ((y & mask) << 2) | ((y >> 2) & mask); // 2비트씩 교환
  mask = 0x0f | (0x0f << 8); // 0x0f0f
  y = ((y & mask) << 4) | ((y >> 4) & mask); // 4비트씩 교환
  y = ((y & 0xff) << 8) | ((y >> 8) & 0xff); // 8비트씩 교환

  return !((y ^ x) & (~0 + (1 << 16))); // 상위 16비트와 하위 16bit 비교
}
/* 
 * signMag2TwosComp - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: signMag2TwosComp(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int signMag2TwosComp(int x) {
    int sign = x >> 31;  // x의 부호 비트 추출
    int abs = x & ~(1 << 31);  // x의 절대값 추출
    return (abs ^ sign) + (sign & 1); // 2의 보수로 변환
}
/* 
 * floatNegate - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatNegate(unsigned uf) {
    if ((uf & 0x7FFFFFFF) > 0x7F800000) {  // NaN이면 그대로
        return uf; 
    }
    return uf ^ 0x80000000; // 음수로 변환
}
/* 
 * floatInt2Float - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatInt2Float(int x) {  
 unsigned mask1, mask2, mask3, mask4, mask5;
    unsigned sign = 0, shiftleft = 0, flag = 0, tmp;
    unsigned ux = x;

    mask1 = 0x80000000; // 부호 비트 마스크 
    mask2 = 0x01FF;      // 하위 9비트를 추출하는 마스크
    mask3 = 0x0100;      // 반올림을 결정하는 마스크
    mask4 = 0x03FF;      // 하위 16비트를 추출하는 마스크
    mask5 = 0x0300;      // 반올림 경계조건을 위한 마스크
    if( x == 0 ) return 0;  
    if( x < 0 ) {  
     sign = mask1;  
     ux = -x;    // 절대값으로 변환
    } 

    while(1){   // x의 가장 왼쪽 1을 찾기 위한 shift
    tmp = ux;  
    ux = ux << 1;  
    shiftleft++;  
    if( tmp & mask1 ) break;  // 찾으면 while문 종료
    }  

    if((ux & mask2) > mask3) flag = 1; // 반올림 여부 확인
    if((ux & mask4) == mask5) flag = 1; // 조건에 따라 반올림

    return sign + (ux >> 9) + ((159 - shiftleft) << 23) + flag; // float 형식으로 변환하고 반
    }
/* 
 * floatScale64 - Return bit-level equivalent of expression 64*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of환
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 35
 *   Rating: 4
 */
unsigned floatScale64(unsigned uf) { 
    unsigned mask1 = 0x80000000;  // 부호 비트 마스크
    unsigned mask2 = 0x7F800000;  // 지수 비트 마스크
    unsigned mask3 = 0x00800000;  // 지수 비트를 증가시키기 위한 마스크
    unsigned mask4 = 0xFF800000;  // NaN이나 infinity일 경우 처리를 위한 마스크

    int num = 6, sign;

    sign = uf & mask1; // 부호 비트 추출

    while (num--) { // 64배 증가
        int exp = uf & mask2; 
        int exp_zero = !exp; // 지수가 0인지 확인

        if (exp_zero) { // 지수가 0이면
            uf = sign | (uf << 1); // 1비트 왼쪽 shift
        } else if (exp != mask2) { // 지수가 NaN이나 infinity가 아니면
            uf += mask3;     // 지수를 증가
            exp = uf & mask2;
            if (exp == mask2) { // 지수가 infinity가 되면
                uf &= mask4;
            }
        }
    }

    return uf;
}
/* 
 * floatAbsVal - Return bit-level equivalent of absolute value of f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument..
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned floatAbsVal(unsigned uf) {
     unsigned result = uf & 0x7FFFFFFF; // 부호 비트를 0으로 하여 절대값 생성
    if (result > 0x7F800000) { // NaN이면 그대로
        return uf;  
    }
    return result;  
}
