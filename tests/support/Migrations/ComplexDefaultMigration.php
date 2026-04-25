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

namespace Phalcon\Tests\Support\Migrations;

class ComplexDefaultMigration extends AbstractMigration
{
    protected $table = 'complex_default';

    /**
     * @param int|null    $id
     * @param string|null $created
     * @param string|null $updated
     *
     * @return int
     */
    public function insert(
        ?int $id,
        ?string $created = null,
        ?string $updated = null,
    ): int {
        $sql = <<<'SQL'
INSERT INTO complex_default (
    id, created, updated
) VALUES (
    :id, :created, :updated
)
SQL;

        $params = [
            ':id'      => $id ?? null,
            ':created' => $created ?? null,
            ':update'  => $updated ?? null,
        ];

        return $this->execute($sql, $params);
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
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists complex_default;
            ",
            "
create table complex_default
(
    id           integer constraint complex_default_pk primary key autoincrement,
    created      text default (datetime('now')),
    updated      text default (datetime('now')),
    updated_null text null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}