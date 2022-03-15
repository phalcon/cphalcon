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

namespace Phalcon\Tests\Integration\Session\Adapter\Noop;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GcCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Noop :: gc()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionAdapterNoopGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Noop - gc()');

        $adapter = $this->newService('sessionNoop');

        $actual = $adapter->gc(1);
        $I->assertTrue($actual);
    }
}
