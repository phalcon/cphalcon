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
 * Owns `foreign_key_parent` only - `foreign_key_child` is
 * ForeignKeyChildMigration, which sorts first so its table is dropped and
 * created before this one runs.
 *
 * The pgsql FK constraint is added here rather than by the child, because it
 * needs both tables to exist and this class is the later of the two.
 */
class ForeignKeyParentMigration extends AbstractSchema
{
    protected string $table = 'foreign_key_parent';

    /**
     * @return list<string>
     */
    public function getDependencies(): array
    {
        return ['foreign_key_child'];
    }

    public function insert(): int
    {
        return 0;
    }

    protected function getStatementsMysql(): array
    {
        return [
            "
CREATE TABLE `foreign_key_parent` (
    `id`        int(10) NOT NULL AUTO_INCREMENT,
    `name`      varchar(70) NOT NULL,
    `refer_int` int NOT NULL,
    PRIMARY KEY (`id`),
    UNIQUE KEY `foreign_key_parent_refer_int` (`refer_int`)
) ENGINE=InnoDB;
            ",
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
CREATE TABLE foreign_key_parent (
    id        serial      not null,
    name      varchar(70) not null,
    refer_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (refer_int)
);
            ",
            "
ALTER TABLE foreign_key_child
    ADD CONSTRAINT test_describereferences
    FOREIGN KEY (child_int)
    REFERENCES foreign_key_parent (refer_int)
    ON UPDATE CASCADE ON DELETE RESTRICT;
            ",
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
            "
CREATE TABLE foreign_key_parent (
    id        INTEGER PRIMARY KEY AUTOINCREMENT,
    name      varchar(70) NOT NULL,
    refer_int INTEGER     NOT NULL,
    UNIQUE (refer_int)
);
            ",
        ];
    }
}
