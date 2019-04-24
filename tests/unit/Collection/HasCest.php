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

/**
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Collection :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionHas(UnitTester $I)
    {
        $I->wantToTest('Collection - has()');
        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new Collection($data);

        $actual = $collection->has('three');
        $I->assertTrue($actual);

        $actual = $collection->has('THREE');
        $I->assertTrue($actual);

        $actual = $collection->has('THREE', false);
        $I->assertFalse($actual);

        $actual = $collection->has('unknown');
        $I->assertFalse($actual);

        $actual = $collection->__isset('three');
        $I->assertTrue($actual);

        $actual = isset($collection['three']);
        $I->assertTrue($actual);

        $actual = isset($collection['unknown']);
        $I->assertFalse($actual);

        $actual = $collection->offsetExists('three');
        $I->assertTrue($actual);

        $actual = $collection->offsetExists('unknown');
        $I->assertFalse($actual);
    }
}
