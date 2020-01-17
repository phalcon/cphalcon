<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Migrations;

class FractalDatesMigration extends AbstractMigration
{
    protected $table = "fractal_dates";

    public function create()
    {
        $this->drop();

        $sql = <<<SQL
create table fractal_dates
(
    id         int(10) auto_increment primary key,
    ftime      time(2) null,
    fdatetime  datetime(2) null,
    ftimestamp timestamp(2) null
);
SQL;
        $this->connection->execute($sql);

        $this->insert(
            1,
            '14:15:16.444',
            '2019-12-25 17:18:19.666',
            '2019-12-25 20:21:22.888'
        );
    }

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

        $this->connection->execute($sql);
    }
}
