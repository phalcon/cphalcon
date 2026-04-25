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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

use function env;

final class DbDescribeMysqlTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Db :: Mysql - tableExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     */
    public function testDbMySqlTableExists(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->tableExists('co_invoices'));
        $this->assertFalse($db->tableExists('noexist'));
        $this->assertTrue($db->tableExists('co_invoices', env('DATA_MYSQL_NAME')));
        $this->assertFalse($db->tableExists('co_invoices', 'test'));
    }

    /**
     * Tests Phalcon\Db :: Mysql - describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbMySqlDescribeColumns(): void
    {
        /**
         * @TODO - Check this after refactoring
         */
        $this->markTestSkipped('Need implementation - expected columns data not yet defined');
    }

    /**
     * Tests Phalcon\Db :: Mysql - tableOptions()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbMySqlTableOptions(): void
    {
        $this->markTestSkipped('Need implementation - personas table not in current schema');
    }

    /**
     * Tests Phalcon\Db :: Mysql - describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbMySqlDescribeIndexes(): void
    {
        $this->markTestSkipped('Need implementation - robots_parts and issue_11036 tables not in current schema');
    }

    /**
     * Tests Phalcon\Db :: Mysql - describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbMySqlDescribeReferences(): void
    {
        $this->markTestSkipped('Need implementation - robots_parts table not in current schema');
    }
}
