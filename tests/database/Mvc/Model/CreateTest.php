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

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function date;
use function uniqid;

final class CreateTest extends AbstractDatabaseTestCase
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     * @group pgsql
     */
    public function testMvcModelCreate(): void
    {
        $title                    = uniqid('inv-');
        $date                     = date('Y-m-d H:i:s');
        $invoice                  = new Invoices();
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 3;
        $invoice->inv_title       = $title;
        $invoice->inv_total       = 100.12;
        $invoice->inv_created_at  = $date;

        $result = $invoice->create();
        $this->assertNotFalse($result);
    }

    /**
     * Inserting with an explicit primary key on PostgreSQL must not throw a
     * "currval of sequence not yet defined in this session" error.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16436
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-26
     *
     * @group pgsql
     */
    public function testMvcModelCreateWithExplicitIdPgsql(): void
    {
        $date                     = date('Y-m-d H:i:s');
        $invoice                  = new Invoices();
        $invoice->inv_id          = 77;
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 1;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 50.00;
        $invoice->inv_created_at  = $date;

        $result = $invoice->create();

        $this->assertNotFalse($result);
        $this->assertSame(77, (int) $invoice->inv_id);
    }

    /**
     * After an explicit-id insert (which bypasses the sequence), a subsequent
     * auto-increment insert must still obtain the generated id without error.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16436
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-26
     *
     * @group pgsql
     */
    public function testMvcModelCreateAutoIncrementAfterExplicitIdPgsql(): void
    {
        $date = date('Y-m-d H:i:s');

        $first                    = new Invoices();
        $first->inv_id            = 77;
        $first->inv_cst_id        = 1;
        $first->inv_status_flag   = 1;
        $first->inv_title         = uniqid('inv-');
        $first->inv_total         = 10.00;
        $first->inv_created_at    = $date;

        $this->assertNotFalse($first->create());

        // Advance the sequence past the explicit id so the next
        // auto-increment insert does not collide with it.
        $connection = self::getConnection();
        $connection->exec(
            "SELECT setval(pg_get_serial_sequence('co_invoices', 'inv_id'), 77)"
        );

        $second                   = new Invoices();
        $second->inv_cst_id       = 2;
        $second->inv_status_flag  = 2;
        $second->inv_title        = uniqid('inv-');
        $second->inv_total        = 20.00;
        $second->inv_created_at   = $date;

        $this->assertNotFalse($second->create());
        $this->assertGreaterThan(77, (int) $second->inv_id);
    }
}
