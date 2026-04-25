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

    /**
     * @param int              $id
     * @param string|null      $time
     * @param string|null      $dateTime
     * @param string|null      $timeStamp
     */
    public function insert(
        ?int $id,
        ?string $time = null,
        ?string $dateTime = null,
        ?string $timeStamp = null
    ): int {
        $sql    = <<<SQL
insert into fractal_dates (id, ftime, fdatetime, ftimestamp)
values (:id, :time, :dateTime, :timeStamp)
SQL;
        $params = [
            ':id'        => $id,
            ':time'      => $time,
            ':dateTime'  => $dateTime,
            ':timeStamp' => $timeStamp,
        ];

        $result = $this->execute($sql, $params);

        if ($id !== null) {
            $this->advanceSequence('id', $id);
        }

        return $result;
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
        return [
            "
drop table if exists fractal_dates;
            ",
            "
CREATE TABLE fractal_dates (
    id           serial       constraint fractal_dates_pk primary key,
    ftime        TIME(2),
    fdatetime    TIMESTAMP(2),
    ftimestamp   TIMESTAMP(2)
);
            ",
        ];
    }

    protected function getSqlSqlsrv(): array
    {
        return [];
    }
}
