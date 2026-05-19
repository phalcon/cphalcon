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

use PDO;
use Phalcon\Db\Enum;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

final class InsertTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: insert()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoInsert(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $success = $db->insert(
            'co_invoices',
            [1, 4, 'Insert test', 250.75],
            ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total'],
            [PDO::PARAM_INT, PDO::PARAM_INT, PDO::PARAM_STR, PDO::PARAM_STR]
        );
        $this->assertTrue($success);

        $row = $db->fetchOne(
            'SELECT inv_cst_id, inv_status_flag, inv_title, inv_total '
            . 'FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['Insert test']
        );

        $this->assertNotEmpty($row);
        $this->assertSame(1, (int) $row['inv_cst_id']);
        $this->assertSame(4, (int) $row['inv_status_flag']);
        $this->assertSame('Insert test', $row['inv_title']);
        $this->assertSame(250.75, (float) $row['inv_total']);
    }
}
