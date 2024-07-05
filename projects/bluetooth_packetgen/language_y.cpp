// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison GLR parsers in C

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

/* C GLR parser skeleton written by Paul Hilfinger.  */

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "glr.cc"

/* Pure parsers.  */
#define YYPURE 1






// First part of user prologue.
#line 12 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"

  #include "language_y.h"
  extern int yylex(yy::parser::semantic_type*, yy::parser::location_type*, void *);

  ParseLocation toParseLocation(yy::parser::location_type loc) {
    return ParseLocation(loc.begin.line);
  }
  #define LOC toParseLocation(yylloc)

#line 68 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "language_y.h"

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

// This skeleton is based on C, yet compiles it as C++.
// So expect warnings about C style casts.
#if defined __clang__ && 306 <= __clang_major__ * 100 + __clang_minor__
# pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined __GNUC__ && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

// On MacOS, PTRDIFF_MAX is defined as long long, which Clang's
// -pedantic reports as being a C++11 extension.
#if defined __APPLE__ && YY_CPLUSPLUS < 201103L \
    && defined __clang__ && 4 <= __clang_major__
# pragma clang diagnostic ignored "-Wc++11-long-long"
#endif

#undef YYEMPTY
#define YYEMPTY yy::parser::token::YYEMPTY
#undef YYEOF
#define YYEOF yy::parser::token::YYEOF
#undef YYerror
#define YYerror yy::parser::token::YYerror

#ifndef YYSTYPE
# define YYSTYPE yy::parser::value_type
#endif
#ifndef YYLTYPE
# define YYLTYPE yy::parser::location_type
#endif

typedef yy::parser::symbol_kind_type yysymbol_kind_t;

// Expose C++ symbol kinds to C.
#define S_YYEMPTY       yy::parser::symbol_kind::S_YYEMPTY
#define S_YYEOF         yy::parser::symbol_kind::S_YYEOF
#define S_YYerror       yy::parser::symbol_kind::S_YYerror
#define S_YYUNDEF       yy::parser::symbol_kind::S_YYUNDEF
#define S_INTEGER       yy::parser::symbol_kind::S_INTEGER
#define S_IS_LITTLE_ENDIAN yy::parser::symbol_kind::S_IS_LITTLE_ENDIAN
#define S_IDENTIFIER    yy::parser::symbol_kind::S_IDENTIFIER
#define S_SIZE_MODIFIER yy::parser::symbol_kind::S_SIZE_MODIFIER
#define S_STRING        yy::parser::symbol_kind::S_STRING
#define S_ENUM          yy::parser::symbol_kind::S_ENUM
#define S_PACKET        yy::parser::symbol_kind::S_PACKET
#define S_PAYLOAD       yy::parser::symbol_kind::S_PAYLOAD
#define S_BODY          yy::parser::symbol_kind::S_BODY
#define S_STRUCT        yy::parser::symbol_kind::S_STRUCT
#define S_SIZE          yy::parser::symbol_kind::S_SIZE
#define S_COUNT         yy::parser::symbol_kind::S_COUNT
#define S_FIXED         yy::parser::symbol_kind::S_FIXED
#define S_RESERVED      yy::parser::symbol_kind::S_RESERVED
#define S_GROUP         yy::parser::symbol_kind::S_GROUP
#define S_CUSTOM_FIELD  yy::parser::symbol_kind::S_CUSTOM_FIELD
#define S_CHECKSUM      yy::parser::symbol_kind::S_CHECKSUM
#define S_CHECKSUM_START yy::parser::symbol_kind::S_CHECKSUM_START
#define S_PADDING       yy::parser::symbol_kind::S_PADDING
#define S_TEST          yy::parser::symbol_kind::S_TEST
#define S_23_           yy::parser::symbol_kind::S_23_
#define S_24_           yy::parser::symbol_kind::S_24_
#define S_25_           yy::parser::symbol_kind::S_25_
#define S_26_           yy::parser::symbol_kind::S_26_
#define S_27_           yy::parser::symbol_kind::S_27_
#define S_28_           yy::parser::symbol_kind::S_28_
#define S_29_           yy::parser::symbol_kind::S_29_
#define S_30_           yy::parser::symbol_kind::S_30_
#define S_31_           yy::parser::symbol_kind::S_31_
#define S_YYACCEPT      yy::parser::symbol_kind::S_YYACCEPT
#define S_file          yy::parser::symbol_kind::S_file
#define S_declarations  yy::parser::symbol_kind::S_declarations
#define S_declaration   yy::parser::symbol_kind::S_declaration
#define S_enum_definition yy::parser::symbol_kind::S_enum_definition
#define S_enumeration_list yy::parser::symbol_kind::S_enumeration_list
#define S_enumeration   yy::parser::symbol_kind::S_enumeration
#define S_group_definition yy::parser::symbol_kind::S_group_definition
#define S_checksum_definition yy::parser::symbol_kind::S_checksum_definition
#define S_custom_field_definition yy::parser::symbol_kind::S_custom_field_definition
#define S_test_definition yy::parser::symbol_kind::S_test_definition
#define S_test_case_list yy::parser::symbol_kind::S_test_case_list
#define S_test_case     yy::parser::symbol_kind::S_test_case
#define S_struct_definition yy::parser::symbol_kind::S_struct_definition
#define S_packet_definition yy::parser::symbol_kind::S_packet_definition
#define S_field_definition_list yy::parser::symbol_kind::S_field_definition_list
#define S_field_definition yy::parser::symbol_kind::S_field_definition
#define S_group_field_definition yy::parser::symbol_kind::S_group_field_definition
#define S_constraint_list yy::parser::symbol_kind::S_constraint_list
#define S_constraint    yy::parser::symbol_kind::S_constraint
#define S_type_def_field_definition yy::parser::symbol_kind::S_type_def_field_definition
#define S_scalar_field_definition yy::parser::symbol_kind::S_scalar_field_definition
#define S_body_field_definition yy::parser::symbol_kind::S_body_field_definition
#define S_payload_field_definition yy::parser::symbol_kind::S_payload_field_definition
#define S_checksum_start_field_definition yy::parser::symbol_kind::S_checksum_start_field_definition
#define S_padding_field_definition yy::parser::symbol_kind::S_padding_field_definition
#define S_size_field_definition yy::parser::symbol_kind::S_size_field_definition
#define S_fixed_field_definition yy::parser::symbol_kind::S_fixed_field_definition
#define S_reserved_field_definition yy::parser::symbol_kind::S_reserved_field_definition
#define S_array_field_definition yy::parser::symbol_kind::S_array_field_definition


/* Default (constant) value used for initialization for null
   right-hand sides.  Unlike the standard yacc.c template, here we set
   the default value of $$ to a zeroed-out value.  Since the default
   value is undefined, this behavior is technically correct.  */
static YYSTYPE yyval_default;
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;

// Second part of user prologue.
#line 274 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
static void
yyerror (const yy::parser::location_type *yylocationp,
         yy::parser& yyparser, void* scanner, Declarations* decls,
         const char* msg);
#line 279 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"


#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif
#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YYFREE
# define YYFREE free
#endif
#ifndef YYMALLOC
# define YYMALLOC malloc
#endif
#ifndef YYREALLOC
# define YYREALLOC realloc
#endif

#ifdef __cplusplus
  typedef bool yybool;
# define yytrue true
# define yyfalse false
#else
  /* When we move to stdbool, get rid of the various casts to yybool.  */
  typedef signed char yybool;
# define yytrue 1
# define yyfalse 0
#endif

#ifndef YYSETJMP
# include <setjmp.h>
# define YYJMP_BUF jmp_buf
# define YYSETJMP(Env) setjmp (Env)
/* Pacify Clang and ICC.  */
# define YYLONGJMP(Env, Val)                    \
 do {                                           \
   longjmp (Env, Val);                          \
   YY_ASSERT (0);                               \
 } while (yyfalse)
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* The _Noreturn keyword of C11.  */
#ifndef _Noreturn
# if (defined __cplusplus \
      && ((201103 <= __cplusplus && !(__GNUC__ == 4 && __GNUC_MINOR__ == 7)) \
          || (defined _MSC_VER && 1900 <= _MSC_VER)))
#  define _Noreturn [[noreturn]]
# elif ((!defined __cplusplus || defined __clang__) \
        && (201112 <= (defined __STDC_VERSION__ ? __STDC_VERSION__ : 0) \
            || (!defined __STRICT_ANSI__ \
                && (4 < __GNUC__ + (7 <= __GNUC_MINOR__) \
                    || (defined __apple_build_version__ \
                        ? 6000000 <= __apple_build_version__ \
                        : 3 < __clang_major__ + (5 <= __clang_minor__))))))
   /* _Noreturn works as-is.  */
# elif (2 < __GNUC__ + (8 <= __GNUC_MINOR__) || defined __clang__ \
        || 0x5110 <= __SUNPRO_C)
#  define _Noreturn __attribute__ ((__noreturn__))
# elif 1200 <= (defined _MSC_VER ? _MSC_VER : 0)
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   145

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  30
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168
/* YYMAXRHS -- Maximum number of symbols on right-hand side of rule.  */
#define YYMAXRHS 10
/* YYMAXLEFT -- Maximum number of symbols to the left of a handle
   accessed by $0, $-1, etc., in any rule.  */
#define YYMAXLEFT 0

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   277

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : S_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,    25,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    23,     2,
       2,    27,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    24,     2,    26,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   111,   111,   122,   123,   126,   131,   136,   141,   145,
     149,   153,   159,   173,   180,   189,   198,   205,   214,   220,
     228,   245,   251,   259,   266,   280,   306,   342,   356,   380,
     417,   421,   438,   457,   462,   467,   472,   477,   482,   487,
     492,   497,   502,   507,   514,   526,   572,   579,   588,   595,
     605,   618,   626,   633,   639,   646,   654,   661,   667,   672,
     677,   685,   690,   710,   717,   723,   731,   738,   749,   762
};
#endif

#define YYPACT_NINF (-72)
#define YYTABLE_NINF (-1)

// YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
// STATE-NUM.
static const yytype_int16 yypact[] =
{
      24,   -72,    30,    25,   -72,    35,    43,    49,    51,    58,
      59,    60,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -14,    34,    36,    11,     4,    44,    42,    65,    64,     5,
      66,     5,     5,   -72,    67,    69,    68,    52,    17,    38,
      54,   -72,    45,    46,    53,    55,    56,    57,    62,    61,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,    22,    63,    70,    72,    74,   -72,    73,   -72,    77,
       5,    78,     9,    78,    71,    12,    80,    33,    87,    86,
      89,   -72,     5,     5,    78,   -72,   -72,   -72,   -72,    -2,
      75,    79,   -72,    81,    76,    82,    83,    84,    85,    90,
      88,    91,    92,    93,    94,    95,    96,   -72,    97,    98,
     -72,    99,   101,   -72,   -72,   102,     3,   -72,    50,   103,
      78,     0,     1,   -72,   100,   105,   109,   110,   111,   107,
     108,   -72,   -72,   -72,   112,   -72,   -72,   -72,   -72,   -72,
       5,   -72,   104,   106,   -72,   113,   114,   -72,   -72,   135,
     136,   137,   138,   -72,   -72,     5,   116,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   -72,   117,   -72,   -72
};

// YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
// Performed when YYTABLE does not specify something else to do.  Zero
// means the default is an error.
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     2,     1,     0,     0,     0,     0,     0,
       0,     0,     4,     5,     8,     9,    10,    11,     7,     6,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    30,
       0,    30,    30,    19,     0,     0,     0,     0,     0,    44,
      54,    52,     0,     0,     0,     0,     0,     0,     0,    31,
      33,    34,    35,    39,    40,    36,    37,    38,    41,    42,
      43,     0,     0,     0,     0,     0,    23,     0,    21,     0,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    27,    30,    30,     0,    24,    16,    18,    17,     0,
       0,     0,    13,     0,     0,     0,    47,    51,    50,     0,
       0,     0,     0,     0,     0,     0,     0,    63,     0,     0,
      32,     0,     0,    20,    22,     0,     0,    28,     0,     0,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
       0,    55,    56,    25,     0,    15,    12,    14,    48,    49,
      30,    46,     0,     0,    64,     0,     0,    67,    53,     0,
       0,     0,     0,    61,    62,    30,     0,    66,    65,    69,
      68,    57,    58,    59,    60,     0,    29,    26
};

// YYPGOTO[NTERM-NUM].
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   -23,   -72,   -72,   -72,
     -72,   -72,     6,   -72,   -72,   -31,   -72,   -72,   -71,   -72,
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72
};

// YYDEFGOTO[NTERM-NUM].
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    12,    13,    91,    92,    14,    15,    16,
      17,    67,    68,    18,    19,    48,    49,    50,    95,    96,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60
};

// YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
// positive, shift that token.  If negative, reduce the rule whose
// number is the opposite.  If YYTABLE_NINF, syntax error.
static const yytype_uint8 yytable[] =
{
      62,    63,    99,   142,   145,    66,   143,   146,    90,    27,
      39,    33,    97,   112,    98,    40,    41,   101,    42,    43,
      44,    45,   102,   103,   113,    46,    47,    34,     1,   136,
       4,   144,   147,     5,     6,    32,   105,     7,   106,    93,
      20,    70,     8,     9,    10,    71,    83,    11,    21,   141,
      84,   110,   111,   138,    22,   139,    23,    28,    29,    30,
      31,    72,    73,    24,    25,    26,    36,    35,    37,    38,
      64,    61,    65,    75,    76,    66,    69,    74,    78,    87,
      77,    88,    90,    94,    79,   104,    82,    80,    81,    85,
     107,   108,   109,   137,   124,   114,    86,     0,    89,     0,
       0,   100,   115,   118,   116,   135,     0,   117,   120,   156,
     153,   119,     0,   154,   121,   122,   123,     0,   129,   130,
     125,   126,   127,   128,   165,   133,   131,   140,   149,   132,
     134,   148,   150,   151,   152,   157,   155,   158,   161,   162,
     163,   164,   166,   167,   159,   160
};

