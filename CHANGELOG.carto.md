# Changelog

## 2.4.1.1+carto-1

**Release date**: 2017-10-30

Changes:
- Port in-place support for simplify/repeatedpoint/grid functions back from trunk, for use in MVT generator. See https://github.com/CartoDB/postgis/commit/967a12befc4d0185ef8897e7533faeb456e8981f
- Bind in-place functions into "fast" mvt implementation that skips validity testing, and C library hook for potential SQL function. See https://github.com/CartoDB/postgis/commit/b140061bd65ff3ee97d10ca1d24b62ff6c3cf05c
- Hook up SQL function to "fast" C backend. See https://github.com/CartoDB/postgis/commit/cb6c1ade4ec1703239f1f11b5137b775f3554456
- Fix early-free problem and clean some error messages out. See https://github.com/CartoDB/postgis/commit/988f02ef08ba96a7ec88ed333574a871f6724756
- Port in-place support for simplify/repeatedpoint/grid functions back from trunk, for use in MVT generator. See https://github.com/CartoDB/postgis/commit/508fa5f7ea60d32e78f78f5d3d9f8e90534545a5
- Bind in-place functions into "fast" mvt implementation that skips validity testing, and C library hook for potential SQL function. See https://github.com/CartoDB/postgis/commit/405c9c31ee078fdeb3f1dc9236838c7dda6b1951
- Hook up SQL function to "fast" C backend. See https://github.com/CartoDB/postgis/commit/8dd8ebe77ef1fc063657cbc0607798534d0a5eba
- Rename few fast version into place. See https://github.com/CartoDB/postgis/commit/3bcf6d3dfec03d5ecf5ab9e93fce263aa59a581a
- Port fix from Raul into our branch. See https://github.com/CartoDB/postgis/commit/b036c3d74c5eb034477fdb9b6b074769decf5d52
- Bump forward versions. See https://github.com/CartoDB/postgis/commit/f4fb0212eb3f0083bc90b0e21e79c95a0635399e
- Quiet compile warnings. See https://github.com/CartoDB/postgis/commit/13fbaa1363e9c6c89931be973db1c00580ecc217
- Reflect CFLAGS passed into configure. See https://github.com/CartoDB/postgis/commit/1f38e26aed35169927ecc79e9c015de1fc745011
- Reflect CFLAGS passed into core. See https://github.com/CartoDB/postgis/commit/7bdd22b098ce9bbdc575dd468cad4678cac20284
- Put build AUX files under build-aux. See https://github.com/CartoDB/postgis/commit/40e1b2607e8121c90cbf410ae6d00c30b872e91c
- Add draft function endpoint. See https://github.com/CartoDB/postgis/commit/2378c3083afa2e7f954f82912742dda0a92401b4
- Add SQL signature. See https://github.com/CartoDB/postgis/commit/8d9fb4a6fef342287b2eaa432c11251e1b897a10
- Use in-line methods for `ST_Simplify` and `ST_RemoveRepeatedPoints`. See https://github.com/CartoDB/postgis/commit/bd4364b6ad11bbca4fc110697a7b3ccb39a52b30
- Add CartoDB dist.sh script. See https://github.com/CartoDB/postgis/commit/2b6002fbdce4bd920deac2e974f60244b53370e0


## 2.4.1

**Release date**: 2017-10-18

Vanilla PostGIS 2.4.1 in which the rest of the changes are based on. See https://svn.osgeo.org/postgis/tags/2.4.1/ChangeLog
