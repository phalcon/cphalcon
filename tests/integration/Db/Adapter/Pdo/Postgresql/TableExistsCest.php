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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class TableExistsCest
 */
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

        $table = 'dialect_table';
        $I->assertTrue($this->connection->tableExists($table));
        $I->assertFalse($this->connection->tableExists('unknown-table'));
        $I->assertTrue($this->connection->tableExists($table, $this->getSchemaName()));
        $I->assertFalse($this->connection->tableExists('unknown-table', 'unknown-db'));
    }
}
