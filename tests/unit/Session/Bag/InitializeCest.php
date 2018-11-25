<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Session\Bag;

use UnitTester;

class InitializeCest
{
    /**
     * Tests Phalcon\Session\Bag :: initialize()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionBagInitialize(UnitTester $I)
    {
        $I->wantToTest("Session\Bag - initialize()");
        $I->skipTest("Need implementation");
    }
}
