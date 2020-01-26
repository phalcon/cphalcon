<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\DM\Pdo\Profiler\Profiler;

use IntegrationTester;
use Phalcon\DM\Pdo\Profiler\Profiler;

class ConstructCest
{
    /**
     * Integration Tests Phalcon\DM\Pdo\Profiler\Profiler :: __construct()
     *
     * @since  2020-01-25
     */
    public function dMPdoProfilerProfilerConstruct(IntegrationTester $I)
    {
        $I->wantToTest('DM\Pdo\Profiler\Profiler - __construct()');

        $profiler = new Profiler();

        $I->assertInstanceOf(Profiler::class, $profiler);
    }
}
