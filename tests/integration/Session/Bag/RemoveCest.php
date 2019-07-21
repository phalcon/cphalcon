<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Session\Bag;

use IntegrationTester;
use Phalcon\Session\Bag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Fixtures\Traits\SessionBagTrait;

class RemoveCest
{
    use DiTrait;
    use SessionBagTrait;

    /**
     * Tests Phalcon\Session\Bag :: remove()
     *
     * @author Phalcon Team <team@phalconphp.com>
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
