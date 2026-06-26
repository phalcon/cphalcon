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
final class FetchColumnTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionFetchCol(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $result = $migration->insert(1, 1, 1, null, 101);
        $this->assertEquals(1, $result);
        $result = $migration->insert(2, 1, 1, null, 102);
        $this->assertEquals(1, $result);
        $result = $migration->insert(3, 1, 1, null, 103);
        $this->assertEquals(1, $result);

        $all = $connection->fetchColumn(
            'select * from co_invoices'
        );

        $this->assertIsArray($all);
        $this->assertEquals(1, $all[0]);
        $this->assertEquals(2, $all[1]);
        $this->assertEquals(3, $all[2]);

        $all = $connection->fetchColumn(
            'select * from co_invoices',
            [],
            4
        );

        /**
         * Intentionally casting things as an array because I don't want
         * drivers to fail based on how many decimals they can hold
         */
        $this->assertIsArray($all);
        $this->assertEquals(101, (int) $all[0]);
        $this->assertEquals(102, (int) $all[1]);
        $this->assertEquals(103, (int) $all[2]);
    }
}
