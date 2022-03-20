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
 * Class RemoveCest
 *
 * @package Phalcon\Tests\Integration\Session\Bag
 */
class RemoveCest
{
    use DiTrait;

    /**
     * Tests Phalcon\Session\Bag :: remove()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function sessionBagRemove(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - remove()');

        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag($this->container->get("session"), 'BagTest');

        $collection->init($data);
        $I->assertEquals($data, $collection->toArray());

        $collection->remove('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $I->assertEquals($expected, $collection->toArray());

        $collection->remove('FIVE');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $I->assertEquals($expected, $collection->toArray());

        $collection->init($data);

        unset($collection['five']);

        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $I->assertEquals($expected, $collection->toArray());

        $collection->init($data);
        $collection->offsetUnset('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $I->assertEquals($expected, $collection->toArray());
    }
}