static const yytype_int16 yycheck[] =
{
      31,    32,    73,     3,     3,     7,     6,     6,     5,    23,
       5,     7,     3,    84,     5,    10,    11,     5,    13,    14,
      15,    16,    10,    11,    26,    20,    21,    23,     4,    26,
       0,    31,    31,     8,     9,    24,     3,    12,     5,    70,
       5,    24,    17,    18,    19,    28,    24,    22,     5,   120,
      28,    82,    83,     3,     5,     5,     5,    23,    24,    23,
      24,    23,    24,     5,     5,     5,    24,    23,     3,     5,
       3,     5,     3,    28,    28,     7,    24,    23,    23,     7,
      27,     7,     5,     5,    28,     5,    25,    30,    26,    26,
       3,     5,     3,   116,     6,    89,    26,    -1,    25,    -1,
      -1,    30,    27,    27,    25,     3,    -1,    26,    25,   140,
       3,    29,    -1,     5,    30,    30,    26,    -1,    23,    23,
      29,    29,    29,    29,   155,    26,    29,    24,    23,    31,
      29,    31,    23,    23,    23,    31,    24,    31,     3,     3,
       3,     3,    26,    26,    31,    31
};

// YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
// state STATE-NUM.
static const yytype_int8 yystos[] =
{
       0,     4,    33,    34,     0,     8,     9,    12,    17,    18,
      19,    22,    35,    36,    39,    40,    41,    42,    45,    46,
       5,     5,     5,     5,     5,     5,     5,    23,    23,    24,
      23,    24,    24,     7,    23,    23,    24,     3,     5,     5,
      10,    11,    13,    14,    15,    16,    20,    21,    47,    48,
      49,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,     5,    47,    47,     3,     3,     7,    43,    44,    24,
      24,    28,    23,    24,    23,    28,    28,    27,    23,    28,
      30,    26,    25,    24,    28,    26,    26,     7,     7,    25,
       5,    37,    38,    47,     5,    50,    51,     3,     5,    50,
      30,     5,    10,    11,     5,     3,     5,     3,     5,     3,
      47,    47,    50,    26,    44,    27,    25,    26,    27,    29,
      25,    30,    30,    26,     6,    29,    29,    29,    29,    23,
      23,    29,    31,    26,    29,     3,    26,    38,     3,     5,
      24,    50,     3,     6,    31,     3,     6,    31,    31,    23,
      23,    23,    23,     3,     5,    24,    47,    31,    31,    31,
      31,     3,     3,     3,     3,    47,    26,    26
};

// YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      35,    35,    36,    37,    37,    38,    39,    40,    41,    41,
      42,    43,    43,    44,    45,    45,    45,    46,    46,    46,
      47,    47,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    53,    54,    55,    55,    56,    57,    58,    58,    58,
      58,    59,    59,    60,    61,    61,    61,    61,    61,    61
};

// YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     1,     1,     1,     1,     1,
       1,     1,     8,     1,     3,     3,     5,     5,     5,     3,
       6,     1,     3,     1,     5,     7,    10,     5,     7,    10,
       0,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     3,     3,
       3,     3,     1,     5,     1,     4,     4,     6,     6,     6,
       6,     5,     5,     3,     5,     6,     6,     5,     6,     6
};


/* YYDPREC[RULE-NUM] -- Dynamic precedence of rule #RULE-NUM (0 if none).  */
static const yytype_int8 yydprec[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYMERGER[RULE-NUM] -- Index of merging function for rule #RULE-NUM.  */
static const yytype_int8 yymerger[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYIMMEDIATE[RULE-NUM] -- True iff rule #RULE-NUM is not to be deferred, as
   in the case of predicates.  */
static const yybool yyimmediate[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0
};

/* YYCONFLP[YYPACT[STATE-NUM]] -- Pointer into YYCONFL of start of
   list of conflicting reductions corresponding to action entry for
   state STATE-NUM in yytable.  0 means no conflicts.  The list in
   yyconfl is terminated by a rule number of 0.  */
static const yytype_int8 yyconflp[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0
};

/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
   0, pointed into by YYCONFLP.  */
static const short yyconfl[] =
{
       0
};


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif

# define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)



#undef yynerrs
#define yynerrs (yystackp->yyerrcnt)
#undef yychar
#define yychar (yystackp->yyrawchar)
#undef yylval
#define yylval (yystackp->yyval)
#undef yylloc
#define yylloc (yystackp->yyloc)


enum { YYENOMEM = -2 };

typedef enum { yyok, yyaccept, yyabort, yyerr, yynomem } YYRESULTTAG;

#define YYCHK(YYE)                              \
  do {                                          \
    YYRESULTTAG yychk_flag = YYE;               \
    if (yychk_flag != yyok)                     \
      return yychk_flag;                        \
  } while (0)

/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif

/* Minimum number of free items on the stack allowed after an
   allocation.  This is to allow allocation and initialization
   to be completed by functions that call yyexpandGLRStack before the
   stack is expanded, thus insuring that all necessary pointers get
   properly redirected to new data.  */
#define YYHEADROOM 2

#ifndef YYSTACKEXPANDABLE
#  define YYSTACKEXPANDABLE 1
#endif

#if YYSTACKEXPANDABLE
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyexpandGLRStack (Yystack);                       \
  } while (0)
#else
# define YY_RESERVE_GLRSTACK(Yystack)                   \
  do {                                                  \
    if (Yystack->yyspaceLeft < YYHEADROOM)              \
      yyMemoryExhausted (Yystack);                      \
  } while (0)
#endif

/** State numbers. */
typedef int yy_state_t;

/** Rule numbers. */
typedef int yyRuleNum;

/** Item references. */
typedef short yyItemNum;

typedef struct yyGLRState yyGLRState;
typedef struct yyGLRStateSet yyGLRStateSet;
typedef struct yySemanticOption yySemanticOption;
typedef union yyGLRStackItem yyGLRStackItem;
typedef struct yyGLRStack yyGLRStack;

struct yyGLRState
{
  /** Type tag: always true.  */
  yybool yyisState;
  /** Type tag for yysemantics.  If true, yyval applies, otherwise
   *  yyfirstVal applies.  */
  yybool yyresolved;
  /** Number of corresponding LALR(1) machine state.  */
  yy_state_t yylrState;
  /** Preceding state in this stack */
  yyGLRState* yypred;
  /** Source position of the last token produced by my symbol */
  YYPTRDIFF_T yyposn;
  union {
    /** First in a chain of alternative reductions producing the
     *  nonterminal corresponding to this state, threaded through
     *  yynext.  */
    yySemanticOption* yyfirstVal;
    /** Semantic value for this state.  */
    YYSTYPE yyval;
  } yysemantics;
  /** Source location for this state.  */
  YYLTYPE yyloc;
};

struct yyGLRStateSet
{
  yyGLRState** yystates;
  /** During nondeterministic operation, yylookaheadNeeds tracks which
   *  stacks have actually needed the current lookahead.  During deterministic
   *  operation, yylookaheadNeeds[0] is not maintained since it would merely
   *  duplicate yychar != YYEMPTY.  */
  yybool* yylookaheadNeeds;
  YYPTRDIFF_T yysize;
  YYPTRDIFF_T yycapacity;
};

struct yySemanticOption
{
  /** Type tag: always false.  */
  yybool yyisState;
  /** Rule number for this reduction */
  yyRuleNum yyrule;
  /** The last RHS state in the list of states to be reduced.  */
  yyGLRState* yystate;
  /** The lookahead for this reduction.  */
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;
  /** Next sibling in chain of options.  To facilitate merging,
   *  options are chained in decreasing order by address.  */
  yySemanticOption* yynext;
};

/** Type of the items in the GLR stack.  The yyisState field
 *  indicates which item of the union is valid.  */
union yyGLRStackItem {
  yyGLRState yystate;
  yySemanticOption yyoption;
};

struct yyGLRStack {
  int yyerrState;
  /* To compute the location of the error token.  */
  yyGLRStackItem yyerror_range[3];

  int yyerrcnt;
  int yyrawchar;
  YYSTYPE yyval;
  YYLTYPE yyloc;

  YYJMP_BUF yyexception_buffer;
  yyGLRStackItem* yyitems;
  yyGLRStackItem* yynextFree;
  YYPTRDIFF_T yyspaceLeft;
  yyGLRState* yysplitPoint;
  yyGLRState* yylastDeleted;
  yyGLRStateSet yytops;
};

#if YYSTACKEXPANDABLE
static void yyexpandGLRStack (yyGLRStack* yystackp);
#endif

_Noreturn static void
yyFail (yyGLRStack* yystackp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, Declarations* decls, const char* yymsg)
{
  if (yymsg != YY_NULLPTR)
    yyerror (yylocp, yyparser, scanner, decls, yymsg);
  YYLONGJMP (yystackp->yyexception_buffer, 1);
}

_Noreturn static void
yyMemoryExhausted (yyGLRStack* yystackp)
{
  YYLONGJMP (yystackp->yyexception_buffer, 2);
}

/** Accessing symbol of state YYSTATE.  */
static inline yysymbol_kind_t
yy_accessing_symbol (yy_state_t yystate)
{
  return YY_CAST (yysymbol_kind_t, yystos[yystate]);
}

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INTEGER",
  "IS_LITTLE_ENDIAN", "IDENTIFIER", "SIZE_MODIFIER", "STRING", "\"enum\"",
  "\"packet\"", "\"payload\"", "\"body\"", "\"struct\"", "\"size\"",
  "\"count\"", "\"fixed\"", "\"reserved\"", "\"group\"",
  "\"custom_field\"", "\"checksum\"", "\"checksum_start\"", "\"padding\"",
  "\"test\"", "':'", "'{'", "','", "'}'", "'='", "'('", "')'", "'['",
  "']'", "$accept", "file", "declarations", "declaration",
  "enum_definition", "enumeration_list", "enumeration", "group_definition",
  "checksum_definition", "custom_field_definition", "test_definition",
  "test_case_list", "test_case", "struct_definition", "packet_definition",
  "field_definition_list", "field_definition", "group_field_definition",
  "constraint_list", "constraint", "type_def_field_definition",
  "scalar_field_definition", "body_field_definition",
  "payload_field_definition", "checksum_start_field_definition",
  "padding_field_definition", "size_field_definition",
  "fixed_field_definition", "reserved_field_definition",
  "array_field_definition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

/** Left-hand-side symbol for rule #YYRULE.  */
static inline yysymbol_kind_t
yylhsNonterm (yyRuleNum yyrule)
{
  return YY_CAST (yysymbol_kind_t, yyr1[yyrule]);
}

#if YYDEBUG

# ifndef YYFPRINTF
#  define YYFPRINTF fprintf
# endif

# define YY_FPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_FPRINTF_

# define YY_FPRINTF_(Args)                      \
  do {                                          \
    YYFPRINTF Args;                             \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)

# define YY_DPRINTF                             \
  YY_IGNORE_USELESS_CAST_BEGIN YY_DPRINTF_

# define YY_DPRINTF_(Args)                      \
  do {                                          \
    if (yydebug)                                \
      YYFPRINTF Args;                           \
    YY_IGNORE_USELESS_CAST_END                  \
  } while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


/*--------------------.
| Print this symbol.  |
`--------------------*/

static void
yy_symbol_print (FILE *, yy::parser::symbol_kind_type yytoken,
                 const yy::parser::value_type *yyvaluep,
                 const yy::parser::location_type *yylocationp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  YY_USE (yyparser);
  YY_USE (scanner);
  YY_USE (decls);
  yyparser.yy_symbol_print_ (yytoken, yyvaluep, yylocationp);
}


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                  \
  do {                                                                  \
    if (yydebug)                                                        \
      {                                                                 \
        YY_FPRINTF ((stderr, "%s ", Title));                            \
        yy_symbol_print (stderr, Kind, Value, Location, yyparser, scanner, decls);        \
        YY_FPRINTF ((stderr, "\n"));                                    \
      }                                                                 \
  } while (0)

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, yy::parser& yyparser, void* scanner, Declarations* decls);

# define YY_REDUCE_PRINT(Args)          \
  do {                                  \
    if (yydebug)                        \
      yy_reduce_print Args;             \
  } while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;

static void yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
  YY_ATTRIBUTE_UNUSED;
static void yypdumpstack (yyGLRStack* yystackp)
  YY_ATTRIBUTE_UNUSED;

#else /* !YYDEBUG */

# define YY_DPRINTF(Args) do {} while (yyfalse)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_REDUCE_PRINT(Args)

#endif /* !YYDEBUG */

#ifndef yystrlen
# define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


/** Fill in YYVSP[YYLOW1 .. YYLOW0-1] from the chain of states starting
 *  at YYVSP[YYLOW0].yystate.yypred.  Leaves YYVSP[YYLOW1].yystate.yypred
 *  containing the pointer to the next state in the chain.  */
static void yyfillin (yyGLRStackItem *, int, int) YY_ATTRIBUTE_UNUSED;
static void
yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
{
  int i;
  yyGLRState *s = yyvsp[yylow0].yystate.yypred;
  for (i = yylow0-1; i >= yylow1; i -= 1)
    {
#if YYDEBUG
      yyvsp[i].yystate.yylrState = s->yylrState;
#endif
      yyvsp[i].yystate.yyresolved = s->yyresolved;
      if (s->yyresolved)
        yyvsp[i].yystate.yysemantics.yyval = s->yysemantics.yyval;
      else
        /* The effect of using yyval or yyloc (in an immediate rule) is
         * undefined.  */
        yyvsp[i].yystate.yysemantics.yyfirstVal = YY_NULLPTR;
      yyvsp[i].yystate.yyloc = s->yyloc;
      s = yyvsp[i].yystate.yypred = s->yypred;
    }
}


/** If yychar is empty, fetch the next token.  */
static inline yysymbol_kind_t
yygetToken (int *yycharp, yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  yysymbol_kind_t yytoken;
  YY_USE (yyparser);
  YY_USE (scanner);
  YY_USE (decls);
  if (*yycharp == YYEMPTY)
    {
      YY_DPRINTF ((stderr, "Reading a token\n"));
#if YY_EXCEPTIONS
      try
        {
#endif // YY_EXCEPTIONS
          *yycharp = yylex (&yylval, &yylloc, scanner);
#if YY_EXCEPTIONS
        }
      catch (const yy::parser::syntax_error& yyexc)
        {
          YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));
          yylloc = yyexc.location;
          yyerror (&yylloc, yyparser, scanner, decls, yyexc.what ());
          // Map errors caught in the scanner to the undefined token,
          // so that error handling is started.  However, record this
          // with this special value of yychar.
          *yycharp = YYerror;
        }
