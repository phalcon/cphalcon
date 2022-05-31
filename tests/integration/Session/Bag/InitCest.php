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

use function uniqid;

/**
 * Class InitCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class InitCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: init()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagInit(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - init()');

        $store = $_SESSION ?? [];

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');

        $name = uniqid();
        $_SESSION[$name] = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag($this->container->get("session"), $name);

        $expected = 2;
        $actual   = $collection->count();
        $I->assertEquals($expected, $actual);

        $collection->init($data);
        $actual = $collection->toArray();
        $I->assertEquals($data, $actual);

        $_SESSION = $store;
    }
}
