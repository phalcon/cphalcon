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

final class UpdateAsDictTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: updateAsDict()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoUpdateAsDict(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 100);
        $migration->insert(2, 1, 1, 'title 2', 200);
        $migration->insert(3, 1, 1, 'title 3', 300);

        $success = $db->updateAsDict(
            'co_invoices',
            [
                'inv_title'       => 'updated dict',
                'inv_status_flag' => 7,
            ],
            'inv_id = 2'
        );
        $this->assertTrue($success);
        $this->assertSame(1, $db->affectedRows());

        $row = $db->fetchOne(
            'SELECT inv_title, inv_status_flag FROM co_invoices WHERE inv_id = ?',
            Enum::FETCH_ASSOC,
            [2]
        );
        $this->assertSame('updated dict', $row['inv_title']);
        $this->assertSame(7, (int) $row['inv_status_flag']);
    }
}
