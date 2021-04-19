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
 * Class DialectIntermediateMigration
 */
class DialectIntermediateMigration extends AbstractMigration
{
    protected $table = 'co_dialect_intermediate';

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
drop table if exists `co_dialect_intermediate`;
            ",
            "
create table co_dialect_intermediate
(
  field_primary_id int null,
  field_remote_id  int null,
  constraint dialect_table_intermediate_primary__fk
    foreign key (field_primary_id) references dialect_table (field_primary),
  constraint dialect_table_intermediate_remote__fk
    foreign key (field_remote_id) references dialect_table_remote (field_primary)
      on update cascade on delete set null
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
