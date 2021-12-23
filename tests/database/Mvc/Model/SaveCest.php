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

namespace Phalcon\Tests\Integration\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Tests\Fixtures\Migrations\CustomersDefaultsMigration;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Migrations\SourcesMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\CustomersDefaults;
use Phalcon\Tests\Models\CustomersKeepSnapshots;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\InvoicesKeepSnapshots;
use Phalcon\Tests\Models\InvoicesSchema;
use Phalcon\Tests\Models\InvoicesValidationFails;
use Phalcon\Tests\Models\Sources;
use Phalcon\Tests\Models\Customers;

use function uniqid;

class SaveCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    public function _after(DatabaseTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model :: save()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-10
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSave(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save()');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $customersMigration = new CustomersMigration($connection);

        /**
         * New model
         */
        $customer                 = new Customers();
        $customer->cst_name_first = 'cst_test_firstName';

        $actual = $customer->save();
        $I->assertTrue($actual);

        $customer->cst_name_last = 'cst_test_lastName';

        $actual = $customer->save();
        $I->assertTrue($actual);

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
        $I->assertSame($expected, $actual);

        $customer->cst_status_flag = 1;

        $actual = $customer->save();
        $I->assertTrue($actual);

        /**
         * Modified saved model
         */
        $customer = Customers::findFirst();

        $expected = 1;
        $actual   = $customer->cst_status_flag;
        $I->assertSame($expected, $actual);

        $customer->cst_name_last = null;

        $actual = $customer->save();
        $I->assertTrue($actual);

        /**
         * Verify model count
         */
        $expected = 1;
        $actual   = Customers::count();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-30
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveWithRelatedRecords(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with related records');

        $invoice = new InvoicesKeepSnapshots();

        $invoice->customer = new CustomersKeepSnapshots();
        $invoice->customer->assign(
            [
                'cst_status_flag' => 0,
                'cst_name_first'  => 'cst_test_firstName'
            ]
        );

        $actual = $invoice->save();
        $I->assertTrue($actual);

        $expected = 0;
        $actual   = $invoice->inv_cst_id;
        $I->assertGreaterThan($expected, $actual);

        $expected = $invoice->inv_cst_id;
        $actual   = $invoice->customer->cst_id;
        $I->assertEquals($expected, $actual);

        $connection = $this->getService('db');

        $actual = $connection->isUnderTransaction();
        $I->assertFalse($actual);

        $expected = Model::DIRTY_STATE_PERSISTENT;
        $actual   = $invoice->getDirtyState();
        $I->assertSame($expected, $actual);

        $expected = Model::DIRTY_STATE_PERSISTENT;
        $actual   = $invoice->customer->getDirtyState();
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with related records property
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-10-31
     *
     * @see https://github.com/phalcon/cphalcon/issues/15148
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveWithRelatedRecordsProperty(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with related records property');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

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
        $I->assertSame($expected, $actual);

        $invoice->customer->cst_name_first  = 'new_firstName';
        $invoice->customer->cst_status_flag = 0;

        $actual = $invoice->save();
        $I->assertTrue($actual);

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst(1);

        $expected = 'new_firstName';
        $actual   = $customer->cst_name_first;
        $I->assertSame($expected, $actual);

        $expected = 0;
        $actual   = $customer->cst_status_flag;
        $I->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after fetching related records
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveAfterFetchingRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after fetching related');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

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
        $I->assertTrue($actual);

        /**
         * @var Model\Resultset\Simple $invoices
         */
        $invoices = $customer->invoices;

        $actual = $customer->save();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after using related records getters
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13964
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-04-26
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveAfterUsingRelatedGetters(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() after using related records getters');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

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
        $I->assertTrue($actual);

        /**
         * @var Model\Resultset\Simple $invoices
         */
        $invoices = $customer->getInvoices();

        $actual = $customer->save();
        $I->assertTrue($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() when default values are not set
     *
     * @see    https://github.com/phalcon/cphalcon/issues/13781
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-17
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveAfterWithoutDefaultValues(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() when default values are not set');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $customersMigration = new CustomersDefaultsMigration($connection);
        $customer           = new CustomersDefaults();

        /**
         * Default values are present in schema
         */
        $customerData = [
            'cst_status_flag' => 1
        ];

        $customer->assign($customerData);

        $actual = $customer->save();
        $I->assertTrue($actual);

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
            $I->assertEquals($value, $actual);
        }
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with circular unsaved relations
     *
     * @since  2019-04-28
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveCircularRelation(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model::save() with circular unsaved relations');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $customersMigration = new CustomersMigration($connection);

        $invoice = new InvoicesKeepSnapshots(
            [
                'inv_title' => 'Test invoice'
            ]
        );

        $customer = new Customers(
            [
                'cst_name_last'  => 'Evil',
                'cst_name_first' => 'Customer'
            ]
        );

        // Assign relationship in both directions on unsaved models
        $invoice->customer = $customer;

        $customer->invoices = [
            $invoice
        ];

        // Save should handle the circular relation without issue
        $actual = $customer->save();
        $I->assertTrue($actual);

        // Both should have an ID now
        $actual = $invoice->inv_id;
        $I->assertNotNull($actual);
        $actual = $customer->cst_id;
        $I->assertNotNull($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after setting empty array
     *
     * @see    https://github.com/phalcon/cphalcon/issues/1482214270
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-10-09
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveAfterSettingEmptyRelated(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model::save() after setting empty array');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        $customer = Customers::findFirst();

        $invoice = new InvoicesValidationFails();

        $customer->invoices = [
            $invoice
        ];

        $customer->invoices = [];

        $actual = $customer->save();
        $I->assertTrue($actual);

        $actual = $invoice->save();
        $I->assertFalse($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with a tinyint(1)
     *
     * @see          https://github.com/phalcon/cphalcon/issues/14355
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-08-02
     * @dataProvider tinyintProvider
     *
     * @group        mysql
     * @group        pgsql
     * @group        sqlite
     */
    public function mvcModelSaveWithTinyInt(DatabaseTester $I, \Codeception\Example $example)
    {
        $I->wantToTest('Mvc\Model::save() with a tinyint(1)');

        $customer                  = new Customers();
        $customer->cst_status_flag = $example['value'];

        $actual = $customer->save();
        $I->assertTrue($actual);

        $actual = $customer->cst_id;
        $I->assertNotNull($actual);

        $storedModel = Customers::findFirstByCstId($customer->cst_id);

        $expected = $example['value'];
        $actual   = $storedModel->cst_status_flag;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model\ :: save() with schema
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group  mysql
     */
    public function mvcModelSaveWithSchema(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with a schema');

        $model = new Invoices();

        $model->inv_cst_id      = 1;
        $model->inv_status_flag = 1;
        $model->inv_title       = uniqid();
        $model->inv_total       = 100;
        $model->inv_created_at  = date('Y-m-d H:i:s');

        $result = $model->save();
        $I->assertNotFalse($result);

        $model = new InvoicesSchema();

        $model->inv_cst_id      = 1;
        $model->inv_status_flag = 1;
        $model->inv_title       = uniqid();
        $model->inv_total       = 100;
        $model->inv_created_at  = date('Y-m-d H:i:s');

        $result = $model->save();
        $I->assertNotFalse($result);
    }

    /**
     * Tests Phalcon\Mvc\Model\ :: save() with property source
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group  mysql
     * @group  sqlite
     */
    public function mvcModelSaveWithPropertySource(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with property source');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $sourcesMigration = new SourcesMigration($connection);
        $sourcesMigration->insert(1, 'llama', 'test_source');

        $model = Sources::findFirst(
            [
                'conditions' => 'id = :id:',
                'bind'       => [
                    'id' => 1,
                ],
            ]
        );

        $class = Sources::class;
        $I->assertInstanceOf($class, $model);

        $expected = 1;
        $actual   = $model->id;
        $I->assertSame($expected, $actual);

        $expected = 'co_sources';
        $actual   = $model->getSource();
        $I->assertSame($expected, $actual);

        $model->username = 'vader';
        $result          = $model->save();

        $expected = 0;
        $actual   = $model->getMessages();
        $I->assertCount($expected, $actual);
        $I->assertNotFalse($result);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with related records property (relation many - belongs)
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2020-11-04
     *
     * @see https://github.com/phalcon/cphalcon/issues/15148
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveWithRelatedManyAndBelongsRecordsProperty(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with related records property (relation many - belongs)');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

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
        $I->assertSame($expected, $actual);

        $invoice->customer->cst_name_first  = 'new_firstName';
        $invoice->customer->cst_status_flag = 0;

        $actual = $invoice->save();
        $I->assertTrue($actual);

        /**
         * @var Customers $customer
         */
        $customer = Customers::findFirst(1);

        $expected = 'new_firstName';
        $actual   = $customer->cst_name_first;
        $I->assertSame($expected, $actual);

        $expected = 0;
        $actual   = $customer->cst_status_flag;
        $I->assertSame($expected, $actual);
    }

    /**
     * @return \string[][]
     */
    private function tinyintProvider(): array
    {
        return [
            ['value' => "1"],
            ['value' => "0"],
            ['value' => "127"]
        ];
    }
}
