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
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\InvoicesSkipCreate;
use Phalcon\Tests\Support\Models\InvoicesSkipDynamic;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function date;
use function str_starts_with;
use function uniqid;

final class SkipAttributesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    private array $statements = [];

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection));

        $this->statements = [];
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
    }

    /**
     * Tests that an attribute registered with skipAttributes() is not part of
     * the generated INSERT statement.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17382
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSkipAttributesOmitsAttributeFromInsert(): void
    {
        $connection = $this->recordStatements();

        $invoice                  = new InvoicesSkipCreate();
        $invoice->inv_cst_id      = 2;
        $invoice->inv_status_flag = 1;
        $invoice->inv_title       = uniqid('inv-');
        $invoice->inv_total       = 100.12;
        $invoice->inv_created_at  = date('Y-m-d H:i:s');

        $this->assertTrue($invoice->create());

        /**
         * The skipped attribute must not be part of the INSERT
         */
        $actual = $this->getStatement('INSERT');
        $this->assertStringNotContainsString('inv_created_at', $actual);

        /**
         * The value assigned to the model must never reach the database
         */
        $actual = $connection->fetchOne(
            'select inv_created_at from co_invoices where inv_id = ' . $invoice->inv_id
        );
        $this->assertNull($actual['inv_created_at']);
    }

    /**
     * Tests that an attribute registered with skipAttributes() is not part of
     * the generated UPDATE statement when dynamic update is enabled.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17382
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSkipAttributesOmitsAttributeFromDynamicUpdate(): void
    {
        $date = '2026-07-20 10:00:00';

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection))->insert(4, 1, 1, 'inv-title', 100.12, $date);

        $connection = $this->recordStatements();

        /** @var InvoicesSkipDynamic $invoice */
        $invoice                 = InvoicesSkipDynamic::findFirst(
            [
                'conditions' => 'inv_id = :id:',
                'bind'       => ['id' => 4],
            ]
        );
        $invoice->inv_title      = uniqid('inv-');
        $invoice->inv_created_at = '2026-07-20 11:00:00';

        $this->assertTrue($invoice->save());

        /**
         * The skipped attribute must not be part of the UPDATE
         */
        $actual = $this->getStatement('UPDATE');
        $this->assertStringNotContainsString('inv_created_at', $actual);

        /**
         * The value assigned to the model must never reach the database
         */
        $actual = $connection->fetchOne(
            'select inv_created_at from co_invoices where inv_id = 4'
        );
        $this->assertStringStartsWith('2026-07-20 10:00:00', $actual['inv_created_at']);
    }

    /**
     * Tests that an attribute registered with skipAttributes() is not part of
     * the generated UPDATE statement.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17382
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-07-20
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSkipAttributesOmitsAttributeFromUpdate(): void
    {
        $date = '2026-07-20 10:00:00';

        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        (new InvoicesMigration($connection))->insert(3, 1, 1, 'inv-title', 100.12, $date);

        $connection = $this->recordStatements();

        /** @var InvoicesSkipCreate $invoice */
        $invoice                 = InvoicesSkipCreate::findFirst(
            [
                'conditions' => 'inv_id = :id:',
                'bind'       => ['id' => 3],
            ]
        );
        $invoice->inv_title      = uniqid('inv-');
        $invoice->inv_created_at = '2026-07-20 11:00:00';

        $this->assertTrue($invoice->save());

        /**
         * The skipped attribute must not be part of the UPDATE
         */
        $actual = $this->getStatement('UPDATE');
        $this->assertStringNotContainsString('inv_created_at', $actual);

        /**
         * The value assigned to the model must never reach the database
         */
        $actual = $connection->fetchOne(
            'select inv_created_at from co_invoices where inv_id = 3'
        );
        $this->assertStringStartsWith('2026-07-20 10:00:00', $actual['inv_created_at']);
    }

    /**
     * Returns the first recorded statement starting with the given prefix
     */
    private function getStatement(string $prefix): string
    {
        foreach ($this->statements as $statement) {
            if (str_starts_with($statement, $prefix)) {
                return $statement;
            }
        }

        return '';
    }

    /**
     * Attaches a listener to the connection recording every statement sent
     * to the database
     */
    private function recordStatements()
    {
        $connection = $this->container->get('db');
        $manager    = new Manager();

        $manager->attach(
            'db:beforeQuery',
            function (Event $event) use ($connection) {
                $this->statements[] = $connection->getSQLStatement();
            }
        );

        $connection->setEventsManager($manager);

        return $connection;
    }
}
