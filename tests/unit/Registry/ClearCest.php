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

namespace Phalcon\Test\Unit\Registry;

use Phalcon\Registry;
use UnitTester;

class ClearCest
{
    /**
     * Tests Phalcon\Registry :: clear()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionClear(UnitTester $I)
    {
        $I->wantToTest('Registry - clear()');

        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry($data);

        $I->assertEquals(
            $data,
            $registry->toArray()
        );

        $registry->clear();

        $I->assertEquals(
            0,
            $registry->count()
        );
    }
}
