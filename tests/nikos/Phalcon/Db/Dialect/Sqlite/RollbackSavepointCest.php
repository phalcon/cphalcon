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

namespace Phalcon\Test\Unit\Db\Dialect\Sqlite;

use UnitTester;

/**
 * Class RollbackSavepointCest
 */
class RollbackSavepointCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: rollbackSavepoint()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function dbDialectSqliteRollbackSavepoint(UnitTester $I)
    {
        $I->wantToTest('Db\Dialect\Sqlite - rollbackSavepoint()');
        $I->skipTest('Need implementation');
    }
}
