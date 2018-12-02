<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class TableExistsCest
{
    use DiTrait;
    use PostgresqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: tableExists()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresqlTableExists(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - tableExists()");

        $actual = $this->connection->tableExists('personas');
        $I->assertTrue($actual);
        $actual = $this->connection->tableExists('personas', env('DATA_POSTGRES_SCHEMA'));
        $I->assertTrue($actual);
        $actual = $this->connection->tableExists('noexist');
        $I->assertFalse($actual);
        $actual = $this->connection->tableExists('noexist', env('DATA_POSTGRES_SCHEMA'));
        $I->assertFalse($actual);
        $actual = $this->connection->tableExists('personas', 'test');
        $I->assertFalse($actual);
    }
}
