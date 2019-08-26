<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Collection\Collection;

use Phalcon\Collection;
use UnitTester;

class UnserializeCest
{
    /**
     * Tests Phalcon\Collection :: unserialize()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionUnserialize(UnitTester $I)
    {
        $I->wantToTest('Collection\Collection - unserialize()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $serialized = serialize($data);

        $collection = new Collection();

        $collection->unserialize($serialized);

        $I->assertEquals(
            $data,
            $collection->toArray()
        );
    }
}
