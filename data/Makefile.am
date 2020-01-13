
man_MANS = lxrandr.1
desktop_in_files = lxrandr.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)
@INTLTOOL_DESKTOP_RULE@
desktopdir=$(datadir)/applications

DISTCLEANFILES = $(desktop_DATA)

EXTRA_DIST = \
	$(man_MANS) \
	$(man_in_files) \
	$(desktop_DATA) \
	$(desktop_in_files)
