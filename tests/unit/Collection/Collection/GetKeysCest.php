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

namespace Phalcon\Test\Unit\Collection\Collection;

use Phalcon\Collection;
use UnitTester;

class GetKeysCest
{
    /**
     * Tests Phalcon\Collection :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionGetKeys(UnitTester $I)
    {
        $I->wantToTest('Collection - getKeys()');

        $data = [
            'one'   => 'two',
            'Three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $expected = [
            'one',
            'Three',
            'five',
        ];

        $I->assertEquals(
            $expected,
            $collection->getKeys(false)
        );


        $expected = [
            'one',
            'three',
            'five',
        ];

        $I->assertEquals(
            $expected,
            $collection->getKeys()
        );
    }
}
