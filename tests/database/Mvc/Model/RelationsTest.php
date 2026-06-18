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
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\OrdersMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsMultCompMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsMultMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsOneCompMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsOneMigration;
use Phalcon\Tests\Support\Migrations\ProductsMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\OrdersMultiple;
use Phalcon\Tests\Support\Models\OrdersProductsFieldsMult;
use Phalcon\Tests\Support\Models\OrdersProductsFieldsMultComp;
use Phalcon\Tests\Support\Models\OrdersProductsFieldsOne;
use Phalcon\Tests\Support\Models\OrdersProductsFieldsOneComp;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

use function uniqid;

/**
 * Class RelationsTest
 */
final class RelationsTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Mvc\Model :: BelongsTo() - get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetBelongsTo(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

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
        $this->assertNotNull($actual);

        $actual = $invoice->customerMultipleFields;
        $this->assertNull($actual);

        $invoice = Invoices::findFirst(70);
        $actual = $invoice->customer;
        $this->assertNotNull($actual);

        $actual = $invoice->customerMultipleFields;
        $this->assertNotNull($actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: HasMany() - get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetHasMany(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

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
        $this->assertEquals($expected, $actual);

        $invoices = $customer->getRelated('invoicesMultipleFields');
        $actual = count($invoices);
        $expected = 1;
        $this->assertEquals($expected, $actual);

        $invoice = $invoices->getFirst();
        $expected = 0;
        $actual = $invoice->inv_status_flag;
        $this->assertEquals($expected, $actual);

        $invoices = $customer->getRelated('invoices');
        $actual = count($invoices);
        $expected = 2;
        $this->assertEquals($expected, $actual);

        $invoice = $invoices->getFirst();
        $expected = 1;
        $actual = $invoice->inv_status_flag;
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetHasOneThrough(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId       = 10;
        $orderName     = uniqid('ord', true);
        $orderStatus   = 5;
        $productId     = 20;
        $productName   = uniqid('prd', true);
        $productStatus = 10;
        $quantity      = 1;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert(1, $orderId, $productId, $quantity);

        $productId     = 30;
        $productName   = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert(1, $orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $product  = $orders->singleProductFieldsOne;
        $expected = 20;
        $actual   = $product->prd_id;
        $this->assertEquals($expected, $actual);

        $product  = $orders->singleProductFieldsMult;
        $expected = 30;
        $actual   = $product->prd_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - get
     * Compound Primary Key Intermediate Relations
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetHasOneThroughComp(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId       = 10;
        $orderName     = uniqid('ord', true);
        $orderStatus   = 5;
        $productId     = 20;
        $productName   = uniqid('prd', true);
        $productStatus = 10;
        $quantity      = 1;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert($orderId, $productId, $quantity);

        $productId     = 30;
        $productName   = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert($orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $product  = $orders->singleProductFieldsOneComp;
        $expected = 20;
        $actual   = $product->prd_id;
        $this->assertEquals($expected, $actual);

        $product  = $orders->singleProductFieldsMultComp;
        $expected = 30;
        $actual   = $product->prd_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManytoMany() - get
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetHasManyToMany(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId       = 10;
        $orderName     = uniqid('ord', true);
        $orderStatus   = 5;
        $productId     = 20;
        $productName   = uniqid('prd', true);
        $productStatus = 10;
        $quantity      = 1;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert(1, $orderId, $productId, $quantity);

        $productId     = 30;
        $productName   = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert(1, $orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $products = $orders->productsFieldsOne;
        $expected = 1;
        $actual   = count($products);
        $this->assertEquals($expected, $actual);

        $products = $orders->productsFieldsMult;
        $expected = 1;
        $actual   = count($products);
        $this->assertEquals($expected, $actual);

        $product  = $products->getFirst();
        $expected = 30;
        $actual   = $product->prd_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManytoMany() - get
     * Compound Primary Key Intermediate Relations
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelGetHasManyToManyComp(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId       = 10;
        $orderName     = uniqid('ord', true);
        $orderStatus   = 5;
        $productId     = 20;
        $productName   = uniqid('prd', true);
        $productStatus = 10;
        $quantity      = 1;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsOneMigration->insert($orderId, $productId, $quantity);

        $productId     = 30;
        $productName   = uniqid('prd-2-', true);
        $productStatus = 10;
        $productsMigrations->insert($productId, $productName, $productStatus);
        $ordersProductsMultMigration->insert($orderId, $productId, $quantity, $orderStatus, $productStatus);

        $orders = OrdersMultiple::findFirst(10);

        $products = $orders->productsFieldsOneComp;
        $expected = 1;
        $actual   = count($products);
        $this->assertEquals($expected, $actual);

        $products = $orders->productsFieldsMultComp;
        $expected = 1;
        $actual   = count($products);
        $this->assertEquals($expected, $actual);

        $product  = $products->getFirst();
        $expected = 30;
        $actual   = $product->prd_id;
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: BelongsTo() - set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetBelongsTo(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

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

        $invoice            = new Invoices();
        $invoice->inv_id    = 70;
        $invoice->inv_title = uniqid('inv-');

        $invoice->customerMultipleFields = $customer;

        $actual = $invoice->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $invoice->inv_status_flag;
        $this->assertEquals($expected, $actual);

        $expected = 50;
        $actual   = $invoice->inv_cst_id;
        $this->assertEquals($expected, $actual);

        $expected = 0;
        $actual   = $invoice->getDirtyState();
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasMany() - set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasMany(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

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

        $invoice            = new Invoices();
        $invoice->inv_id    = 70;
        $invoice->inv_title = uniqid('inv-');

        $customer->InvoicesMultipleFields = [$invoice];
        $actual = $customer->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $invoice->inv_status_flag;
        $this->assertEquals($expected, $actual);

        $expected = 50;
        $actual   = $invoice->inv_cst_id;
        $this->assertEquals($expected, $actual);

        $expected = 0;
        $actual   = $invoice->getDirtyState();
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasOneThrough(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders              = OrdersMultiple::findFirst(10);
        $product             = new Products();
        $product->prd_name   = uniqid('prd', true);
        $product->prd_status_flag = 0;

        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $product             = new Products();
        $product->prd_name   = uniqid('prd2', true);
        $product->prd_status_flag = 10;

        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();
        $this->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $orders->singleProductFieldsMultComp = $product;
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasOneThrough() - set
     * Compound Primary Key Intermediate Relations
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasOneThroughComp(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders              = OrdersMultiple::findFirst(10);
        $product             = new Products();
        $product->prd_name   = uniqid('prd', true);
        $product->prd_status_flag = 0;

        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $product             = new Products();
        $product->prd_name   = uniqid('prd2', true);
        $product->prd_status_flag = 10;

        $orders->singleProductFieldsOneComp = $product;
        $actual = $orders->save();
        $this->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $orders->singleProductFieldsMultComp = $product;
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManyToMany() - set
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasManyToMany(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders              = OrdersMultiple::findFirst(10);
        $product1            = new Products();
        $product1->prd_name  = uniqid('prd1', true);
        $product1->prd_status_flag = 5;

        $product2            = new Products();
        $product2->prd_name  = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        $orders->productsFieldsOne = [$product1];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product1->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOne::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $orders->productsFieldsOne = [$product1, $product2];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product2->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOne::find();
        $expected     = 2;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $products = Products::find();
        $expected = 2;
        $actual   = $products->count();
        $this->assertEquals($expected, $actual);

        /**
         * Multiple Keys
         */
        $orders->productsFieldsMult = [$product1];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMult::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $orders->productsFieldsMult = [$product2];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMult::find();
        $expected     = 2;
        $actual       = $intermidiate->count();
        $this->assertEquals($expected, $actual);

        $orders->productsFieldsMult = [$product1, $product2];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMult::find();
        $expected     = 2;
        $actual       = $intermidiate->count();
        $this->assertEquals($expected, $actual);

        $products = $orders->getRelated('productsFieldsMult');
        $expected = 2;
        $actual   = count($products);
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManyToMany() - set with sync option
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17071
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasManyToManySyncOption(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigration            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigration->insert($orderId, $orderName, $orderStatus);

        $orders                    = OrdersMultiple::findFirst(10);
        $product1                  = new Products();
        $product1->prd_name        = uniqid('prd1', true);
        $product1->prd_status_flag = 5;

        $product2                  = new Products();
        $product2->prd_name        = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        // Assign two products -> two intermediate rows
        $orders->productsFieldsOneSync = [$product1, $product2];
        $this->assertTrue($orders->save());
        $this->assertEquals(2, count(OrdersProductsFieldsOne::find()));

        // Sync down to one product -> the other intermediate row is deleted
        $orders->productsFieldsOneSync = [$product1];
        $this->assertTrue($orders->save());
        $this->assertEquals(1, count(OrdersProductsFieldsOne::find()));

        // Both products still exist as records (only the link was removed)
        $this->assertEquals(2, Products::find()->count());

        // Assigning an empty array clears all links
        $orders->productsFieldsOneSync = [];
        $this->assertTrue($orders->save());
        $this->assertEquals(0, count(OrdersProductsFieldsOne::find()));
    }

    /**
     * Tests Phalcon\Mvc\Model :: setSync() chained override on a non-sync
     * relation, plus the wildcard enable.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17071
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasManyToManySetSyncMethod(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigration            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigration->insert($orderId, $orderName, $orderStatus);

        $orders                    = OrdersMultiple::findFirst(10);
        $product1                  = new Products();
        $product1->prd_name        = uniqid('prd1', true);
        $product1->prd_status_flag = 5;

        $product2                  = new Products();
        $product2->prd_name        = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        // Default (no sync) on productsFieldsOne: assignment is additive
        $orders->productsFieldsOne = [$product1, $product2];
        $this->assertTrue($orders->save());
        $this->assertEquals(2, count(OrdersProductsFieldsOne::find()));

        $orders->productsFieldsOne = [$product1];
        $this->assertTrue($orders->save());
        // Additive: product2 link survives
        $this->assertEquals(2, count(OrdersProductsFieldsOne::find()));

        // Now enable sync just for this save via setSync()
        $orders->productsFieldsOne = [$product1];
        $this->assertTrue($orders->setSync('productsFieldsOne')->save());
        // Synced: product2 link removed
        $this->assertEquals(1, count(OrdersProductsFieldsOne::find()));

        // Wildcard enable: assign only product2 then sync everything down to it
        $orders->productsFieldsOne = [$product2];
        $this->assertTrue($orders->setSync()->save());
        $this->assertEquals(1, count(OrdersProductsFieldsOne::find()));
    }

    /**
     * Tests Phalcon\Mvc\Model :: setSync("*", false) disables sync for a
     * relation configured with the `sync` option.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17071
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-04
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasManyToManySetSyncDisable(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigration            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigration->insert($orderId, $orderName, $orderStatus);

        $orders                    = OrdersMultiple::findFirst(10);
        $product1                  = new Products();
        $product1->prd_name        = uniqid('prd1', true);
        $product1->prd_status_flag = 5;

        $product2                  = new Products();
        $product2->prd_name        = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        // productsFieldsOneSync has 'sync' => true; disable it for this save
        $orders->productsFieldsOneSync = [$product1, $product2];
        $this->assertTrue($orders->save());
        $this->assertEquals(2, count(OrdersProductsFieldsOne::find()));

        $orders->productsFieldsOneSync = [$product1];
        $this->assertTrue($orders->setSync('*', false)->save());
        // Sync disabled for this save -> additive, product2 link survives
        $this->assertEquals(2, count(OrdersProductsFieldsOne::find()));
    }

    /**
     * Tests Phalcon\Mvc\Model :: hasManyToMany() - set
     * Compound Primary Key Intermediate Relations
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-16
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelSetHasManyToManyComp(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $orderId     = 10;
        $orderName   = uniqid('ord', true);
        $orderStatus = 5;

        $ordersMigragion            = new OrdersMigration($connection);
        $ordersProductsOneMigration = new OrdersProductsFieldsOneCompMigration($connection);
        $ordersProductsMultMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations         = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName, $orderStatus);

        $orders              = OrdersMultiple::findFirst(10);
        $product1            = new Products();
        $product1->prd_name  = uniqid('prd', true);
        $product1->prd_status_flag = 0;

        $orders->productsFieldsOneComp = [$product1];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product1->getDirtyState();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsOneComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $product2            = new Products();
        $product2->prd_name  = uniqid('prd2', true);
        $product2->prd_status_flag = 10;

        $orders->productsFieldsMultComp = [$product2];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $expected = 0;
        $actual   = $product2->getDirtyState();
        $this->assertEquals($expected, $actual);

        $products = Products::find();
        $expected = 2;
        $actual   = $products->count();
        $this->assertEquals($expected, $actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected     = 1;
        $actual       = count($intermidiate);
        $this->assertEquals($expected, $actual);

        $orders->productsFieldsMultComp = [$product1, $product2];
        $actual = $orders->save();
        $this->assertTrue($actual);

        $intermidiate = OrdersProductsFieldsMultComp::find();
        $expected     = 2;
        $actual       = $intermidiate->count();
        $this->assertEquals($expected, $actual);

        $products = $orders->getRelated('productsFieldsMultComp');
        $expected = 2;
        $actual   = count($products);
        $this->assertEquals($expected, $actual);
    }
}
