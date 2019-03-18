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

/**
 * Class InitCest
 */
class InitCest
{
    /**
     * Tests Phalcon\Registry :: init()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function collectionInit(UnitTester $I)
    {
        $I->wantToTest('Registry - init()');
        $data = [
            'one'   => 'two',
            'three' => 'four',
            'five'  => 'six',
        ];

        $registry = new Registry();

        $expected = 0;
        $actual   = $registry->count();
        $I->assertEquals($expected, $actual);

        $registry->init($data);
        $expected = $data;
        $actual   = $registry->toArray();
        $I->assertEquals($expected, $actual);
    }
}
