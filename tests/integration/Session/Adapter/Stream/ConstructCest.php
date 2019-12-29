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

namespace Phalcon\Test\Integration\Session\Adapter\Stream;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionTrait;
use SessionHandlerInterface;

class ConstructCest
{
    use DiTrait;
    use SessionTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Adapter\Stream :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionAdapterStreamConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - __construct()');
        $adapter = $this->getSessionStream();
        $class   = SessionHandlerInterface::class;
        $I->assertInstanceOf($class, $adapter);
    }
}
