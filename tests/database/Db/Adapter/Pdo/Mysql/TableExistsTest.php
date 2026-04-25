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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Mysql;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function env;

final class TableExistsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: tableExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlTableExists(): void
    {
        $db    = $this->container->get('db');
        $table = 'co_invoices';

        $this->assertTrue(
            $db->tableExists($table)
        );

        $this->assertFalse(
            $db->tableExists('unknown-table')
        );

        $this->assertTrue(
            $db->tableExists($table, env('DATA_MYSQL_NAME'))
        );

        $this->assertFalse(
            $db->tableExists('unknown-table', 'unknown-db')
        );
    }
}
