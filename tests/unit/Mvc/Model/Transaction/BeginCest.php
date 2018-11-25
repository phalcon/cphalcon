<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Mvc\Model\Transaction;

use UnitTester;

class BeginCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction :: begin()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelTransactionBegin(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Transaction - begin()");
        $I->skipTest("Need implementation");
    }
}