#endif // YY_EXCEPTIONS
    }
  if (*yycharp <= YYEOF)
    {
      *yycharp = YYEOF;
      yytoken = S_YYEOF;
      YY_DPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (*yycharp);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }
  return yytoken;
}

/* Do nothing if YYNORMAL or if *YYLOW <= YYLOW1.  Otherwise, fill in
 * YYVSP[YYLOW1 .. *YYLOW-1] as in yyfillin and set *YYLOW = YYLOW1.
 * For convenience, always return YYLOW1.  */
static inline int yyfill (yyGLRStackItem *, int *, int, yybool)
     YY_ATTRIBUTE_UNUSED;
static inline int
yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
{
  if (!yynormal && yylow1 < *yylow)
    {
      yyfillin (yyvsp, *yylow, yylow1);
      *yylow = yylow1;
    }
  return yylow1;
}

/** Perform user action for rule number YYN, with RHS length YYRHSLEN,
 *  and top stack item YYVSP.  YYLVALP points to place to put semantic
 *  value ($$), and yylocp points to place for location information
 *  (@$).  Returns yyok for normal return, yyaccept for YYACCEPT,
 *  yyerr for YYERROR, yyabort for YYABORT, yynomem for YYNOMEM.  */
static YYRESULTTAG
yyuserAction (yyRuleNum yyrule, int yyrhslen, yyGLRStackItem* yyvsp,
              yyGLRStack* yystackp, YYPTRDIFF_T yyk,
              YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  const yybool yynormal YY_ATTRIBUTE_UNUSED = yystackp->yysplitPoint == YY_NULLPTR;
  int yylow = 1;
  YY_USE (yyvalp);
  YY_USE (yylocp);
  YY_USE (yyparser);
  YY_USE (scanner);
  YY_USE (decls);
  YY_USE (yyk);
  YY_USE (yyrhslen);
# undef yyerrok
# define yyerrok (yystackp->yyerrState = 0)
# undef YYACCEPT
# define YYACCEPT return yyaccept
# undef YYABORT
# define YYABORT return yyabort
# undef YYNOMEM
# define YYNOMEM return yynomem
# undef YYERROR
# define YYERROR return yyerrok, yyerr
# undef YYRECOVERING
# define YYRECOVERING() (yystackp->yyerrState != 0)
# undef yyclearin
# define yyclearin (yychar = YYEMPTY)
# undef YYFILL
# define YYFILL(N) yyfill (yyvsp, &yylow, (N), yynormal)
# undef YYBACKUP
# define YYBACKUP(Token, Value)                                              \
  return yyerror (yylocp, yyparser, scanner, decls, YY_("syntax error: cannot back up")),     \
         yyerrok, yyerr

  if (yyrhslen == 0)
    *yyvalp = yyval_default;
  else
    *yyvalp = yyvsp[YYFILL (1-yyrhslen)].yystate.yysemantics.yyval;
  /* Default location. */
  YYLLOC_DEFAULT ((*yylocp), (yyvsp - yyrhslen), yyrhslen);
  yystackp->yyerror_range[1].yystate.yyloc = *yylocp;
  /* If yyk == -1, we are running a deferred action on a temporary
     stack.  In that case, YY_REDUCE_PRINT must not play with YYFILL,
     so pretend the stack is "normal". */
  YY_REDUCE_PRINT ((yynormal || yyk == -1, yyvsp, yyk, yyrule, yyparser, scanner, decls));
#if YY_EXCEPTIONS
  typedef yy::parser::syntax_error syntax_error;
  try
  {
#endif // YY_EXCEPTIONS
  switch (yyrule)
    {
  case 2: // file: IS_LITTLE_ENDIAN declarations
#line 112 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
  {
    decls->is_little_endian = ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer) == 1);
    if (decls->is_little_endian) {
      DEBUG() << "LITTLE ENDIAN ";
    } else {
      DEBUG() << "BIG ENDIAN ";
    }
  }
#line 1445 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 5: // declaration: enum_definition
#line 127 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "FOUND ENUM\n\n";
      decls->AddTypeDef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.enum_definition)->name_, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.enum_definition));
    }
#line 1454 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 6: // declaration: packet_definition
#line 132 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "FOUND PACKET\n\n";
      decls->AddPacketDef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_definition_value)->name_, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_definition_value));
    }
#line 1463 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 7: // declaration: struct_definition
#line 137 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "FOUND STRUCT\n\n";
      decls->AddTypeDef((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.struct_definition_value)->name_, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.struct_definition_value));
    }
#line 1472 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 8: // declaration: group_definition
#line 142 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      // All actions are handled in group_definition
    }
#line 1480 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 9: // declaration: checksum_definition
#line 146 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      // All actions are handled in checksum_definition
    }
#line 1488 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 10: // declaration: custom_field_definition
#line 150 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      // All actions are handled in custom_field_definition
    }
#line 1496 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 11: // declaration: test_definition
#line 154 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      // All actions are handled in test_definition
    }
#line 1504 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 12: // enum_definition: "enum" IDENTIFIER ':' INTEGER '{' enumeration_list ',' '}'
#line 160 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Enum Declared: name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string)
                << " size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.integer) << "\n";

      ((*yyvalp).enum_definition) = new EnumDef(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string)), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.integer));
      for (const auto& e : *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.enumeration_values)) {
        ((*yyvalp).enum_definition)->AddEntry(e.second, e.first);
      }
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.enumeration_values);
    }
#line 1520 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 13: // enumeration_list: enumeration
#line 174 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Enumerator with comma\n";
      ((*yyvalp).enumeration_values) = new std::map<uint64_t, std::string>();
      ((*yyvalp).enumeration_values)->insert(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.enumeration_value)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.enumeration_value);
    }
#line 1531 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 14: // enumeration_list: enumeration_list ',' enumeration
#line 181 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Enumerator with list\n";
      ((*yyvalp).enumeration_values) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.enumeration_values);
      ((*yyvalp).enumeration_values)->insert(std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.enumeration_value)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.enumeration_value);
    }
#line 1542 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 15: // enumeration: IDENTIFIER '=' INTEGER
#line 190 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Enumerator: name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string)
                << " value=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer) << "\n";
      ((*yyvalp).enumeration_value) = new std::pair((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), std::move(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
    }
#line 1553 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 16: // group_definition: "group" IDENTIFIER '{' field_definition_list '}'
#line 199 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      decls->AddGroupDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
    }
#line 1562 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 17: // checksum_definition: "checksum" IDENTIFIER ':' INTEGER STRING
#line 206 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Checksum field defined\n";
      decls->AddTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), new ChecksumDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 1573 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 18: // custom_field_definition: "custom_field" IDENTIFIER ':' INTEGER STRING
#line 215 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      decls->AddTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), new CustomFieldDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 1583 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 19: // custom_field_definition: "custom_field" IDENTIFIER STRING
#line 221 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      decls->AddTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string), new CustomFieldDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 1593 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 20: // test_definition: "test" IDENTIFIER '{' test_case_list ',' '}'
#line 229 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& packet_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string);
      DEBUG() << "Test Declared: name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string) << "\n";
      auto packet = decls->GetPacketDef(packet_name);
      if (packet == nullptr) {
        ERRORLOC(LOC) << "Could not find packet " << packet_name << "\n";
      }

      for (const auto& t : *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.test_cases_t)) {
        packet->AddTestCase(*t);
      }
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.test_cases_t);
    }
#line 1612 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 21: // test_case_list: test_case
#line 246 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Test case with comma\n";
      ((*yyvalp).test_cases_t) = new std::set<std::string*>();
      ((*yyvalp).test_cases_t)->insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.test_case_t));
    }
#line 1622 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 22: // test_case_list: test_case_list ',' test_case
#line 252 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Test case with list\n";
      ((*yyvalp).test_cases_t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.test_cases_t);
      ((*yyvalp).test_cases_t)->insert((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.test_case_t));
    }
#line 1632 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 23: // test_case: STRING
#line 260 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Test Case: name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string) << "\n";
      ((*yyvalp).test_case_t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 1641 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 24: // struct_definition: "struct" IDENTIFIER '{' field_definition_list '}'
#line 267 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& struct_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      auto&& field_definition_list = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);

      DEBUG() << "Struct " << struct_name << " with no parent";
      DEBUG() << "STRUCT FIELD LIST SIZE: " << field_definition_list.size();
      auto struct_definition = new StructDef(std::move(struct_name), std::move(field_definition_list));
      struct_definition->AssignSizeFields();

      ((*yyvalp).struct_definition_value) = struct_definition;
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);
    }
#line 1659 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 25: // struct_definition: "struct" IDENTIFIER ':' IDENTIFIER '{' field_definition_list '}'
#line 281 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& struct_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      auto&& parent_struct_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      auto&& field_definition_list = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);

      DEBUG() << "Struct " << struct_name << " with parent " << parent_struct_name << "\n";
      DEBUG() << "STRUCT FIELD LIST SIZE: " << field_definition_list.size() << "\n";

      auto parent_struct = decls->GetTypeDef(parent_struct_name);
      if (parent_struct == nullptr) {
        ERRORLOC(LOC) << "Could not find struct " << parent_struct_name
                  << " used as parent for " << struct_name;
      }

      if (parent_struct->GetDefinitionType() != TypeDef::Type::STRUCT) {
        ERRORLOC(LOC) << parent_struct_name << " is not a struct";
      }
      auto struct_definition = new StructDef(std::move(struct_name), std::move(field_definition_list), (StructDef*)parent_struct);
      struct_definition->AssignSizeFields();

      ((*yyvalp).struct_definition_value) = struct_definition;
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);
    }
#line 1689 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 26: // struct_definition: "struct" IDENTIFIER ':' IDENTIFIER '(' constraint_list ')' '{' field_definition_list '}'
#line 307 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& struct_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yyval.string);
      auto&& parent_struct_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string);
      auto&& constraints = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.constraint_list_t);
      auto&& field_definition_list = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);

      auto parent_struct = decls->GetTypeDef(parent_struct_name);
      if (parent_struct == nullptr) {
        ERRORLOC(LOC) << "Could not find struct " << parent_struct_name
                  << " used as parent for " << struct_name;
      }

      if (parent_struct->GetDefinitionType() != TypeDef::Type::STRUCT) {
        ERRORLOC(LOC) << parent_struct_name << " is not a struct";
      }

      auto struct_definition = new StructDef(std::move(struct_name), std::move(field_definition_list), (StructDef*)parent_struct);
      struct_definition->AssignSizeFields();

      for (const auto& constraint : constraints) {
        const auto& constraint_name = constraint.first;
        const auto& constraint_value = constraint.second;
        DEBUG() << "Parent constraint on " << constraint_name;
        struct_definition->AddParentConstraint(constraint_name, constraint_value);
      }

      ((*yyvalp).struct_definition_value) = struct_definition;

      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.constraint_list_t);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);
    }
#line 1727 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 27: // packet_definition: "packet" IDENTIFIER '{' field_definition_list '}'
#line 343 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& packet_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      auto&& field_definition_list = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);

      DEBUG() << "Packet " << packet_name << " with no parent";
      DEBUG() << "PACKET FIELD LIST SIZE: " << field_definition_list.size();
      auto packet_definition = new PacketDef(std::move(packet_name), std::move(field_definition_list));
      packet_definition->AssignSizeFields();

      ((*yyvalp).packet_definition_value) = packet_definition;
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);
    }
#line 1745 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 28: // packet_definition: "packet" IDENTIFIER ':' IDENTIFIER '{' field_definition_list '}'
#line 357 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& packet_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      auto&& parent_packet_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      auto&& field_definition_list = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);

      DEBUG() << "Packet " << packet_name << " with parent " << parent_packet_name << "\n";
      DEBUG() << "PACKET FIELD LIST SIZE: " << field_definition_list.size() << "\n";

      auto parent_packet = decls->GetPacketDef(parent_packet_name);
      if (parent_packet == nullptr) {
        ERRORLOC(LOC) << "Could not find packet " << parent_packet_name
                  << " used as parent for " << packet_name;
      }


      auto packet_definition = new PacketDef(std::move(packet_name), std::move(field_definition_list), parent_packet);
      packet_definition->AssignSizeFields();

      ((*yyvalp).packet_definition_value) = packet_definition;
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);
    }
#line 1773 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 29: // packet_definition: "packet" IDENTIFIER ':' IDENTIFIER '(' constraint_list ')' '{' field_definition_list '}'
#line 381 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto&& packet_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yyval.string);
      auto&& parent_packet_name = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string);
      auto&& constraints = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.constraint_list_t);
      auto&& field_definition_list = *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);

      DEBUG() << "Packet " << packet_name << " with parent " << parent_packet_name << "\n";
      DEBUG() << "PACKET FIELD LIST SIZE: " << field_definition_list.size() << "\n";
      DEBUG() << "CONSTRAINT LIST SIZE: " << constraints.size() << "\n";

      auto parent_packet = decls->GetPacketDef(parent_packet_name);
      if (parent_packet == nullptr) {
        ERRORLOC(LOC) << "Could not find packet " << parent_packet_name
                  << " used as parent for " << packet_name << "\n";
      }

      auto packet_definition = new PacketDef(std::move(packet_name), std::move(field_definition_list), parent_packet);
      packet_definition->AssignSizeFields();

      for (const auto& constraint : constraints) {
        const auto& constraint_name = constraint.first;
        const auto& constraint_value = constraint.second;
        DEBUG() << "Parent constraint on " << constraint_name;
        packet_definition->AddParentConstraint(constraint_name, constraint_value);
      }

      ((*yyvalp).packet_definition_value) = packet_definition;

      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-8)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-6)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.constraint_list_t);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.packet_field_definitions);
    }
