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
use Phalcon\Di\FactoryDefault;
use Phalcon\Session\Bag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetSetDICest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Session\Bag :: getDI()/setDI()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionBagGetSetDI(IntegrationTester $I)
    {
        $I->wantToTest("Session\Bag - getDI()/setDI()");

        $container = new FactoryDefault();
        $sessionBag = new Bag('DiTest', $this->container);

        $sessionBag->setDI($container);

        $expected = $container;
        $actual   = $sessionBag->getDI();
        $I->assertEquals($expected, $actual);
    }
}
