<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

class ComplexDefaultMigration extends AbstractMigration
{
    protected $table = 'complex_default';

    /**
     * @param int|null $id
     * @param string|null $created
     * @param string|null $updated
     * @return int
     */
    public function insert(
        $id,
        string $created = null,
        string $updated = null
    ): int {
        $id  = $id ?: 'null';
        $sql = <<<SQL
insert into complex_default (
    id, created, updated
) values (
    {$id}, {$created}, "{$updated}"
)
SQL;

        return $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `complex_default`;
            ",
            "
create table complex_default
(
    `id`          int(10) auto_increment primary key,
    `created`  TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `updated`  TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
);
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
