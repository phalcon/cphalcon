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

class ForeignKeyParentMigration extends AbstractMigration
{
    protected $table = 'foreign_key_parent';

    public function insert(): int
    {
        return 0;
    }

    protected function getSqlMysql(): array
    {
        return [];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlPgsql(): array
    {
        return [
            "
DROP TABLE IF EXISTS foreign_key_child;
            ",
            "
DROP TABLE IF EXISTS foreign_key_parent;
            ",
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
CREATE TABLE foreign_key_child (
    id        serial      not null,
    name      varchar(70) not null,
    child_int integer     not null,
    PRIMARY KEY (id),
    UNIQUE (child_int)
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

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
