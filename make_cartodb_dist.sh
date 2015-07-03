#!/bin/sh

#
# USAGE:
#
# -- postgis-cvs.tar.gz 
# sh make_dist.sh
#
# -- postgis-1.1.0.tar.gz 
# sh make_dist.sh 1.1.0
#
# NOTE: will not work prior to 1.1.0
#
#


v_major=`cat Version.config | perl -ne 'print if s/POSTGIS_MAJOR_VERSION=(\d)/$1/'`
v_minor=`cat Version.config | perl -ne 'print if s/POSTGIS_MINOR_VERSION=(\d)/$1/'`
v_micro=`cat Version.config | perl -ne 'print if s/POSTGIS_MICRO_VERSION=(\d)/$1/'`
v_carto=`cat Version.config | perl -ne 'print if s/CARTODB_MICRO_VERSION=(\d)/$1/'`

version="${v_major}.${v_minor}.${v_micro}.${v_carto}"

tag=trunk

outdir="postgis-$version"
package="postgis-$version.tar.gz"

if [ -d "$outdir" ]; then
  /bin/rm -rf $outdir
fi
mkdir $outdir

echo "Exporting to $outdir ..."

git archive svn-2.1-cartodb | tar -x -C $outdir
if [ $? -gt 0 ]; then
  echo "Git archive to $outdir failed!"
	exit 1
fi

echo "Removing ignore files, make_dist.sh and HOWTO_RELEASE"
find "$outdir" -name .\*ignore -exec rm -v {} \;
rm -fv "$outdir"/make_dist.sh "$outdir"/HOWTO_RELEASE

# generating configure script and configuring
echo "Running autogen.sh; ./configure"
pushd $outdir
./autogen.sh
./configure
# generating postgis_svn_revision.h for >= 2.0.0 tags 
if test -f utils/svn_repo_revision.pl; then 
	echo "Generating postgis_svn_revision.h"
	perl utils/svn_repo_revision.pl $svnurl
fi
popd 

# generating comments
echo "Generating documentation"
pushd ${outdir}/doc
make comments
if [ $? -gt 0 ]; then
	exit 1
fi
make clean # won't drop the comment files
popd

# Run make distclean
echo "Running make distclean"
pushd $outdir
make distclean
popd

echo "Generating $package file"
tar czf "$package" "$outdir"

#echo "Cleaning up"
#rm -Rf "$outdir"

