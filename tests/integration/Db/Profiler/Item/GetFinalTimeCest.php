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

namespace Phalcon\Test\Integration\Db\Profiler\Item;

use IntegrationTester;

/**
 * Class GetFinalTimeCest
 */
class GetFinalTimeCest
{
    /**
     * Tests Phalcon\Db\Profiler\Item :: getFinalTime()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbProfilerItemGetFinalTime(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler\Item - getFinalTime()');
        $I->skipTest('Need implementation');
    }
}
