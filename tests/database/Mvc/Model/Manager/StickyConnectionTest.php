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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use PDO;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\InvoicesReadWrite;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function date;
use function uniqid;

/**
 * The read/write split relies on two separate connections observing the same
 * committed data, so these end-to-end tests run against the server databases
 * only (mirroring Query\ForUpdateConnectionTest).
 */
#[Group('mysql')]
#[Group('pgsql')]
final class StickyConnectionTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $this->container->setShared('dbRead', $this->newDbService());
        $this->container->setShared('dbWrite', $this->newDbService());

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * Tests that with sticky disabled (the default) a read after a write still
     * uses the read connection.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17256
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcModelManagerStickyDisabledKeepsReadOnReadConnection(): void
    {
        $invoice                  = new InvoicesReadWrite();
        $invoice->inv_cst_id      = 1;
        $invoice->inv_status_flag = 0;
        $invoice->inv_title       = uniqid('inv-', true);
        $invoice->inv_total       = 100.0;
        $invoice->inv_created_at  = date('Y-m-d H:i:s');

        $this->assertTrue($invoice->save());

        InvoicesReadWrite::find();

        /**
         * Sticky is off, so the SELECT is executed on the read connection.
         */
        $readSql = $this->container->getShared('dbRead')->getRealSQLStatement();

        $this->assertStringContainsStringIgnoringCase('SELECT', $readSql);
        $this->assertStringContainsString('co_invoices', $readSql);
    }

    /**
     * Tests that a read issued after a write during the same request cycle is
     * served from the write connection when sticky is enabled.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17256
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-04
     */
    public function testMvcModelManagerStickyRoutesReadToWriteAfterWrite(): void
    {
        /** @var Manager $manager */
        $manager = $this->container->getShared('modelsManager');
        $manager->setSticky(true);

        $invoice                  = new InvoicesReadWrite();
        $invoice->inv_cst_id      = 1;
        $invoice->inv_status_flag = 0;
        $invoice->inv_title       = uniqid('inv-', true);
        $invoice->inv_total       = 100.0;
        $invoice->inv_created_at  = date('Y-m-d H:i:s');

        $this->assertTrue($invoice->save());

        InvoicesReadWrite::find();

        /**
         * With sticky active, the SELECT is executed on the write connection.
         */
        $writeSql = $this->container->getShared('dbWrite')->getRealSQLStatement();

        $this->assertStringContainsStringIgnoringCase('SELECT', $writeSql);
        $this->assertStringContainsString('co_invoices', $writeSql);
    }
}
