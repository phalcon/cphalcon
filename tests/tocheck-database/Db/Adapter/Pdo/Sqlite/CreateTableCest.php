<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;

/**
 * Class CreateTableCest
 */
class CreateTableCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: createTable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteCreateTable(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - createTable()');
        $I->skipTest('Need implementation');
    }
}
