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

namespace Phalcon\Test\Unit\Collection\Collection;

use Phalcon\Collection\Collection;
use UnitTester;

class InitCest
{
    /**
     * Tests Phalcon\Collection :: init()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionInit(UnitTester $I)
    {
        $I->wantToTest('Collection - init()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new Collection();

        $I->assertEquals(
            0,
            $collection->count()
        );

        $collection->init($data);

        $I->assertEquals(
            $data,
            $collection->toArray()
        );
    }
}
