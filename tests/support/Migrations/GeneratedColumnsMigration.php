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

/**
 * Class GeneratedColumnsMigration
 *
 * MySQL only. A stored generated column rejects any explicitly supplied value
 * (error 3105) but accepts the `DEFAULT` keyword.
 */
class GeneratedColumnsMigration extends AbstractMigration
{
    protected $table = 'co_generated';

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `co_generated`;
            ",
            "
create table co_generated
(
    `gen_id`       int(10) auto_increment primary key,
    `gen_url`      varchar(255) not null,
    `gen_url_hash` binary(16) generated always as (unhex(md5(gen_url))) stored
);
            ",
        ];
    }

    protected function getSqlPgsql(): array
    {
        return [];
    }

    protected function getSqlSqlite(): array
    {
        return [];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
