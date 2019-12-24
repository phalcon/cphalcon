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

use Phalcon\Db\Adapter\AdapterInterface;

class FractalDatesMigration
{
    public function __invoke(AdapterInterface $db)
    {
        $sql = <<<SQL
drop table if exists fractal_dates
SQL;
        $db->execute($sql);

        $sql = <<<SQL
create table fractal_dates
(
    id         int(10) auto_increment primary key,
    ftime      time(2) null,
    fdatetime  datetime(2) null,
    ftimestamp timestamp(2) null
);
SQL;
        $db->execute($sql);

        $this->insert(
            $db,
            1,
            '14:15:16.444',
            '2019-12-25 17:18:19.666',
            '2019-12-25 20:21:22.888'
        );
    }

    /**
     * @param AdapterInterface $db
     * @param int              $id
     * @param string|null      $time
     * @param string|null      $dateTime
     * @param string|null      $timeStamp
     */
    public function insert(
        AdapterInterface $db,
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

        $db->execute($sql);
    }
}
