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

namespace Phalcon\Test\Database\Db\Profiler\Item;

use DatabaseTester;
use Phalcon\Db\Profiler\Item;

class GetTotalElapsedNanoMicroSecondsCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getTotalElapsedNanoseconds() /
     * getTotalElapsedMicroseconds() / getTotalElapsedSeconds()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbProfilerItemGetTotalElapsedNanoMicroSeconds(DatabaseTester $I)
    {
        $I->wantToTest(
            'Db\Profiler\Item - getTotalElapsedNanoseconds() / getTotalElapsedMicroseconds() / getTotalElapsedSeconds()'
        );

        $item = new Item();
        $start = 444445555566666;
        $end   = 999999999999999;

        $item->setInitialTime($start);
        $item->setFinalTime($end);

        $expected = $end - $start;
        $actual = $item->getTotalElapsedNanoseconds();
        $I->assertEquals($expected, $actual);

        $expected = ($end - $start) / 1000000;
        $actual = $item->getTotalElapsedMilliseconds();
        $I->assertEquals($expected, $actual);

        $expected = ($end - $start) / 1000000000;
        $actual = $item->getTotalElapsedSeconds();
        $I->assertEquals($expected, $actual);
    }
}
