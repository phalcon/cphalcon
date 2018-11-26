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

class GetForeignKeyChecksCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: getForeignKeyChecks()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbDialectMysqlGetForeignKeyChecks(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - getForeignKeyChecks()");
        $I->skipTest("Need implementation");
    }
}
