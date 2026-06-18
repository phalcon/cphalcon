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
final class FetchAllTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionFetchAll(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $result = $migration->insert(1);
        $this->assertEquals(1, $result);
        $result = $migration->insert(2);
        $this->assertEquals(1, $result);
        $result = $migration->insert(3);
        $this->assertEquals(1, $result);
        $result = $migration->insert(4);
        $this->assertEquals(1, $result);

        $all = $connection->fetchAll(
            'SELECT * from co_invoices'
        );
        $this->assertCount(4, $all);

        $this->assertEquals(1, $all[0]['inv_id']);
        $this->assertEquals(2, $all[1]['inv_id']);
        $this->assertEquals(3, $all[2]['inv_id']);
        $this->assertEquals(4, $all[3]['inv_id']);
    }
}