#line 1811 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 30: // field_definition_list: %empty
#line 417 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Empty Field definition\n";
      ((*yyvalp).packet_field_definitions) = new FieldList();
    }
#line 1820 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 31: // field_definition_list: field_definition
#line 422 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Field definition\n";
      ((*yyvalp).packet_field_definitions) = new FieldList();

      if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type)->GetFieldType() == GroupField::kFieldType) {
        auto group_fields = static_cast<GroupField*>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type))->GetFields();
	FieldList reversed_fields(group_fields->rbegin(), group_fields->rend());
        for (auto& field : reversed_fields) {
          ((*yyvalp).packet_field_definitions)->PrependField(field);
        }
	delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
        break;
      }

      ((*yyvalp).packet_field_definitions)->PrependField((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type));
    }
#line 1841 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 32: // field_definition_list: field_definition ',' field_definition_list
#line 439 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Field definition with list\n";
      ((*yyvalp).packet_field_definitions) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_definitions);

      if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.packet_field_type)->GetFieldType() == GroupField::kFieldType) {
        auto group_fields = static_cast<GroupField*>((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.packet_field_type))->GetFields();
	FieldList reversed_fields(group_fields->rbegin(), group_fields->rend());
        for (auto& field : reversed_fields) {
          ((*yyvalp).packet_field_definitions)->PrependField(field);
        }
	delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.packet_field_type);
        break;
      }

      ((*yyvalp).packet_field_definitions)->PrependField((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.packet_field_type));
    }
#line 1862 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 33: // field_definition: group_field_definition
#line 458 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Group Field";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1871 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 34: // field_definition: type_def_field_definition
#line 463 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Field with a pre-defined type\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1880 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 35: // field_definition: scalar_field_definition
#line 468 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Scalar field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1889 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 36: // field_definition: checksum_start_field_definition
#line 473 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Checksum start field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1898 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 37: // field_definition: padding_field_definition
#line 478 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Padding field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1907 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 38: // field_definition: size_field_definition
#line 483 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Size field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1916 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 39: // field_definition: body_field_definition
#line 488 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Body field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1925 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 40: // field_definition: payload_field_definition
#line 493 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Payload field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1934 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 41: // field_definition: fixed_field_definition
#line 498 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Fixed field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1943 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 42: // field_definition: reserved_field_definition
#line 503 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Reserved field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1952 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 43: // field_definition: array_field_definition
#line 508 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "ARRAY field\n";
      ((*yyvalp).packet_field_type) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.packet_field_type);
    }
#line 1961 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 44: // group_field_definition: IDENTIFIER
#line 515 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      auto group = decls->GetGroupDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string));
      if (group == nullptr) {
        ERRORLOC(LOC) << "Could not find group with name " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
      }

      std::list<PacketField*>* expanded_fields;
      expanded_fields = new std::list<PacketField*>(group->begin(), group->end());
      ((*yyvalp).packet_field_type) = new GroupField(LOC, expanded_fields);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 1977 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 45: // group_field_definition: IDENTIFIER '{' constraint_list '}'
#line 527 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Group with fixed field(s) " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string) << "\n";
      auto group = decls->GetGroupDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string));
      if (group == nullptr) {
        ERRORLOC(LOC) << "Could not find group with name " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      }

      std::list<PacketField*>* expanded_fields = new std::list<PacketField*>();
      for (const auto field : *group) {
        const auto constraint = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.constraint_list_t)->find(field->GetName());
        if (constraint != (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.constraint_list_t)->end()) {
          if (field->GetFieldType() == ScalarField::kFieldType) {
            DEBUG() << "Fixing group scalar value\n";
            expanded_fields->push_back(new FixedScalarField(field->GetSize().bits(), std::get<int64_t>(constraint->second), LOC));
          } else if (field->GetFieldType() == EnumField::kFieldType) {
            DEBUG() << "Fixing group enum value\n";

            auto type_def = decls->GetTypeDef(field->GetDataType());
            EnumDef* enum_def = (type_def->GetDefinitionType() == TypeDef::Type::ENUM ? (EnumDef*)type_def : nullptr);
            if (enum_def == nullptr) {
              ERRORLOC(LOC) << "No enum found of type " << field->GetDataType();
            }
            if (!enum_def->HasEntry(std::get<std::string>(constraint->second))) {
              ERRORLOC(LOC) << "Enum " << field->GetDataType() << " has no enumeration " << std::get<std::string>(constraint->second);
            }

            expanded_fields->push_back(new FixedEnumField(enum_def, std::get<std::string>(constraint->second), LOC));
          } else {
            ERRORLOC(LOC) << "Unimplemented constraint of type " << field->GetFieldType();
          }
          (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.constraint_list_t)->erase(constraint);
        } else {
          expanded_fields->push_back(field);
        }
      }
      if ((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.constraint_list_t)->size() > 0) {
        ERRORLOC(LOC) << "Could not find member " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.constraint_list_t)->begin()->first << " in group " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      }

      ((*yyvalp).packet_field_type) = new GroupField(LOC, expanded_fields);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.constraint_list_t);
    }
#line 2025 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 46: // constraint_list: constraint ',' constraint_list
#line 573 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Group field value list\n";
      (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.constraint_list_t)->insert(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.constraint_t));
      ((*yyvalp).constraint_list_t) = (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.constraint_list_t);
      delete((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.constraint_t));
    }
#line 2036 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 47: // constraint_list: constraint
#line 580 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Group field value\n";
      ((*yyvalp).constraint_list_t) = new std::map<std::string, std::variant<int64_t, std::string>>();
      ((*yyvalp).constraint_list_t)->insert(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.constraint_t));
      delete((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.constraint_t));
    }
#line 2047 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 48: // constraint: IDENTIFIER '=' INTEGER
#line 589 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Group with a fixed integer value=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string) << " value=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer) << "\n";

      ((*yyvalp).constraint_t) = new std::pair(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string), std::variant<int64_t,std::string>((int64_t)(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
    }
#line 2058 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 49: // constraint: IDENTIFIER '=' IDENTIFIER
#line 596 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Group with a fixed enum field value=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string) << " enum=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);

      ((*yyvalp).constraint_t) = new std::pair(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string), std::variant<int64_t,std::string>(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string)));
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 2070 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 50: // type_def_field_definition: IDENTIFIER ':' IDENTIFIER
#line 606 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Predefined type field " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string) << " : " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string) << "\n";
      if (auto type_def = decls->GetTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string))) {
        ((*yyvalp).packet_field_type) = type_def->GetNewField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string), LOC);
      } else {
        ERRORLOC(LOC) << "No type with this name\n";
      }
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 2085 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 51: // scalar_field_definition: IDENTIFIER ':' INTEGER
#line 619 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Scalar field " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string) << " : " << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer) << "\n";
      ((*yyvalp).packet_field_type) = new ScalarField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
    }
#line 2095 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 52: // body_field_definition: "body"
#line 627 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Body field\n";
      ((*yyvalp).packet_field_type) = new BodyField(LOC);
    }
#line 2104 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 53: // payload_field_definition: "payload" ':' '[' SIZE_MODIFIER ']'
#line 634 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Payload field with modifier " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string) << "\n";
      ((*yyvalp).packet_field_type) = new PayloadField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
    }
#line 2114 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 54: // payload_field_definition: "payload"
#line 640 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Payload field\n";
      ((*yyvalp).packet_field_type) = new PayloadField("", LOC);
    }
#line 2123 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 55: // checksum_start_field_definition: "checksum_start" '(' IDENTIFIER ')'
#line 647 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "ChecksumStart field defined\n";
      ((*yyvalp).packet_field_type) = new ChecksumStartField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
    }
#line 2133 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 56: // padding_field_definition: "padding" '[' INTEGER ']'
#line 655 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Padding field defined\n";
      ((*yyvalp).packet_field_type) = new PaddingField((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer), LOC);
    }
#line 2142 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 57: // size_field_definition: "size" '(' IDENTIFIER ')' ':' INTEGER
#line 662 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Size field defined\n";
      ((*yyvalp).packet_field_type) = new SizeField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
    }
#line 2152 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 58: // size_field_definition: "size" '(' "payload" ')' ':' INTEGER
#line 668 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Size for payload defined\n";
      ((*yyvalp).packet_field_type) = new SizeField("payload", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), LOC);
    }
#line 2161 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 59: // size_field_definition: "size" '(' "body" ')' ':' INTEGER
#line 673 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Size for body defined\n";
      ((*yyvalp).packet_field_type) = new SizeField("body", (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), LOC);
    }
#line 2170 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 60: // size_field_definition: "count" '(' IDENTIFIER ')' ':' INTEGER
#line 678 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Count field defined\n";
      ((*yyvalp).packet_field_type) = new CountField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
    }
#line 2180 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 61: // fixed_field_definition: "fixed" '=' INTEGER ':' INTEGER
#line 686 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Fixed field defined value=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.integer) << " size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer) << "\n";
      ((*yyvalp).packet_field_type) = new FixedScalarField((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.integer), LOC);
    }
#line 2189 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 62: // fixed_field_definition: "fixed" '=' IDENTIFIER ':' IDENTIFIER
#line 691 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Fixed enum field defined value=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string) << " enum=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
      auto type_def = decls->GetTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string));
      if (type_def != nullptr) {
        EnumDef* enum_def = (type_def->GetDefinitionType() == TypeDef::Type::ENUM ? (EnumDef*)type_def : nullptr);
        if (!enum_def->HasEntry(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string))) {
          ERRORLOC(LOC) << "Previously defined enum " << enum_def->GetTypeName() << " has no entry for " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
        }

        ((*yyvalp).packet_field_type) = new FixedEnumField(enum_def, *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string), LOC);
      } else {
        ERRORLOC(LOC) << "No enum found with name " << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
      }

      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.string);
    }
#line 2211 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 63: // reserved_field_definition: "reserved" ':' INTEGER
#line 711 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Reserved field of size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer) << "\n";
      ((*yyvalp).packet_field_type) = new ReservedField((YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (0)].yystate.yysemantics.yyval.integer), LOC);
    }
#line 2220 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 64: // array_field_definition: IDENTIFIER ':' INTEGER '[' ']'
#line 718 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Vector field defined name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string) << " element_size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.integer);
      ((*yyvalp).packet_field_type) = new VectorField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.integer), "", LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string);
    }
#line 2230 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 65: // array_field_definition: IDENTIFIER ':' INTEGER '[' SIZE_MODIFIER ']'
#line 724 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Vector field defined name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string) << " element_size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.integer)
             << " size_modifier=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
      ((*yyvalp).packet_field_type) = new VectorField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.integer), *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
    }
#line 2242 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 66: // array_field_definition: IDENTIFIER ':' INTEGER '[' INTEGER ']'
#line 732 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Array field defined name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string) << " element_size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.integer)
             << " fixed_size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer);
      ((*yyvalp).packet_field_type) = new ArrayField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.integer), (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer), LOC);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
    }
#line 2253 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 67: // array_field_definition: IDENTIFIER ':' IDENTIFIER '[' ']'
#line 739 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Vector field defined name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string) << " type=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
      if (auto type_def = decls->GetTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string))) {
        ((*yyvalp).packet_field_type) = new VectorField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string), type_def, "", LOC);
      } else {
        ERRORLOC(LOC) << "Can't find type used in array field.";
      }
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-4)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-2)].yystate.yysemantics.yyval.string);
    }
#line 2268 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 68: // array_field_definition: IDENTIFIER ':' IDENTIFIER '[' SIZE_MODIFIER ']'
#line 750 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Vector field defined name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string) << " type=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string)
             << " size_modifier=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
      if (auto type_def = decls->GetTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string))) {
        ((*yyvalp).packet_field_type) = new VectorField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string), type_def, *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string), LOC);
      } else {
        ERRORLOC(LOC) << "Can't find type used in array field.";
      }
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.string);
    }
#line 2285 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;

  case 69: // array_field_definition: IDENTIFIER ':' IDENTIFIER '[' INTEGER ']'
#line 763 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
    {
      DEBUG() << "Array field defined name=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string) << " type=" << *(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string)
             << " fixed_size=" << (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer);
      if (auto type_def = decls->GetTypeDef(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string))) {
        ((*yyvalp).packet_field_type) = new ArrayField(*(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string), type_def, (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-1)].yystate.yysemantics.yyval.integer), LOC);
      } else {
        ERRORLOC(LOC) << "Can't find type used in array field.";
      }
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-5)].yystate.yysemantics.yyval.string);
      delete (YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL (-3)].yystate.yysemantics.yyval.string);
    }
#line 2301 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
    break;


#line 2305 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"

      default: break;
    }
#if YY_EXCEPTIONS
  }
  catch (const syntax_error& yyexc)
    {
      YY_DPRINTF ((stderr, "Caught exception: %s\n", yyexc.what()));
      *yylocp = yyexc.location;
      yyerror (yylocp, yyparser, scanner, decls, yyexc.what ());
      YYERROR;
    }
#endif // YY_EXCEPTIONS
  YY_SYMBOL_PRINT ("-> $$ =", yylhsNonterm (yyrule), yyvalp, yylocp);

  return yyok;
# undef yyerrok
# undef YYABORT
# undef YYACCEPT
# undef YYNOMEM
# undef YYERROR
# undef YYBACKUP
# undef yyclearin
# undef YYRECOVERING
}


static void
yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
{
  YY_USE (yy0);
  YY_USE (yy1);

  switch (yyn)
    {

      default: break;
    }
}

                              /* Bison grammar-table manipulation.  */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  YY_USE (yyparser);
  YY_USE (scanner);
  YY_USE (decls);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case S_IDENTIFIER: // IDENTIFIER
#line 106 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
            { std::cout << "DESTROYING STRING " << *((*yyvaluep).string) << "\n"; delete ((*yyvaluep).string); }
#line 2371 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
        break;

    case S_SIZE_MODIFIER: // SIZE_MODIFIER
#line 106 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
            { std::cout << "DESTROYING STRING " << *((*yyvaluep).string) << "\n"; delete ((*yyvaluep).string); }
#line 2377 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
        break;

    case S_STRING: // STRING
#line 106 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"
            { std::cout << "DESTROYING STRING " << *((*yyvaluep).string) << "\n"; delete ((*yyvaluep).string); }
