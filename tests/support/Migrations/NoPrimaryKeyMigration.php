<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Support\Migrations;

use Phalcon\Talon\Database\Schema\AbstractSchema;

/**
 * Class NoPrimaryKeyMigration
 */
class NoPrimaryKeyMigration extends AbstractSchema
{
    protected string $table = "no_primary_key";

    protected function getStatementsMysql(): array
    {
        return [
            "
create table no_primary_key
(
    `nokey_id`   int(10) unsigned,
    `nokey_name` varchar(100) not null
);
            ",
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
            "
create table no_primary_key
(
    nokey_id   integer,
    nokey_name text not null
);
            ",
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
create table no_primary_key
(
    nokey_id   integer,
    nokey_name varchar(100) not null
);
            ",
        ];
    }
}