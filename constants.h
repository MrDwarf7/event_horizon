#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <math.h>
#include <stddef.h>
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef float f32;
typedef double f64;

// usize
typedef ptrdiff_t ptrdiff;
typedef size_t usize;

// single boolean

#ifndef CONSTANTS_H_DELT_VARS
#  define CONSTANTS_H_DELT_VARS
#  define DELT_0_5 0.5
#  define DELT_0_01 0.01
#  define DELT_1 0.1
#endif // CONSTANTS_H_DELT_VARS

#define EXPONEN_1e_6 1e-6
#define SDL_ALPHAOPAQUE 255

#endif // CONSTANTS_H_

#ifdef CONSTANTS_H_DEFAULTS

#define WIDTH 1000
#define HEIGHT 1000

#endif // CONSTANTS_H_DEFAULTS

#ifdef CONSTANTS_H_ASCIIS

#define WIDTH (u8)40
#define HEIGHT (u8)40

#endif // CONSTANTS_H_ASCIIS
