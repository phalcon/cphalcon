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
use Phalcon\Tests\Fixtures\Traits\SessionBagTrait;

class RemoveCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDiService('sessionStream');
    }

    /**
     * Tests Phalcon\Session\Bag :: remove()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function sessionBagRemove(IntegrationTester $I)
    {
        $I->wantToTest('Session\Bag - remove()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Bag('BagTest');

        $collection->init($data);

        $I->assertEquals(
            $data,
            $collection->toArray()
        );


        $collection->remove('five');

        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $I->assertEquals(
            $expected,
            $collection->toArray()
        );


        $collection->remove('FIVE');

        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $I->assertEquals(
            $expected,
            $collection->toArray()
        );


        $collection->init($data);

        unset($collection['five']);

        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $I->assertEquals(
            $expected,
            $collection->toArray()
        );


        $collection->init($data);

        $collection->offsetUnset('five');

        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];

        $I->assertEquals(
            $expected,
            $collection->toArray()
        );
    }
}
