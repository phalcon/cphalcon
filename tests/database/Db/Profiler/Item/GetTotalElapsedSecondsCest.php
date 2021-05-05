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

class GetTotalElapsedSecondsCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getTotalElapsedSeconds()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group  common
     */
    public function dbProfilerItemGetTotalElapsedSeconds(DatabaseTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getTotalElapsedSeconds()');

        $item = new Item();
        $item->setInitialTime(100.45);
        $item->setFinalTime(220.15);
        $I->assertEquals(119.7, $item->getTotalElapsedSeconds());
    }
}