#line 2383 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}

/** Number of symbols composing the right hand side of rule #RULE.  */
static inline int
yyrhsLength (yyRuleNum yyrule)
{
  return yyr2[yyrule];
}

static void
yydestroyGLRState (char const *yymsg, yyGLRState *yys, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  if (yys->yyresolved)
    yydestruct (yymsg, yy_accessing_symbol (yys->yylrState),
                &yys->yysemantics.yyval, &yys->yyloc, yyparser, scanner, decls);
  else
    {
#if YYDEBUG
      if (yydebug)
        {
          if (yys->yysemantics.yyfirstVal)
            YY_FPRINTF ((stderr, "%s unresolved", yymsg));
          else
            YY_FPRINTF ((stderr, "%s incomplete", yymsg));
          YY_SYMBOL_PRINT ("", yy_accessing_symbol (yys->yylrState), YY_NULLPTR, &yys->yyloc);
        }
#endif

      if (yys->yysemantics.yyfirstVal)
        {
          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
          yyGLRState *yyrh;
          int yyn;
          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
               yyn > 0;
               yyrh = yyrh->yypred, yyn -= 1)
            yydestroyGLRState (yymsg, yyrh, yyparser, scanner, decls);
        }
    }
}

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

/** True iff LR state YYSTATE has only a default reduction (regardless
 *  of token).  */
static inline yybool
yyisDefaultedState (yy_state_t yystate)
{
  return yypact_value_is_default (yypact[yystate]);
}

/** The default reduction for YYSTATE, assuming it has one.  */
static inline yyRuleNum
yydefaultAction (yy_state_t yystate)
{
  return yydefact[yystate];
}

#define yytable_value_is_error(Yyn) \
  0

/** The action to take in YYSTATE on seeing YYTOKEN.
 *  Result R means
 *    R < 0:  Reduce on rule -R.
 *    R = 0:  Error.
 *    R > 0:  Shift to state R.
 *  Set *YYCONFLICTS to a pointer into yyconfl to a 0-terminated list
 *  of conflicting reductions.
 */
static inline int
yygetLRActions (yy_state_t yystate, yysymbol_kind_t yytoken, const short** yyconflicts)
{
  int yyindex = yypact[yystate] + yytoken;
  if (yytoken == S_YYerror)
    {
      // This is the error token.
      *yyconflicts = yyconfl;
      return 0;
    }
  else if (yyisDefaultedState (yystate)
           || yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
    {
      *yyconflicts = yyconfl;
      return -yydefact[yystate];
    }
  else if (! yytable_value_is_error (yytable[yyindex]))
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return yytable[yyindex];
    }
  else
    {
      *yyconflicts = yyconfl + yyconflp[yyindex];
      return 0;
    }
}

/** Compute post-reduction state.
 * \param yystate   the current state
 * \param yysym     the nonterminal to push on the stack
 */
static inline yy_state_t
yyLRgotoState (yy_state_t yystate, yysymbol_kind_t yysym)
{
  int yyr = yypgoto[yysym - YYNTOKENS] + yystate;
  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
    return yytable[yyr];
  else
    return yydefgoto[yysym - YYNTOKENS];
}

static inline yybool
yyisShiftAction (int yyaction)
{
  return 0 < yyaction;
}

static inline yybool
yyisErrorAction (int yyaction)
{
  return yyaction == 0;
}

                                /* GLRStates */

/** Return a fresh GLRStackItem in YYSTACKP.  The item is an LR state
 *  if YYISSTATE, and otherwise a semantic option.  Callers should call
 *  YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
 *  headroom.  */

static inline yyGLRStackItem*
yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
{
  yyGLRStackItem* yynewItem = yystackp->yynextFree;
  yystackp->yyspaceLeft -= 1;
  yystackp->yynextFree += 1;
  yynewItem->yystate.yyisState = yyisState;
  return yynewItem;
}

/** Add a new semantic action that will execute the action for rule
 *  YYRULE on the semantic values in YYRHS to the list of
 *  alternative actions for YYSTATE.  Assumes that YYRHS comes from
 *  stack #YYK of *YYSTACKP. */
static void
yyaddDeferredAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyGLRState* yystate,
                     yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yySemanticOption* yynewOption =
    &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
  YY_ASSERT (!yynewOption->yyisState);
  yynewOption->yystate = yyrhs;
  yynewOption->yyrule = yyrule;
  if (yystackp->yytops.yylookaheadNeeds[yyk])
    {
      yynewOption->yyrawchar = yychar;
      yynewOption->yyval = yylval;
      yynewOption->yyloc = yylloc;
    }
  else
    yynewOption->yyrawchar = YYEMPTY;
  yynewOption->yynext = yystate->yysemantics.yyfirstVal;
  yystate->yysemantics.yyfirstVal = yynewOption;

  YY_RESERVE_GLRSTACK (yystackp);
}

                                /* GLRStacks */

/** Initialize YYSET to a singleton set containing an empty stack.  */
static yybool
yyinitStateSet (yyGLRStateSet* yyset)
{
  yyset->yysize = 1;
  yyset->yycapacity = 16;
  yyset->yystates
    = YY_CAST (yyGLRState**,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yystates[0]));
  if (! yyset->yystates)
    return yyfalse;
  yyset->yystates[0] = YY_NULLPTR;
  yyset->yylookaheadNeeds
    = YY_CAST (yybool*,
               YYMALLOC (YY_CAST (YYSIZE_T, yyset->yycapacity)
                         * sizeof yyset->yylookaheadNeeds[0]));
  if (! yyset->yylookaheadNeeds)
    {
      YYFREE (yyset->yystates);
      return yyfalse;
    }
  memset (yyset->yylookaheadNeeds,
          0,
          YY_CAST (YYSIZE_T, yyset->yycapacity) * sizeof yyset->yylookaheadNeeds[0]);
  return yytrue;
}

static void yyfreeStateSet (yyGLRStateSet* yyset)
{
  YYFREE (yyset->yystates);
  YYFREE (yyset->yylookaheadNeeds);
}

/** Initialize *YYSTACKP to a single empty stack, with total maximum
 *  capacity for all stacks of YYSIZE.  */
static yybool
yyinitGLRStack (yyGLRStack* yystackp, YYPTRDIFF_T yysize)
{
  yystackp->yyerrState = 0;
  yynerrs = 0;
  yystackp->yyspaceLeft = yysize;
  yystackp->yyitems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yysize)
                         * sizeof yystackp->yynextFree[0]));
  if (!yystackp->yyitems)
    return yyfalse;
  yystackp->yynextFree = yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;
  return yyinitStateSet (&yystackp->yytops);
}


#if YYSTACKEXPANDABLE
# define YYRELOC(YYFROMITEMS, YYTOITEMS, YYX, YYTYPE)                   \
  &((YYTOITEMS)                                                         \
    - ((YYFROMITEMS) - YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX))))->YYTYPE

/** If *YYSTACKP is expandable, extend it.  WARNING: Pointers into the
    stack from outside should be considered invalid after this call.
    We always expand when there are 1 or fewer items left AFTER an
    allocation, so that we can avoid having external pointers exist
    across an allocation.  */
static void
yyexpandGLRStack (yyGLRStack* yystackp)
{
  yyGLRStackItem* yynewItems;
  yyGLRStackItem* yyp0, *yyp1;
  YYPTRDIFF_T yynewSize;
  YYPTRDIFF_T yyn;
  YYPTRDIFF_T yysize = yystackp->yynextFree - yystackp->yyitems;
  if (YYMAXDEPTH - YYHEADROOM < yysize)
    yyMemoryExhausted (yystackp);
  yynewSize = 2*yysize;
  if (YYMAXDEPTH < yynewSize)
    yynewSize = YYMAXDEPTH;
  yynewItems
    = YY_CAST (yyGLRStackItem*,
               YYMALLOC (YY_CAST (YYSIZE_T, yynewSize)
                         * sizeof yynewItems[0]));
  if (! yynewItems)
    yyMemoryExhausted (yystackp);
  for (yyp0 = yystackp->yyitems, yyp1 = yynewItems, yyn = yysize;
       0 < yyn;
       yyn -= 1, yyp0 += 1, yyp1 += 1)
    {
      *yyp1 = *yyp0;
      if (*YY_REINTERPRET_CAST (yybool *, yyp0))
        {
          yyGLRState* yys0 = &yyp0->yystate;
          yyGLRState* yys1 = &yyp1->yystate;
          if (yys0->yypred != YY_NULLPTR)
            yys1->yypred =
              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULLPTR)
            yys1->yysemantics.yyfirstVal =
              YYRELOC (yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
        }
      else
        {
          yySemanticOption* yyv0 = &yyp0->yyoption;
          yySemanticOption* yyv1 = &yyp1->yyoption;
          if (yyv0->yystate != YY_NULLPTR)
            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
          if (yyv0->yynext != YY_NULLPTR)
            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
        }
    }
  if (yystackp->yysplitPoint != YY_NULLPTR)
    yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
                                      yystackp->yysplitPoint, yystate);

  for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
    if (yystackp->yytops.yystates[yyn] != YY_NULLPTR)
      yystackp->yytops.yystates[yyn] =
        YYRELOC (yystackp->yyitems, yynewItems,
                 yystackp->yytops.yystates[yyn], yystate);
  YYFREE (yystackp->yyitems);
  yystackp->yyitems = yynewItems;
  yystackp->yynextFree = yynewItems + yysize;
  yystackp->yyspaceLeft = yynewSize - yysize;
}
#endif

static void
yyfreeGLRStack (yyGLRStack* yystackp)
{
  YYFREE (yystackp->yyitems);
  yyfreeStateSet (&yystackp->yytops);
}

/** Assuming that YYS is a GLRState somewhere on *YYSTACKP, update the
 *  splitpoint of *YYSTACKP, if needed, so that it is at least as deep as
 *  YYS.  */
static inline void
yyupdateSplit (yyGLRStack* yystackp, yyGLRState* yys)
{
  if (yystackp->yysplitPoint != YY_NULLPTR && yystackp->yysplitPoint > yys)
    yystackp->yysplitPoint = yys;
}

/** Invalidate stack #YYK in *YYSTACKP.  */
static inline void
yymarkStackDeleted (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    yystackp->yylastDeleted = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yystates[yyk] = YY_NULLPTR;
}

/** Undelete the last stack in *YYSTACKP that was marked as deleted.  Can
    only be done once after a deletion, and only when all other stacks have
    been deleted.  */
static void
yyundeleteLastStack (yyGLRStack* yystackp)
{
  if (yystackp->yylastDeleted == YY_NULLPTR || yystackp->yytops.yysize != 0)
    return;
  yystackp->yytops.yystates[0] = yystackp->yylastDeleted;
  yystackp->yytops.yysize = 1;
  YY_DPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
  yystackp->yylastDeleted = YY_NULLPTR;
}

static inline void
yyremoveDeletes (yyGLRStack* yystackp)
{
  YYPTRDIFF_T yyi, yyj;
  yyi = yyj = 0;
  while (yyj < yystackp->yytops.yysize)
    {
      if (yystackp->yytops.yystates[yyi] == YY_NULLPTR)
        {
          if (yyi == yyj)
            YY_DPRINTF ((stderr, "Removing dead stacks.\n"));
          yystackp->yytops.yysize -= 1;
        }
      else
        {
          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
          /* In the current implementation, it's unnecessary to copy
             yystackp->yytops.yylookaheadNeeds[yyi] since, after
             yyremoveDeletes returns, the parser immediately either enters
             deterministic operation or shifts a token.  However, it doesn't
             hurt, and the code might evolve to need it.  */
          yystackp->yytops.yylookaheadNeeds[yyj] =
            yystackp->yytops.yylookaheadNeeds[yyi];
          if (yyj != yyi)
            YY_DPRINTF ((stderr, "Rename stack %ld -> %ld.\n",
                        YY_CAST (long, yyi), YY_CAST (long, yyj)));
          yyj += 1;
        }
      yyi += 1;
    }
}

/** Shift to a new state on stack #YYK of *YYSTACKP, corresponding to LR
 * state YYLRSTATE, at input position YYPOSN, with (resolved) semantic
 * value *YYVALP and source location *YYLOCP.  */
static inline void
yyglrShift (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
            YYPTRDIFF_T yyposn,
            YYSTYPE* yyvalp, YYLTYPE* yylocp)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yytrue;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyval = *yyvalp;
  yynewState->yyloc = *yylocp;
  yystackp->yytops.yystates[yyk] = yynewState;

  YY_RESERVE_GLRSTACK (yystackp);
}

/** Shift stack #YYK of *YYSTACKP, to a new state corresponding to LR
 *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
 *  semantic value of YYRHS under the action for YYRULE.  */
