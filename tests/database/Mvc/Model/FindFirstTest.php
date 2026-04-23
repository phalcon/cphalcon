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
use Phalcon\Db\RawValue;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Model\Row;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\StringPrimaryMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesExtended;
use Phalcon\Tests\Support\Models\InvoicesMap;
use Phalcon\Tests\Support\Models\ModelWithStringPrimary;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

/**
 *
 * @group phql
 */
final class FindFirstTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return array
     */
    public static function findFirstProvider(): array
    {
        return [
            [
                "uuid = '5741bfd7-6870-40b7-adf6-cbacb515b9a9'",
                true,
            ],
            [
                "uuid = '1c53079c-249e-0c63-af8d-52413bfa2a2b'",
                true,
            ],
            [
                "uuid = '1c53079c-249e-0c63-af8d-52413bfa2a2c'",
                false,
            ],
            [
                '134',
                false,
            ],
            [
                "uuid = '134'",
                false,
            ],
        ];
    }

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
     */
    public function testMvcModelFindFirst(): void
    {
        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = Invoices::findFirst();

        $class  = Invoices::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $this->assertEquals($expected, $actual);

        $invoice = Invoices::findFirst(null);

        $class  = Invoices::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindFirstByNotFound(): void
    {
        $actual = Invoices::findFirstByInvTitle('unknown');
        $this->assertNull($actual);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/15356
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-11-22
     *
     * @group mysql
     */
    public function testMvcModelFindFirstColumn(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4);

        $invoice = Invoices::findFirst(
            [
                'columns' => 'inv_id',
            ]
        );

        $class  = Row::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $this->assertEquals($expected, $actual);

        $expected = ['inv_id' => 4];
        $actual   = $invoice->toArray();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindFirstColumnMap(): void
    {
        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = InvoicesMap::findFirst();

        $class  = InvoicesMap::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $invoice);

        $expected = 4;
        $actual   = $invoice->id;
        $this->assertEquals($expected, $actual);

        $expected = $title;
        $actual   = $invoice->title;
        $this->assertEquals($expected, $actual);

        $invoice = InvoicesMap::findFirst(null);

        $class  = InvoicesMap::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->id;
        $this->assertEquals($expected, $actual);

        $expected = $title;
        $actual   = $invoice->title;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindFirstException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Parameters passed must be of type array, string, numeric or null in '"
            . Invoices::class . "'"
        );

        Invoices::findFirst(false);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindFirstExtended(): void
    {
        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = InvoicesExtended::findFirst(4);

        $class  = InvoicesExtended::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $actual);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $this->assertEquals($expected, $actual);

        $invoice = InvoicesExtended::findFirst(0);
        $this->assertNull($invoice);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-02-05
     *
     * @group mysql
     */
    public function testMvcModelFindFirstExtendedColumn(): void
    {
        $title = uniqid('inv-');
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 0, $title);

        $invoice = InvoicesExtended::findFirst(
            [
                'columns' => 'inv_title',
            ]
        );

        $class  = Row::class;
        $actual = $invoice;
        $this->assertInstanceOf($class, $actual);

        $expected = $title;
        $actual   = $invoice->inv_title;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2022-06-14
     *
     * @group mysql
     */
    public function testMvcModelFindFirstFoundNotFoundGetRelated(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $invoicesMigration  = new InvoicesMigration($connection);
        $customersMigration->insert(
            1,
            1,
            uniqid('cust-', true),
            uniqid('cust-', true)
        );
        $invoicesMigration->insert(
            1,
            1,
            1,
            uniqid('inv-', true),
            100
        );
        $invoicesMigration->insert(
            2,
            2,
            1,
            uniqid('inv-', true),
            100
        );

        // Find record
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 1,
                ],
            ]
        );

        $this->assertNotNull($invoice);
        $this->assertInstanceOf(Invoices::class, $invoice);

        // Not found
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 4,
                ],
            ]
        );

        $this->assertNull($invoice);

        // Relationship found
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 1,
                ],
            ]
        );

        $customer = $invoice->getRelated('customer');

        $this->assertNotNull($customer);
        $this->assertInstanceOf(Customers::class, $customer);

        // Relationship not found
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 2,
                ],
            ]
        );

        $customer = $invoice->getRelated('customer');

        $this->assertNull($customer);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindFirstNotFound(): void
    {
        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_id < 0',
            ]
        );

        $this->assertNull($invoice);
    }

    /**
     * @dataProvider findFirstProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-27
     *
     * @group mysql
     */
    public function testMvcModelFindFirstStringPrimaryKey(
        array | string $params,
        bool $found
    ): void {
        $connection = self::getConnection();
        $migration  = new StringPrimaryMigration($connection);
        $migration->insert(
            '5741bfd7-6870-40b7-adf6-cbacb515b9a9',
            1
        );
        $migration->insert(
            '1c53079c-249e-0c63-af8d-52413bfa2a2b',
            2
        );

        $model = ModelWithStringPrimary::findFirst($params);

        $this->assertSame($found, $model instanceof Model);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16350
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group mysql
     */
    public function testMvcModelFindFirstWithRawValueBind(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(4, null, 1, 'test-raw-value', 100, '2000-01-01 00:00:00');

        $invoice = Invoices::findFirst(
            [
                'conditions' => 'inv_created_at <= :date: AND inv_status_flag = :status:',
                'bind'       => [
                    'date'   => new RawValue('NOW()'),
                    'status' => 1,
                ],
            ]
        );

        $this->assertNotNull($invoice);
        $this->assertInstanceOf(Invoices::class, $invoice);

        $expected = 4;
        $actual   = $invoice->inv_id;
        $this->assertEquals($expected, $actual);
    }
}
