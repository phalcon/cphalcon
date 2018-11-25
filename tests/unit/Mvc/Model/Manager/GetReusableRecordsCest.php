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

class GetReusableRecordsCest
{
    /**
     * Tests Phalcon\Mvc\Model\Manager :: getReusableRecords()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelManagerGetReusableRecords(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Manager - getReusableRecords()");
        $I->skipTest("Need implementation");
    }
}
