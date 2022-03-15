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
 * Class ClearCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class ClearCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: clear()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagClear(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - clear()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag($this->container->get("session"), 'BagTest');

        $collection->init($data);

        $actual = $collection->toArray();
        $I->assertEquals($data, $actual);

        $collection->clear();

        $actual = $collection->count();
        $I->assertEquals(0, $actual);
    }
}
