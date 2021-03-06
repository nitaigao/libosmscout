dnl Process this file with autoconf to produce a configure script.
AC_PREREQ(2.56)
AC_INIT([libosmscout-import],[0.1],[tim@teulings.org],[libosmscout-import])

AC_CONFIG_SRCDIR(src/osmscout/import/Import.cpp)
AC_CONFIG_MACRO_DIR([m4])

AC_CONFIG_HEADERS([include/osmscout/private/Config.h include/osmscout/ImportFeatures.h])
AM_INIT_AUTOMAKE([no-define nostdinc subdir-objects dist-bzip2])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_CXX
AC_LANG(C++)
LT_INIT([win32-dll])
AC_PROG_INSTALL

AX_CXXFLAGS_WARN_ALL

AC_ARG_WITH([protoc],
            [AC_HELP_STRING([--with-protoc=PATH],
                            [Specify a specific path to protoc])],
            [protoc=$with_protoc])

AC_SUBST(protoc)

AC_TYPE_SIZE_T
AC_CHECK_SIZEOF([wchar_t])

AC_SEARCH_LIBS([sqrt],[m],[])

AC_CHECK_FUNCS([mmap])

AC_SYS_LARGEFILE
AC_FUNC_FSEEKO

AS_IF([test "x$GXX" = xyes],
      [CXXFLAGS="$CXXFLAGS -Wextra -Wpointer-arith -Wundef -Wcast-qual -Wcast-align -Wredundant-decls -Wno-long-long"])

dnl Selfmade tests

dnl if test "x$ac_cv_header_stdint_h" = xyes; then
dnl   AC_DEFINE([OSMSCOUT_HAVE_STDINT_H],[1],[system header stdint.h is available])
dnl fi

dnl Check for libosmscout
PKG_CHECK_MODULES(LIBOSMSCOUT,[libosmscout],
                  [AC_SUBST(LIBOSMSCOUT_CFLAGS)
                   AC_SUBST(LIBOSMSCOUT_LIBS)])

if test "$build_os" != "mingw32"; then
  AC_MSG_CHECKING([for gcc symbol visibility support])
  OLDCXXFLAGS="$CXXFLAGS"
  CXXFLAGS="$CXXFLAGS -fvisibility=hidden -fvisibility-inlines-hidden"
  AC_TRY_COMPILE([],
                 [],
                 [LIB_CXXFLAGS="-fvisibility=hidden -fvisibility-inlines-hidden"
                  AC_SUBST(LIB_CXXFLAGS)
                  AC_MSG_RESULT(yes)
                  AC_DEFINE([OSMSCOUT_IMPORT_EXPORT_SYMBOLS],[1],[libosmscout uses special gcc compiler features to export symbols])],
                 [AC_MSG_RESULT(no)])
  CXXFLAGS="$OLDCXXFLAGS"
fi

AC_MSG_CHECKING([for WIN32])
  AC_LINK_IFELSE([
    AC_LANG_PROGRAM([[#include <windows.h>]],
                    [[GetModuleHandleA(0);]])],
    [AC_MSG_RESULT(yes);
     LDFLAGS="$LDFLAGS -lwsock32 -no-undefined"],
    [AC_MSG_RESULT(no)])

dnl Check for libxml2
PKG_CHECK_MODULES(XML2,
                  [libxml-2.0 >= 2.6.0],
                  [AC_SUBST(XML2_CFLAGS)
                   AC_SUBST(XML2_LIBS)
                   AC_DEFINE(HAVE_LIB_XML,1,[libxml detected])
                   LIB_XML_FOUND=true],
                   [LIB_XML_FOUND=false])

AM_CONDITIONAL(HAVE_LIB_XML,[test "$LIB_XML_FOUND" = true])

PKG_CHECK_MODULES(PROTOBUF,
                  [protobuf],
                  [AC_SUBST(PROTOBUF_CFLAGS)
                   AC_SUBST(PROTOBUF_LIBS)
                   AC_DEFINE(HAVE_LIB_PROTOBUF,1,[libprotobuf detected])
                   LIB_PROTOBUF_FOUND=true],
                   [LIB_PROTOBUF_FOUND=false])

AM_CONDITIONAL(HAVE_LIB_PROTOBUF,[test "$LIB_PROTOBUF_FOUND" = true])

PKG_CHECK_MODULES(ZLIB,
                  [zlib],
                  [AC_SUBST(ZLIB_CFLAGS)
                   AC_SUBST(ZLIB_LIBS)
                   AC_DEFINE(HAVE_LIB_ZLIB,1,[zlib detected])
                   LIB_ZLIB_FOUND=true],
                   [HAVE_ZLIB_FOUND=false])
AM_CONDITIONAL(HAVE_LIB_ZLIB,[test "$LIB_ZLIB_FOUND" = true])

dnl Checking for protoc
AC_PATH_PROG(protoc,protoc,)
AM_CONDITIONAL(HAVE_PROG_PROTOC,[test -n "$protoc"])

AS_IF([test "$enable_marisa_support" != "no"],
      [PKG_CHECK_MODULES(MARISA,
                         [marisa],
                         [AC_SUBST(MARISA_CFLAGS)
                          AC_SUBST(MARISA_LIBS)
                          AC_DEFINE(OSMSCOUT_IMPORT_HAVE_LIB_MARISA,1,[libmarisa detected])
                          LIB_MARISA_FOUND=true],
                         [LIB_MARISA_FOUND=false])])

AM_CONDITIONAL(OSMSCOUT_HAVE_LIB_MARISA,[test "$LIB_MARISA_FOUND" = true])

CPPFLAGS="-DLIB_DATADIR=\\\"$datadir/$PACKAGE_NAME\\\" $CPPFLAGS"

AX_CREATE_PKGCONFIG_INFO([],
                         [libosmscout],
                         [-losmscoutimport $PROTOBUF_LIBS $ZLIB_LIBS $XML2_LIBS],
                         [libosmscout import library],
                         [$PROTOBUF_CFLAGS $ZLIB_CFLAGS $XML2_CFLAGS],
                         [])

AC_CONFIG_FILES([Makefile src/Makefile src/protobuf/Makefile include/Makefile])
AC_OUTPUT

