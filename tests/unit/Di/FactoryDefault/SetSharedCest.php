<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Di\FactoryDefault;

use UnitTester;

class SetSharedCest
{
    /**
     * Tests Phalcon\Di\FactoryDefault :: setShared()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diFactorydefaultSetShared(UnitTester $I)
    {
        $I->wantToTest("Di\FactoryDefault - setShared()");
        $I->skipTest("Need implementation");
    }
}
