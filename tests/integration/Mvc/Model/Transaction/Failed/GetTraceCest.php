<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Transaction\Failed;

use IntegrationTester;

class GetTraceCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Failed :: getTrace()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelTransactionFailedGetTrace(IntegrationTester $I)
    {
        $I->wantToTest("Mvc\Model\Transaction\Failed - getTrace()");
        $I->skipTest("Need implementation");
    }
}
