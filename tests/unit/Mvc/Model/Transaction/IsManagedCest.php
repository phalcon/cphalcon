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

class IsManagedCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction :: isManaged()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelTransactionIsManaged(UnitTester $I)
    {
        $I->wantToTest("Mvc\Model\Transaction - isManaged()");
        $I->skipTest("Need implementation");
    }
}
