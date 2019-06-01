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

namespace Phalcon\Test\Unit\Collection\ReadCollection;

use Phalcon\Collection\ReadCollection;
use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Collection :: get()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionGet(UnitTester $I)
    {
        $I->wantToTest('Collection - get()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadCollection($data);

        $expected = 'four';

        $I->assertEquals(
            $expected,
            $collection->get('three')
        );

        $I->assertEquals(
            $expected,
            $collection->get('THREE')
        );

        $I->assertEquals(
            $expected,
            $collection->get('unknown', 'four')
        );

        $I->assertEquals(
            $expected,
            $collection['three']
        );

        $I->assertEquals(
            $expected,
            $collection->three
        );

        $I->assertEquals(
            $expected,
            $collection->offsetGet('three')
        );
    }
}
