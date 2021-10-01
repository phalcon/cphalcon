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

class GetKeysCest
{
    /**
     * Tests Phalcon\Support\Collection :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionGetKeys(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - getKeys()');

        $keys = [
            'one',
            'three',
            'five',
        ];

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $expected = $keys;
        $actual   = $collection->getKeys();
        $I->assertEquals($expected, $actual);

        $data = [
            'one'   => 'two',
            'Three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);
        $expected   = $keys;
        $actual     = $collection->getKeys();
        $I->assertEquals($expected, $actual);

        $expected = array_keys($data);
        $actual   = $collection->getKeys(false);
        $I->assertEquals($expected, $actual);
    }
}
