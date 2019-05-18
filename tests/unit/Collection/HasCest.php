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

namespace Phalcon\Test\Unit\Collection;

use Phalcon\Collection;
use UnitTester;

class HasCest
{
    /**
     * Tests Phalcon\Collection :: has()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionHas(UnitTester $I)
    {
        $I->wantToTest('Collection - has()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $I->assertTrue(
            $collection->has('three')
        );

        $I->assertTrue(
            $collection->has('THREE')
        );

        $I->assertFalse(
            $collection->has('THREE', false)
        );

        $I->assertFalse(
            $collection->has('unknown')
        );

        $I->assertTrue(
            $collection->__isset('three')
        );

        $I->assertTrue(
            isset($collection['three'])
        );

        $I->assertFalse(
            isset($collection['unknown'])
        );

        $I->assertTrue(
            $collection->offsetExists('three')
        );

        $I->assertFalse(
            $collection->offsetExists('unknown')
        );
    }
}
