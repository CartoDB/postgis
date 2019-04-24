/**********************************************************************
 *
 * PostGIS - Spatial Types for PostgreSQL
 * http://postgis.net
 * Copyright 2010 Paul Ramsey <pramsey@cleverelephant.ca>
 *
 * This is free software; you can redistribute and/or modify it under
 * the terms of the GNU General Public Licence. See the COPYING file.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CUnit/Basic.h"

#include "liblwgeom_internal.h"
#include "cu_tester.h"

/*
** Global variable to hold hex WKB strings
*/
static char *s;
static size_t s_size;

/*
** The suite initialization function.
** Create any re-used objects.
*/
static int init_wkb_out_suite(void)
{
	s = NULL;
	return 0;
}

/*
** The suite cleanup function.
** Frees any global objects.
*/
static int clean_wkb_out_suite(void)
{
	if (s) free(s);
	s = NULL;
	return 0;
}

/*
** Creating an input from a hexwkb
*/
static void cu_wkb_from_hexwkb(char *hexwkb)
{
	LWGEOM *g = lwgeom_from_hexwkb(hexwkb, LW_PARSER_CHECK_NONE);
	if ( s ) free(s);
	s = (char*)lwgeom_to_wkb(g, WKB_HEX | WKB_XDR | WKB_EXTENDED, 0);
	lwgeom_free(g);
}

/*
** Creating an input WKB from a wkb string
*/
static void cu_wkb(char *wkt)
{
	LWGEOM *g = lwgeom_from_wkt(wkt, LW_PARSER_CHECK_NONE);
	if ( s ) free(s);
	s = (char*)lwgeom_to_wkb(g, WKB_HEX | WKB_XDR | WKB_EXTENDED, &s_size);
	lwgeom_free(g);
}

static void cu_wkb_empty_point_check(char *hex)
{
	LWGEOM *g;
	g = lwgeom_from_hexwkb(hex, LW_PARSER_CHECK_NONE);
	CU_ASSERT(g != NULL);
	CU_ASSERT(lwgeom_is_empty(g));
	CU_ASSERT(g->type == POINTTYPE);
	lwgeom_free(g);
}

static void test_wkb_out_point(void)
{
	cu_wkb("POINT(0 0 0 0)");
	CU_ASSERT_STRING_EQUAL(s,"00C00000010000000000000000000000000000000000000000000000000000000000000000");

	cu_wkb("SRID=4;POINTM(1 1 1)");
	CU_ASSERT_STRING_EQUAL(s,"0060000001000000043FF00000000000003FF00000000000003FF0000000000000");

	cu_wkb("POINT EMPTY");
	cu_wkb_empty_point_check(s);

	cu_wkb("SRID=4326;POINT EMPTY");
	cu_wkb_empty_point_check(s);

	cu_wkb("POINT Z EMPTY");
	cu_wkb_empty_point_check(s);

	cu_wkb("POINT M EMPTY");
	cu_wkb_empty_point_check(s);

	cu_wkb("POINT ZM EMPTY");
	cu_wkb_empty_point_check(s);
}

static void test_wkb_out_linestring(void)
{
	cu_wkb("LINESTRING(0 0,1 1)");
	CU_ASSERT_STRING_EQUAL(s,"000000000200000002000000000000000000000000000000003FF00000000000003FF0000000000000");

	cu_wkb("LINESTRING(0 0 1,1 1 2,2 2 3)");
	CU_ASSERT_STRING_EQUAL(s,"008000000200000003000000000000000000000000000000003FF00000000000003FF00000000000003FF00000000000004000000000000000400000000000000040000000000000004008000000000000");

	cu_wkb("LINESTRING EMPTY");
	CU_ASSERT_STRING_EQUAL(s,"000000000200000000");
}

