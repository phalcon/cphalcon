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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Postgresql;

use Phalcon\Db\Enum;
use Phalcon\Db\Result\PdoResult;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function is_array;
use function is_object;

final class QueryTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoPostgresqlQuery(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 1.0);
        $migration->insert(2, 1, 1, 'title 2', 2.0);
        $migration->insert(3, 1, 1, 'title 3', 3.0);
        $migration->insert(4, 1, 1, 'title 4', 4.0);
        $migration->insert(5, 1, 1, 'title 5', 5.0);

        // Simple Select
        $result = $db->query('SELECT * FROM co_invoices LIMIT 3');
        $this->assertTrue(is_object($result));
        $this->assertInstanceOf(PdoResult::class, $result);

        $row = $result->fetch();
        $this->assertEquals(1, $row['inv_id']);
        $row = $result->fetch();
        $this->assertEquals(2, $row['inv_id']);
        $row = $result->fetch();
        $this->assertEquals(3, $row['inv_id']);

        $row = $result->fetch();
        $this->assertFalse($row);
        $this->assertEquals(3, $result->numRows());

        // Number count
        $number = 0;
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $this->assertTrue(is_object($result));

        while ($result->fetch()) {
            $number++;
        }
        $this->assertEquals(5, $number);

        // FETCH_NUM
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_NUM);
        $row = $result->fetch();
        $this->assertTrue(is_array($row));
        $this->assertCount(6, $row);
        $this->assertTrue(isset($row[0]));
        $this->assertFalse(isset($row['inv_id']));

        // FETCH_ASSOC
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_ASSOC);
        $row = $result->fetch();
        $this->assertTrue(is_array($row));
        $this->assertCount(6, $row);
        $this->assertFalse(isset($row[0]));
        $this->assertTrue(isset($row['inv_id']));

        // FETCH_OBJ
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_OBJ);
        $row = $result->fetch();
        $this->assertTrue(is_object($row));
        $this->assertTrue(isset($row->inv_id));

        // FETCH_BOTH with dataSeek
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_BOTH);
        $result->dataSeek(4);
        $result->fetch();
        $row = $result->fetch();
        $this->assertEquals(false, $row);
    }
}
