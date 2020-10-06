<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model;

use DatabaseTester;
use Phalcon\Mvc\Model;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models;

class UnderscoreSetCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set()
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSet(DatabaseTester $I)
    {
        $I->wantToTest("Mvc\Model - __set()");

        $customer = new Models\Customers();

        $customer->cst_id = 999;

        $I->assertEquals(
            999,
            $customer->cst_id
        );

        $customer->cst_name_first = 'cst_firstName';

        $I->assertEquals(
            'cst_firstName',
            $customer->cst_name_first
        );

        $associativeArray = [
            'value_0',
            'key_1' => 'value_1',
            'key_2' => 'value_2',
        ];

        $customer->cst_data = $associativeArray;

        $I->assertEquals(
            $associativeArray,
            $customer->cst_data
        );

        $I->assertEquals(
            [
                'cst_id'          => 999,
                'cst_status_flag' => null,
                'cst_name_last'   => null,
                'cst_name_first'  => 'cst_firstName',
            ],
            $customer->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() whether it is using setters correctly
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetIsUsingSetters(DatabaseTester $I)
    {
        $I->wantToTest("Mvc\Model - __set() whether it is using setters correctly");

        $customer = new Models\Customers();

        $customer->id = 999;

        $I->assertEquals(
            999,
            $customer->cst_id
        );

        $customer->firstName = 'cst_firstName';

        $I->assertEquals(
            'cst_firstName',
            $customer->cst_name_first
        );

        $associativeArray = [
            'value_0',
            'key_1' => 'value_1',
            'key_2' => 'value_2',
        ];

        $customer->data = $associativeArray;

        $I->assertEquals(
            $associativeArray,
            $customer->cst_data
        );

        $I->assertEquals(
            [
                'cst_id'          => 999,
                'cst_status_flag' => null,
                'cst_name_last'   => null,
                'cst_name_first'  => 'cst_firstName',
            ],
            $customer->toArray()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with belongs-to related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithBelongsToRelatedRecord(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with belongs-to related record');

        $customerSnap           = new Models\CustomersKeepSnapshots();
        $customerSnap->invoices = new Models\Invoices();

        $invoices = $customerSnap->invoices;

        $I->assertInstanceOf(
            Models\Invoices::class,
            $invoices
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $customerSnap->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with an array as properties of a
     * belongs-to related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithArrayOfBelongsToRelatedRecord(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with an array as properties of a belongs-to related record');

        $invoice           = new Models\Invoices();
        $invoice->customer = [
            'cst_id'          => 33,
            'cst_status_flag' => 1
        ];

        $customer = $invoice->customer;

        $I->assertInstanceOf(
            Models\Customers::class,
            $customer
        );

        $I->assertEquals(
            $invoice->getDirtyState(),
            Model::DIRTY_STATE_TRANSIENT
        );

        $I->assertEquals(
            33,
            $customer->cst_id
        );

        $I->assertEquals(
            1,
            $customer->cst_status_flag
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-one related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithHasOneRelatedRecord(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-one related record');

        $invoice           = new Models\Invoices();
        $invoice->customer = new Models\Customers();

        $customer = $invoice->customer;

        $I->assertInstanceOf(
            Models\Customers::class,
            $customer
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $invoice->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-one-through related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-11-03
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithHasOneThroughRelatedRecord(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-one-through related record');

        $product = new Models\Products();

        $order                = new Models\Orders();
        $order->singleProduct = $product;

        $I->assertInstanceOf(
            Models\Products::class,
            $order->singleProduct
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $order->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with an array as properties of a
     * has-one related record
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithArrayOfHasOneRelatedRecord(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with an array as properties of a has-one related record');

        $invoice           = new Models\Invoices();
        $invoice->customer = [
            'cst_id'         => 99,
            'cst_name_first' => 'cst_firstName'
        ];

        $customer = $invoice->customer;

        $I->assertInstanceOf(
            Models\Customers::class,
            $customer
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $invoice->getDirtyState()
        );

        $I->assertEquals(
            99,
            $customer->cst_id
        );

        $I->assertEquals(
            'cst_firstName',
            $customer->cst_name_first
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-many related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithHasManyRelatedRecords(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-many related records');

        $customer           = new Models\Orders();
        $customer->invoices = [
            new Models\Invoices(),
            new Models\Invoices()
        ];

        $invoices = $customer->invoices;

        $I->assertIsArray(
            $invoices
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $customer->getDirtyState()
        );

        $I->assertCount(
            2,
            $invoices
        );

        $I->assertInstanceOf(
            Models\Invoices::class,
            $invoices[0]
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $customer->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() with has-many-to-many related records
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetWithHasManyToManyRelatedRecords(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() with has-many-to-many related records');

        $order           = new Models\Orders();
        $order->products = [
            new Models\Products(),
            new Models\Products()
        ];

        $products = $order->products;

        $I->assertIsArray(
            $products
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $order->getDirtyState()
        );

        $I->assertCount(
            2,
            $products
        );

        $I->assertInstanceOf(
            Models\Products::class,
            $products[0]
        );

        $I->assertEquals(
            Model::DIRTY_STATE_TRANSIENT,
            $order->getDirtyState()
        );
    }

    /**
     * Tests Phalcon\Mvc\Model :: __set() undefined property with associative
     * array
     *
     * @see    https://github.com/phalcon/cphalcon/issues/14021
     *
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-05-02
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelUnderscoreSetUndefinedPropertyWithAssociativeArray(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - __set() undefined property with associative array');

        $associativeArray = [
            'cst_id'         => 123,
            'cst_name_first' => 'cst_firstName',
        ];

        $customer                            = new Models\Customers();
        $customer->whatEverUndefinedProperty = $associativeArray;

        $I->assertEquals(
            [
                'cst_id'          => null,
                'cst_status_flag' => null,
                'cst_name_last'   => null,
                'cst_name_first'  => null
            ],
            $customer->toArray()
        );
    }
}
