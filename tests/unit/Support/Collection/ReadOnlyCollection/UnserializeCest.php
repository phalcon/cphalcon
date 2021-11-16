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

namespace Phalcon\Tests\Unit\Support\Collection\ReadOnlyCollection;

use Phalcon\Support\Collection\ReadOnlyCollection;
use UnitTester;

class UnserializeCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnlyCollection :: serialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionSerialize(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnlyCollection - serialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $serialized = serialize($data);
        $collection = new ReadOnlyCollection();

        $collection->unserialize($serialized);

        $expected = $data;
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);
    }
}
