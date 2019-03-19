# Changelog

## 2.4.7.1+carto-1

**Release date**: 2019-03-13

Changes:
- carto-package.json: Declare compatibility guaranteed only with PG 10.
- Update from community branch (svn-2.4 2019-03-12 // 2.4.7), except MVT changes

## 2.4.4.6+carto-1

**Release date**: 2018-11-02

Changes:
- No changes from 2.4.4.5+carto-1

## 2.4.4.5+carto-1

**Release date**: 2018-10-03

Changes:
- Merge community branch (svn-2.4 2018-10-03)
- MVT: Backport [`35db4ea`](https://github.com/postgis/postgis/commit/4385284de6156a83a51cd640b5362ccd22d90492): St_AsMVTGeom: Handle type changes in geometry collections


## 2.4.4.4+carto-1

**Release date**: 2018-10-01

Changes:
- Merge community branch (svn-2.4 2018-10-01)
- MVT: Backport [`bcbf7b1`](https://github.com/postgis/postgis/commit/bcbf7b193f66f29afa983602cb537316b6c2fd79): Avoid type changes due to validation
- MVT: Backport [`35db4ea`](https://github.com/postgis/postgis/commit/35db4ea0c0b02b15090f1e916c8fdb8ff6c5cc22): St_AsMVTGeom: Fix bug when clipping an invalid geometry


## 2.4.4.3+carto-1

**Release date**: 2018-08-29

Changes:
- Merge community branch (svn-2.4 2018-08-13)
- MVT: Backport [`3c81bccd1`](https://github.com/postgis/postgis/commit/3c81bccd115faee5bfb54878f771507c69a2f09a): Speedup MVT column parsing
- MVT: Backport [`ae6f8ec39`](https://github.com/postgis/postgis/commit/ae6f8ec390c1c4f045ef7ae70d7aa138ff64db73): Fix resource leak when the first geometry is NULL
- MVT Backport (from 3.0) [`e5c92b18f`](https://github.com/postgis/postgis/commit/e5c92b18ffad323b3996fd68f0b23f80dc5bca28): Drop geometries smaller than the resolution

## 2.4.4.2+carto-1

**Release date**: 2018-07-19

Changes:
- Merge community branch (svn-2.4 2018-07-18)
- Backport some other X_in_place functions (specially lwgeom_reverse_in_place)ç
- MVT: Backport fix for mvt combination
- MVT: Backport current status of trunk mvt_geom into mvt_geom_fast.

## 2.4.4.1+carto-1

**Release date**: 2018-05-21

Changes:
- Merge community branch (svn-2.4 2018-05-21)

## 2.4.1.7+carto-1

**Release date**: 2018-04-23

Changes
- Fix for ST_RemoveRepeatedPoints bug: always take a copy of the input geometries.

## 2.4.1.6+carto-1

**Release date**: 2018-01-12

Changes:
- When looking up SRID numbers, assume that spatial_ref_sys will share a schema will the calling function (st_transform, usually) and look for spatial_ref_sys there.

## 2.4.1.5+carto-1

**Release date**: 2018-01-08

Changes:
- Fix for ST_RemoveRepeatedPoints and support for json-c >= 0.13 [#9](https://github.com/CartoDB/postgis/pull/9)


## 2.4.1.4+carto-1

**Release date**: 2017-12-11

Changes:
- Minor tweaks in twkb and bytebuffer code lines to try and drop a few instructions while running mass point queries. See [#7](https://github.com/CartoDB/postgis/pull/7)
- Add this very file `CHANGELOG.carto.md`. See [#8](https://github.com/CartoDB/postgis/pull/8)


## 2.4.1.3+carto-1

**Release date**: 2017-11-29

Changes:
- Bump microversion again (needed for a new package). See [607ebd0](https://github.com/CartoDB/postgis/commit/3a51a613be7a79757e181ed7c446973eac081ad5)


## 2.4.1.2+carto-1

**Release date**: 2017-11-29

Changes:
- Fix mistake in handling collapsed interior rings. See [9b64add](https://github.com/CartoDB/postgis/commit/9b64add747f0c89935a791beea75b7190df78467)
- Remove memory free calls on postgis side since the pg-mem manager will clean up the memory as soon as the function exits anyways. See [faa8865](https://github.com/CartoDB/postgis/commit/faa8865e423ce876a74598c530dfe2bb8ca03266)
- Add parallel implementation of `ST_AsMVT`. See [d0b5a60](https://github.com/CartoDB/postgis/commit/d0b5a608deae376cea00ebd52fffea5940e03629)
- Allow invalid MVT output. Revert this if returning to valid MVT outputs. See [ea18668](https://github.com/CartoDB/postgis/commit/ea186680700e9bbaa0b53981f6366959179ca5f1)
- Add cost defines and strip decorators from 'sql' functions so that inlining works better. See [07991fb](https://github.com/CartoDB/postgis/commit/07991fbabb053e7e965cbce7526a2e9edc5bbe06)
- Add explicit costs to expensive and other functions. See [fe0d578](https://github.com/CartoDB/postgis/commit/fe0d5780a1b6f3fa728b747e0d431ad7f8e46f8d)
- Change simplification regime to be kinder to inputs. See [73ec5f8](https://github.com/CartoDB/postgis/commit/73ec5f89fa3a3c07c9d57b4f7112f2dd9131a67d)
- Bump microversion. See [16ad637](https://github.com/CartoDB/postgis/commit/16ad63789f299050ffabd820b244b3ba2046a22c)


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
