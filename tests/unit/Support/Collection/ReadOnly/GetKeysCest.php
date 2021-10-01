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

namespace Phalcon\Tests\Unit\Support\Collection\ReadOnly;

use Phalcon\Support\Collection\ReadOnly;
use UnitTester;

class GetKeysCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnly :: get()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionReadOnlyGetKeys(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnly - getKeys()');

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

        $collection = new ReadOnly($data);

        $expected = $keys;
        $actual   = $collection->getKeys();
        $I->assertEquals($expected, $actual);

        $data = [
            'one'   => 'two',
            'Three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnly($data);
        $expected   = $keys;
        $actual     = $collection->getKeys();
        $I->assertEquals($expected, $actual);

        $expected = array_keys($data);
        $actual   = $collection->getKeys(false);
        $I->assertEquals($expected, $actual);
    }
}
