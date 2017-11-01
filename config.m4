PHP_ARG_WITH(wkhtmltox, for wkhtmltox support,
[  --with-wkhtmltox             Include wkhtmltox support])

if test "$PHP_WKHTMLTOX" != "no"; then

  SEARCH_PATH="/usr/local /usr"     # you might want to change this
  SEARCH_FOR="/include/wkhtmltox/pdf.h"  # you most likely want to change this
  if test -r $PHP_WKHTMLTOX/$SEARCH_FOR; then # path given as parameter
    WKHTMLTOX_DIR=$PHP_WKHTMLTOX
  else
    AC_MSG_CHECKING([for libwkhtmltox files in default path])
    for i in $SEARCH_PATH ; do
      if test -r $i/$SEARCH_FOR; then
        WKHTMLTOX_DIR=$i
        AC_MSG_RESULT(found in $i)
      fi
    done
  fi

  if test -z "$WKHTMLTOX_DIR"; then
    AC_MSG_RESULT([not found])
    AC_MSG_ERROR([Please reinstall the wkhtmltox distribution])
  fi

  PHP_ADD_INCLUDE($WKHTMLTOX_DIR/include)

  LIBNAME=wkhtmltox
  LIBSYMBOL=wkhtmltopdf_init

  PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  [
    PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $WKHTMLTOX_DIR/$PHP_LIBDIR, WKHTMLTOX_SHARED_LIBADD)
    AC_DEFINE(HAVE_WKHTMLTOXLIB,1,[ ])
  ],[
    AC_MSG_ERROR([wrong libwkhtmltox version or libwkhtmltox not found])
  ],[
    -L$WKHTMLTOX_DIR/$PHP_LIBDIR -lm
  ])

  PHP_SUBST(WKHTMLTOX_SHARED_LIBADD)
  PHP_ADD_BUILD_DIR($ext_builddir/src, 1)
  PHP_NEW_EXTENSION(wkhtmltox, wkhtmltox.c src/pdf.c src/image.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
fi
