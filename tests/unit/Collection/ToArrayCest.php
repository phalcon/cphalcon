<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Collection;

use Phalcon\Collection;
use UnitTester;

/**
 * Class ToArrayCest
 */
class ToArrayCest
{
    /**
     * Tests Phalcon\Collection :: toArray()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionToArray(UnitTester $I)
    {
        $I->wantToTest('Collection - toArray()');
        $data       = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];
        $collection = new Collection($data);

        $expected = $data;
        $actual   = $collection->toArray();
        $I->assertEquals($expected, $actual);
    }
}
