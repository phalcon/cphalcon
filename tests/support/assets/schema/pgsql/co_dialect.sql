DROP TABLE IF EXISTS "co_dialect";

CREATE TABLE co_dialect (
    field_primary            INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    field_blob               BYTEA,
    field_binary             BYTEA,
    field_bit                BIT(10),
    field_bit_default        BIT(10) DEFAULT B'1',
    field_bigint             BIGINT,
    field_bigint_default     BIGINT DEFAULT 1,
    field_boolean            SMALLINT,
    field_boolean_default    SMALLINT DEFAULT 1,
    field_char               CHAR(10),
    field_char_default       CHAR(10) DEFAULT 'ABC',
    field_decimal            NUMERIC(10,4),
    field_decimal_default    NUMERIC(10,4) DEFAULT 14.5678,
    field_enum               VARCHAR(10),
    field_integer            INTEGER,
    field_integer_default    INTEGER DEFAULT 1,
    field_json               JSONB,
    field_float              REAL,
    field_float_default      REAL DEFAULT 14.5678,
    field_date               DATE,
    field_date_default       DATE DEFAULT '2018-10-01',
    field_datetime           TIMESTAMP,
    field_datetime_default   TIMESTAMP DEFAULT '2018-10-01 12:34:56',
    field_time               TIME,
    field_time_default       TIME DEFAULT '12:34:56',
    field_timestamp          TIMESTAMP,
    field_timestamp_default  TIMESTAMP DEFAULT '2018-10-01 12:34:56',
    field_mediumint          INTEGER,
    field_mediumint_default  INTEGER DEFAULT 1,
    field_smallint           SMALLINT,
    field_smallint_default   SMALLINT DEFAULT 1,
    field_tinyint            SMALLINT,
    field_tinyint_default    SMALLINT DEFAULT 1,
    field_longtext           TEXT,
    field_mediumtext         TEXT,
    field_tinytext           TEXT,
    field_text               TEXT,
    field_varbinary          BYTEA,
    field_varchar            VARCHAR(10),
    field_varchar_default    VARCHAR(10) DEFAULT 'D',
    UNIQUE (field_integer)
);

CREATE INDEX dialect_table_index ON co_dialect(field_bigint);

CREATE INDEX dialect_table_two_fields ON co_dialect(field_char, field_char_default);

COMMENT ON COLUMN co_dialect.field_primary IS 'field_primary field';

COMMENT ON COLUMN co_dialect.field_blob IS 'field_blob field';

COMMENT ON COLUMN co_dialect.field_binary IS 'field_binary field';

COMMENT ON COLUMN co_dialect.field_bit IS 'field_bit field';

COMMENT ON COLUMN co_dialect.field_bit_default IS 'field_bit_default field';

COMMENT ON COLUMN co_dialect.field_bigint IS 'field_bigint field';

COMMENT ON COLUMN co_dialect.field_bigint_default IS 'field_bigint_default field';

COMMENT ON COLUMN co_dialect.field_boolean IS 'field_boolean field';

COMMENT ON COLUMN co_dialect.field_boolean_default IS 'field_boolean_default field';

COMMENT ON COLUMN co_dialect.field_char IS 'field_char field';

COMMENT ON COLUMN co_dialect.field_char_default IS 'field_char_default field';

COMMENT ON COLUMN co_dialect.field_decimal IS 'field_decimal field';

COMMENT ON COLUMN co_dialect.field_decimal_default IS 'field_decimal_default field';

COMMENT ON COLUMN co_dialect.field_enum IS 'field_enum field';

COMMENT ON COLUMN co_dialect.field_integer IS 'field_integer field';

COMMENT ON COLUMN co_dialect.field_integer_default IS 'field_integer_default field';

COMMENT ON COLUMN co_dialect.field_json IS 'field_json field';

COMMENT ON COLUMN co_dialect.field_float IS 'field_float field';

COMMENT ON COLUMN co_dialect.field_float_default IS 'field_float_default field';

COMMENT ON COLUMN co_dialect.field_date IS 'field_date field';

COMMENT ON COLUMN co_dialect.field_date_default IS 'field_date_default field';

COMMENT ON COLUMN co_dialect.field_datetime IS 'field_datetime field';

COMMENT ON COLUMN co_dialect.field_datetime_default IS 'field_datetime_default field';

COMMENT ON COLUMN co_dialect.field_time IS 'field_time field';

COMMENT ON COLUMN co_dialect.field_time_default IS 'field_time_default field';

COMMENT ON COLUMN co_dialect.field_timestamp IS 'field_timestamp field';

COMMENT ON COLUMN co_dialect.field_timestamp_default IS 'field_timestamp_default field';

COMMENT ON COLUMN co_dialect.field_mediumint IS 'field_mediumint field';

COMMENT ON COLUMN co_dialect.field_mediumint_default IS 'field_mediumint_default field';

COMMENT ON COLUMN co_dialect.field_smallint IS 'field_smallint field';

COMMENT ON COLUMN co_dialect.field_smallint_default IS 'field_smallint_default field';

COMMENT ON COLUMN co_dialect.field_tinyint IS 'field_tinyint field';

COMMENT ON COLUMN co_dialect.field_tinyint_default IS 'field_tinyint_default field';

COMMENT ON COLUMN co_dialect.field_longtext IS 'field_longtext field';

COMMENT ON COLUMN co_dialect.field_mediumtext IS 'field_mediumtext field';

COMMENT ON COLUMN co_dialect.field_tinytext IS 'field_tinytext field';

COMMENT ON COLUMN co_dialect.field_text IS 'field_text field';

COMMENT ON COLUMN co_dialect.field_varbinary IS 'field_varbinary field';

COMMENT ON COLUMN co_dialect.field_varchar IS 'field_varchar field';

COMMENT ON COLUMN co_dialect.field_varchar_default IS 'field_varchar_default field';
