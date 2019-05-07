<?php
declare(strict_types=1);

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

class GetTraceAsStringCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Failed :: getTraceAsString()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function mvcModelTransactionFailedGetTraceAsString(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Failed - getTraceAsString()');

        $I->skipTest('Need implementation');
    }
}
