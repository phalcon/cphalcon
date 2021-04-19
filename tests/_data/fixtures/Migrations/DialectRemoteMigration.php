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
class DialectRemoteMigration extends AbstractMigration
{
    protected $table = 'co_dialect_remote';

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
drop table if exists `co_dialect_remote`;
            ",
            "
create table co_dialect_remote
(
  field_primary int auto_increment primary key,
  field_text    varchar(20) null
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
