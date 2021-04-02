<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

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
    {$id}, '{$created}', '{$updated}'
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
    `id`           int(10) auto_increment primary key,
    `created`      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    `updated`      TIMESTAMP DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
    `updated_null` TIMESTAMP NULL DEFAULT NULL ON UPDATE CURRENT_TIMESTAMP
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
        return [
            "
drop table if exists complex_default;
            ",
            "
create table complex_default
(
    id           SERIAL PRIMARY KEY,
    created      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated      TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    updated_null TIMESTAMP NULL DEFAULT NULL
);
            ",
            "
CREATE OR REPLACE FUNCTION update_timestamp()
RETURNS TRIGGER AS $$
BEGIN
   NEW.updated = NOW(); 
   NEW.updated_null = NOW();
   RETURN NEW;
END;
$$ language 'plpgsql';
            ",
            "
CREATE TRIGGER update_timestamp BEFORE UPDATE
ON complex_default FOR EACH ROW EXECUTE PROCEDURE 
update_timestamp();
            "
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}