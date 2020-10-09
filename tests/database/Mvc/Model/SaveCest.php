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

namespace Phalcon\Test\Integration\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\MetaData;
use Phalcon\Test\Fixtures\Migrations\CustomersMigration;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Test\Fixtures\Migrations\SourcesMigration;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\CustomersDefaults;
use Phalcon\Test\Models\CustomersKeepSnapshots;
use Phalcon\Test\Models\Invoices;
use Phalcon\Test\Models\InvoicesKeepSnapshots;
use Phalcon\Test\Models\InvoicesSchema;
use Phalcon\Test\Models\InvoicesValidationFails;
use Phalcon\Test\Models\Sources;
use Phalcon\Test\Models\Customers;

use function uniqid;

class SaveCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
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

        /**
         * New model
         */
        $customer                 = new Customers();
        $customer->cst_id         = 54321;
        $customer->cst_name_first = 'cst_test_firstName';

        $I->assertTrue(
            $customer->save()
        );

        $customer->cst_name_last = 'cst_test_lastName';

        $I->assertTrue(
            $customer->save()
        );

        /**
         * Saved model
         */
        $customer = Customers::findFirst(54321);

        $I->assertEquals(
            [
                'cst_id'          => 54321,
                'cst_status_flag' => null,
                'cst_name_first'  => 'cst_test_firstName',
                'cst_name_last'   => 'cst_test_lastName',
            ],
            $customer->toArray()
        );

        $customer->cst_status_flag = 1;

        $I->assertTrue(
            $customer->save()
        );

        /**
         * Modified saved model
         */
        $customer = Customers::findFirst(54321);

        $I->assertEquals(
            1,
            $customer->cst_status_flag
        );

        $customer->cst_name_last = null;

        $I->assertTrue(
            $customer->save()
        );

        /**
         * Verify model count
         */
        $I->assertEquals(
            1,
            Customers::count(
                [
                    'cst_id = 54321',
                ]
            )
        );
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
                'cst_id'          => 999,
                'cst_status_flag' => 0,
                'cst_name_first'  => 'cst_test_firstName'
            ]
        );

        $I->assertTrue(
            $invoice->save()
        );

        $I->assertGreaterThan(
            0,
            $invoice->inv_cst_id
        );

        $I->assertEquals(
            999,
            $invoice->customer->cst_id
        );

        $connection = $this->getService('db');

        $I->assertFalse(
            $connection->isUnderTransaction()
        );

        $I->assertEquals(
            Model::DIRTY_STATE_PERSISTENT,
            $invoice->getDirtyState()
        );

        $I->assertEquals(
            Model::DIRTY_STATE_PERSISTENT,
            $invoice->customer->getDirtyState()
        );
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
        $invoicesMigration->clear();
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();
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

        $I->assertTrue(
            $invoice->save()
        );

        /**
         * @var Model\Resultset\Simple $invoices
         */
        $invoices = $customer->invoices;

        $I->assertTrue(
            $customer->save()
        );
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
        $invoicesMigration->clear();
        $invoicesMigration->insert(77, 1, 0, uniqid('inv-'));
        $invoicesMigration->insert(88, 1, 1, uniqid('inv-'));

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();
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

        $I->assertTrue(
            $invoice->save()
        );

        /**
         * @var Model\Resultset\Simple $invoices
         */
        $invoices = $customer->getInvoices();

        $I->assertTrue(
            $customer->save()
        );
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

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();

        $customer = new CustomersDefaults();

        /**
         * Default values are present in schema
         */
        $customerData = [
            'cst_id' => 999
        ];

        $customer->assign($customerData);

        $I->assertTrue(
            $customer->save()
        );

        /**
         * @var MetaData
         */
        $metaData = $customer->getModelsMetaData();

        /**
         * @var array
         */
        $defaultValues = $metaData->getDefaultValues($customer);

        foreach ($defaultValues as $attribute => $value) {
            $I->assertEquals(
                $value,
                $customer->{$attribute}
            );
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
        $invoicesMigration->clear();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();

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
        $invoice->customer  = $customer;
        $customer->invoices = [
            $invoice
        ];

        // Save should handle the circular relation without issue
        $I->assertTrue(
            $customer->save()
        );

        // Both should have an ID now
        $I->assertNotNull($invoice->inv_id);
        $I->assertNotNull($customer->cst_id);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() after fetching related using magic
     * getter
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14270
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-08-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveAfterFetchingRelatedWithMagicGetter(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model::save() after fetching related using magic getter');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->clear();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();

        $customer = new Customers(
            [
                'cst_name_last'  => 'Evil',
                'cst_name_first' => 'Customer'
            ]
        );

        $invoice1 = new Invoices(
            [
                'inv_title' => 'Money is',
            ]
        );
        $invoice2 = new Invoices(
            [
                'inv_title' => 'the',
            ]
        );

        // Assign relationship in both directions on unsaved models
        $customer->invoices = [$invoice1, $invoice2];

        $I->assertTrue(
            $customer->save()
        );

        $evilCustomer = Customers::findFirstByCstNameLast("Evil");

        // Query the parts, for some reason,
        // for example to check if the parts are in the db already...
        $invoices = $evilCustomer->invoices;

        $I->assertCount(
            2,
            $invoices
        );

        $invoice3           = new Invoices(
            [
                'inv_title' => 'root',
            ]
        );
        $invoice4           = new Invoices(
            [
                'inv_title' => 'of all evil',
            ]
        );
        $customer->invoices = [$invoice3, $invoice4];

        $I->assertTrue(
            $customer->save()
        );

        $allEvilCustomer = Customers::findFirstByCstNameLast("Evil");

        $allInvoices = $allEvilCustomer->getRelated('invoices');

        $I->assertEquals(
            4,
            count($allInvoices)
        );
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
        $customersMigration->clear();
        $customersMigration->insert(1, 1, 'test_firstName_1', 'test_lastName_1');

        $customer = Customers::findFirst();

        $invoice = new InvoicesValidationFails();

        $customer->invoices = [
            $invoice
        ];

        $customer->invoices = [];

        $I->assertTrue(
            $customer->save()
        );

        $I->assertNull(
            $invoice->inv_cst_id
        );
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

        $I->assertTrue(
            $customer->save()
        );

        $I->assertNotNull(
            $customer->cst_id
        );

        $storedModel = Customers::findFirstByCstId($customer->cst_id);

        $I->assertEquals(
            $example['value'],
            $storedModel->cst_status_flag
        );
    }

    /**
     * @return array
     */
    protected function tinyintProvider()
    {
        return [
            ['value' => "1"],
            ['value' => "0"],
            ['value' => "127"]
        ];
    }

    /**
     * Tests Phalcon\Mvc\Model\ :: save() with schema
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-11-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
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
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSaveWithPropertySource(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - save() with property source');

        /** @var \PDO $connection */
        $connection = $I->getConnection();

        $sourcesMigration = new SourcesMigration($connection);
        $sourcesMigration->clear();
        $sourcesMigration->insert(1, 'llama', 'test_source');

        $model = Sources::findFirst(
            [
                'conditions' => 'id = :id:',
                'bind'       => [
                    'id' => 1,
                ],
            ]
        );

        $I->assertInstanceOf(Sources::class, $model);
        $I->assertEquals(1, $model->id);
        $I->assertEquals('co_sources', $model->getSource());

        $model->username = 'vader';
        $result          = $model->save();

        $I->assertCount(0, $model->getMessages());
        $I->assertNotFalse($result);
    }
}
