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

class GetIteratorCest
{
    /**
     * Tests Phalcon\Support\Collection\ReadOnly :: getIterator()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportCollectionGetIterator(UnitTester $I)
    {
        $I->wantToTest('Support\Collection\ReadOnly - getIterator()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnly($data);

        foreach ($collection as $key => $value) {
            $expected = $data[$key];
            $actual   = $collection[$key];
            $I->assertEquals($expected, $actual);
        }
    }
}
