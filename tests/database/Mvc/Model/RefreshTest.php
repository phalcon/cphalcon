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
use Phalcon\Tests\Support\Models\InvoicesWithTypedSetters;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function uniqid;

#[Group('phql')]
final class RefreshTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelRefresh(): void
    {
        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = Invoices::findFirst();
        $data    = $invoice->toArray();

        $invoice->assign(
            [
                'inv_id'          => 4,
                'inv_cst_id'      => 5,
                'inv_status_flag' => 6,
                'inv_total'       => 200.12,
            ]
        );

        $invoice->refresh();

        $this->assertEquals(
            $data,
            $invoice->toArray()
        );
    }

    /**
     * Tests that refresh() does not throw when a setter has a strict type hint
     * that is incompatible with the raw DB value. The ORM must catch the
     * TypeError and fall back to direct property assignment.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17335
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-14
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelRefreshSetterTypeErrorFallback(): void
    {
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, 'raw-string-from-db');

        /** @var InvoicesWithTypedSetters $invoice */
        $invoice = InvoicesWithTypedSetters::findFirst();

        // setInvTitle() expects ?array - the raw string causes a TypeError.
        // refresh() must NOT throw; it must fall back to direct property
        // assignment.
        $invoice->refresh();

        $this->assertSame('raw-string-from-db', $invoice->inv_title);
    }
}
