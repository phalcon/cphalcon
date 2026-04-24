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
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersDefaultsMigration;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\SourcesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\CustomersDefaults;
use Phalcon\Tests\Support\Models\CustomersKeepSnapshots;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesHasOneNotReusable;
use Phalcon\Tests\Support\Models\InvoicesKeepSnapshots;
use Phalcon\Tests\Support\Models\InvoicesSchema;
use Phalcon\Tests\Support\Models\InvoicesValidationFails;
use Phalcon\Tests\Support\Models\Sources;
use Phalcon\Tests\Support\Traits\DiTrait;

use function uniqid;

/**
 *
 * @group phql
 */
final class SaveTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {

        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    public function tearDown(): void
    {

        $this->tearDownDatabase();
    }


    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16395
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-09
     *
     * @group mysql
     * @group sqlite
     */
    public function infiniteSaveLoop(): void
    {

        /** @var PDO $connection */
        $connection        = self::getConnection();
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-', true));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        $customer           = Customers::findFirst(1);
        $invoice            = Invoices::findFirst(77);
        $invoice->customer  = $customer;
        $customer->invoices = [$invoice];
        $customer->save();
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-30
     * @since  2019-05-10
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSave(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);

        /**
         * New model
         */
        $customer                 = new Customers();
        $customer->cst_name_first = 'cst_test_firstName';

        $actual = $customer->save();
        $this->assertTrue($actual);

        $customer->cst_name_last = 'cst_test_lastName';

        $actual = $customer->save();
        $this->assertTrue($actual);

        /**
         * Saved model
         */
        $customer = Customers::findFirst();

        $expected = [
            'cst_id'          => $customer->cst_id,
            'cst_status_flag' => null,
            'cst_name_last'   => 'cst_test_lastName',
            'cst_name_first'  => 'cst_test_firstName',
        ];
        $actual   = $customer->toArray();
        $this->assertSame($expected, $actual);

        $customer->cst_status_flag = 1;

        $actual = $customer->save();
        $this->assertTrue($actual);

        /**
         * Modified saved model
         */
        $customer = Customers::findFirst();

        $expected = 1;
        $actual   = $customer->cst_status_flag;
        $this->assertEquals($expected, $actual);

        $customer->cst_name_last = null;

        $actual = $customer->save();
        $this->assertTrue($actual);

        /**
         * Verify model count
         */
        $expected = 1;
        $actual   = Customers::count();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveAfterFetchingRelated(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');
        $customersMigration->insert(2, 0, 'test_firstName_2', 'test_lastName_2');

        /**
         * @var Invoices $invoice
         */
        $invoice = Invoices::findFirst();

        /**
         * @var Customers $customer
         */
        $customer = $invoice->customer;

        $actual = $invoice->save();
        $this->assertTrue($actual);

        /**
         * @var Model\Resultset\Simple $invoices
         */
        $invoices = $customer->invoices;

        $actual = $customer->save();
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-10-09
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveAfterSettingEmptyRelated(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        $customer = Customers::findFirst();

        $invoice = new InvoicesValidationFails();

        $customer->invoices = [
            $invoice,
        ];

        $customer->invoices = [];

        $actual = $customer->save();
        $this->assertTrue($actual);

        $actual = $invoice->save();
        $this->assertFalse($actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveAfterUsingRelatedGetters(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');
        $customersMigration->insert(2, 0, 'test_firstName_2', 'test_lastName_2');

        /**
         * @var Invoices $invoice
         */
        $invoice = Invoices::findFirst();

        /**
         * @var Customers $customer
         */
        $customer = $invoice->getCustomer();

        $actual = $invoice->save();
        $this->assertTrue($actual);

        /**
         * @var Model\Resultset\Simple $invoices
         */
        $invoices = $customer->getInvoices();

        $actual = $customer->save();
        $this->assertTrue($actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-17
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveAfterWithoutDefaultValues(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersDefaultsMigration($connection);
        $customer           = new CustomersDefaults();

        /**
         * Default values are present in schema
         */
        $customerData = [
            'cst_status_flag' => 1,
        ];

        $customer->assign($customerData);

        $actual = $customer->save();
        $this->assertTrue($actual);

        /**
         * @var MetaData
         */
        $metaData = $customer->getModelsMetaData();

        /**
         * @var array
         */
        $defaultValues = $metaData->getDefaultValues($customer);

        foreach ($defaultValues as $attribute => $value) {
            $actual = $customer->{$attribute};
            $this->assertEquals($value, $actual);
        }
    }

    /**
     * @since  2019-04-28
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveCircularRelation(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration  = new InvoicesMigration($connection);
        $customersMigration = new CustomersMigration($connection);

        $invoice = new InvoicesKeepSnapshots([
                                                 'inv_title' => 'Test invoice',
                                             ]);

        $customer = new Customers([
                                      'cst_name_last'  => 'Evil',
                                      'cst_name_first' => 'Customer',
                                  ]);

        // Assign relationship in both directions on unsaved models
        $invoice->customer = $customer;

        $customer->invoices = [
            $invoice,
        ];

        // Save should handle the circular relation without issue
        $actual = $customer->save();
        $this->assertTrue($actual);

        // Both should have an ID now
        $actual = $invoice->inv_id;
        $this->assertNotNull($actual);
        $actual = $customer->cst_id;
        $this->assertNotNull($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-21
     *
     * @issue  15554
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveMultipleChangedRelationValues(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-', true));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'firstName', 'lastName');

        $invoice = InvoicesHasOneNotReusable::findFirst(77);

        $invoice->customer->cst_name_first  = 'newFirstName';
        $invoice->customer->cst_status_flag = 0;

        $this->assertTrue($invoice->save());

        $customer = Customers::findFirst(1);

        $this->assertSame('newFirstName', $customer->cst_name_first);
        $this->assertSame(0, (int) $customer->cst_status_flag);
    }

    /**
     * @issue  #11922
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveWithPropertySource(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $sourcesMigration = new SourcesMigration($connection);
        $sourcesMigration->insert(1, 'llama', 'test_source');

        $model = Sources::findFirst([
                                        'conditions' => 'id = :id:',
                                        'bind'       => [
                                            'id' => 1,
                                        ],
                                    ]);

        $class = Sources::class;
        $this->assertInstanceOf($class, $model);

        $expected = 1;
        $actual   = $model->id;
        $this->assertEquals($expected, $actual);

        $expected = 'co_sources';
        $actual   = $model->getSource();
        $this->assertSame($expected, $actual);

        $model->username = 'vader';
        $result          = $model->save();

        $expected = 0;
        $actual   = $model->getMessages();
        $this->assertCount($expected, $actual);
        $this->assertNotFalse($result);

        /**
         * Try now with `create()`
         */
        $source           = new Sources();
        $source->id       = 2;
        $source->username = 'llama';
        $source->source   = 'test_source';
        $result           = $source->create();
        $this->assertTrue($result);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-11-04
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveWithRelatedManyAndBelongsRecordsProperty(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-', true));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        /**
         * @var Invoices $invoice
         */
        $invoice = InvoicesKeepSnapshots::findFirst(77);

        $expected = 1;
        $actual   = $invoice->customer->id;
        $this->assertEquals($expected, $actual);

        $invoice->customer->cst_name_first  = 'new_firstName';
        $invoice->customer->cst_status_flag = 0;

        $actual = $invoice->save();
        $this->assertTrue($actual);

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst(1);

        $expected = 'new_firstName';
        $actual   = $customer->cst_name_first;
        $this->assertSame($expected, $actual);

        $expected = 0;
        $actual   = $customer->cst_status_flag;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveWithRelatedRecords(): void
    {

        $invoice = new InvoicesKeepSnapshots();

        $invoice->customer = new CustomersKeepSnapshots();
        $invoice->customer->assign([
                                       'cst_status_flag' => 0,
                                       'cst_name_first'  => 'cst_test_firstName',
                                   ]);

        $actual = $invoice->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $invoice->inv_cst_id;
        $this->assertGreaterThan($expected, $actual);

        $expected = $invoice->inv_cst_id;
        $actual   = $invoice->customer->cst_id;
        $this->assertEquals($expected, $actual);

        $connection = $this->getService('db');

        $actual = $connection->isUnderTransaction();
        $this->assertFalse($actual);

        $expected = Model::DIRTY_STATE_PERSISTENT;
        $actual   = $invoice->getDirtyState();
        $this->assertSame($expected, $actual);

        $expected = Model::DIRTY_STATE_PERSISTENT;
        $actual   = $invoice->customer->getDirtyState();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-31
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveWithRelatedRecordsProperty(): void
    {

        /** @var PDO $connection */
        $connection = self::getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-', true));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        /**
         * @var Invoices $invoice
         */
        $invoice = Invoices::findFirst(77);

        $expected = 1;
        $actual   = $invoice->customer->id;
        $this->assertEquals($expected, $actual);

        $invoice->customer->cst_name_first  = 'new_firstName';
        $invoice->customer->cst_status_flag = 0;

        $actual = $invoice->save();
        $this->assertTrue($actual);

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst(1);

        $expected = 'new_firstName';
        $actual   = $customer->cst_name_first;
        $this->assertSame($expected, $actual);

        $expected = 0;
        $actual   = $customer->cst_status_flag;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group mysql
     */
    public function testMvcModelSaveWithSchema(): void
    {

        $model = new Invoices();

        $model->inv_cst_id      = 1;
        $model->inv_status_flag = 1;
        $model->inv_title       = uniqid();
        $model->inv_total       = 100;
        $model->inv_created_at  = date('Y-m-d H:i:s');

        $result = $model->save();
        $this->assertNotFalse($result);

        $model = new InvoicesSchema();

        $model->inv_cst_id      = 1;
        $model->inv_status_flag = 1;
        $model->inv_title       = uniqid();
        $model->inv_total       = 100;
        $model->inv_created_at  = date('Y-m-d H:i:s');

        $result = $model->save();
        $this->assertNotFalse($result);
    }

    /**
     * @dataProvider tinyintProvider
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-08-02
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelSaveWithTinyInt(string $value): void
    {

        $customer                  = new Customers();
        $customer->cst_status_flag = $value;

        $actual = $customer->save();
        $this->assertTrue($actual);

        $actual = $customer->cst_id;
        $this->assertNotNull($actual);

        $storedModel = Customers::findFirstByCstId($customer->cst_id);

        $expected = $value;
        $actual   = $storedModel->cst_status_flag;
        $this->assertEquals($expected, $actual);
    }

    /**
     * @return string[][]
     */
    public static function tinyintProvider(): array
    {

        return [
            ["1"],
            ["0"],
            ["127"],
        ];
    }
}
