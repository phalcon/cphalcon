<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Profiler\Item;

use UnitTester;

class SetFinalTimeCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: setFinalTime()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbProfilerItemSetFinalTime(UnitTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - setFinalTime()');

        $I->skipTest('Need implementation');
    }
}
