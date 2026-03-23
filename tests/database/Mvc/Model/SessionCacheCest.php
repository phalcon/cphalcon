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
use Phalcon\Storage\Adapter\Weak;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Migrations\InvoicesMigration;
use Phalcon\Tests\Fixtures\Migrations\ObjectsMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersMigration;
use Phalcon\Tests\Fixtures\Migrations\OrdersProductsMigration;
use Phalcon\Tests\Fixtures\Migrations\ProductsMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\Invoices;
use Phalcon\Tests\Models\Objects;
use Phalcon\Tests\Models\Orders;
use Phalcon\Tests\Models\Products;

use function uniqid;

/**
 * Class FindCest
 */
class SessionCacheCest
{
    use DiTrait;

    public function _before(DatabaseTester $I)
    {
        $this->setNewFactoryDefault();
        $this->setDatabase($I);
        ini_set('phalcon.orm.session_cache', '1');
        $modelsManager = $this->container->get('modelsManager');
        $cache = new Weak(new SerializerFactory());
        $modelsManager->setSessionCache($cache);
    }

    public function _after(DatabaseTester $I)
    {
        $this->container['db']->close();
        ini_set('phalcon.orm.session_cache', '0');
        $modelsManager = $this->container->get('modelsManager');
        $cache = new Weak(new SerializerFactory());
        $modelsManager->setSessionCache($cache);
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
    public function mvcModelFind(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - find()');

        /** @var PDO $connection */
        $connection = $I->getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);

        $data = Objects::find();

        $I->assertEquals(1, count($data));

        $record = $data[0];
        $I->assertEquals(1, $record->obj_id);
        $I->assertEquals('random data', $record->obj_name);

        $other = Objects::findFirst();

        $expected = spl_object_id($record);
        $actual = spl_object_id($other);
        $I->assertEquals($expected, $actual);
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
    public function mvcModelRelationsComplex(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - SessionCache Complex');


        $connection = $I->getConnection();

        $orderId    = 10;
        $orderName = uniqid('ord', true);
        $productId  = 20;
        $productName  = uniqid('prd', true);
        $quantity = 1;

        $ordersMigragion = new OrdersMigration($connection);
        $ordersProductsMigration = new OrdersProductsMigration($connection);
        $productsMigrations = new ProductsMigration($connection);

        $ordersMigragion->insert($orderId, $orderName);
        $productsMigrations->insert($productId, $productName);
        $ordersProductsMigration->insert($orderId, $productId, $quantity, 0, 0);

        $productId  = 30;
        $productName  = uniqid('prd-2-', true);
        $productsMigrations->insert($productId, $productName);
        $ordersProductsMigration->insert($orderId, $productId, $quantity);


        $order1 = Orders::findFirst(10);

        $products = $order1->products;
        $expected = 2;
        $actual = count($products);
        $I->assertEquals($expected, $actual);

        $productRelation = $products->getFirst();
        $productFind = Products::findFirst($productRelation->prd_id);
        $expected = spl_object_id($productRelation);
        $actual = spl_object_id($productFind);
        $I->assertEquals($expected, $actual);
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
    public function mvcModelRelationsSimple(DatabaseTester $I)
    {

        $I->wantToTest('Mvc\Model - SessionCache Simple');

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

        $customer1 = Customers::findFirst(50);

        $invoices = $customer1->getRelated('invoices');
        $actual = count($invoices);
        $expected = 2;
        $I->assertEquals($expected, $actual);

        $invoice1 = $invoices->getFirst();
        $invoice2 = Invoices::findFirst($invoice1->inv_id);
        $expected = spl_object_id($invoice1);
        $actual = spl_object_id($invoice2);
        $I->assertEquals($expected, $actual);

        $customer2 = $invoice1->customer;
        $expected = spl_object_id($customer1);
        $actual = spl_object_id($customer2);
        $I->assertEquals($expected, $actual);
    }
}
