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

class RewindCest
{
    /**
     * Tests Phalcon\Registry :: rewind()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function testRewind(UnitTester $I)
    {
        $registry = new Registry();
        $registry->offsetSet('one', 1);
        $registry->offsetSet('two', 2);
        $registry->offsetSet('three', 3);

        $registry->next();
        $registry->next();

        $expected = 3;
        $actual  = $registry->current();
        $I->assertEquals($expected, $actual);

        $registry->rewind();

        $expected = 1;
        $actual  = $registry->current();
        $I->assertEquals($expected, $actual);
    }
}
