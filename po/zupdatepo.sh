#!/bin/sh

# https://www.labri.fr/perso/fleury/posts/programming/a-quick-gettext-tutorial.html

# files
po_dir=. # po

potfile=${po_dir}/lxrandr.pot

LINGUAS=${po_dir}/LINGUAS
POTFILES=${po_dir}/POTFILES

c_files=../src/*.c  #src/*.c
desktop_in=../data/lxrandr.desktop.in

#============================================
#Update LINGUAS
echo -n > ${LINGUAS}
for i in $(ls ${po_dir}/*.po | sort | sed 's%.*/%% ; s%\.po%%')
do
	echo $i >> ${LINGUAS}
done

#============================================
# Update POT file

# .c
xgettext \
	--language=C \
	--add-comments \
	--from-code=UTF-8 \
	--keyword=_ \
	-o ${potfile} ${c_files}

# this is tricky.. fix .desktop.in
sed -i \
	-e 's/^_Name=/Name=/' \
	-e 's/^_Comment=/Comment=/' \
	-e 's/^_Keywords=/Keywords=/' \
	${desktop_in}

# desktop.in
xgettext \
	--language=Desktop \
	--from-code=UTF-8 \
	--join-existing \
	-k \
	--keyword=Name \
	--keyword=Comment \
	--keyword=Keywords \
	-o ${potfile} ${desktop_in}


#============================================
# Update PO files
for i in ${po_dir}/*.po
do
	msgmerge --no-fuzzy-matching --update $i ${potfile}
done

#============================================
# Update desktop file
#msgfmt --desktop -d . --template ${desktop_in} -o ${desktop_in%.in}

#============================================

sed -i \
	-e 's/^Name=/_Name=/' \
	-e 's/^Comment=/_Comment=/' \
	-e 's/^Keywords=/_Keywords=/' \
	${desktop_in}

# Clean up
rm -f ${po_dir}/*.po~
sed -i '/#~ /d' ${po_dir}/*.po
