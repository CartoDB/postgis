## 3.0.2.1+carto-1

**Release date**: 2020-XX-XX

Changes:
- Update from `stable-3.0` up to 2020-10-11 (https://github.com/postgis/postgis/commit/7b6d177b97555fb5918aab553c56eea1dc387699).
- Backport (from master) improvements in MVTs (https://github.com/postgis/postgis/commit/99c50d4602a6e1d94f65932cbcbee933af998ea1).

## 3.0.1.2+carto-1

**Release date**: 2020-01-15

Changes:
- Update from `stable-3.0` up to 2020-01-15 (https://github.com/postgis/postgis/commit/b73f67376145d96c9f5bb2c31bc407dd6e311746).


## 3.0.1.1+carto-1

**Release date**: 2020-01-10

Changes:
- Start from `stable-3.0` (https://github.com/postgis/postgis/commit/318bfa75b9968b95a3f958bb7199b5a25c72752d).
- Adding this changelog file.
- Add carto-package.json (https://github.com/CartoDB/postgis/commit/bb3336f79c1f17b65783b4a58c4ae12ecfa07c85)
- Ported (2.4.1.1+carto-1): make_cartodb_dist.sh (https://github.com/CartoDB/postgis/commit/3c6436c35237758e1533321096378711eacd924a)
- carto-package.json: Declare internal package compatibility (https://github.com/CartoDB/postgis/commit/29b1ee63ff281c131a128cae9c9b7d6be1fa6579)
- Added a static cache for SRID 4326 and 3857 if the lookup fails. This is to prevent failures during pg_upgrade when calling ST_Transform before loading the data of spatial_ref_sys. (https://github.com/CartoDB/postgis/commit/c82a74ec53faa914c2606d994814d6e23c4ea83d)
- Update from `stable-3.0` to 2020-01-07.

