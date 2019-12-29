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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresqlTableExists(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - tableExists()");

        $table = 'dialect_table';

        $I->assertTrue(
            $this->connection->tableExists($table)
        );

        $I->assertFalse(
            $this->connection->tableExists('unknown-table')
        );

        $I->assertTrue(
            $this->connection->tableExists(
                $table,
                $this->getSchemaName()
            )
        );

        $I->assertFalse(
            $this->connection->tableExists('unknown-table', 'unknown-db')
        );
    }
}
