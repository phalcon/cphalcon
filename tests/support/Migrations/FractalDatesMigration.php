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

/**
 * Class FractalDatesMigration
 */
class FractalDatesMigration extends AbstractMigration
{
    protected $table = "fractal_dates";

    public function insert(
        ?int $id,
        ?string $time = null,
        ?string $dateTime = null,
        ?string $timeStamp = null,
    ) {
        $sql = <<<SQL
insert into fractal_dates (
    id, ftime, fdatetime, ftimestamp
) values (
    :id, :time, :dateTime, :timeStamp
);
SQL;

        $params = [
            ':id'        => $id ?? null,
            ':time'      => $time,
            ':dateTime'  => $dateTime ?? null,
            ':timeStamp' => $timeStamp ?? null,
        ];

        return $this->execute($sql, $params);
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

    protected function getSqlPgsql(): array
    {
        return [
            "
DROP TABLE IF EXISTS fractal_dates;
            ",
            "
CREATE TABLE fractal_dates (
    id           INTEGER GENERATED ALWAYS AS IDENTITY PRIMARY KEY,
    ftime        TIME(2),
    fdatetime    TIMESTAMP(2),
    ftimestamp   TIMESTAMP(2)
);
",
        ];
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
