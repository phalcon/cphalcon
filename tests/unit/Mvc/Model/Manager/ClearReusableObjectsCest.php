<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Manager;

use UnitTester;

class ClearReusableObjectsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: clearReusableObjects()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelManagerClearReusableObjects(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Manager - clearReusableObjects()");
        $I->skipTest("Need implementation");
    }
}
