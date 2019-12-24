<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Db\Column;

use DatabaseTester;
use Phalcon\Db\Adapter\Pdo\Mysql as DbMysql;
use Phalcon\Db\Dialect\Mysql as DialectMysql;
use Phalcon\Test\Fixtures\Migrations\FractalDatesMigration;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\FractalDates;

class GetScaleCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Column :: getScale()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group common
     */
    public function dbColumnGetScale(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column - getScale()");

        $columns         = $this->getColumns();
        $expectedColumns = $this->getExpectedColumns();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals(
                $columns[$index]['scale'] ?? null,
                $column->getScale()
            );
        }
    }

    /**
     * Tests Phalcon\Db\Column :: getScale() - datetime, time, timestamp
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-23
     */
    public function dbColumnGetScaleDateTimeTimeTimeStamp(IntegrationTester $I)
    {
        $I->wantToTest("Db\Column - getScale() - datetime, time, timestamp");

        /**
         * @todo this is for MySql
         */
        /** @var DbMysql $db */
        $db = $this->container->get('db');
        (new FractalDatesMigration())($db);

        $record = FractalDates::findFirst('id = 1');

        $I->assertEquals(1, $record->id);
        $I->assertEquals('14:15:16.44', $record->ftime);
        $I->assertEquals('2019-12-25 17:18:19.67', $record->fdatetime);
        $I->assertEquals('2019-12-25 20:21:22.89', $record->ftimestamp);
    }
}
