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

use Phalcon\Db\Enum;
use Phalcon\Db\Result\PdoResult;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

use function is_array;
use function is_object;

final class QueryTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: query()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-22
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoQuery(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);
        $migration->insert(2, 1, 1, 'title 2', 102);
        $migration->insert(3, 1, 1, 'title 3', 103);
        $migration->insert(4, 1, 1, 'title 4', 104);
        $migration->insert(5, 1, 1, 'title 5', 105);
        $migration->insert(6, 1, 1, 'title 6', 106);
        $migration->insert(7, 1, 1, 'title 7', 107);
        $migration->insert(8, 1, 1, 'title 8', 108);
        $migration->insert(9, 1, 1, 'title 9', 109);
        $migration->insert(10, 1, 1, 'title 10', 110);

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
        $this->assertInstanceOf(PdoResult::class, $result);

        while ($result->fetch()) {
            $number++;
        }
        $this->assertEquals(5, $number);

        // FETCH_NUM
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_NUM);
        $row = $result->fetch();

        $this->assertTrue(is_array($row));
        $this->assertEquals(1, $row[0]);

        // FETCH_ASSOC
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_ASSOC);
        $row = $result->fetch();

        $this->assertTrue(is_array($row));
        $this->assertEquals(1, $row['inv_id']);

        // FETCH_OBJ
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_OBJ);
        $row = $result->fetch();

        $this->assertTrue(is_object($row));
        $this->assertEquals(1, $row->inv_id);

        // FETCH_BOTH
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_BOTH);
        $row = $result->fetch();

        $this->assertTrue(is_array($row));
        $this->assertEquals(1, $row[0]);
        $this->assertEquals(1, $row['inv_id']);

        // FETCH_COLUMN
        $result = $db->fetchAll(
            'SELECT inv_id FROM co_invoices LIMIT 5',
            Enum::FETCH_COLUMN
        );

        $this->assertTrue(is_array($result));

        $expected = ['1', '2', '3', '4', '5'];
        $this->assertEquals($expected, $result);
    }
}
