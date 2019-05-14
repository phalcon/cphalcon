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

namespace Phalcon\Test\Integration\Mvc\Model\Transaction;

use IntegrationTester;

/**
 * Class SetRollbackOnAbortCest
 */
class SetRollbackOnAbortCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction :: setRollbackOnAbort()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function mvcModelTransactionSetRollbackOnAbort(IntegrationTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction - setRollbackOnAbort()');
        $I->skipTest('Need implementation');
    }
}
