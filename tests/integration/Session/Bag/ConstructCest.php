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

namespace Phalcon\Tests\Integration\Session\Bag;

use IntegrationTester;
use Phalcon\Session\Bag;
use Phalcon\Session\Exception;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class ConstructCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests Phalcon\Session\Bag :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionBagConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - __construct()');

        $this->setDiService('sessionStream');
        $collection = new Bag('BagTest', $this->container);

        $class = Bag::class;
        $I->assertInstanceOf($class, $collection);
    }

    /**
     * Tests Phalcon\Session\Bag :: __construct() - exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-02
     */
    public function sessionBagConstructException(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - __construct() - exception');

        $I->expectThrowable(
            new Exception(
                "A dependency injection container is required to access the 'session' service"
            ),
            function () {
                $collection = new Bag('BagTest');
            }
        );

        $container = $this->container;

        $I->expectThrowable(
            new Exception(
                "A dependency injection container is required to access the 'session' service"
            ),
            function () use ($container) {
                $collection = new Bag('BagTest', $container);
            }
        );
    }
}
