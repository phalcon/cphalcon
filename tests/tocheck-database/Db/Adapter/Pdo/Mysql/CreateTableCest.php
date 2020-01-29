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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;

/**
 * Class CreateTableCest
 */
class CreateTableCest
{
    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: createTable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlCreateTable(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - createTable()');
        $I->skipTest('Need implementation');
    }
}
