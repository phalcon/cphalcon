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

class SetNameCest
{
    /**
     * Tests Phalcon\Session\Adapter\Files :: setName()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesSetName(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Files - setName()");
        $I->skipTest("Need implementation");
    }
}