static inline void
yyglrShiftDefer (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yy_state_t yylrState,
                 YYPTRDIFF_T yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
{
  yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
  YY_ASSERT (yynewState->yyisState);

  yynewState->yylrState = yylrState;
  yynewState->yyposn = yyposn;
  yynewState->yyresolved = yyfalse;
  yynewState->yypred = yystackp->yytops.yystates[yyk];
  yynewState->yysemantics.yyfirstVal = YY_NULLPTR;
  yystackp->yytops.yystates[yyk] = yynewState;

  /* Invokes YY_RESERVE_GLRSTACK.  */
  yyaddDeferredAction (yystackp, yyk, yynewState, yyrhs, yyrule);
}

#if YYDEBUG

/*----------------------------------------------------------------------.
| Report that stack #YYK of *YYSTACKP is going to be reduced by YYRULE. |
`----------------------------------------------------------------------*/

static inline void
yy_reduce_print (yybool yynormal, yyGLRStackItem* yyvsp, YYPTRDIFF_T yyk,
                 yyRuleNum yyrule, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  int yynrhs = yyrhsLength (yyrule);
  int yylow = 1;
  int yyi;
  YY_FPRINTF ((stderr, "Reducing stack %ld by rule %d (line %d):\n",
               YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
  if (! yynormal)
    yyfillin (yyvsp, 1, -yynrhs);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YY_FPRINTF ((stderr, "   $%d = ", yyi + 1));
      yy_symbol_print (stderr,
                       yy_accessing_symbol (yyvsp[yyi - yynrhs + 1].yystate.yylrState),
                       &yyvsp[yyi - yynrhs + 1].yystate.yysemantics.yyval,
                       &(YY_CAST (yyGLRStackItem const *, yyvsp)[YYFILL ((yyi + 1) - (yynrhs))].yystate.yyloc)                       , yyparser, scanner, decls);
      if (!yyvsp[yyi - yynrhs + 1].yystate.yyresolved)
        YY_FPRINTF ((stderr, " (unresolved)"));
      YY_FPRINTF ((stderr, "\n"));
    }
}
#endif

/** Pop the symbols consumed by reduction #YYRULE from the top of stack
 *  #YYK of *YYSTACKP, and perform the appropriate semantic action on their
 *  semantic values.  Assumes that all ambiguities in semantic values
 *  have been previously resolved.  Set *YYVALP to the resulting value,
 *  and *YYLOCP to the computed location (if any).  Return value is as
 *  for userAction.  */
static inline YYRESULTTAG
yydoAction (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
            YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  int yynrhs = yyrhsLength (yyrule);

  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      /* Standard special case: single stack.  */
      yyGLRStackItem* yyrhs
        = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yytops.yystates[yyk]);
      YY_ASSERT (yyk == 0);
      yystackp->yynextFree -= yynrhs;
      yystackp->yyspaceLeft += yynrhs;
      yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
      return yyuserAction (yyrule, yynrhs, yyrhs, yystackp, yyk,
                           yyvalp, yylocp, yyparser, scanner, decls);
    }
  else
    {
      yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
      yyGLRState* yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
        = yystackp->yytops.yystates[yyk];
      int yyi;
      if (yynrhs == 0)
        /* Set default location.  */
        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;
      for (yyi = 0; yyi < yynrhs; yyi += 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yystackp->yytops.yystates[yyk] = yys;
      return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, yyk, yyvalp, yylocp, yyparser, scanner, decls);
    }
}

/** Pop items off stack #YYK of *YYSTACKP according to grammar rule YYRULE,
 *  and push back on the resulting nonterminal symbol.  Perform the
 *  semantic action associated with YYRULE and store its value with the
 *  newly pushed state, if YYFORCEEVAL or if *YYSTACKP is currently
 *  unambiguous.  Otherwise, store the deferred semantic action with
 *  the new state.  If the new state would have an identical input
 *  position, LR state, and predecessor to an existing state on the stack,
 *  it is identified with that existing state, eliminating stack #YYK from
 *  *YYSTACKP.  In this case, the semantic value is
 *  added to the options for the existing state's semantic value.
 */
static inline YYRESULTTAG
yyglrReduce (yyGLRStack* yystackp, YYPTRDIFF_T yyk, yyRuleNum yyrule,
             yybool yyforceEval, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  YYPTRDIFF_T yyposn = yystackp->yytops.yystates[yyk]->yyposn;

  if (yyforceEval || yystackp->yysplitPoint == YY_NULLPTR)
    {
      YYSTYPE yyval;
      YYLTYPE yyloc;

      YYRESULTTAG yyflag = yydoAction (yystackp, yyk, yyrule, &yyval, &yyloc, yyparser, scanner, decls);
      if (yyflag == yyerr && yystackp->yysplitPoint != YY_NULLPTR)
        YY_DPRINTF ((stderr,
                     "Parse on stack %ld rejected by rule %d (line %d).\n",
                     YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule]));
      if (yyflag != yyok)
        return yyflag;
      yyglrShift (yystackp, yyk,
                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
                                 yylhsNonterm (yyrule)),
                  yyposn, &yyval, &yyloc);
    }
  else
    {
      YYPTRDIFF_T yyi;
      int yyn;
      yyGLRState* yys, *yys0 = yystackp->yytops.yystates[yyk];
      yy_state_t yynewLRState;

      for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
           0 < yyn; yyn -= 1)
        {
          yys = yys->yypred;
          YY_ASSERT (yys);
        }
      yyupdateSplit (yystackp, yys);
      yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
      YY_DPRINTF ((stderr,
                   "Reduced stack %ld by rule %d (line %d); action deferred.  "
                   "Now in state %d.\n",
                   YY_CAST (long, yyk), yyrule - 1, yyrline[yyrule],
                   yynewLRState));
      for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULLPTR)
          {
            yyGLRState *yysplit = yystackp->yysplitPoint;
            yyGLRState *yyp = yystackp->yytops.yystates[yyi];
            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
              {
                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
                  {
                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
                    yymarkStackDeleted (yystackp, yyk);
                    YY_DPRINTF ((stderr, "Merging stack %ld into stack %ld.\n",
                                 YY_CAST (long, yyk), YY_CAST (long, yyi)));
                    return yyok;
                  }
                yyp = yyp->yypred;
              }
          }
      yystackp->yytops.yystates[yyk] = yys;
      yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
    }
  return yyok;
}

static YYPTRDIFF_T
yysplitStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  if (yystackp->yysplitPoint == YY_NULLPTR)
    {
      YY_ASSERT (yyk == 0);
      yystackp->yysplitPoint = yystackp->yytops.yystates[yyk];
    }
  if (yystackp->yytops.yycapacity <= yystackp->yytops.yysize)
    {
      YYPTRDIFF_T state_size = YYSIZEOF (yystackp->yytops.yystates[0]);
      YYPTRDIFF_T half_max_capacity = YYSIZE_MAXIMUM / 2 / state_size;
      if (half_max_capacity < yystackp->yytops.yycapacity)
        yyMemoryExhausted (yystackp);
      yystackp->yytops.yycapacity *= 2;

      {
        yyGLRState** yynewStates
          = YY_CAST (yyGLRState**,
                     YYREALLOC (yystackp->yytops.yystates,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewStates[0])));
        if (yynewStates == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yystates = yynewStates;
      }

      {
        yybool* yynewLookaheadNeeds
          = YY_CAST (yybool*,
                     YYREALLOC (yystackp->yytops.yylookaheadNeeds,
                                (YY_CAST (YYSIZE_T, yystackp->yytops.yycapacity)
                                 * sizeof yynewLookaheadNeeds[0])));
        if (yynewLookaheadNeeds == YY_NULLPTR)
          yyMemoryExhausted (yystackp);
        yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
      }
    }
  yystackp->yytops.yystates[yystackp->yytops.yysize]
    = yystackp->yytops.yystates[yyk];
  yystackp->yytops.yylookaheadNeeds[yystackp->yytops.yysize]
    = yystackp->yytops.yylookaheadNeeds[yyk];
  yystackp->yytops.yysize += 1;
  return yystackp->yytops.yysize - 1;
}

/** True iff YYY0 and YYY1 represent identical options at the top level.
 *  That is, they represent the same rule applied to RHS symbols
 *  that produce the same terminal symbols.  */
static yybool
yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  if (yyy0->yyrule == yyy1->yyrule)
    {
      yyGLRState *yys0, *yys1;
      int yyn;
      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
           yyn = yyrhsLength (yyy0->yyrule);
           yyn > 0;
           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
        if (yys0->yyposn != yys1->yyposn)
          return yyfalse;
      return yytrue;
    }
  else
    return yyfalse;
}

/** Assuming identicalOptions (YYY0,YYY1), destructively merge the
 *  alternative semantic values for the RHS-symbols of YYY1 and YYY0.  */
static void
yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
{
  yyGLRState *yys0, *yys1;
  int yyn;
  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
       yyn = yyrhsLength (yyy0->yyrule);
       0 < yyn;
       yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
    {
      if (yys0 == yys1)
        break;
      else if (yys0->yyresolved)
        {
          yys1->yyresolved = yytrue;
          yys1->yysemantics.yyval = yys0->yysemantics.yyval;
        }
      else if (yys1->yyresolved)
        {
          yys0->yyresolved = yytrue;
          yys0->yysemantics.yyval = yys1->yysemantics.yyval;
        }
      else
        {
          yySemanticOption** yyz0p = &yys0->yysemantics.yyfirstVal;
          yySemanticOption* yyz1 = yys1->yysemantics.yyfirstVal;
          while (yytrue)
            {
              if (yyz1 == *yyz0p || yyz1 == YY_NULLPTR)
                break;
              else if (*yyz0p == YY_NULLPTR)
                {
                  *yyz0p = yyz1;
                  break;
                }
              else if (*yyz0p < yyz1)
                {
                  yySemanticOption* yyz = *yyz0p;
                  *yyz0p = yyz1;
                  yyz1 = yyz1->yynext;
                  (*yyz0p)->yynext = yyz;
                }
              yyz0p = &(*yyz0p)->yynext;
            }
          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
        }
    }
}

/** Y0 and Y1 represent two possible actions to take in a given
 *  parsing state; return 0 if no combination is possible,
 *  1 if user-mergeable, 2 if Y0 is preferred, 3 if Y1 is preferred.  */
static int
yypreference (yySemanticOption* y0, yySemanticOption* y1)
{
  yyRuleNum r0 = y0->yyrule, r1 = y1->yyrule;
  int p0 = yydprec[r0], p1 = yydprec[r1];

  if (p0 == p1)
    {
      if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
        return 0;
      else
        return 1;
    }
  if (p0 == 0 || p1 == 0)
    return 0;
  if (p0 < p1)
    return 3;
  if (p1 < p0)
    return 2;
  return 0;
}

static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls);


/** Resolve the previous YYN states starting at and including state YYS
 *  on *YYSTACKP. If result != yyok, some states may have been left
 *  unresolved possibly with empty semantic option chains.  Regardless
 *  of whether result = yyok, each state has been left with consistent
 *  data so that yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveStates (yyGLRState* yys, int yyn,
                 yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  if (0 < yyn)
    {
      YY_ASSERT (yys->yypred);
      YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp, yyparser, scanner, decls));
      if (! yys->yyresolved)
        YYCHK (yyresolveValue (yys, yystackp, yyparser, scanner, decls));
    }
  return yyok;
}

/** Resolve the states for the RHS of YYOPT on *YYSTACKP, perform its
 *  user action, and return the semantic value and location in *YYVALP
 *  and *YYLOCP.  Regardless of whether result = yyok, all RHS states
 *  have been destroyed (assuming the user action destroys all RHS
 *  semantic values if invoked).  */
static YYRESULTTAG
yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
                 YYSTYPE* yyvalp, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
  int yynrhs = yyrhsLength (yyopt->yyrule);
  YYRESULTTAG yyflag =
    yyresolveStates (yyopt->yystate, yynrhs, yystackp, yyparser, scanner, decls);
  if (yyflag != yyok)
    {
      yyGLRState *yys;
      for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
        yydestroyGLRState ("Cleanup: popping", yys, yyparser, scanner, decls);
      return yyflag;
    }

  yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred = yyopt->yystate;
  if (yynrhs == 0)
    /* Set default location.  */
    yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yyopt->yystate->yyloc;
  {
    int yychar_current = yychar;
    YYSTYPE yylval_current = yylval;
    YYLTYPE yylloc_current = yylloc;
    yychar = yyopt->yyrawchar;
    yylval = yyopt->yyval;
    yylloc = yyopt->yyloc;
    yyflag = yyuserAction (yyopt->yyrule, yynrhs,
                           yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
                           yystackp, -1, yyvalp, yylocp, yyparser, scanner, decls);
    yychar = yychar_current;
    yylval = yylval_current;
    yylloc = yylloc_current;
  }
  return yyflag;
}

#if YYDEBUG
static void
yyreportTree (yySemanticOption* yyx, int yyindent)
{
  int yynrhs = yyrhsLength (yyx->yyrule);
  int yyi;
  yyGLRState* yys;
  yyGLRState* yystates[1 + YYMAXRHS];
  yyGLRState yyleftmost_state;

  for (yyi = yynrhs, yys = yyx->yystate; 0 < yyi; yyi -= 1, yys = yys->yypred)
    yystates[yyi] = yys;
  if (yys == YY_NULLPTR)
    {
      yyleftmost_state.yyposn = 0;
      yystates[0] = &yyleftmost_state;
    }
  else
    yystates[0] = yys;

  if (yyx->yystate->yyposn < yys->yyposn + 1)
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, empty>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1));
  else
    YY_FPRINTF ((stderr, "%*s%s -> <Rule %d, tokens %ld .. %ld>\n",
                 yyindent, "", yysymbol_name (yylhsNonterm (yyx->yyrule)),
                 yyx->yyrule - 1, YY_CAST (long, yys->yyposn + 1),
                 YY_CAST (long, yyx->yystate->yyposn)));
  for (yyi = 1; yyi <= yynrhs; yyi += 1)
    {
      if (yystates[yyi]->yyresolved)
        {
          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
            YY_FPRINTF ((stderr, "%*s%s <empty>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState))));
          else
            YY_FPRINTF ((stderr, "%*s%s <tokens %ld .. %ld>\n", yyindent+2, "",
                         yysymbol_name (yy_accessing_symbol (yystates[yyi]->yylrState)),
                         YY_CAST (long, yystates[yyi-1]->yyposn + 1),
                         YY_CAST (long, yystates[yyi]->yyposn)));
        }
      else
        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
    }
}
#endif

static YYRESULTTAG
yyreportAmbiguity (yySemanticOption* yyx0,
                   yySemanticOption* yyx1, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  YY_USE (yyx0);
  YY_USE (yyx1);

#if YYDEBUG
  YY_FPRINTF ((stderr, "Ambiguity detected.\n"));
  YY_FPRINTF ((stderr, "Option 1,\n"));
  yyreportTree (yyx0, 2);
  YY_FPRINTF ((stderr, "\nOption 2,\n"));
  yyreportTree (yyx1, 2);
  YY_FPRINTF ((stderr, "\n"));
#endif

  yyerror (yylocp, yyparser, scanner, decls, YY_("syntax is ambiguous"));
  return yyabort;
}

/** Resolve the locations for each of the YYN1 states in *YYSTACKP,
 *  ending at YYS1.  Has no effect on previously resolved states.
 *  The first semantic option of a state is always chosen.  */
static void
yyresolveLocations (yyGLRState *yys1, int yyn1,
                    yyGLRStack *yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  if (0 < yyn1)
    {
      yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp, yyparser, scanner, decls);
      if (!yys1->yyresolved)
        {
          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
          int yynrhs;
          yySemanticOption *yyoption = yys1->yysemantics.yyfirstVal;
          YY_ASSERT (yyoption);
          yynrhs = yyrhsLength (yyoption->yyrule);
          if (0 < yynrhs)
            {
              yyGLRState *yys;
              int yyn;
              yyresolveLocations (yyoption->yystate, yynrhs,
                                  yystackp, yyparser, scanner, decls);
              for (yys = yyoption->yystate, yyn = yynrhs;
                   yyn > 0;
                   yys = yys->yypred, yyn -= 1)
                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
            }
          else
            {
              /* Both yyresolveAction and yyresolveLocations traverse the GSS
                 in reverse rightmost order.  It is only necessary to invoke
                 yyresolveLocations on a subforest for which yyresolveAction
                 would have been invoked next had an ambiguity not been
                 detected.  Thus the location of the previous state (but not
                 necessarily the previous state itself) is guaranteed to be
                 resolved already.  */
              yyGLRState *yyprevious = yyoption->yystate;
              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
            }
          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
        }
    }
}

