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

namespace Phalcon\Test\Database\Db\Adapter\Pdo;

use DatabaseTester;
use Phalcon\Db\Enum;
use Phalcon\Db\Result\Pdo;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;

use function is_array;
use function is_object;

class QueryCest
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-22
     *
     * @group mysql
     * @group sqlite
     */
    public function dbAdapterPdoQuery(DatabaseTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - query()');

        $connection = $I->getConnection();
        $db = $this->container->get('db');

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

        $I->assertTrue(is_object($result));
        $I->assertInstanceOf(Pdo::class, $result);

        $row = $result->fetch();
        $I->assertEquals(1, $row['inv_id']);
        $row = $result->fetch();
        $I->assertEquals(2, $row['inv_id']);
        $row = $result->fetch();
        $I->assertEquals(3, $row['inv_id']);

        $row = $result->fetch();
        $I->assertFalse($row);
        $I->assertEquals(3, $result->numRows());

        // Number count
        $number = 0;
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');

        $I->assertTrue(is_object($result));
        $I->assertInstanceOf(Pdo::class, $result);

        while ($row = $result->fetch()) {
            $number++;
        }
        $I->assertEquals(5, $number);

        // FETCH_NUM
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_NUM);
        $row = $result->fetch();

        $I->assertTrue(is_array($row));
        $I->assertEquals(1, $row[0]);

        // FETCH_ASSOC
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_ASSOC);
        $row = $result->fetch();

        $I->assertTrue(is_array($row));
        $I->assertEquals(1, $row['inv_id']);

        // FETCH_OBJ
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_OBJ);
        $row = $result->fetch();

        $I->assertTrue(is_object($row));
        $I->assertEquals(1, $row->inv_id);

        // FETCH_BOTH
        $result = $db->query('SELECT * FROM co_invoices LIMIT 5');
        $result->setFetchMode(Enum::FETCH_BOTH);
        $row = $result->fetch();

        $I->assertTrue(is_array($row));
        $I->assertEquals(1, $row[0]);
        $I->assertEquals(1, $row['inv_id']);

        // FETCH_COLUMN
        $result = $db->fetchAll(
            'SELECT inv_id FROM co_invoices LIMIT 5',
            Enum::FETCH_COLUMN
        );

        $I->assertTrue(is_array($result));

        $expected = ['1', '2', '3', '4', '5'];
        $I->assertEquals($expected, $result);
    }
}
