<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Transaction\Failed;

use UnitTester;

class GetPreviousCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Failed :: getPrevious()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelTransactionFailedGetPrevious(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Transaction\Failed - getPrevious()");
        $I->skipTest("Need implementation");
    }
}
