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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class QueryTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionQuery(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $result = $migration->insert(1);
        $this->assertEquals(1, $result);

        $all = $connection
            ->query('select * from co_invoices WHERE inv_id = 1')
            ->fetch()
        ;

        $this->assertIsArray($all);
        $this->assertEquals(1, $all['inv_id']);
        $this->assertArrayHasKey('inv_id', $all);
        $this->assertArrayHasKey('inv_cst_id', $all);
        $this->assertArrayHasKey('inv_status_flag', $all);
        $this->assertArrayHasKey('inv_title', $all);
        $this->assertArrayHasKey('inv_total', $all);
        $this->assertArrayHasKey('inv_created_at', $all);
    }
}
