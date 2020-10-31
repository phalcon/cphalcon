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

class InitCest
{
    /**
     * Tests Phalcon\Collection\ReadOnly :: init()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function collectionInit(UnitTester $I)
    {
        $I->wantToTest('ReadOnly - init()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $collection = new ReadOnly();

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
