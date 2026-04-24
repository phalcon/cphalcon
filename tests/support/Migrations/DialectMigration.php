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

use PDO;
use Phalcon\Db\Column;
use PHPUnit\Framework\Assert;
use function array_key_exists;
use function array_values;
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
        $sql    = <<<SQL
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
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?,
    ?
)
SQL;
        $binaryPack    = pack('I', $binary);
        $varbinaryPack = pack('I', $varbinary);
        $params        = [
            $primary       => Column::BIND_PARAM_INT,
            $blob          => Column::BIND_PARAM_BLOB,
            $binaryPack    => Column::BIND_PARAM_BLOB,
            $bit           => Column::BIND_PARAM_INT,
            $bigint        => Column::BIND_PARAM_INT,
            $boolean       => Column::BIND_PARAM_BOOL,
            $char          => Column::BIND_PARAM_STR,
            $decimal       => Column::BIND_PARAM_DECIMAL,
            $enum          => Column::BIND_PARAM_STR,
            $integer       => Column::BIND_PARAM_INT,
            $json          => Column::BIND_PARAM_STR,
            $float         => Column::BIND_PARAM_DECIMAL,
            $date          => Column::BIND_PARAM_STR,
            $datetime      => Column::BIND_PARAM_STR,
            $time          => Column::BIND_PARAM_STR,
            $timestamp     => Column::BIND_PARAM_STR,
            $mediumint     => Column::BIND_PARAM_INT,
            $smallint      => Column::BIND_PARAM_INT,
            $tinyint       => Column::BIND_PARAM_INT,
            $longtext      => Column::BIND_PARAM_STR,
            $mediumtext    => Column::BIND_PARAM_STR,
            $tinytext      => Column::BIND_PARAM_STR,
            $text          => Column::BIND_PARAM_STR,
            $varbinaryPack => Column::BIND_PARAM_BLOB,
            $varchar       => Column::BIND_PARAM_STR,
        ];

        if (!$result = $this->connection->exec($sql, array_keys($params), array_values($params))) {
            $table  = $this->getTable();
            $driver = $this->getDriverName();
            Assert::fail(
                sprintf(
                    "Failed to insert row #%d into table '%s' using '%s' driver",
                    $primary,
                    $table,
                    $driver
                )
            );
        }

        return $result;
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
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
