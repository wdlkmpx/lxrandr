dnl Process this file with autoconf to produce a configure script.

AC_INIT([lxrandr],[0.3.4w])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([.])
AM_GNU_GETTEXT([external])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
m4_ifdef([AM_MAINTAINER_MODE], [AM_MAINTAINER_MODE])

# Init intltool
IT_PROG_INTLTOOL

AC_SEARCH_LIBS([strerror],[cposix])
AC_PROG_CC
AM_PROG_CC_STDC
AC_HEADER_STDC
AM_PROG_CC_C_O

AC_ARG_ENABLE(more_warnings,
       [AS_HELP_STRING([--enable-more-warnings],[Add more warnings @<:@default=no@:>@])],
       [enable_more_warnings="${enableval}"],
       [enable_more_warnings=no]
)

AC_ARG_ENABLE(gtk3,
AS_HELP_STRING([--enable-gtk3],[enable to use gtk-3.0 instead of gtk-2.0]),
[case "${enableval}" in
  yes)  enable_gtk3=yes ;;
  no)   enable_gtk3=no ;;
  *) AC_MSG_ERROR([bad value "${enableval}" for --enable-gtk3, use "yes" (default) or "no".]) ;;
esac],[])

if test "x$enable_gtk3" = "xyes" ; then
  CFLAGS="$CFLAGS -DENABLE_GTK3"
  gtk_modules="gtk+-3.0 >= 3.0.0"
else
  gtk_modules="gtk+-2.0 >= 2.14.0"
fi
PKG_CHECK_MODULES(GTK, [$gtk_modules])
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

if test x"$enable_more_warnings" = x"yes"; then
  ADDITIONAL_FLAGS="-Wall -Werror=all -Werror=format -Werror=implicit-function-declaration -Werror=implicit-int -Werror=missing-braces -Werror=parentheses -Werror=return-type -Werror=strict-aliasing -Werror=switch -Wuninitialized -Werror=unused-label -Werror=unused-value -Wextra -Wno-missing-field-initializers -Wno-unused-parameter -Werror=missing-declarations -Wredundant-decls -Wmissing-noreturn -Wpointer-arith -Wcast-align -Wwrite-strings -Werror=inline -Werror=format-nonliteral -Wformat-nonliteral -Werror=format-security -Wformat-security -Winit-self -Werror=missing-include-dirs -Werror=undef -Werror=aggregate-return -Wmissing-format-attribute -Werror=nested-externs -fno-strict-aliasing -fmessage-length=0 -Wp,-D_FORTIFY_SOURCE=2 -DG_DISABLE_DEPRECATED -DG_DISABLE_SINGLE_INCLUDES -DGDK_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_DEPRECATED -DGDK_PIXBUF_DISABLE_SINGLE_INCLUDES -DGTK_DISABLE_DEPRECATED -DGTK_DISABLE_SINGLE_INCLUDES"
fi
AC_SUBST(ADDITIONAL_FLAGS)

GETTEXT_PACKAGE=lxrandr
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Gettext package.])

AM_GLIB_GNU_GETTEXT

AC_ARG_ENABLE(debug,
    [AC_HELP_STRING([--enable-debug],
        [build lxrandr with debug support @<:@default=no@:>@])],
    [enable_debug="${enableval}"],
    [enable_debug=no]
)

case "$CC" in gcc*)
	CPPFLAGS="$CPPFLAGS -Wall -Wextra -Wno-unused-parameter -Wno-missing-field-initializers" ;;
esac

if test "$enable_debug" = "yes"; then
    # turn on debug and disable optimization
    CPPFLAGS="$CPPFLAGS -DG_ENABLE_DEBUG -O0 -g"
    dnl Be more strict on portability
    CPPFLAGS="$CPPFLAGS -D_POSIX_C_SOURCE=200112L -D_XOPEN_SOURCE=700"
fi

AC_CONFIG_FILES([
Makefile
src/Makefile
po/Makefile.in
data/Makefile
])
AC_OUTPUT