static void test_wkb_out_polygon(void)
{
	cu_wkb("SRID=4;POLYGON((0 0 0,0 1 0,1 1 0,1 0 0,0 0 0))");
	CU_ASSERT_STRING_EQUAL(s,"00A000000300000004000000010000000500000000000000000000000000000000000000000000000000000000000000003FF000000000000000000000000000003FF00000000000003FF000000000000000000000000000003FF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

	cu_wkb("SRID=14;POLYGON((0 0 0 1,0 1 0 2,1 1 0 3,1 0 0 4,0 0 0 5))");
	CU_ASSERT_STRING_EQUAL(s,"00E00000030000000E00000001000000050000000000000000000000000000000000000000000000003FF000000000000000000000000000003FF0000000000000000000000000000040000000000000003FF00000000000003FF0000000000000000000000000000040080000000000003FF00000000000000000000000000000000000000000000040100000000000000000000000000000000000000000000000000000000000004014000000000000");

	cu_wkb("SRID=4;POLYGON((0 0 0 1,0 1 0 2,1 1 0 3,1 0 0 4,0 0 0 5))");
	CU_ASSERT_STRING_EQUAL(s,"00E00000030000000400000001000000050000000000000000000000000000000000000000000000003FF000000000000000000000000000003FF0000000000000000000000000000040000000000000003FF00000000000003FF0000000000000000000000000000040080000000000003FF00000000000000000000000000000000000000000000040100000000000000000000000000000000000000000000000000000000000004014000000000000");

	cu_wkb("POLYGON EMPTY");
	CU_ASSERT_STRING_EQUAL(s,"000000000300000000");

	/*
	*  POLYGON with EMPTY shell
	*  See http://http://trac.osgeo.org/postgis/ticket/937
	*/
	cu_wkb_from_hexwkb("01030000000100000000000000");
	CU_ASSERT_STRING_EQUAL(s,"000000000300000000");
}

static void test_wkb_out_multipoint(void)
{
	cu_wkb("SRID=4;MULTIPOINT(0 0 0,0 1 0,1 1 0,1 0 0,0 0 0)");
	CU_ASSERT_STRING_EQUAL(s,"00A000000400000004000000050080000001000000000000000000000000000000000000000000000000008000000100000000000000003FF0000000000000000000000000000000800000013FF00000000000003FF0000000000000000000000000000000800000013FF0000000000000000000000000000000000000000000000080000001000000000000000000000000000000000000000000000000");

	cu_wkb("MULTIPOINT(0 0 0, 0.26794919243112270647255365849413 1 3)");
	CU_ASSERT_STRING_EQUAL(s,"008000000400000002008000000100000000000000000000000000000000000000000000000000800000013FD126145E9ECD563FF00000000000004008000000000000");

	cu_wkb("MULTIPOINT EMPTY");
	CU_ASSERT_STRING_EQUAL(s,"000000000400000000");
}

static void test_wkb_out_multilinestring(void) {}

static void test_wkb_out_multipolygon(void)
{
	cu_wkb("SRID=14;MULTIPOLYGON(((0 0 0,0 1 0,1 1 0,1 0 0,0 0 0)),((-1 -1 0,-1 2 0,2 2 0,2 -1 0,-1 -1 0),(0 0 0,0 1 0,1 1 0,1 0 0,0 0 0)))");
	CU_ASSERT_STRING_EQUAL(s,"00A00000060000000E000000020080000003000000010000000500000000000000000000000000000000000000000000000000000000000000003FF000000000000000000000000000003FF00000000000003FF000000000000000000000000000003FF00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000800000030000000200000005BFF0000000000000BFF00000000000000000000000000000BFF0000000000000400000000000000000000000000000004000000000000000400000000000000000000000000000004000000000000000BFF00000000000000000000000000000BFF0000000000000BFF000000000000000000000000000000000000500000000000000000000000000000000000000000000000000000000000000003FF000000000000000000000000000003FF00000000000003FF000000000000000000000000000003FF000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

	cu_wkb("MULTIPOLYGON EMPTY");
	CU_ASSERT_STRING_EQUAL(s,"000000000600000000");
}

static void test_wkb_out_collection(void)
{
	cu_wkb("SRID=14;GEOMETRYCOLLECTION(POLYGON((0 0 0,0 1 0,1 1 0,1 0 0,0 0 0)),POINT(1 1 1))");
	CU_ASSERT_STRING_EQUAL(s,"00A00000070000000E000000020080000003000000010000000500000000000000000000000000000000000000000000000000000000000000003FF000000000000000000000000000003FF00000000000003FF000000000000000000000000000003FF00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000800000013FF00000000000003FF00000000000003FF0000000000000");

	cu_wkb("GEOMETRYCOLLECTION EMPTY");
	CU_ASSERT_STRING_EQUAL(s,"000000000700000000");

	cu_wkb("GEOMETRYCOLLECTION(LINESTRING EMPTY)");
	CU_ASSERT_STRING_EQUAL(s,"000000000700000001000000000200000000");

	cu_wkb("GEOMETRYCOLLECTION(LINESTRING EMPTY, MULTILINESTRING(EMPTY,EMPTY))");
	// printf("%s\n",s );
	CU_ASSERT_STRING_EQUAL(s,"000000000700000002000000000200000000000000000500000002000000000200000000000000000200000000");
}

static void test_wkb_out_circularstring(void)
{
	cu_wkb("CIRCULARSTRING(0 -2,-2 0,0 2,2 0,0 -2)");
	CU_ASSERT_STRING_EQUAL(s,"0000000008000000050000000000000000C000000000000000C000000000000000000000000000000000000000000000004000000000000000400000000000000000000000000000000000000000000000C000000000000000");

	cu_wkb("CIRCULARSTRING(-5 0 0 4, 0 5 1 3, 5 0 2 2, 10 -5 3 1, 15 0 4 0)");
	CU_ASSERT_STRING_EQUAL(s,"00C000000800000005C014000000000000000000000000000000000000000000004010000000000000000000000000000040140000000000003FF0000000000000400800000000000040140000000000000000000000000000400000000000000040000000000000004024000000000000C01400000000000040080000000000003FF0000000000000402E000000000000000000000000000040100000000000000000000000000000");

	cu_wkb("SRID=43;CIRCULARSTRING(-5 0 0 4, 0 5 1 3, 5 0 2 2, 10 -5 3 1, 15 0 4 0)");
	CU_ASSERT_STRING_EQUAL(s,"00E00000080000002B00000005C014000000000000000000000000000000000000000000004010000000000000000000000000000040140000000000003FF0000000000000400800000000000040140000000000000000000000000000400000000000000040000000000000004024000000000000C01400000000000040080000000000003FF0000000000000402E000000000000000000000000000040100000000000000000000000000000");
}

static void test_wkb_out_compoundcurve(void)
{
	cu_wkb("COMPOUNDCURVE(CIRCULARSTRING(0 0 0, 0.26794919243112270647255365849413 1 3, 0.5857864376269049511983112757903 1.4142135623730950488016887242097 1),(0.5857864376269049511983112757903 1.4142135623730950488016887242097 1,2 0 0,0 0 0))");
	CU_ASSERT_STRING_EQUAL(s,"0080000009000000020080000008000000030000000000000000000000000000000000000000000000003FD126145E9ECD563FF000000000000040080000000000003FE2BEC3330188673FF6A09E667F3BCD3FF00000000000000080000002000000033FE2BEC3330188673FF6A09E667F3BCD3FF0000000000000400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
}

static void test_wkb_out_curvpolygon(void)
{
	cu_wkb("CURVEPOLYGON(CIRCULARSTRING(-2 0 0 0,-1 -1 1 2,0 0 2 4,1 -1 3 6,2 0 4 8,0 2 2 4,-2 0 0 0),(-1 0 1 2,0 0.5 2 4,1 0 3 6,0 1 3 4,-1 0 1 2))");
	CU_ASSERT_STRING_EQUAL(s,"00C000000A0000000200C000000800000007C000000000000000000000000000000000000000000000000000000000000000BFF0000000000000BFF00000000000003FF0000000000000400000000000000000000000000000000000000000000000400000000000000040100000000000003FF0000000000000BFF00000000000004008000000000000401800000000000040000000000000000000000000000000401000000000000040200000000000000000000000000000400000000000000040000000000000004010000000000000C00000000000000000000000000000000000000000000000000000000000000000C000000200000005BFF000000000000000000000000000003FF0000000000000400000000000000000000000000000003FE0000000000000400000000000000040100000000000003FF000000000000000000000000000004008000000000000401800000000000000000000000000003FF000000000000040080000000000004010000000000000BFF000000000000000000000000000003FF00000000000004000000000000000");
}

static void test_wkb_out_multicurve(void) {}

static void test_wkb_out_multisurface(void) {}

static void test_wkb_out_polyhedralsurface(void)
{
//	cu_wkb("POLYHEDRALSURFACE(((0 0 0 0,0 0 1 0,0 1 0 2,0 0 0 0)),((0 0 0 0,0 1 0 0,1 0 0 4,0 0 0 0)),((0 0 0 0,1 0 0 0,0 0 1 6,0 0 0 0)),((1 0 0 0,0 1 0 0,0 0 1 0,1 0 0 0)))");
//	CU_ASSERT_STRING_EQUAL(s, t);
//	printf("\nnew: %s\nold: %s\n",s,t);
}

/*
** Used by test harness to register the tests in this file.
*/
void wkb_out_suite_setup(void);
void wkb_out_suite_setup(void)
{
	CU_pSuite suite = CU_add_suite("wkb_output", init_wkb_out_suite, clean_wkb_out_suite);
	PG_ADD_TEST(suite, test_wkb_out_point);
	PG_ADD_TEST(suite, test_wkb_out_linestring);
	PG_ADD_TEST(suite, test_wkb_out_polygon);
	PG_ADD_TEST(suite, test_wkb_out_multipoint);
	PG_ADD_TEST(suite, test_wkb_out_multilinestring);
	PG_ADD_TEST(suite, test_wkb_out_multipolygon);
	PG_ADD_TEST(suite, test_wkb_out_collection);
	PG_ADD_TEST(suite, test_wkb_out_circularstring);
	PG_ADD_TEST(suite, test_wkb_out_compoundcurve);
	PG_ADD_TEST(suite, test_wkb_out_curvpolygon);
	PG_ADD_TEST(suite, test_wkb_out_multicurve);
	PG_ADD_TEST(suite, test_wkb_out_multisurface);
	PG_ADD_TEST(suite, test_wkb_out_polyhedralsurface);
}
