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

namespace Phalcon\Test\Integration\Db\Profiler;

use IntegrationTester;

class GetTotalElapsedSecondsCest
{
    /**
     * Tests Phalcon\Db\Profiler :: getTotalElapsedSeconds()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbProfilerGetTotalElapsedSeconds(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler - getTotalElapsedSeconds()');
        $I->skipTest('Need implementation');
    }
}
