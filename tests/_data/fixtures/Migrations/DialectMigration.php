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

namespace Phalcon\Test\Fixtures\Migrations;

use PHPUnit\Framework\Assert;

/**
 * Class DialectMigration
 */
class DialectMigration extends AbstractMigration
{
    protected $table = 'co_dialect';

    /**
     * @param int         $id
     * @param int|null    $custId
     * @param int         $status
     * @param string|null $title
     * @param float       $total
     * @param string|null $createdAt
     *
     * @return int
     */
    public function insert(
        $id,
        int $custId = null,
        int $status = 0,
        string $title = null,
        float $total = 0,
        string $createdAt = null
    ): int {
        $id     = $id ?: 'null';
        $title  = $title ?: uniqid('', true);
        $custId = $custId ?: 1;
        $now    = $createdAt ?: date('Y-m-d H:i:s');
        $sql    = <<<SQL
insert into co_invoices (
    inv_id, inv_cst_id, inv_status_flag, inv_title, inv_total, inv_created_at
) values (
    {$id}, {$custId}, {$status}, '{$title}', {$total}, '{$now}'
)
SQL;

        if (!$result = $this->connection->exec($sql)) {
            $table  = $this->getTable();
            $driver = $this->getDriverName();
            Assert::fail(
                sprintf("Failed to insert row #%d into table '%s' using '%s' driver", $id, $table, $driver)
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
  field_primary           int auto_increment primary key,
  field_blob              blob                                        null,
  field_binary            binary                                      null,
  field_bit               bit                                         null,
  field_bit_default       bit           default b'1'                  null,
  field_bigint            bigint                                      null,
  field_bigint_default    bigint        default 1                     null,
  field_boolean           tinyint(1)                                  null,
  field_boolean_default   tinyint(1)    default 1                     null,
  field_char              char(10)                                    null,
  field_char_default      char(10)      default 'ABC'                 null,
  field_decimal           decimal(10,4)                               null,
  field_decimal_default   decimal(10,4) default 14.5678               null,
  field_enum              enum('xs', 's', 'm', 'l', 'xl', 'internal') null,
  field_integer           int(10)                                     null,
  field_integer_default   int(10)       default 1                     null,
  field_json              json                                        null,
  field_float             float(10,4)                                 null,
  field_float_default     float(10,4)   default 14.5678               null,
  field_date              date                                        null,
  field_date_default      date          default '2018-10-01'          null,
  field_datetime          datetime                                    null,
  field_datetime_default  datetime      default '2018-10-01 12:34:56' null,
  field_time              time                                        null,
  field_time_default      time          default '12:34:56'            null,
  field_timestamp         timestamp                                   null,
  field_timestamp_default timestamp     default '2018-10-01 12:34:56' null,
  field_mediumint         mediumint(10)                               null,
  field_mediumint_default mediumint(10) default 1                     null,
  field_smallint          smallint(10)                                null,
  field_smallint_default  smallint(10)  default 1                     null,
  field_tinyint           tinyint(10)                                 null,
  field_tinyint_default   tinyint(10)   default 1                     null,
  field_longtext          longtext                                    null,
  field_mediumtext        mediumtext                                  null,
  field_tinytext          tinytext                                    null,
  field_text              text                                        null,
  field_varbinary         varbinary(10)                               null,
  field_varchar           varchar(10)                                 null,
  field_varchar_default   varchar(10)   default 'D'                   null,
  unique key dialect_table_unique (field_integer),
  key dialect_table_index (field_bigint),
  key dialect_table_two_fields (field_char, field_char_default)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [];
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