/** Resolve the ambiguity represented in state YYS in *YYSTACKP,
 *  perform the indicated actions, and set the semantic value of YYS.
 *  If result != yyok, the chain of semantic options in YYS has been
 *  cleared instead or it has been left unmodified except that
 *  redundant options may have been removed.  Regardless of whether
 *  result = yyok, YYS has been left with consistent data so that
 *  yydestroyGLRState can be invoked if necessary.  */
static YYRESULTTAG
yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  yySemanticOption* yyoptionList = yys->yysemantics.yyfirstVal;
  yySemanticOption* yybest = yyoptionList;
  yySemanticOption** yypp;
  yybool yymerge = yyfalse;
  YYSTYPE yyval;
  YYRESULTTAG yyflag;
  YYLTYPE *yylocp = &yys->yyloc;

  for (yypp = &yyoptionList->yynext; *yypp != YY_NULLPTR; )
    {
      yySemanticOption* yyp = *yypp;

      if (yyidenticalOptions (yybest, yyp))
        {
          yymergeOptionSets (yybest, yyp);
          *yypp = yyp->yynext;
        }
      else
        {
          switch (yypreference (yybest, yyp))
            {
            case 0:
              yyresolveLocations (yys, 1, yystackp, yyparser, scanner, decls);
              return yyreportAmbiguity (yybest, yyp, yylocp, yyparser, scanner, decls);
              break;
            case 1:
              yymerge = yytrue;
              break;
            case 2:
              break;
            case 3:
              yybest = yyp;
              yymerge = yyfalse;
              break;
            default:
              /* This cannot happen so it is not worth a YY_ASSERT (yyfalse),
                 but some compilers complain if the default case is
                 omitted.  */
              break;
            }
          yypp = &yyp->yynext;
        }
    }

  if (yymerge)
    {
      yySemanticOption* yyp;
      int yyprec = yydprec[yybest->yyrule];
      yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, yyparser, scanner, decls);
      if (yyflag == yyok)
        for (yyp = yybest->yynext; yyp != YY_NULLPTR; yyp = yyp->yynext)
          {
            if (yyprec == yydprec[yyp->yyrule])
              {
                YYSTYPE yyval_other;
                YYLTYPE yydummy;
                yyflag = yyresolveAction (yyp, yystackp, &yyval_other, &yydummy, yyparser, scanner, decls);
                if (yyflag != yyok)
                  {
                    yydestruct ("Cleanup: discarding incompletely merged value for",
                                yy_accessing_symbol (yys->yylrState),
                                &yyval, yylocp, yyparser, scanner, decls);
                    break;
                  }
                yyuserMerge (yymerger[yyp->yyrule], &yyval, &yyval_other);
              }
          }
    }
  else
    yyflag = yyresolveAction (yybest, yystackp, &yyval, yylocp, yyparser, scanner, decls);

  if (yyflag == yyok)
    {
      yys->yyresolved = yytrue;
      yys->yysemantics.yyval = yyval;
    }
  else
    yys->yysemantics.yyfirstVal = YY_NULLPTR;
  return yyflag;
}

static YYRESULTTAG
yyresolveStack (yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  if (yystackp->yysplitPoint != YY_NULLPTR)
    {
      yyGLRState* yys;
      int yyn;

      for (yyn = 0, yys = yystackp->yytops.yystates[0];
           yys != yystackp->yysplitPoint;
           yys = yys->yypred, yyn += 1)
        continue;
      YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
                             , yyparser, scanner, decls));
    }
  return yyok;
}

/** Called when returning to deterministic operation to clean up the extra
 * stacks. */
static void
yycompressStack (yyGLRStack* yystackp)
{
  /* yyr is the state after the split point.  */
  yyGLRState *yyr;

  if (yystackp->yytops.yysize != 1 || yystackp->yysplitPoint == YY_NULLPTR)
    return;

  {
    yyGLRState *yyp, *yyq;
    for (yyp = yystackp->yytops.yystates[0], yyq = yyp->yypred, yyr = YY_NULLPTR;
         yyp != yystackp->yysplitPoint;
         yyr = yyp, yyp = yyq, yyq = yyp->yypred)
      yyp->yypred = yyr;
  }

  yystackp->yyspaceLeft += yystackp->yynextFree - yystackp->yyitems;
  yystackp->yynextFree = YY_REINTERPRET_CAST (yyGLRStackItem*, yystackp->yysplitPoint) + 1;
  yystackp->yyspaceLeft -= yystackp->yynextFree - yystackp->yyitems;
  yystackp->yysplitPoint = YY_NULLPTR;
  yystackp->yylastDeleted = YY_NULLPTR;

  while (yyr != YY_NULLPTR)
    {
      yystackp->yynextFree->yystate = *yyr;
      yyr = yyr->yypred;
      yystackp->yynextFree->yystate.yypred = &yystackp->yynextFree[-1].yystate;
      yystackp->yytops.yystates[0] = &yystackp->yynextFree->yystate;
      yystackp->yynextFree += 1;
      yystackp->yyspaceLeft -= 1;
    }
}

static YYRESULTTAG
yyprocessOneStack (yyGLRStack* yystackp, YYPTRDIFF_T yyk,
                   YYPTRDIFF_T yyposn, YYLTYPE *yylocp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  while (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
    {
      yy_state_t yystate = yystackp->yytops.yystates[yyk]->yylrState;
      YY_DPRINTF ((stderr, "Stack %ld Entering state %d\n",
                   YY_CAST (long, yyk), yystate));

      YY_ASSERT (yystate != YYFINAL);

      if (yyisDefaultedState (yystate))
        {
          YYRESULTTAG yyflag;
          yyRuleNum yyrule = yydefaultAction (yystate);
          if (yyrule == 0)
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          yyflag = yyglrReduce (yystackp, yyk, yyrule, yyimmediate[yyrule], yyparser, scanner, decls);
          if (yyflag == yyerr)
            {
              YY_DPRINTF ((stderr,
                           "Stack %ld dies "
                           "(predicate failure or explicit user error).\n",
                           YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              return yyok;
            }
          if (yyflag != yyok)
            return yyflag;
        }
      else
        {
          yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, yyparser, scanner, decls);
          const short* yyconflicts;
          const int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;

          for (/* nothing */; *yyconflicts; yyconflicts += 1)
            {
              YYRESULTTAG yyflag;
              YYPTRDIFF_T yynewStack = yysplitStack (yystackp, yyk);
              YY_DPRINTF ((stderr, "Splitting off stack %ld from %ld.\n",
                           YY_CAST (long, yynewStack), YY_CAST (long, yyk)));
              yyflag = yyglrReduce (yystackp, yynewStack,
                                    *yyconflicts,
                                    yyimmediate[*yyconflicts], yyparser, scanner, decls);
              if (yyflag == yyok)
                YYCHK (yyprocessOneStack (yystackp, yynewStack,
                                          yyposn, yylocp, yyparser, scanner, decls));
              else if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yynewStack)));
                  yymarkStackDeleted (yystackp, yynewStack);
                }
              else
                return yyflag;
            }

          if (yyisShiftAction (yyaction))
            break;
          else if (yyisErrorAction (yyaction))
            {
              YY_DPRINTF ((stderr, "Stack %ld dies.\n", YY_CAST (long, yyk)));
              yymarkStackDeleted (yystackp, yyk);
              break;
            }
          else
            {
              YYRESULTTAG yyflag = yyglrReduce (yystackp, yyk, -yyaction,
                                                yyimmediate[-yyaction], yyparser, scanner, decls);
              if (yyflag == yyerr)
                {
                  YY_DPRINTF ((stderr,
                               "Stack %ld dies "
                               "(predicate failure or explicit user error).\n",
                               YY_CAST (long, yyk)));
                  yymarkStackDeleted (yystackp, yyk);
                  break;
                }
              else if (yyflag != yyok)
                return yyflag;
            }
        }
    }
  return yyok;
}

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYSTACKP, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  */
static int
yypcontext_expected_tokens (const yyGLRStack* yystackp,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[yystackp->yytops.yystates[0]->yylrState];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != S_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = S_YYEMPTY;
  return yycount;
}

static int
yy_syntax_error_arguments (const yyGLRStack* yystackp,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  yysymbol_kind_t yytoken = yychar == YYEMPTY ? S_YYEMPTY : YYTRANSLATE (yychar);
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != S_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yystackp,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}



static void
yyreportSyntaxError (yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  if (yystackp->yyerrState != 0)
    return;
  {
  yybool yysize_overflow = yyfalse;
  char* yymsg = YY_NULLPTR;
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount
    = yy_syntax_error_arguments (yystackp, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    yyMemoryExhausted (yystackp);

  switch (yycount)
    {
#define YYCASE_(N, S)                   \
      case N:                           \
        yyformat = S;                   \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysz
          = yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (YYSIZE_MAXIMUM - yysize < yysz)
          yysize_overflow = yytrue;
        else
          yysize += yysz;
      }
  }

  if (!yysize_overflow)
    yymsg = YY_CAST (char *, YYMALLOC (YY_CAST (YYSIZE_T, yysize)));

  if (yymsg)
    {
      char *yyp = yymsg;
      int yyi = 0;
      while ((*yyp = *yyformat))
        {
          if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
            {
              yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
              yyformat += 2;
            }
          else
            {
              ++yyp;
              ++yyformat;
            }
        }
      yyerror (&yylloc, yyparser, scanner, decls, yymsg);
      YYFREE (yymsg);
    }
  else
    {
      yyerror (&yylloc, yyparser, scanner, decls, YY_("syntax error"));
      yyMemoryExhausted (yystackp);
    }
  }
  yynerrs += 1;
}

/* Recover from a syntax error on *YYSTACKP, assuming that *YYSTACKP->YYTOKENP,
   yylval, and yylloc are the syntactic category, semantic value, and location
   of the lookahead.  */
static void
yyrecoverSyntaxError (yyGLRStack* yystackp, yy::parser& yyparser, void* scanner, Declarations* decls)
{
  if (yystackp->yyerrState == 3)
    /* We just shifted the error token and (perhaps) took some
       reductions.  Skip tokens until we can proceed.  */
    while (yytrue)
      {
        yysymbol_kind_t yytoken;
        int yyj;
        if (yychar == YYEOF)
          yyFail (yystackp, &yylloc, yyparser, scanner, decls, YY_NULLPTR);
        if (yychar != YYEMPTY)
          {
            /* We throw away the lookahead, but the error range
               of the shifted error token must take it into account.  */
            yyGLRState *yys = yystackp->yytops.yystates[0];
            yyGLRStackItem yyerror_range[3];
            yyerror_range[1].yystate.yyloc = yys->yyloc;
            yyerror_range[2].yystate.yyloc = yylloc;
            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);
            yytoken = YYTRANSLATE (yychar);
            yydestruct ("Error: discarding",
                        yytoken, &yylval, &yylloc, yyparser, scanner, decls);
            yychar = YYEMPTY;
          }
        yytoken = yygetToken (&yychar, yystackp, yyparser, scanner, decls);
        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
        if (yypact_value_is_default (yyj))
          return;
        yyj += yytoken;
        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
          {
            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
              return;
          }
        else if (! yytable_value_is_error (yytable[yyj]))
          return;
      }

  /* Reduce to one stack.  */
  {
    YYPTRDIFF_T yyk;
    for (yyk = 0; yyk < yystackp->yytops.yysize; yyk += 1)
      if (yystackp->yytops.yystates[yyk] != YY_NULLPTR)
        break;
    if (yyk >= yystackp->yytops.yysize)
      yyFail (yystackp, &yylloc, yyparser, scanner, decls, YY_NULLPTR);
    for (yyk += 1; yyk < yystackp->yytops.yysize; yyk += 1)
      yymarkStackDeleted (yystackp, yyk);
    yyremoveDeletes (yystackp);
    yycompressStack (yystackp);
  }

  /* Pop stack until we find a state that shifts the error token.  */
  yystackp->yyerrState = 3;
  while (yystackp->yytops.yystates[0] != YY_NULLPTR)
    {
      yyGLRState *yys = yystackp->yytops.yystates[0];
      int yyj = yypact[yys->yylrState];
      if (! yypact_value_is_default (yyj))
        {
          yyj += S_YYerror;
          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == S_YYerror
              && yyisShiftAction (yytable[yyj]))
            {
              /* Shift the error token.  */
              int yyaction = yytable[yyj];
              /* First adjust its location.*/
              YYLTYPE yyerrloc;
              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);
              YY_SYMBOL_PRINT ("Shifting", yy_accessing_symbol (yyaction),
                               &yylval, &yyerrloc);
              yyglrShift (yystackp, 0, yyaction,
                          yys->yyposn, &yylval, &yyerrloc);
              yys = yystackp->yytops.yystates[0];
              break;
            }
        }
      yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;
      if (yys->yypred != YY_NULLPTR)
        yydestroyGLRState ("Error: popping", yys, yyparser, scanner, decls);
      yystackp->yytops.yystates[0] = yys->yypred;
      yystackp->yynextFree -= 1;
      yystackp->yyspaceLeft += 1;
    }
  if (yystackp->yytops.yystates[0] == YY_NULLPTR)
    yyFail (yystackp, &yylloc, yyparser, scanner, decls, YY_NULLPTR);
}

