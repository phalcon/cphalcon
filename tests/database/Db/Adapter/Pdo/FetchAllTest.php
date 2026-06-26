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
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class FetchAllTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: fetchAll()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoFetchAll(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 100);
        $migration->insert(2, 1, 1, 'title 2', 200);
        $migration->insert(3, 1, 1, 'title 3', 300);

        $rows = $db->fetchAll(
            'SELECT inv_id, inv_title FROM co_invoices ORDER BY inv_id'
        );
        $this->assertCount(3, $rows);
        $this->assertSame('title 1', $rows[0]['inv_title']);
        $this->assertSame('title 2', $rows[1]['inv_title']);
        $this->assertSame('title 3', $rows[2]['inv_title']);

        $rowsNum = $db->fetchAll(
            'SELECT inv_id, inv_title FROM co_invoices ORDER BY inv_id',
            Enum::FETCH_NUM
        );
        $this->assertCount(3, $rowsNum);
        $this->assertSame('title 1', $rowsNum[0][1]);
        $this->assertSame('title 2', $rowsNum[1][1]);
        $this->assertSame('title 3', $rowsNum[2][1]);
    }
}
