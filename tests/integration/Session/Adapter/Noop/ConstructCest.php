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
use SessionHandlerInterface;

class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Adapter\Noop :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterNoopConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Noop - __construct()');

        $adapter = $this->newService('sessionNoop');

        $I->assertInstanceOf(
            SessionHandlerInterface::class,
            $adapter
        );
    }
}
