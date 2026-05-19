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
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

final class FetchColumnTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: fetchColumn()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoFetchColumn(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 100);
        $migration->insert(2, 1, 1, 'title 2', 200);
        $migration->insert(3, 1, 1, 'title 3', 300);

        $this->assertEquals(
            3,
            $db->fetchColumn('SELECT COUNT(*) FROM co_invoices')
        );

        $this->assertEquals(
            'title 2',
            $db->fetchColumn(
                'SELECT inv_title FROM co_invoices WHERE inv_id = ?',
                [2]
            )
        );

        $this->assertEquals(
            'title 2',
            $db->fetchColumn(
                'SELECT inv_id, inv_title FROM co_invoices WHERE inv_id = ?',
                [2],
                'inv_title'
            )
        );

        $this->assertEquals(
            'title 2',
            $db->fetchColumn(
                'SELECT inv_id, inv_title FROM co_invoices WHERE inv_id = ?',
                [2],
                1
            )
        );
    }
}
