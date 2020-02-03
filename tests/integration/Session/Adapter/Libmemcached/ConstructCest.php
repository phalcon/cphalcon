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

namespace Phalcon\Test\Integration\Session\Adapter\Libmemcached;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use SessionHandlerInterface;

class ConstructCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Libmemcached :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterLibmemcachedConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Libmemcached - __construct()');

        $adapter = $this->newService('sessionLibmemcached');

        $I->assertInstanceOf(
            SessionHandlerInterface::class,
            $adapter
        );
    }
}
