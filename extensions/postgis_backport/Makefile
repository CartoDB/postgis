EXTENSION = postgis_backport
DATA = postgis_backport--2.1a.sql

# 
# Leave the below alone
#

PG_CONFIG = /opt/pgsql/9.3/bin/pg_config
PERL = /opt/local/bin/perl
MINOR_VERSION = 2.1
BACKPORT_FULL_VERSION = $(MINOR_VERSION)$(BACKPORT_VERSION)

EXTRA_CLEAN = $(DATA)

PGXS := $(shell $(PG_CONFIG) --pgxs)
include $(PGXS)

%.sql: %.sql.in
	$(PERL) -lpe "s'MODULE_PATHNAME'\$$libdir/postgis-2.1'g" < $< > $@

all: $(DATA)
