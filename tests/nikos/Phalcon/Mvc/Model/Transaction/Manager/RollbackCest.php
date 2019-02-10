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

namespace Phalcon\Test\Unit\Mvc\Model\Transaction\Manager;

use UnitTester;

/**
 * Class RollbackCest
 */
class RollbackCest
{
    /**
     * Tests Phalcon\Mvc\Model\Transaction\Manager :: rollback()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function mvcModelTransactionManagerRollback(UnitTester $I)
    {
        $I->wantToTest('Mvc\Model\Transaction\Manager - rollback()');
        $I->skipTest('Need implementation');
    }
}
