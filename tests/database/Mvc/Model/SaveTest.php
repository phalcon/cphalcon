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
use Phalcon\Events\Manager as EventsManager;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersDefaultsMigration;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\OnlyIdentityMigration;
use Phalcon\Tests\Support\Migrations\SourcesMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\CustomersDefaults;
use Phalcon\Tests\Support\Models\CustomersKeepSnapshots;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesBelongsToCustomers;
use Phalcon\Tests\Support\Models\InvoicesHasOneKeepSnapshots;
use Phalcon\Tests\Support\Models\InvoicesHasOneNotReusable;
use Phalcon\Tests\Support\Models\InvoicesKeepSnapshots;
use Phalcon\Tests\Support\Models\InvoicesSchema;
use Phalcon\Tests\Support\Models\InvoicesValidationFails;
use Phalcon\Tests\Support\Models\OnlyIdentity;
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
     * @group pgsql
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
     * @issue  https://github.com/phalcon/phalcon/issues/156
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-04
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelSaveOnlyIdentityColumn(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $migration = new OnlyIdentityMigration($connection);

        $model  = new OnlyIdentity();
        $actual = $model->save();

        $this->assertTrue($actual);
        $this->assertNotNull($model->oid_id);
        $this->assertGreaterThan(0, (int) $model->oid_id);

        $second = new OnlyIdentity();
        $second->save();

        $this->assertGreaterThan((int) $model->oid_id, (int) $second->oid_id);
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-30
     * @since  2019-05-10
     *
     * @group mysql
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * @issue  https://github.com/phalcon/cphalcon/issues/15554
     * @group mysql
     * @group pgsql
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
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-02
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16222
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelSaveBelongsToUpdatesExistingParent(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'firstName', 'lastName');

        $invoicesMigration = new InvoicesMigration($connection);

        $customer = Customers::findFirst(1);
        $this->assertNotNull($customer);

        $customer->cst_name_first = 'updatedFirstName';

        $invoice = new InvoicesBelongsToCustomers();
        $invoice->inv_title      = uniqid('inv-', true);
        $invoice->inv_created_at = date('Y-m-d H:i:s');
        $invoice->setCustomer($customer);

        $this->assertTrue($invoice->save());

        $reloaded = Customers::findFirst(1);

        $this->assertSame('updatedFirstName', $reloaded->cst_name_first);
        $this->assertSame(1, (int) $invoice->inv_cst_id);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-30
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16611
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelSaveNullRelatedAfterCallingGetter(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'firstName', 'lastName');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-', true));

        $invoice = InvoicesBelongsToCustomers::findFirst(77);

        $this->assertNotNull($invoice->inv_cst_id);

        // Calling the getter caches the related customer in $this->related.
        // Setting the relation to null must clear that cache so that
        // preSaveRelatedRecords() does not overwrite inv_cst_id on save.
        $invoice->getCustomer();
        $invoice->setCustomer(null);

        $this->assertTrue($invoice->save());

        $reloaded = InvoicesBelongsToCustomers::findFirst(77);

        $this->assertNull($reloaded->inv_cst_id);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-28
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16000
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelSaveDoesNotSaveUnmodifiedHasOneRelation(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'firstName', 'lastName');

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-', true));

        $invoice  = InvoicesHasOneKeepSnapshots::findFirst(77);
        $customer = $invoice->getRelated('customer');

        $this->assertNotFalse($customer);

        $eventsManager  = new EventsManager();
        $customerSaved  = false;
        $eventsManager->attach(
            'model:beforeSave',
            function () use (&$customerSaved): void {
                $customerSaved = true;
            }
        );
        $customer->setEventsManager($eventsManager);

        $invoice->inv_title = uniqid('inv-updated-', true);

        $this->assertTrue($invoice->save());
        $this->assertFalse($customerSaved, 'Unmodified hasOne related record must not be saved');
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/11922
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group mysql
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * @group pgsql
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
     * Tests that the reusable-records cache in Manager is cleared after a
     * successful save(), preventing unbounded memory growth in long-running
     * processes that call save() in a loop.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/16566
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-30
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMvcModelSaveClearsReusableObjects(): void
    {
        $connection        = self::getConnection();
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert('default', 1, 0, uniqid('inv-', true));

        /** @var Manager $manager */
        $manager = $this->container->getShared('modelsManager');

        $manager->setReusableRecords('SomeModel', 'key-abc', ['record1', 'record2']);

        $actual = $manager->getReusableRecords('SomeModel', 'key-abc');
        $this->assertNotNull($actual);

        $invoice              = new Invoices();
        $invoice->inv_cst_id  = 1;
        $invoice->inv_status_flag = 0;
        $invoice->inv_title   = uniqid('inv-', true);
        $invoice->inv_total   = 100.0;
        $invoice->inv_created_at = date('Y-m-d H:i:s');

        $actual = $invoice->save();
        $this->assertTrue($actual);

        $actual = $manager->getReusableRecords('SomeModel', 'key-abc');
        $this->assertNull($actual);
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
