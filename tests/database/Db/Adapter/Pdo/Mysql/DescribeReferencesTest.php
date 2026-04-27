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

use Phalcon\Db\Reference;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class DescribeReferencesTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlDescribeReferences(): void
    {
        $this->markTestSkipped(
            'Need implementation - dialect_table_intermediate not in current schema'
        );
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeReferences() - count
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlDescribeReferencesCount(): void
    {
        $this->markTestSkipped(
            'Need implementation - dialect_table_intermediate not in current schema'
        );
    }

    /**
     * Tests Mysql::describeReferences - columns count
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoMysqlDescribeReferencesColumnsCount(): void
    {
        $this->markTestSkipped(
            'Need implementation - robots_parts table not in current schema'
        );
    }

    /**
     * @return array<string, Reference>
     */
    private function getExpectedReferences(): array
    {
        return [];
    }
}
