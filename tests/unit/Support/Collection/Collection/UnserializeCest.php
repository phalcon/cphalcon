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

class UnserializeCest
{
    /**
     * Tests Phalcon\Support\Collection :: unserialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionUnserialize(UnitTester $I)
    {
        $I->wantToTest('Support\Collection - unserialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $serialized = serialize($data);
        $collection = new Collection();

        $collection->unserialize($serialized);

        $expected = $data;
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);
    }
}
