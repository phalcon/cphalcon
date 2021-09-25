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

namespace Phalcon\Tests\Unit\Collection\Collection;

use Phalcon\Collection;
use UnitTester;

class GetKeysCest
{
    /**
     * Tests Phalcon\Collection :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-12-12
     */
    public function collectionCollectionGetKeys(UnitTester $I)
    {
        $I->wantToTest('Collection\Collection - getKeys()');

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

        $I->assertEquals($keys, $collection->getKeys());

        $data = [
            'one'   => 'two',
            'Three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);
        $I->assertEquals($keys, $collection->getKeys());
        $I->assertEquals(array_keys($data), $collection->getKeys(false));
    }
}
