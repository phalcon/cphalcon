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

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Sqlite;

use UnitTester;

/**
 * Class IsUnderTransactionCest
 */
class IsUnderTransactionCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: isUnderTransaction()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbAdapterPdoSqliteIsUnderTransaction(UnitTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - isUnderTransaction()');
        $I->skipTest('Need implementation');
    }
}
