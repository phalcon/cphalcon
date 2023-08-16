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

use DatabaseTester;
use PDO;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersProductsFieldsMultCompMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersProductsFieldsMultMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersProductsFieldsOneCompMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersProductsFieldsOneMigration;
use Phalcon\Tests\Fixtures\Migrations\ProductsMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\OrdersMultiple;
use Phalcon\Tests\Models\OrdersProductsFieldsMult;
use Phalcon\Tests\Models\OrdersProductsFieldsMultComp;
use Phalcon\Tests\Models\OrdersProductsFieldsOne;
use Phalcon\Tests\Models\OrdersProductsFieldsOneComp;
use Phalcon\Tests\Models\Products;

use function uniqid;

/**
 * Class GetRelatedCest
 */
class RelationsCest
{
    use DiTrait;

    /**
     * @param DatabaseTester $I
     */
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
     * Tests Phalcon\Mvc\Model :: BelongsTo() - get
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetBelongsTo(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - get - BelongsTo()');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $custIdOne    = 50;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);

        $invoiceId = 50;
        $title = uniqid('inv-');
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoiceId = 70;
        $title = uniqid('inv-');
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            0,
            $title . ''
        );

        $invoice = Invoices::findFirst(50);
        $actual = $invoice->customer;
        $I->assertNotNull($actual);

        $actual = $invoice->customerMultipleFields;
        $I->assertNull($actual);

        $invoice = Invoices::findFirst(70);
        $actual = $invoice->customer;
        $I->assertNotNull($actual);

        $actual = $invoice->customerMultipleFields;
        $I->assertNotNull($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: HasMany() - get
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetHasMany(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - get - HasMany()');

        /** @var PDO $connection */
        $connection = $I->getConnection();


        $custIdOne    = 50;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);

        $invoiceId = 50;
        $title = uniqid('inv-');
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $invoiceId = 70;
        $title = uniqid('inv-');
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            0,
            $title . ''
        );

        $customer = Customers::findFirst(50);

        $invoices = $customer->getRelated('invoices');
        $actual = count($invoices);
        $expected = 2;
        $I->assertEquals($expected, $actual);

        $invoices = $customer->getRelated('invoicesMultipleFields');
        $actual = count($invoices);
        $expected = 1;
        $I->assertEquals($expected, $actual);

        $invoice = $invoices->getFirst();
        $expected = 0;
        $actual = $invoice->inv_status_flag;

        $I->assertEquals($expected, $actual);

