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
use Phalcon\Tests\Support\Migrations\InvoicesCustomersFkMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class DescribeReferencesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private ?InvoicesCustomersFkMigration $migration = null;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->migration = new InvoicesCustomersFkMigration(
            self::getConnection(),
            false
        );
        $this->migration->create();
    }

    public function tearDown(): void
    {
        if ($this->migration !== null) {
            $this->migration->drop();
            $this->migration = null;
        }
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoDescribeReferences(): void
    {
        $db         = $this->container->get('db');
        $references = $db->describeReferences('co_invoices_fk');

        $this->assertNotEmpty($references);

        $found = false;
        foreach ($references as $ref) {
            if ($ref->getReferencedTable() !== 'co_customers_fk') {
                continue;
            }

            $this->assertSame(['inv_cst_id'], $ref->getColumns());
            $this->assertSame(['cst_id'], $ref->getReferencedColumns());
            $found = true;
        }

        $this->assertTrue(
            $found,
            'No reference from co_invoices_fk → co_customers_fk was reported'
        );
    }
}
