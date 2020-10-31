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

namespace Phalcon\Test\Unit\Collection\ReadOnly;

use Phalcon\Collection\ReadOnly;
use UnitTester;

class GetIteratorCest
{
    /**
     * Tests Phalcon\Collection\ReadOnly :: getIterator()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionGetIterator(UnitTester $I)
    {
        $I->wantToTest('ReadOnly - getIterator()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnly($data);

        foreach ($collection as $key => $value) {
            $I->assertEquals(
                $data[$key],
                $collection[$key]
            );
        }
    }
}