        $invoices = $customer->getRelated('invoices');
        $actual = count($invoices);
        $expected = 2;
        $I->assertEquals($expected, $actual);
        $invoice = $invoices->getFirst();
        $expected = 1;
        $actual = $invoice->inv_status_flag;

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - get
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetHasOneThrough(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - get - HasOneThrough()');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;
        $productId  = 20;
        $productName  = uniqid('prd', true);
        $productStatus = 10;
        $quantity = 1;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert(1, $orderId, $productId, $quantity);

        $productId  = 30;
        $productName  = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert(1, $orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $product = $orders->singleProductFieldsOne;
        $expected = 20;
        $actual = $product->prd_id;
        $I->assertEquals($expected, $actual);

        $product = $orders->singleProductFieldsMult;
        $expected = 30;
        $actual = $product->prd_id;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManytoMany() - get
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetHasManyToMany(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - get - HasManyToMany()');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;
        $productId  = 20;
        $productName  = uniqid('prd', true);
        $productStatus = 10;
        $quantity = 1;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert(1, $orderId, $productId, $quantity);

        $productId  = 30;
        $productName  = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert(1, $orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $products = $orders->productsFieldsOne;
        $expected = 1;
        $actual = count($products);
        $I->assertEquals($expected, $actual);

        $products = $orders->productsFieldsMult;
        $expected = 1;
        $actual = count($products);
        $I->assertEquals($expected, $actual);

        $product = $products->getFirst();
        $expected = 30;
        $actual = $product->prd_id;
        $I->assertEquals($expected, $actual);
    }

        /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - get
     * Compound Primary Key Intermediate Relations
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetHasOneThroughComp(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - get - HasOneThrough() Comp');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;
        $productId  = 20;
        $productName  = uniqid('prd', true);
        $productStatus = 10;
        $quantity = 1;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert($orderId, $productId, $quantity);

        $productId  = 30;
        $productName  = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert($orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $product = $orders->singleProductFieldsOneComp;
        $expected = 20;
        $actual = $product->prd_id;
        $I->assertEquals($expected, $actual);

        $product = $orders->singleProductFieldsMultComp;
        $expected = 30;
        $actual = $product->prd_id;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManytoMany() - get
     * Compound Primary Key Intermediate Relations
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelGetHasManyToManyComp(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - get - HasManyToMany() Comp');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;
        $productId  = 20;
        $productName  = uniqid('prd', true);
        $productStatus = 10;
        $quantity = 1;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert($orderId, $productId, $quantity);

        $productId  = 30;
        $productName  = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert($orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $products = $orders->productsFieldsOneComp;
        $expected = 1;
        $actual = count($products);
        $I->assertEquals($expected, $actual);

        $products = $orders->productsFieldsMultComp;
        $expected = 1;
        $actual = count($products);
        $I->assertEquals($expected, $actual);

        $product = $products->getFirst();
        $expected = 30;
        $actual = $product->prd_id;
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: BelongsTo() - set
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetBelongsTo(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - set - BelongsTo()');

        /** @var PDO $connection */
        $connection = $I->getConnection();


        $custIdOne    = 50;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);

        $invoiceId = 50;
        $title = uniqid('inv-');
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $customer = Customers::findFirst(50);

        $invoice = new Invoices();
        $invoice->inv_id = 70;
        $invoice->inv_title = $title = uniqid('inv-');

        $invoice->customerMultipleFields = $customer;

        $actual = $invoice->save();

        $I->assertTrue($actual);

        $expected = 0;
        $actual = $invoice->inv_status_flag;
        $I->assertEquals($expected, $actual);

        $expected = 50;
        $actual = $invoice->inv_cst_id;
        $I->assertEquals($expected, $actual);

        $expected = 0;
        $actual = $invoice->getDirtyState();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasMany() - set
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetHasMany(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - set - HasMany()');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $custIdOne    = 50;
        $firstNameOne = uniqid('cust-1-', true);
        $lastNameOne  = uniqid('cust-1-', true);

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert($custIdOne, 0, $firstNameOne, $lastNameOne);

        $invoiceId = 50;
        $title = uniqid('inv-');
        $invoicesMigration = new InvoicesMigration($connection);
        $invoicesMigration->insert(
            $invoiceId,
            $custIdOne,
            Invoices::STATUS_PAID,
            $title . '-paid'
        );
        $customer = Customers::findFirst(50);

        $invoice = new Invoices();
        $invoice->inv_id = 70;
        $invoice->inv_title = $title = uniqid('inv-');


        $customer->InvoicesMultipleFields = [$invoice];
        $actual = $customer->save();

        $I->assertTrue($actual);

        $expected = 0;
        $actual = $invoice->inv_status_flag;
        $I->assertEquals($expected, $actual);

        $expected = 50;
        $actual = $invoice->inv_cst_id;
        $I->assertEquals($expected, $actual);

        $expected = 0;
        $actual = $invoice->getDirtyState();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - set
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetHasOneThrough(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - set - HasOneThrough()');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations = new ProductsMigration($connection);


        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders = OrdersMultiple::findFirst(10);
        $product = new Products();
        $product->prd_name = uniqid('prd', true);
        $product->prd_status_flag = 0;

        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();

        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $product = new Products();
        $product->prd_name = uniqid('prd2', true);
        $product->prd_status_flag = 10;


        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();
        $I->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $orders->singleProductFieldsMultComp = $product;
        $actual = $orders->save();
        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManyToMany() - set
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetHasManyToMany(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - set - HasManyToMany()');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders = OrdersMultiple::findFirst(10);
        $product1 = new Products();
        $product1->prd_name = uniqid('prd1', true);
        $product1->prd_status_flag = 5;

        $product2 = new Products();
        $product2->prd_name = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        $orders->productsFieldsOne = [$product1];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product1->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOne::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $orders->productsFieldsOne = [$product1, $product2];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product2->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOne::find();
        $expected = 2;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $products = Products::find();
        $expected = 2;
        $actual = $products->count();
        $I->assertEquals($expected, $actual);

        /**
         * Multiple Keys
         */
        $orders->productsFieldsMult = [$product1];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMult::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $orders->productsFieldsMult = [$product2];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMult::find();
        $expected = 2;
        $actual = $intermidiate->count();
        $I->assertEquals($expected, $actual);

        $orders->productsFieldsMult = [$product1, $product2];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMult::find();
        $expected = 2;
        $actual = $intermidiate->count();
        $I->assertEquals($expected, $actual);

        $products = $orders->getRelated('productsFieldsMult');
        $expected = 2;
        $actual = count($products);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - set
     * Compound Primary Key Intermediate Relations
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetHasOneThroughComp(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - set - HasOneThrough() Comp');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations = new ProductsMigration($connection);


        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders = OrdersMultiple::findFirst(10);
        $product = new Products();
        $product->prd_name = uniqid('prd', true);
        $product->prd_status_flag = 0;

        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();

        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $product = new Products();
        $product->prd_name = uniqid('prd2', true);
        $product->prd_status_flag = 10;


        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();
        $I->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $orders->singleProductFieldsMultComp = $product;
        $actual = $orders->save();
        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManyToMany() - set
     * Compound Primary Key Intermediate Relations
     *
     * @param DatabaseTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function mvcModelSetHasManyToManyComp(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - set - HasManyToMany() Comp');

        /** @var PDO $connection */
        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders = OrdersMultiple::findFirst(10);
        $product1 = new Products();
        $product1->prd_name = uniqid('prd', true);
        $product1->prd_status_flag = 0;

        $orders->productsFieldsOneComp = [$product1];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $expected = 0;
        $actual = $product1->getDirtyState();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $product2 = new Products();
        $product2->prd_name = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        $orders->productsFieldsMultComp = [$product2];
        $actual = $orders->save();
        $I->assertTrue($actual);


        $expected = 0;
        $actual = $product2->getDirtyState();
        $I->assertEquals($expected, $actual);

        $products = Products::find();
        $expected = 2;
        $actual = $products->count();
        $I->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected = 1;
        $actual = count($intermidiate);
        $I->assertEquals($expected, $actual);

        $orders->productsFieldsMultComp = [$product1, $product2];
        $actual = $orders->save();
        $I->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected = 2;
        $actual = $intermidiate->count();
        $I->assertEquals($expected, $actual);

        $products = $orders->getRelated('productsFieldsMultComp');
        $expected = 2;
        $actual = count($products);
        $I->assertEquals($expected, $actual);
    }
}
