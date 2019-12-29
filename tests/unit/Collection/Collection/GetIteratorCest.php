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

class GetIteratorCest
{
    /**
     * Tests Phalcon\Collection :: getIterator()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionGetIterator(UnitTester $I)
    {
        $I->wantToTest('Collection - getIterator()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        foreach ($collection as $key => $value) {
            $I->assertEquals(
                $data[$key],
                $collection[$key]
            );
        }
    }
}
