## 3.0.0.1+carto-1

**Release date**: 2019-11-12

Changes:
- Start from `stable-3.0` (https://github.com/postgis/postgis/commit/318bfa75b9968b95a3f958bb7199b5a25c72752d).
- Adding this changelog file.
- Add carto-package.json (https://github.com/CartoDB/postgis/commit/bb3336f79c1f17b65783b4a58c4ae12ecfa07c85)
- Ported (2.4.1.1+carto-1): make_cartodb_dist.sh (https://github.com/CartoDB/postgis/commit/3c6436c35237758e1533321096378711eacd924a)
- carto-package.json: Declare internal package compatibility (https://github.com/CartoDB/postgis/commit/29b1ee63ff281c131a128cae9c9b7d6be1fa6579)
- Added a static cache for SRID 4326 and 3857 if the lookup fails. This is to prevent failures during pg_upgrade when calling ST_Transform before loading the data of spatial_ref_sys. (https://github.com/CartoDB/postgis/commit/c82a74ec53faa914c2606d994814d6e23c4ea83d)

