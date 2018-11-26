<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;

class DropTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: dropTable()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectMysqlDropTable(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - dropTable()");
        $I->skipTest("Need implementation");
    }
}
