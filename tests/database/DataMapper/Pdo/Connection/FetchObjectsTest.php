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
use Phalcon\Tests\Support\Resultset;
use PHPUnit\Framework\Attributes\Group;
use stdClass;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class FetchObjectsTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testConnectionFetchObjectsCtor(): void
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

        $all = $connection->fetchObjects(
            'SELECT * from co_invoices',
            [],
            Resultset::class,
            [
                'darth',
            ]
        );
        $this->assertCount(4, $all);

        $this->assertInstanceOf(Resultset::class, $all[0]);
        $this->assertInstanceOf(Resultset::class, $all[1]);
        $this->assertInstanceOf(Resultset::class, $all[2]);
        $this->assertInstanceOf(Resultset::class, $all[3]);

        $this->assertEquals(1, $all[0]->inv_id);
        $this->assertEquals(2, $all[1]->inv_id);
        $this->assertEquals(3, $all[2]->inv_id);
        $this->assertEquals(4, $all[3]->inv_id);

        $this->assertEquals('darth', $all[0]->calculated);
        $this->assertEquals('darth', $all[1]->calculated);
        $this->assertEquals('darth', $all[2]->calculated);
        $this->assertEquals('darth', $all[3]->calculated);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionFetchObjects(): void
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

        $all = $connection->fetchObjects(
            'SELECT * from co_invoices'
        );
        $this->assertCount(4, $all);

        $this->assertInstanceOf(stdClass::class, $all[0]);
        $this->assertInstanceOf(stdClass::class, $all[1]);
        $this->assertInstanceOf(stdClass::class, $all[2]);
        $this->assertInstanceOf(stdClass::class, $all[3]);

        $this->assertEquals(1, $all[0]->inv_id);
        $this->assertEquals(2, $all[1]->inv_id);
        $this->assertEquals(3, $all[2]->inv_id);
        $this->assertEquals(4, $all[3]->inv_id);
    }
}
