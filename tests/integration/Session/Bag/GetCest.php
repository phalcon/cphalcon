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
 * Class GetCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class GetCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: get()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagGet(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - get()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new Bag($this->container->get("session"), 'BagTest');
        $collection->init($data);

        $expected = 'four';
        $actual   = $collection->get('three');
        $I->assertEquals($expected, $actual);

        $actual = $collection->get('THREE');
        $I->assertEquals($expected, $actual);

        $actual = $collection['three'];
        $I->assertEquals($expected, $actual);

        $actual = $collection->three;
        $I->assertEquals($expected, $actual);

        $actual = $collection->offsetGet('three');
        $I->assertEquals($expected, $actual);
    }
}
