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

final class DescribeIndexesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeIndexes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoDescribeIndexes(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $indexes = $db->describeIndexes('co_invoices');
        $this->assertNotEmpty($indexes);

        $byName = [];
        foreach ($indexes as $idx) {
            $byName[$idx->getName()] = $idx;
        }

        $this->assertArrayHasKey('co_invoices_inv_cst_id_index', $byName);
        $this->assertArrayHasKey('co_invoices_inv_status_flag_index', $byName);
        $this->assertArrayHasKey('co_invoices_inv_created_at_index', $byName);

        $this->assertSame(
            ['inv_cst_id'],
            $byName['co_invoices_inv_cst_id_index']->getColumns()
        );
        $this->assertSame(
            ['inv_status_flag'],
            $byName['co_invoices_inv_status_flag_index']->getColumns()
        );
        $this->assertSame(
            ['inv_created_at'],
            $byName['co_invoices_inv_created_at_index']->getColumns()
        );
    }
}
