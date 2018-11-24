<?php

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

class KeyCest
{
    /**
     * Tests Phalcon\Registry :: key()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryKey(UnitTester $I)
    {
        $I->wantToTest('Registry - key()');
        $registry = new Registry();
        $registry->offsetSet('one', 1);
        $registry->offsetSet('two', 2);
        $registry->offsetSet('three', 3);

        $expected = 'one';
        $actual   = $registry->key();
        $I->assertEquals($expected, $actual);

        $registry->next();
        $expected = 'two';
        $actual   = $registry->key();
        $I->assertEquals($expected, $actual);
    }
}
