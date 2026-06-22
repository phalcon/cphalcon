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

namespace Phalcon\Tests\Database\Db\Result\Pdo;

use Phalcon\Db\Enum;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class FetchArrayTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Result\Pdo :: fetchArray()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbResultPdoFetchArray(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);

        $db     = $this->container->get('db');
        $result = $db->query('SELECT * FROM co_invoices ORDER BY inv_id');
        $result->setFetchMode(Enum::FETCH_ASSOC);

        $row = $result->fetchArray();

        $this->assertIsArray($row);
        $this->assertEquals(1, $row['inv_id']);
        $this->assertEquals('title 1', $row['inv_title']);
    }
}
