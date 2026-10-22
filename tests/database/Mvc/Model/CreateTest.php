<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model;

use PDO;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

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
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));
    }

    /**
     * @return array<string, array{0: int|string}>
     */
    public static function zeroIdentityProvider(): array
    {
        return [
            'int'    => [0],
            'string' => ['0'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
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
     * Calling create() on a record that already exists must return false with
     * an `InvalidCreateAttempt` message and must not raise a deprecation
     * warning when constructing the message.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17224
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-25
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelCreateAlreadyExists(): void
    {
        $date                     = date('Y-m-d H:i:s');
        $invoice                  = new Invoices();
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 3;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 100.12;
        $invoice->inv_created_at  = $date;

        $this->assertNotFalse($invoice->create());

        $deprecations = [];
        set_error_handler(
            static function (int $errno, string $errstr) use (&$deprecations): bool {
                $deprecations[] = $errstr;

                return true;
            },
            E_DEPRECATED
        );

        $result = $invoice->create();

        restore_error_handler();

        $this->assertFalse($result);
        $this->assertEmpty($deprecations);

        $messages = $invoice->getMessages();
        $this->assertCount(1, $messages);

        $expected = 'Record cannot be created because it already exists';
        $this->assertSame($expected, $messages[0]->getMessage());
        $this->assertSame('', $messages[0]->getField());
        $this->assertSame('InvalidCreateAttempt', $messages[0]->getType());
    }

    /**
     * After an explicit-id insert (which bypasses the sequence), a subsequent
     * auto-increment insert must still obtain the generated id without error.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16436
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-26
     */
    #[Group('pgsql')]
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
        $connection = self::getPdoConnection();
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

    /**
     * An explicit identity value is kept as set on the model (same value and
     * type) on MySQL and SQLite.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17689
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-22
     */
    #[Group('mysql')]
    #[Group('sqlite')]
    public function testMvcModelCreateWithExplicitIdMysqlSqlite(): void
    {
        $invoice                  = new Invoices();
        $invoice->inv_id          = 77;
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 1;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 50.00;
        $invoice->inv_created_at  = date('Y-m-d H:i:s');

        $this->assertNotFalse($invoice->create());
        $this->assertSame(77, $invoice->inv_id);
    }

    /**
     * Inserting with an explicit primary key on PostgreSQL must not throw a
     * "currval of sequence not yet defined in this session" error.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16436
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-26
     */
    #[Group('pgsql')]
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
     * On MySQL, an identity left at 0 is replaced by a generated id; the
     * model must read it back with lastInsertId() instead of keeping 0.
     * Assumes the default sql_mode (no NO_AUTO_VALUE_ON_ZERO).
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17689
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-10-22
     */
    #[DataProvider('zeroIdentityProvider')]
    #[Group('mysql')]
    public function testMvcModelCreateWithZeroIdentityMysql(int | string $zero): void
    {
        $invoice                  = new Invoices();
        $invoice->inv_id          = $zero;
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 1;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 50.00;
        $invoice->inv_created_at  = date('Y-m-d H:i:s');

        $this->assertNotFalse($invoice->create());

        $stored = Invoices::findFirst();

        $this->assertNotNull($stored);
        $this->assertGreaterThan(0, (int) $stored->inv_id);
        $this->assertEquals($stored->inv_id, $invoice->inv_id);
    }
}
