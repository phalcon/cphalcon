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

namespace Phalcon\Test\Database\Db\Column;

use DatabaseTester;
use Phalcon\Test\Fixtures\Migrations\FractalDatesMigration;
use Phalcon\Test\Fixtures\Traits\DbTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\FractalDates;

class GetScaleCest
{
    use DbTrait;
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Db\Column :: getScale()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbColumnGetScale(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column - getScale()");
        $I->skipTest('Temporary disabled');

        // $columns         = $this->getColumnsArray();
        // $expectedColumns = $this->getColumnsObjects();

        // foreach ($expectedColumns as $index => $column) {
        //     $I->assertEquals(
        //         $columns[$index]['scale'] ?? null,
        //         $column->getScale()
        //     );
        // }
    }

    /**
     * Tests Phalcon\Db\Column :: getScale() - datetime, time, timestamp
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-23
     */
    public function dbColumnGetScaleDateTimeTimeTimeStamp(DatabaseTester $I)
    {
        $I->wantToTest("Db\Column - getScale() - datetime, time, timestamp");

        $driver = $I->getDriver();

        if ('mysql' === $driver) {
            /**
             * @todo this is for MySql
             */
            $connection = $I->getConnection();
            $migration  = new FractalDatesMigration($connection);
            $migration->clear();
            $migration->insert(
                1,
                '14:15:16.444',
                '2019-12-25 17:18:19.666',
                '2019-12-25 20:21:22.888'
            );

            $record = FractalDates::findFirst('id = 1');

            $I->assertEquals(1, $record->id);
            $I->assertEquals('14:15:16.44', $record->ftime);
            $I->assertEquals('2019-12-25 17:18:19.67', $record->fdatetime);
            $I->assertEquals('2019-12-25 20:21:22.89', $record->ftimestamp);
        }
    }
}
