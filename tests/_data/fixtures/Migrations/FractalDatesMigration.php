<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Fixtures\Migrations;

/**
 * Class FractalDatesMigration
 */
class FractalDatesMigration extends AbstractMigration
{
    protected $table = "fractal_dates";

    /**
     * @param int              $id
     * @param string|null      $time
     * @param string|null      $dateTime
     * @param string|null      $timeStamp
     */
    public function insert(
        int $id,
        string $time = null,
        string $dateTime = null,
        string $timeStamp = null
    ) {
        if (0 === $id) {
            $id = null;
        }
        $sql = <<<SQL
insert into fractal_dates (id, ftime, fdatetime, ftimestamp)
values ({$id}, "{$time}", "{$dateTime}", "{$timeStamp}");
SQL;

        $this->connection->exec($sql);
    }

    protected function getSqlMysql(): array
    {
        return [
            "
drop table if exists `fractal_dates`;
            ",
            "
create table fractal_dates
(
    `id`           int(10)      auto_increment primary key,
    `ftime`        time(2)      null,
    `fdatetime`    datetime(2)  null,
    `ftimestamp`   timestamp(2) null
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
