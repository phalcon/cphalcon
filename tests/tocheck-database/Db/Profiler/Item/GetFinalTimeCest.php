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

class GetFinalTimeCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getFinalTime()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbProfilerItemGetFinalTime(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getFinalTime()');
        $I->skipTest('Need implementation');
    }
}