#define YYCHK1(YYE)                             \
  do {                                          \
    switch (YYE) {                              \
    case yyok:     break;                       \
    case yyabort:  goto yyabortlab;             \
    case yyaccept: goto yyacceptlab;            \
    case yyerr:    goto yyuser_error;           \
    case yynomem:  goto yyexhaustedlab;         \
    default:       goto yybuglab;               \
    }                                           \
  } while (0)

/*----------.
| yyparse.  |
`----------*/

int
yy_parse_impl (yy::parser& yyparser, void* scanner, Declarations* decls)
{
  int yyresult;
  yyGLRStack yystack;
  yyGLRStack* const yystackp = &yystack;
  YYPTRDIFF_T yyposn;

  YY_DPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY;
  yylval = yyval_default;
  yylloc = yyloc_default;

  // User initialization code.
yylloc.initialize ();
#line 3813 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"


  if (! yyinitGLRStack (yystackp, YYINITDEPTH))
    goto yyexhaustedlab;
  switch (YYSETJMP (yystack.yyexception_buffer))
    {
    case 0: break;
    case 1: goto yyabortlab;
    case 2: goto yyexhaustedlab;
    default: goto yybuglab;
    }
  yyglrShift (&yystack, 0, 0, 0, &yylval, &yylloc);
  yyposn = 0;

  while (yytrue)
    {
      /* For efficiency, we have two loops, the first of which is
         specialized to deterministic operation (single stack, no
         potential ambiguity).  */
      /* Standard mode. */
      while (yytrue)
        {
          yy_state_t yystate = yystack.yytops.yystates[0]->yylrState;
          YY_DPRINTF ((stderr, "Entering state %d\n", yystate));
          if (yystate == YYFINAL)
            goto yyacceptlab;
          if (yyisDefaultedState (yystate))
            {
              yyRuleNum yyrule = yydefaultAction (yystate);
              if (yyrule == 0)
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  yyreportSyntaxError (&yystack, yyparser, scanner, decls);
                  goto yyuser_error;
                }
              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue, yyparser, scanner, decls));
            }
          else
            {
              yysymbol_kind_t yytoken = yygetToken (&yychar, yystackp, yyparser, scanner, decls);
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken, &yyconflicts);
              if (*yyconflicts)
                /* Enter nondeterministic mode.  */
                break;
              if (yyisShiftAction (yyaction))
                {
                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
                  yychar = YYEMPTY;
                  yyposn += 1;
                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval, &yylloc);
                  if (0 < yystack.yyerrState)
                    yystack.yyerrState -= 1;
                }
              else if (yyisErrorAction (yyaction))
                {
                  yystack.yyerror_range[1].yystate.yyloc = yylloc;
                  /* Issue an error message unless the scanner already
                     did. */
                  if (yychar != YYerror)
                    yyreportSyntaxError (&yystack, yyparser, scanner, decls);
                  goto yyuser_error;
                }
              else
                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue, yyparser, scanner, decls));
            }
        }

      /* Nondeterministic mode. */
      while (yytrue)
        {
          yysymbol_kind_t yytoken_to_shift;
          YYPTRDIFF_T yys;

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;

          /* yyprocessOneStack returns one of three things:

              - An error flag.  If the caller is yyprocessOneStack, it
                immediately returns as well.  When the caller is finally
                yyparse, it jumps to an error label via YYCHK1.

              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
                yyparse's following invocation of yyremoveDeletes will remove
                the stack.

              - yyok, when ready to shift a token.

             Except in the first case, yyparse will invoke yyremoveDeletes and
             then shift the next token onto all remaining stacks.  This
             synchronization of the shift (that is, after all preceding
             reductions on all stacks) helps prevent double destructor calls
             on yylval in the event of memory exhaustion.  */

          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn, &yylloc, yyparser, scanner, decls));
          yyremoveDeletes (&yystack);
          if (yystack.yytops.yysize == 0)
            {
              yyundeleteLastStack (&yystack);
              if (yystack.yytops.yysize == 0)
                yyFail (&yystack, &yylloc, yyparser, scanner, decls, YY_("syntax error"));
              YYCHK1 (yyresolveStack (&yystack, yyparser, scanner, decls));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yystack.yyerror_range[1].yystate.yyloc = yylloc;
              yyreportSyntaxError (&yystack, yyparser, scanner, decls);
              goto yyuser_error;
            }

          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
             a copy of yylval will already be on stack 0 in the event of a
             failure in the following loop.  Thus, yychar is set to YYEMPTY
             before the loop to make sure the user destructor for yylval isn't
             called twice.  */
          yytoken_to_shift = YYTRANSLATE (yychar);
          yychar = YYEMPTY;
          yyposn += 1;
          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
            {
              yy_state_t yystate = yystack.yytops.yystates[yys]->yylrState;
              const short* yyconflicts;
              int yyaction = yygetLRActions (yystate, yytoken_to_shift,
                              &yyconflicts);
              /* Note that yyconflicts were handled by yyprocessOneStack.  */
              YY_DPRINTF ((stderr, "On stack %ld, ", YY_CAST (long, yys)));
              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
              yyglrShift (&yystack, yys, yyaction, yyposn,
                          &yylval, &yylloc);
              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                           YY_CAST (long, yys),
                           yystack.yytops.yystates[yys]->yylrState));
            }

          if (yystack.yytops.yysize == 1)
            {
              YYCHK1 (yyresolveStack (&yystack, yyparser, scanner, decls));
              YY_DPRINTF ((stderr, "Returning to deterministic operation.\n"));
              yycompressStack (&yystack);
              break;
            }
        }
      continue;
    yyuser_error:
      yyrecoverSyntaxError (&yystack, yyparser, scanner, decls);
      yyposn = yystack.yytops.yystates[0]->yyposn;
    }

 yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;

 yybuglab:
  YY_ASSERT (yyfalse);
  goto yyabortlab;

 yyabortlab:
  yyresult = 1;
  goto yyreturnlab;

 yyexhaustedlab:
  yyerror (&yylloc, yyparser, scanner, decls, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;

 yyreturnlab:
  if (yychar != YYEMPTY)
    yydestruct ("Cleanup: discarding lookahead",
                YYTRANSLATE (yychar), &yylval, &yylloc, yyparser, scanner, decls);

  /* If the stack is well-formed, pop the stack until it is empty,
     destroying its entries as we go.  But free the stack regardless
     of whether it is well-formed.  */
  if (yystack.yyitems)
    {
      yyGLRState** yystates = yystack.yytops.yystates;
      if (yystates)
        {
          YYPTRDIFF_T yysize = yystack.yytops.yysize;
          YYPTRDIFF_T yyk;
          for (yyk = 0; yyk < yysize; yyk += 1)
            if (yystates[yyk])
              {
                while (yystates[yyk])
                  {
                    yyGLRState *yys = yystates[yyk];
                    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;
                    if (yys->yypred != YY_NULLPTR)
                      yydestroyGLRState ("Cleanup: popping", yys, yyparser, scanner, decls);
                    yystates[yyk] = yys->yypred;
                    yystack.yynextFree -= 1;
                    yystack.yyspaceLeft += 1;
                  }
                break;
              }
        }
      yyfreeGLRStack (&yystack);
    }

  return yyresult;
}

/* DEBUGGING ONLY */
#if YYDEBUG
/* Print *YYS and its predecessors. */
static void
yy_yypstack (yyGLRState* yys)
{
  if (yys->yypred)
    {
      yy_yypstack (yys->yypred);
      YY_FPRINTF ((stderr, " -> "));
    }
  YY_FPRINTF ((stderr, "%d@%ld", yys->yylrState, YY_CAST (long, yys->yyposn)));
}

/* Print YYS (possibly NULL) and its predecessors. */
static void
yypstates (yyGLRState* yys)
{
  if (yys == YY_NULLPTR)
    YY_FPRINTF ((stderr, "<null>"));
  else
    yy_yypstack (yys);
  YY_FPRINTF ((stderr, "\n"));
}

/* Print the stack #YYK.  */
static void
yypstack (yyGLRStack* yystackp, YYPTRDIFF_T yyk)
{
  yypstates (yystackp->yytops.yystates[yyk]);
}

/* Print all the stacks.  */
static void
yypdumpstack (yyGLRStack* yystackp)
{
#define YYINDEX(YYX)                                                    \
  YY_CAST (long,                                                        \
           ((YYX)                                                       \
            ? YY_REINTERPRET_CAST (yyGLRStackItem*, (YYX)) - yystackp->yyitems \
            : -1))

  yyGLRStackItem* yyp;
  for (yyp = yystackp->yyitems; yyp < yystackp->yynextFree; yyp += 1)
    {
      YY_FPRINTF ((stderr, "%3ld. ",
                   YY_CAST (long, yyp - yystackp->yyitems)));
      if (*YY_REINTERPRET_CAST (yybool *, yyp))
        {
          YY_ASSERT (yyp->yystate.yyisState);
          YY_ASSERT (yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Res: %d, LR State: %d, posn: %ld, pred: %ld",
                       yyp->yystate.yyresolved, yyp->yystate.yylrState,
                       YY_CAST (long, yyp->yystate.yyposn),
                       YYINDEX (yyp->yystate.yypred)));
          if (! yyp->yystate.yyresolved)
            YY_FPRINTF ((stderr, ", firstVal: %ld",
                         YYINDEX (yyp->yystate.yysemantics.yyfirstVal)));
        }
      else
        {
          YY_ASSERT (!yyp->yystate.yyisState);
          YY_ASSERT (!yyp->yyoption.yyisState);
          YY_FPRINTF ((stderr, "Option. rule: %d, state: %ld, next: %ld",
                       yyp->yyoption.yyrule - 1,
                       YYINDEX (yyp->yyoption.yystate),
                       YYINDEX (yyp->yyoption.yynext)));
        }
      YY_FPRINTF ((stderr, "\n"));
    }

  YY_FPRINTF ((stderr, "Tops:"));
  {
    YYPTRDIFF_T yyi;
    for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
      YY_FPRINTF ((stderr, "%ld: %ld; ", YY_CAST (long, yyi),
                   YYINDEX (yystackp->yytops.yystates[yyi])));
    YY_FPRINTF ((stderr, "\n"));
  }
#undef YYINDEX
}
#endif

#undef yylval
#undef yychar
#undef yynerrs
#undef yylloc



#line 4107 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"

/*------------------.
| Report an error.  |
`------------------*/

static void
yyerror (const yy::parser::location_type *yylocationp,
         yy::parser& yyparser, void* scanner, Declarations* decls,
         const char* msg)
{
  YY_USE (yyparser);
  YY_USE (scanner);
  YY_USE (decls);
  yyparser.error (*yylocationp, msg);
}


namespace yy {
#line 4126 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"

  /// Build a parser object.
  parser::parser (void* scanner_yyarg, Declarations* decls_yyarg)
    :
#if YYDEBUG
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      decls (decls_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    return ::yy_parse_impl (*this, scanner, decls);
  }

#if YYDEBUG
  /*--------------------.
  | Print this symbol.  |
  `--------------------*/

  void
  parser::yy_symbol_value_print_ (symbol_kind_type yykind,
                           const value_type* yyvaluep,
                           const location_type* yylocationp) const
  {
    YY_USE (yylocationp);
    YY_USE (yyvaluep);
    std::ostream& yyo = debug_stream ();
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    YY_USE (yykind);
  }


  void
  parser::yy_symbol_print_ (symbol_kind_type yykind,
                           const value_type* yyvaluep,
                           const location_type* yylocationp) const
  {
    *yycdebug_ << (yykind < YYNTOKENS ? "token" : "nterm")
               << ' ' << yysymbol_name (yykind) << " ("
               << *yylocationp << ": ";
    yy_symbol_value_print_ (yykind, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }

  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    // Actually, it is yydebug which is really used.
    yydebug = l;
  }

#endif
} // yy
#line 4215 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.cpp"

#undef YYEMPTY
#undef YYEOF
#undef YYerror

#undef S_YYEMPTY
#undef S_YYEOF
#undef S_YYerror
#undef S_YYUNDEF
#undef S_INTEGER
#undef S_IS_LITTLE_ENDIAN
#undef S_IDENTIFIER
#undef S_SIZE_MODIFIER
#undef S_STRING
#undef S_ENUM
#undef S_PACKET
#undef S_PAYLOAD
#undef S_BODY
#undef S_STRUCT
#undef S_SIZE
#undef S_COUNT
#undef S_FIXED
#undef S_RESERVED
#undef S_GROUP
#undef S_CUSTOM_FIELD
#undef S_CHECKSUM
#undef S_CHECKSUM_START
#undef S_PADDING
#undef S_TEST
#undef S_23_
#undef S_24_
#undef S_25_
#undef S_26_
#undef S_27_
#undef S_28_
#undef S_29_
#undef S_30_
#undef S_31_
#undef S_YYACCEPT
#undef S_file
#undef S_declarations
#undef S_declaration
#undef S_enum_definition
#undef S_enumeration_list
#undef S_enumeration
#undef S_group_definition
#undef S_checksum_definition
#undef S_custom_field_definition
#undef S_test_definition
#undef S_test_case_list
#undef S_test_case
#undef S_struct_definition
#undef S_packet_definition
#undef S_field_definition_list
#undef S_field_definition
#undef S_group_field_definition
#undef S_constraint_list
#undef S_constraint
#undef S_type_def_field_definition
#undef S_scalar_field_definition
#undef S_body_field_definition
#undef S_payload_field_definition
#undef S_checksum_start_field_definition
#undef S_padding_field_definition
#undef S_size_field_definition
#undef S_fixed_field_definition
#undef S_reserved_field_definition
#undef S_array_field_definition

#line 775 "packages/modules/Bluetooth/system/gd/packet/parser/language_y.yy"



void yy::parser::error(const yy::parser::location_type& loc, const std::string& error) {
  ERROR() << error << " at location " << loc << "\n";
  abort();
}
