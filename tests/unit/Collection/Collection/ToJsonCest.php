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

class ToJsonCest
{
    /**
     * Tests Phalcon\Collection :: toJson()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionToJson(UnitTester $I)
    {
        $I->wantToTest('Collection - toJson()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection($data);

        $I->assertEquals(
            json_encode($data),
            $collection->toJson()
        );

        $I->assertEquals(
            json_encode($data, JSON_PRETTY_PRINT),
            $collection->toJson(JSON_PRETTY_PRINT)
        );
    }
}
