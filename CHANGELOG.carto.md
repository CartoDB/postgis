## 2.5.1.3+carto-1

**Release date**: 2019-03-06

Changes:
- Reduce the cost of `ST_Simplify` from 512 to 64. The cost turned out to be too high for points, creating PARALLEL plans when it wasn't the best option.
- Enable wagyu by default only if protobuf is available.
- Merged community `svn-2.5` as of 2019-03-06.
- Reduce the cost of `_ST_Intersects` from 512 to 128. Same as `ST_Simplify`.

## 2.5.1.2+carto-1

**Release date**: 2019-02-12

Changes:
- carto-package.json: Declare internal package compatibility.
- Merged community `svn-2.5` as of 2019-02-12.
- Backport wagyu introduction ([5508a4f](https://github.com/postgis/postgis/commit/5508a4f89c20686a19f233ef0a04b796d8a2cbaa)).
- Backport wagyu build improvements ([f4cdc57](https://github.com/postgis/postgis/commit/f4cdc57bc7099f8ffa63f065aff3d665228c5a78)).
- Enable wagyu by default.

## 2.5.1.1+carto-1

**Release date**: 2019-01-31

Changes:
- Start from `svn-2.5` ([427ed71](https://github.com/postgis/postgis/commit/427ed71c10683892d4f6b3f0898da9b5745562b4)).
- Backport .travis from trunk (Sanitizers, multiple builds).
- Backport [24efadd](https://github.com/postgis/postgis/commit/24efadd48d94ae7d6ce2aaab66ca940ab97a0a14): GCC warnings.
- Backport clang-format.
- Ported (2.4.1.1+carto-1): make_cartodb_dist.sh.
- Ported (2.4.1.2+carto-1): Strip decorators from 'sql' functions so inlining works better.
- Ported (2.4.1.2+carto-1 / 2.4.1.4+carto-1): Add explicit costs to expensive and other functions.
- Ported (trunk [e5c92b18f](https://github.com/postgis/postgis/commit/e5c92b18ffad323b3996fd68f0b23f80dc5bca28)): ST_AsMVTGeom: Drop geometries smaller than the resolution.
- Add carto-package.json.
- Merged community `svn-2.5` as of 2019-01-25 ([cb703716d](https://github.com/postgis/postgis/commit/fa3163d575b99abe430133909d2cd755c904e9c3)).
- Backport [789707ed2](https://github.com/postgis/postgis/commit/789707ed2c2e67c728cdc088de427f409379944b): ST_AsMVTGeom: Do resolution check before deserializing.
- Merged community `svn-2.5` as of 2019-01-31.