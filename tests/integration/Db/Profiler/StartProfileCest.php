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

class StartProfileCest
{
    /**
     * Tests Phalcon\Db\Profiler :: startProfile()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbProfilerStartProfile(IntegrationTester $I)
    {
        $I->wantToTest('Db\Profiler - startProfile()');
        $I->skipTest('Need implementation');
    }
}
