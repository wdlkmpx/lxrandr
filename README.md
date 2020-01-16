LXRANDR(w)
=======
Monitor configuration tool

## Compile:
- ./autogen.sh
- ./configure --prefix=/usr
- make
- make install

## Notes for compilation: 
- requires intltool and gtk2/gtk3 to compile.
- use `./configure --prefix=/usr --enable-gtk3` to build the gtk3 ui..
- no need to run `./autogen.sh` if `configure` is already generated (release tarball)

## PO/: Update lxrandr.po / *.po / LINGUAS
- cd po
- sh zupdatepo.sh
- cd ..

