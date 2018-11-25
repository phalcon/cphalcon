<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

class GetSQLBindTypesCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: getSQLBindTypes()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteGetSQLBindTypes(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Sqlite - getSQLBindTypes()");
        $I->skipTest("Need implementation");
    }
}
