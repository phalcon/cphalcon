<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Session\Adapter\Files;

use UnitTester;

class UnderscoreSetCest
{
    /**
     * Tests Phalcon\Session\Adapter\Files :: __set()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesUnderscoreSet(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Files - __set()");
        $I->skipTest("Need implementation");
    }
}
