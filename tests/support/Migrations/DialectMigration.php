<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Migrations;

use function pack;

/**
 * Class DialectMigration
 */
class DialectMigration extends AbstractMigration
{
    protected $table = 'co_dialect';

    public function insert(
        int $primary,
        $blob,
        $binary,
        $bit,
        int $bigint,
        bool $boolean,
        string $char,
        float $decimal,
        $enum,
        int $integer,
        string $json,
        float $float,
        string $date,
        string $datetime,
        string $time,
        string $timestamp,
        int $mediumint,
        int $smallint,
        int $tinyint,
        string $longtext,
        string $mediumtext,
        string $tinytext,
        string $text,
        $varbinary,
        string $varchar
    ): int {
        $binaryPack    = pack('I', $binary);
        $varbinaryPack = pack('I', $varbinary);
        $sql           = <<<SQL
insert into co_dialect (
    field_primary,
    field_blob,
    field_binary,
    field_bit,
    field_bigint,
    field_boolean,
    field_char,
    field_decimal,
    field_enum,
    field_integer,
    field_json,
    field_float,
    field_date,
    field_datetime,
    field_time,
    field_timestamp,
    field_mediumint,
    field_smallint,
    field_tinyint,
    field_longtext,
    field_mediumtext,
    field_tinytext,
    field_text,
    field_varbinary,
    field_varchar
) values (
    :primary,
    :blob,
    :binary,
    :bit,
    :bigint,
    :boolean,
    :char,
    :decimal,
    :enum,
    :integer,
    :json,
    :float,
    :date,
    :datetime,
    :time,
    :timestamp,
    :mediumint,
    :smallint,
    :tinyint,
    :longtext,
    :mediumtext,
    :tinytext,
    :text,
    :varbinary,
    :varchar
)
SQL;
        $params        = [
            ':primary'    => $primary,
            ':blob'       => $blob,
            ':binary'     => $binaryPack,
            ':bit'        => $bit,
            ':bigint'     => $bigint,
            ':boolean'    => $boolean,
            ':char'       => $char,
            ':decimal'    => $decimal,
            ':enum'       => $enum,
            ':integer'    => $integer,
            ':json'       => $json,
            ':float'      => $float,
            ':date'       => $date,
            ':datetime'   => $datetime,
            ':time'       => $time,
            ':timestamp'  => $timestamp,
            ':mediumint'  => $mediumint,
            ':smallint'   => $smallint,
            ':tinyint'    => $tinyint,
            ':longtext'   => $longtext,
            ':mediumtext' => $mediumtext,
            ':tinytext'   => $tinytext,
            ':text'       => $text,
            ':varbinary'  => $varbinaryPack,
            ':varchar'    => $varchar,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_dialect`;
            ",
            "
create table co_dialect
(
  field_primary            int auto_increment primary key                   comment 'field_primary field',
  field_blob               blob                                        null comment 'field_blob field',
  field_binary             binary(10)                                  null comment 'field_binary field',
  field_bit                bit(10)                                     null comment 'field_bit field',
  field_bit_default        bit(10)       default b'1'                  null comment 'field_bit_default field',
  field_bigint             bigint        unsigned                      null comment 'field_bigint field',
  field_bigint_default     bigint        default 1                     null comment 'field_bigint_default field',
  field_boolean            tinyint(1)    unsigned                      null comment 'field_boolean field',
  field_boolean_default    tinyint(1)    default 1                     null comment 'field_boolean_default field',
  field_char               char(10)                                    null comment 'field_char field',
  field_char_default       char(10)      default 'ABC'                 null comment 'field_char_default field',
  field_decimal            decimal(10,4)                               null comment 'field_decimal field',
  field_decimal_default    decimal(10,4) default 14.5678               null comment 'field_decimal_default field',
  field_enum               enum('xs', 's', 'm', 'l', 'xl', 'internal') null comment 'field_enum field',
  field_integer            int(10)                                     null comment 'field_integer field',
  field_integer_default    int(10)       default 1                     null comment 'field_integer_default field',
  field_json               json                                        null comment 'field_json field',
  field_float              float(10,4)                                 null comment 'field_float field',
  field_float_default      float(10,4)   default 14.5678               null comment 'field_float_default field',
  field_date               date                                        null comment 'field_date field',
  field_date_default       date          default '2018-10-01'          null comment 'field_date_default field',
  field_datetime           datetime                                    null comment 'field_datetime field',
  field_datetime_default   datetime      default '2018-10-01 12:34:56' null comment 'field_datetime_default field',
  field_time               time                                        null comment 'field_time field',
  field_time_default       time          default '12:34:56'            null comment 'field_time_default field',
  field_timestamp          timestamp                                   null comment 'field_timestamp field',
  field_timestamp_default  timestamp     default '2018-10-01 12:34:56' null comment 'field_timestamp_default field',
  field_mediumint          mediumint(10) unsigned                      null comment 'field_mediumint field',
  field_mediumint_default  mediumint(10) default 1                     null comment 'field_mediumint_default field',
  field_smallint           smallint(10)  unsigned                      null comment 'field_smallint field',
  field_smallint_default   smallint(10)  default 1                     null comment 'field_smallint_default field',
  field_tinyint            tinyint(10)   unsigned                      null comment 'field_tinyint field',
  field_tinyint_default    tinyint(10)   default 1                     null comment 'field_tinyint_default field',
  field_longtext           longtext                                    null comment 'field_longtext field',
  field_mediumtext         mediumtext                                  null comment 'field_mediumtext field',
  field_tinytext           tinytext                                    null comment 'field_tinytext field',
  field_text               text                                        null comment 'field_text field',
  field_varbinary          varbinary(10)                               null comment 'field_varbinary field',
  field_varchar            varchar(10)                                 null comment 'field_varchar field',
  field_varchar_default    varchar(10)   default 'D'                   null comment 'field_varchar_default field',
  unique key dialect_table_unique (field_integer),
  key dialect_table_index (field_bigint),
  key dialect_table_two_fields (field_char, field_char_default)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists co_dialect;
            ",
            "
create table co_dialect
(
    field_primary           integer constraint co_dialect_pk primary key autoincrement,
    field_blob              blob    null,
    field_binary            blob    null,
    field_bit               integer null,
    field_bit_default       integer default 1    null,
    field_bigint            integer null,
    field_bigint_default    integer default 1    null,
    field_boolean           integer null,
    field_boolean_default   integer default 1    null,
    field_char              text    null,
    field_char_default      text    default 'ABC' null,
    field_decimal           real    null,
    field_decimal_default   real    default 14.5678 null,
    field_enum              text    null,
    field_integer           integer null,
    field_integer_default   integer default 1    null,
    field_json              text    null,
    field_float             real    null,
    field_float_default     real    default 14.5678 null,
    field_date              text    null,
    field_date_default      text    default '2018-10-01' null,
    field_datetime          text    null,
    field_datetime_default  text    default '2018-10-01 12:34:56' null,
    field_time              text    null,
    field_time_default      text    default '12:34:56' null,
    field_timestamp         text    null,
    field_timestamp_default text    default '2018-10-01 12:34:56' null,
    field_mediumint         integer null,
    field_mediumint_default integer default 1    null,
    field_smallint          integer null,
    field_smallint_default  integer default 1    null,
    field_tinyint           integer null,
    field_tinyint_default   integer default 1    null,
    field_longtext          text    null,
    field_mediumtext        text    null,
    field_tinytext          text    null,
    field_text              text    null,
    field_varbinary         blob    null,
    field_varchar           text    null,
    field_varchar_default   text    default 'D'  null
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
DROP TABLE IF EXISTS co_dialect;
            ",
            "
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
            ",
            "
CREATE INDEX dialect_table_index ON co_dialect(field_bigint);
            ",
            "
CREATE INDEX dialect_table_two_fields ON co_dialect(field_char, field_char_default);
            ",
            "
COMMENT ON COLUMN co_dialect.field_primary IS 'field_primary field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_blob IS 'field_blob field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_binary IS 'field_binary field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_bit IS 'field_bit field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_bit_default IS 'field_bit_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_bigint IS 'field_bigint field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_bigint_default IS 'field_bigint_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_boolean IS 'field_boolean field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_boolean_default IS 'field_boolean_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_char IS 'field_char field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_char_default IS 'field_char_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_decimal IS 'field_decimal field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_decimal_default IS 'field_decimal_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_enum IS 'field_enum field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_integer IS 'field_integer field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_integer_default IS 'field_integer_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_json IS 'field_json field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_float IS 'field_float field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_float_default IS 'field_float_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_date IS 'field_date field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_date_default IS 'field_date_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_datetime IS 'field_datetime field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_datetime_default IS 'field_datetime_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_time IS 'field_time field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_time_default IS 'field_time_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_timestamp IS 'field_timestamp field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_timestamp_default IS 'field_timestamp_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_mediumint IS 'field_mediumint field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_mediumint_default IS 'field_mediumint_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_smallint IS 'field_smallint field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_smallint_default IS 'field_smallint_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_tinyint IS 'field_tinyint field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_tinyint_default IS 'field_tinyint_default field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_longtext IS 'field_longtext field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_mediumtext IS 'field_mediumtext field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_tinytext IS 'field_tinytext field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_text IS 'field_text field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_varbinary IS 'field_varbinary field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_varchar IS 'field_varchar field';
            ",
            "
COMMENT ON COLUMN co_dialect.field_varchar_default IS 'field_varchar_default field';
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
