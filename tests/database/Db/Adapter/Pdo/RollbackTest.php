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

final class RollbackTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: rollback()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoRollback(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $this->assertTrue($db->begin());
        $this->assertTrue(
            $db->insertAsDict(
                'co_invoices',
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => 'rollback test',
                    'inv_total'       => 1.0,
                ]
            )
        );
        $this->assertTrue($db->rollback());
        $this->assertFalse($db->isUnderTransaction());

        $row = $db->fetchOne(
            'SELECT inv_title FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['rollback test']
        );
        $this->assertEmpty($row);
    }
}
