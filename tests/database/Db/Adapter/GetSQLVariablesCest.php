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

namespace Phalcon\Tests\Database\Db\Adapter;

use DatabaseTester;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Enum;
use Phalcon\Db\Result\Pdo;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

use function is_array;
use function is_object;

class GetSQLVariablesCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: query()
     *
     * @issue
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-31
     *
     * @group  pgsql
     * @group  mysql
     * @group  sqlite
     */
    public function dbAdapterGetSqlVariablesInit(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter - getSQLVariables() - init');

        $db = $this->container->get('db');

        $actual = $db->getSQLVariables();
        $I->assertIsArray($actual);
        $I->assertEmpty($actual);
    }
}
