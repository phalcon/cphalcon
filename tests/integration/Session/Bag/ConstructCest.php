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
use Phalcon\Tests\Fixtures\Traits\DiTrait;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class ConstructCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: __construct()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - __construct()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $collection = new Bag($this->container->get("session"), 'BagTest');

        $class = Bag::class;
        $I->assertInstanceOf($class, $collection);
    }
}
