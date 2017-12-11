# Changelog

## 2.4.1.1+carto-1

**Release date**: 2017-10-30

Changes:
- Port in-place support for simplify/repeatedpoint/grid functions back from trunk, for use in MVT generator. See [967a12b](https://github.com/CartoDB/postgis/commit/967a12befc4d0185ef8897e7533faeb456e8981f)
- Bind in-place functions into "fast" mvt implementation that skips validity testing, and C library hook for potential SQL function. See [b140061](https://github.com/CartoDB/postgis/commit/b140061bd65ff3ee97d10ca1d24b62ff6c3cf05c)
- Hook up SQL function to "fast" C backend. See [cb6c1ad](https://github.com/CartoDB/postgis/commit/cb6c1ade4ec1703239f1f11b5137b775f3554456)
- Fix early-free problem and clean some error messages out. See [988f02e](https://github.com/CartoDB/postgis/commit/988f02ef08ba96a7ec88ed333574a871f6724756)
- Rename few fast version into place. See [3bcf6d3](https://github.com/CartoDB/postgis/commit/3bcf6d3dfec03d5ecf5ab9e93fce263aa59a581a)
- Port fix from Raul (lwgeom memory leak) into our branch. See [b036c3d](https://github.com/CartoDB/postgis/commit/b036c3d74c5eb034477fdb9b6b074769decf5d52)
- [Backported from svn-2.4] Bump forward versions. See [f4fb021](https://github.com/CartoDB/postgis/commit/f4fb0212eb3f0083bc90b0e21e79c95a0635399e)
- [Backported from svn-2.4] Quiet compile warnings. See [13fbaa1](https://github.com/CartoDB/postgis/commit/13fbaa1363e9c6c89931be973db1c00580ecc217)
- [Backported from svn-2.4] Reflect CFLAGS passed into configure. See [1f38e26](https://github.com/CartoDB/postgis/commit/1f38e26aed35169927ecc79e9c015de1fc745011)
- [Backported from svn-2.4] Reflect CFLAGS passed into core. See [7bdd22b](https://github.com/CartoDB/postgis/commit/7bdd22b098ce9bbdc575dd468cad4678cac20284)
- [Backported from svn-2.4] Put build AUX files under build-aux. See [40e1b26](https://github.com/CartoDB/postgis/commit/40e1b2607e8121c90cbf410ae6d00c30b872e91c)
- Add `CDB_AsSimplifiedTWKB`. See [2378c30](https://github.com/CartoDB/postgis/commit/2378c3083afa2e7f954f82912742dda0a92401b4) and [8d9fb4a](https://github.com/CartoDB/postgis/commit/8d9fb4a6fef342287b2eaa432c11251e1b897a10)
- Use in-line methods for `ST_Simplify` and `ST_RemoveRepeatedPoints`. See [bd4364b](https://github.com/CartoDB/postgis/commit/bd4364b6ad11bbca4fc110697a7b3ccb39a52b30)
- Add CartoDB dist.sh script. See [2b6002f](https://github.com/CartoDB/postgis/commit/2b6002fbdce4bd920deac2e974f60244b53370e0)


## 2.4.1

**Release date**: 2017-10-18

Vanilla PostGIS 2.4.1 in which the rest of the changes are based on. See https://svn.osgeo.org/postgis/tags/2.4.1/ChangeLog
