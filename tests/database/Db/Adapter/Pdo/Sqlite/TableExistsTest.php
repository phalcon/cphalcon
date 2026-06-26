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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Sqlite;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

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
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: tableExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('sqlite')]
    public function testDbAdapterPdoSqliteTableExists(): void
    {
        $db = $this->container->get('db');

        $this->assertTrue($db->tableExists('co_invoices'));
        $this->assertFalse($db->tableExists('noexist'));
        $this->assertTrue($db->tableExists('co_invoices', 'public'));
        $this->assertTrue($db->tableExists('co_invoices', 'test'));
    }
}
