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

use PHPUnit\Framework\Assert;

/**
 * Class ArtistsMigration
 */
class ArtistsMigration extends AbstractMigration
{
    protected $table = 'artists';

    public function insert(
        ?int $id,
        string $name
    ): int {
        $sql = <<<'SQL'
INSERT INTO artists (
    id, name
) VALUES (
    :id, :name
)
SQL;

        $params = [
            ':id'       => $id ?? null,
            ':name'     => $name,
        ];

        return $this->execute($sql, $params);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `artists`;
            ",
            "
create table `artists`
(
    `id`   int(10) auto_increment primary key,
    `name` varchar(100) not null
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
drop table if exists artists;
            ",
            "
create table artists
(
    id   serial constraint artists_pk primary key,
    name varchar(100) not null
);
            ",
        ];
    }

    protected function getSqlSqlite(): array
    {
        return [
            "
drop table if exists artists;
            ",
            "
create table artists
(
    id   integer constraint artists_pk primary key autoincrement not null,
    name text not null
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
