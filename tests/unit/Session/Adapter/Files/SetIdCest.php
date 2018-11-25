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

class SetIdCest
{
    /**
     * Tests Phalcon\Session\Adapter\Files :: setId()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function sessionAdapterFilesSetId(UnitTester $I)
    {
        $I->wantToTest("Session\Adapter\Files - setId()");
        $I->skipTest("Need implementation");
    }
}
