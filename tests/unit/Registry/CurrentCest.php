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
 * Class CurrentCest
 *
 * @package Phalcon\Test\Unit\Registry
 */
class CurrentCest
{
    /**
     * Tests Phalcon\Registry :: current()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function registryCurrent(UnitTester $I)
    {
        $I->wantToTest('Registry - current()');
        $registry = new Registry();
        $registry->offsetSet('one', 1);
        $registry->offsetSet('two', 2);
        $registry->offsetSet('three', 3);

        $expected = 1;
        $actual   = $registry->current();
        $I->assertEquals($expected, $actual);

        $registry->next();
        $expected = 2;
        $actual   = $registry->current();
        $I->assertEquals($expected, $actual);
    }
}
