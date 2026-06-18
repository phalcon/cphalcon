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
use PHPUnit\Framework\Attributes\Group;

final class LastInsertIdTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: lastInsertId()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoLastInsertId(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $success = $db->insertAsDict(
            'co_invoices',
            [
                'inv_cst_id'      => 1,
                'inv_status_flag' => 1,
                'inv_title'       => 'lastInsertId',
                'inv_total'       => 1.0,
            ]
        );
        $this->assertTrue($success);

        $this->assertGreaterThan(0, (int) $db->lastInsertId());
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: lastInsertId() with sequence name
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('pgsql')]
    public function testDbAdapterPdoLastInsertIdPostgresqlSequence(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $success = $db->insertAsDict(
            'co_invoices',
            [
                'inv_cst_id'      => 1,
                'inv_status_flag' => 1,
                'inv_title'       => 'lastInsertId pg sequence',
                'inv_total'       => 1.0,
            ]
        );
        $this->assertTrue($success);

        $this->assertGreaterThan(
            0,
            (int) $db->lastInsertId('co_invoices_inv_id_seq')
        );
    }
}
