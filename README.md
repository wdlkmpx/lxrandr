LXRANDR(w)
=======
Monitor configuration tool

## Requirements:
- GTK2 >= 2.14
- GTK3 >= 3.0

## Compile (git):
- ./autogen.sh
- ./configure --prefix=/usr
- make && make install

## Compile (release tarball)
- ./configure --prefix=/usr
- make && make install

## Notes
- GTK3: `./configure --prefix=/usr --enable-gtk3`
- see also `./configure --help`

## PO/: Update lxrandr.po / *.po / LINGUAS
- cd po
- sh zupdatepo.sh
- cd ..

## Icons

Icons that should be in the current icon theme:
- gtk-save-as / document-save-as
- gtk-apply / dialog-apply
- gtk-cancel / dialog-cancel
- gtk-clear / edit-clear
- gtk-about / help-about
