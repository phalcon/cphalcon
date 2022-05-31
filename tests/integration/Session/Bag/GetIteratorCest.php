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
 * Class GetIteratorCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class GetIteratorCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: getIterator()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagGetIterator(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - getIterator()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag($this->container->get("session"), 'BagTest');
        $collection->init($data);

        foreach ($collection as $key => $value) {
            $I->assertEquals($data[$key], $collection[$key]);
        }
    }
}
