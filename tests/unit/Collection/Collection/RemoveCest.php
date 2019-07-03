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

namespace Phalcon\Test\Unit\Collection\Collection;

use Phalcon\Collection\Collection;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Collection\Collection :: remove()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionRemove(UnitTester $I)
    {
        $I->wantToTest('Collection\Collection - remove()');
        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new Collection($data);

        $expected = $data;
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);

        $collection->remove('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);

        $collection->remove('FIVE');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);

        $collection->init($data);
        unset($collection['five']);
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);

        $collection->init($data);
        $collection->__unset('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);

        $collection->init($data);
        $collection->offsetUnset('five');
        $expected = [
            'one'   => 'two',
            'three' => 'four',
        ];
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);
    }
}
