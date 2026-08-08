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

use Phalcon\Talon\Database\Schema\AbstractSchema;

/**
 * Split out of ForeignKeyParentMigration so each class declares exactly one
 * table, which is what the schema manifest keys on.
 *
 * Sorts before ForeignKeyParentMigration by file name, so its generated DROP
 * runs first - and on pgsql that also removes the FK constraint the parent
 * would otherwise still be referenced by, which is why the child has to go
 * first. The constraint itself is added by the parent, once both tables exist.
 */
class ForeignKeyChildMigration extends AbstractSchema
{
    protected string $table = 'foreign_key_child';

    public function insert(): int
    {
        return 0;
    }

    protected function getStatementsMysql(): array
    {
        return [
            "
CREATE TABLE `foreign_key_child` (
    `id`        int(10) NOT NULL AUTO_INCREMENT,
    `name`      varchar(70) NOT NULL,
    `child_int` int NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE KEY `foreign_key_child_child_int` (`child_int`)
) ENGINE=InnoDB;
            ",
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
CREATE TABLE foreign_key_child (
    id        serial      not null,
    name      varchar(70) not null,
    child_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (child_int)
);
            ",
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
            "
CREATE TABLE foreign_key_child (
    id        INTEGER PRIMARY KEY AUTOINCREMENT,
    name      varchar(70) NOT NULL,
    child_int INTEGER     NOT NULL,
    UNIQUE (child_int)
);
            ",
        ];
    }
}
