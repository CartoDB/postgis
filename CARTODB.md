# CartoDB Feature Branch

The `svn-2.1-cartodb` branch is where the production branch of PostGIS used in CartoDB resides. It is a place where we can place high-priority bug fixes, and back port features from PostGIS trunk for use in CartoDB prior to official community release.

## Versioning

* `svn-2.1-cartodb` is versioned relative to the latest stable release of the PostGIS 2.1 branch.
* If the latest stable release is `2.1.8`, then our version will be, for example `2.1.8.1`
* End users will continue to see `2.1.8` as their version number, and the PostGIS extension will remain at version `2.1.8`. The only place the extended version number will be visible is in:
    * The output of `postgis_full_version()`
    * The source tarball and debian packaging
* Each new release of `svn-2.1-cartodb` to production should be accompanied by an increment in the micro-micro version
* Version numbers that need to be managed reside in
    * `Version.config` for the DLL version number
    * `extensions/postgis_backport` for the backport extension number

## Adding Features

* Take a branch off of `svn-2.1-cartodb` so you're starting with our changes as a baseline.
* Make fixes to the C code as usual.
* Add new functions to the C code as usual.
* Add any new SQL functions (any changes to the SQL API at all, including bindings to the C code) in the `postgis_backport` extension.
    * Copy the latest `postgis_backport--2.1a.sql.in` file to the next version (increment the letter) and add your new SQL functions there.
    * Create an upgrade script (for example, `postgis_backport--2.1a--2.1b.sql.in`) that includes *only* your new functions.
    * Create a downgrade script (for example, `postgis_backport--2.1b--2.1a.sql.in`) that *drops* your new functions.
    * Change the `default_version` in `postgis_backport.control`
    * Add your new scripts (new version, upgrade and downgrade) to the `DATA` variable in `Makefile.in`
* Commit your changes, push to the CartoDB postgis repo and create a pull request relative to `svn-2.1-cartodb`

## Packaging

* To create a package, check out the `svn-2.1-cartodb` branch
* Run the `./make_cartodb_dist.sh` script
    * This will create a `postgis-2.1.8.1` directory
    * This will also create a `postgis-2.1.8.1.tar.gz` source tarball
* ...