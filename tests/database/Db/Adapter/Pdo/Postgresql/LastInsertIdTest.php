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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Postgresql;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;
use function uniqid;

final class LastInsertIdTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: lastInsertId()
     * returns the sequence value after a sequence-using insert.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-26
     *
     * @group pgsql
     */
    public function testDbAdapterPdoPostgresqlLastInsertId(): void
    {
        $db = $this->container->get('db');

        $db->insert(
            'co_invoices',
            [2, 1, uniqid('inv-'), 50.00, date('Y-m-d H:i:s')],
            ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total', 'inv_created_at']
        );

        $lastId = $db->lastInsertId('co_invoices_inv_id_seq');

        $this->assertNotFalse($lastId);
        $this->assertGreaterThan(0, (int) $lastId);
    }
}
