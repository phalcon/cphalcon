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
 * Class OnlyIdentityMigration
 *
 * Table that has only an auto-increment primary key column.
 */
class OnlyIdentityMigration extends AbstractSchema
{
    protected string $table = 'co_only_identity';

    protected function getStatementsMysql(): array
    {
        return [
            "
create table co_only_identity
(
    `oid_id` int(10) auto_increment primary key
);
            ",
        ];
    }

    protected function getStatementsPgsql(): array
    {
        return [
            "
create table co_only_identity
(
    oid_id serial not null constraint co_only_identity_pk primary key
);
            ",
        ];
    }

    protected function getStatementsSqlite(): array
    {
        return [
            "
create table co_only_identity
(
    oid_id integer constraint co_only_identity_pk primary key autoincrement
);
            ",
        ];
    }
}
