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

namespace Phalcon\Test\Integration\Session\Adapter\Noop;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;

class GcCest
{
    use DiTrait;
    use SessionTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Noop :: gc()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterNoopGc(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Noop - gc()');

        $adapter = $this->getSessionNoop();

        $I->assertTrue(
            $adapter->gc(1)
        );
    }
}
