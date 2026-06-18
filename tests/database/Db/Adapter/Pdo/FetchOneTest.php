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

final class FetchOneTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: fetchOne()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoFetchOne(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 100);
        $migration->insert(2, 1, 1, 'title 2', 200);
        $migration->insert(3, 1, 1, 'title 3', 300);

        $row = $db->fetchOne(
            'SELECT inv_id, inv_title FROM co_invoices WHERE inv_id = ?',
            Enum::FETCH_ASSOC,
            [2]
        );
        $this->assertNotEmpty($row);
        $this->assertSame(2, (int) $row['inv_id']);
        $this->assertSame('title 2', $row['inv_title']);

        $rowNum = $db->fetchOne(
            'SELECT inv_id, inv_title FROM co_invoices WHERE inv_id = ?',
            Enum::FETCH_NUM,
            [3]
        );
        $this->assertNotEmpty($rowNum);
        $this->assertSame(3, (int) $rowNum[0]);
        $this->assertSame('title 3', $rowNum[1]);

        $empty = $db->fetchOne(
            'SELECT inv_id FROM co_invoices WHERE inv_id = ?',
            Enum::FETCH_ASSOC,
            [999]
        );
        $this->assertEmpty($empty);
    }
}
