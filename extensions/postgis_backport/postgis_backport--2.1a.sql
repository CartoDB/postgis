
CREATE OR REPLACE FUNCTION ST_AsTWKB(geom geometry, prec int4 default NULL, prec_z int4 default NULL, prec_m int4 default NULL, with_sizes boolean default NULL, with_boxes boolean default NULL)
  RETURNS bytea
  AS '$libdir/postgis-2.1','TWKBFromLWGEOM'
  LANGUAGE 'c' IMMUTABLE;

CREATE OR REPLACE FUNCTION ST_AsTWKB(geom geometry[], ids bigint[], prec int4 default NULL, prec_z int4 default NULL, prec_m int4 default NULL, with_sizes boolean default NULL, with_boxes boolean default NULL)
  RETURNS bytea
  AS '$libdir/postgis-2.1','TWKBFromLWGEOMArray'
  LANGUAGE 'c' IMMUTABLE;

CREATE OR REPLACE FUNCTION ST_GeomFromTWKB(bytea)
  RETURNS geometry
  AS '$libdir/postgis-2.1','LWGEOMFromTWKB'
  LANGUAGE 'c' IMMUTABLE STRICT;
