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

namespace Phalcon\Test\Integration\Db\Profiler\Item;

use IntegrationTester;

class GetInitialTimeCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getInitialTime()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbProfilerItemGetInitialTime(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getInitialTime()');
        $I->skipTest('Need implementation');
    }
}
