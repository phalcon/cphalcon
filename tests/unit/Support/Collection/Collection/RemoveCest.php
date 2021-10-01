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

namespace Phalcon\Tests\Unit\Support\Collection\Collection;

use Phalcon\Support\Collection;
use UnitTester;

class RemoveCest
{
    /**
     * Tests Phalcon\Support\Collection :: remove()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionRemove(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - remove()');
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
