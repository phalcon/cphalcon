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
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Support\Collection;
use Phalcon\Tests\Fixtures\Migrations\CustomersMigration;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Customers;
use Phalcon\Tests\Models\CustomersDymanicUpdate;

class DynamicUpdateCest
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
     * Tests Phalcon\Mvc\Model :: save() With DynamicUpdate Enabled
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-11
     *
     * @issue https://github.com/phalcon/cphalcon/issues/16343
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function enableDynamicUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - DynamicUpdate System Wide Enabled');

        $connection = $I->getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->insert(90, 1, null, null);

        /**
         * Check system wide Dynamic update
         */
        $actual = ini_get('phalcon.orm.dynamic_update');
        $I->assertEquals("1", $actual);

        $collection = new Collection();
        $connection = $this->container->get('db');
        $manager = new Manager();
        $modelsManager = $this->container->get('modelsManager');
        $manager->attach('db:beforeQuery', function (Event $event) use ($connection, $collection) {
                $key = (string) $collection->count();
                $collection->set($key, $connection->getSQLVariables());
        });

        $connection->setEventsManager($manager);

        /**
         * New model
         * @var Customer
         */
        $customer = Customers::findFirst(['cst_id=:id:', 'bind' => ['id' => 90]]);
        $customer->cst_name_first = 'enableDynamicUpdate';

        $actual = $customer->save();
        $I->assertTrue($actual);

        $actual = $modelsManager->isUsingDynamicUpdate($customer);
        $I->assertTrue($actual);

        $collection->clear();

        $customer->cst_name_last = 'cst_test_lastName';

        $actual = $customer->save();
        $I->assertTrue($actual);

        $expected = 2;
        $actual = count($collection->get('0'));
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with DynamicUpdate Disabled
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-11
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function disableDynamicUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - DynamicUpdate Systeam Wide Disabled');
        $collection = new Collection();

        $connection = $this->container->get('db');
        $manager = new Manager();
        $modelsManager = $this->container->get('modelsManager');
        $manager->attach('db:beforeQuery', function (Event $event) use ($connection, $collection) {
                $key = (string) $collection->count();
                $collection->set($key, $connection->getSQLVariables());
        });

        $connection->setEventsManager($manager);

        /**
         * Disable system wide dynamic update
         */
        ini_set('phalcon.orm.dynamic_update', "0");

        /**
         * Check system wide Dynamic update
         */
        $actual = ini_get('phalcon.orm.dynamic_update');

        $I->assertEquals("0", $actual);

        /**
         * New model
         * @var Customer
         */
        $customer = Customers::findFirst(['cst_id=:id:', 'bind' => ['id' => 90]]);
        $customer->cst_name_first = 'disableDynamicUpdate';
        $actual = $customer->save();

        $I->assertTrue($actual);
        $actual = $modelsManager->isUsingDynamicUpdate($customer);
        $I->assertFalse($actual);

        $collection->clear();

        $customer->cst_name_last = 'cst_test_lastName';

        $actual = $customer->save();
        $I->assertTrue($actual);

        $expected = 4;
        $actual = count($collection->get('0'));
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Mvc\Model :: save() with DynamicUpdate Disabled Cherry pick
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-11
     *
     * @group  mysql
     * @group  pgsql
     * @group  sqlite
     */
    public function disabledCherryPickDynamicUpdate(DatabaseTester $I)
    {
        $I->wantToTest('Mvc\Model - DynamicUpdate Systeam Wide Disabled Cherry pick');

        $collection = new Collection();
        $connection = $this->container->get('db');
        $manager = new Manager();
        $modelsManager = $this->container->get('modelsManager');
        $manager->attach('db:beforeQuery', function (Event $event) use ($connection, $collection) {
                $key = (string) $collection->count();
                $collection->set($key, $connection->getSQLVariables());
        });

        $connection->setEventsManager($manager);

        /**
         * Disable system wide dynamic update
         */
        ini_set('phalcon.orm.dynamic_update', "0");

        /**
         * Check system wide Dynamic update
         */
        $actual = ini_get('phalcon.orm.dynamic_update');
        $I->assertEquals("0", $actual);

        /**
         * New model
         * @var CustomersDymanicUpdate
         */
        $customer = CustomersDymanicUpdate::findFirst(['cst_id=:id:', 'bind' => ['id' => 90]]);

        $actual = $modelsManager->isUsingDynamicUpdate($customer);
        $I->assertTrue($actual);

        $collection->clear();

        $customer->cst_name_first = 'disabledCherryPickDynamicUpdate';
        $actual = $customer->save();
        $I->assertTrue($actual);

        $expected = 2;
        $actual = count($collection->get('0'));
        $I->assertEquals($expected, $actual);
    }
}
