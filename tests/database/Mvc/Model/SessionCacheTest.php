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
use Phalcon\Storage\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\ObjectsMigration;
use Phalcon\Tests\Support\Migrations\OrdersMigration;
use Phalcon\Tests\Support\Migrations\OrdersProductsFieldsMultCompMigration;
use Phalcon\Tests\Support\Migrations\ProductsMigration;
use Phalcon\Tests\Support\Models\OrdersMultiple;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\Objects;
use Phalcon\Tests\Support\Models\Products;

use function uniqid;

/**
 * Class FindCest
 */
class SessionCacheTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        ini_set('phalcon.orm.session_cache', '1');
        $modelsManager = $this->container->get('modelsManager');
        $cache = new Weak(new SerializerFactory());
        $modelsManager->setSessionCache($cache);
    }

    public function tearDown(): void
    {
        $this->tearDownDatabase();
        ini_set('phalcon.orm.session_cache', '0');
    }

    /**
     * Tests Phalcon\Mvc\Model :: find()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-23
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMvcModelFind(): void
    {
        /** @var PDO $connection */
        $connection = self::getPdoConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);

        $data = Objects::find();

        $this->assertEquals(1, count($data));

        $record = $data[0];
        $this->assertEquals(1, $record->obj_id);
        $this->assertEquals('random data', $record->obj_name);

        $other = Objects::findFirst();

        $expected = spl_object_id($record);
        $actual = spl_object_id($other);
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: SessionCache Complex
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-23
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMvcModelRelationsComplex(): void
    {
        $connection = self::getPdoConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $productId  = 20;
        $productName  = uniqid('prd', true);
        $quantity = 1;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsMigration = new OrdersProductsFieldsMultCompMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName);
        $productsMigrations->insert($productId, $productName);
        $ordersProductsMigration->insert($orderId, $productId, $quantity, 0, 0);

        $productId  = 30;
        $productName  = uniqid('prd-2-', true);
        $productsMigrations->insert($productId, $productName);
        $ordersProductsMigration->insert($orderId, $productId, $quantity);


        $order1 = OrdersMultiple::findFirst(10);

        $products = $order1->productsFieldsMultComp;
        $expected = 2;
        $actual = count($products);
        $this->assertEquals($expected, $actual);

        $productRelation = $products->getFirst();
        $productFind = Products::findFirst($productRelation->prd_id);
        $expected = spl_object_id($productRelation);
        $actual = spl_object_id($productFind);
        $this->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: SessionCache simple
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-23
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function testMvcModelRelationsSimple(): void
    {

        $connection = self::getPdoConnection();

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

        $customer1 = Customers::findFirst(50);

        $invoices = $customer1->getRelated('invoices');
        $actual = count($invoices);
        $expected = 2;
        $this->assertEquals($expected, $actual);

        $invoice1 = $invoices->getFirst();
        $invoice2 = Invoices::findFirst($invoice1->inv_id);
        $expected = spl_object_id($invoice1);
        $actual = spl_object_id($invoice2);
        $this->assertEquals($expected, $actual);

        $customer2 = $invoice1->customer;
        $expected = spl_object_id($customer1);
        $actual = spl_object_id($customer2);
        $this->assertEquals($expected, $actual);
    }
}
