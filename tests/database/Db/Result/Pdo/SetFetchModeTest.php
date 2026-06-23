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
final class SetFetchModeTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Result\Pdo :: setFetchMode()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbResultPdoSetFetchMode(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);

        $db = $this->container->get('db');

        $result = $db->query('SELECT * FROM co_invoices ORDER BY inv_id');
        $this->assertTrue($result->setFetchMode(Enum::FETCH_NUM));

        $row = $result->fetch();
        $this->assertIsArray($row);
        $this->assertEquals(1, $row[0]);

        $result = $db->query('SELECT * FROM co_invoices ORDER BY inv_id');
        $this->assertTrue($result->setFetchMode(Enum::FETCH_ASSOC));

        $row = $result->fetch();
        $this->assertIsArray($row);
        $this->assertEquals(1, $row['inv_id']);
    }
}
