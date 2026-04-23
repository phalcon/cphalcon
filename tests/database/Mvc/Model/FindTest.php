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
use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Db\RawValue;
use Phalcon\Mvc\Model\Exception;
use Phalcon\Mvc\Router;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\CustomersMigration;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Migrations\ObjectsMigration;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\Objects;
use Phalcon\Tests\Support\Traits\DiTrait;

use function getOptionsRedis;
use function ob_end_clean;
use function ob_get_contents;
use function ob_start;
use function outputDir;
use function sleep;
use function uniqid;
use function var_dump;

/**
 *
 * @group phql
 */
final class FindTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFind(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);

        $data = Objects::find();

        $this->assertEquals(1, count($data));

        $record = $data[0];
        $this->assertEquals(1, $record->obj_id);
        $this->assertEquals('random data', $record->obj_name);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-08-02
     *
     * @group mysql
     */
    public function testMvcModelFindDeprecationWarning(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);
        $migration->insert(2, 'random data 2', 1);
        $migration->insert(4, 'random data 4', 1);

        /**
         * Calling `findFirst()` in the router callable will produce
         * a deprecation warning. If so, this test will fail.
         */

        $this->container->set(
            'router',
            function () {
                var_dump('inside callable');
                $results = Objects::find();
                var_dump($results->toArray());

                return new Router();
            }
        );

        ob_start();
        $router = $this->container->get('router');
        $actual = ob_get_contents();
        ob_end_clean();

        $expected = 'inside callable';
        $this->assertStringContainsString($expected, $actual);
        $expected = 'Deprecated';
        $this->assertStringNotContainsString($expected, $actual);
        $expected = 'Use of "static" in callables in deprecated';
        $this->assertStringNotContainsString($expected, $actual);
    }

    /**
     * @issue  15439
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-05-25
     *
     * @group mysql
     */
    public function testMvcModelFindPrivatePropertyWithRedisCache(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'Test', 101);

        $cacheKey = uniqid('redis-');

        /**
         * Find without models cache
         */
        /** @var iterable $original */
        $original = Invoices::find(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 1,
                ],
            ]
        );

        $this->assertCount(1, $original);

        $record = $original[0];
        $actual = $record->getIsActive();

        $this->assertTrue($actual);

        // Models Cache setup
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);
        $adapter           = $adapterFactory->newInstance('redis', getOptionsRedis());
        $cache             = new Cache($adapter);
        $this->container->setShared('modelsCache', $cache);

        /**
         * Find it - so that we can use the models cache now
         */
        /** @var iterable $cached */
        $cached = Invoices::find(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 1,
                ],
                'cache'      => [
                    'key'      => $cacheKey,
                    'lifetime' => 60,
                ],
            ]
        );

        $this->assertCount(1, $cached);

        $record = $cached[0];
        $actual = $record->getIsActive();
        $this->assertTrue($actual);

        /**
         * Delete the record just in case to ensure we get it from the cache
         */
        $result = $original->delete();
        $this->assertNotFalse($result);

        /**
         * Ensure we do not have anything in the db
         */
        /** @var iterable $original */
        $original = Invoices::find(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 1,
                ],
            ]
        );

        $this->assertCount(0, $original);

        /**
         * Finally get it back from the cache
         */
        /** @var iterable $cached */
        $cached = Invoices::find(
            [
                'conditions' => 'inv_id = :inv_id:',
                'bind'       => [
                    'inv_id' => 1,
                ],
                'cache'      => [
                    'key'      => $cacheKey,
                    'lifetime' => 60,
                ],
            ]
        );

        $this->assertCount(1, $cached);

        $record = $cached[0];
        $actual = $record->getIsActive();
        $this->assertTrue($actual);

        /**
         * delete the cached entry
         */
        $result = $cache->delete($cacheKey);
        $this->assertTrue($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-17
     *
     * @group mysql
     */
    public function testMvcModelFindResultsetSecondIteration(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();

        $customersMigration = new CustomersMigration($connection);
        $customersMigration->clear();
        $customersMigration->insert(
            1,
            1,
            uniqid('cust-', true),
            uniqid('cust-', true)
        );
        $customersMigration->insert(
            2,
            0,
            uniqid('cust-', true),
            uniqid('cust-', true)
        );

        /** @var iterable $customers */
        $customers = Customers::find();

        $this->assertCount(2, $customers);

        /**
         * First iteration
         *
         * @var Customers $customer
         */
        foreach ($customers as $customer) {
            $this->assertNotNull(
                $customer->getId()
            );

            $this->assertIsNumeric(
                $customer->getId()
            );
        }

        /**
         * Second iteration
         *
         * @var Customers $secondCustomer
         */
        foreach ($customers as $secondCustomer) {
            $this->assertNotNull(
                $secondCustomer->getId()
            );

            $this->assertIsNumeric(
                $secondCustomer->getId()
            );
        }
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindWithCache(): void
    {
        $file = outputDir('data-/my/-c/ac/my-cache');
        $this->safeDeleteFile($file);

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);

        $options = [
            'defaultSerializer' => 'Json',
            'storageDir'        => outputDir(),
            'lifetime'          => 172800,
            'prefix'            => 'data-',
        ];

        // Models Cache setup
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);
        $adapter           = $adapterFactory->newInstance('stream', $options);
        $cache             = new Cache($adapter);

        $this->container->setShared('modelsCache', $cache);

        /**
         * Get the records (should cache the resultset)
         */
        $data = Objects::find(
            [
                'cache' => [
                    'key' => 'my-cache',
                ],
            ]
        );

        /**
         * See the file created
         */
        $this->assertFileExists($file);

        $this->assertEquals(1, count($data));

        $record = $data[0];
        $this->assertEquals(1, $record->obj_id);
        $this->assertEquals('random data', $record->obj_name);

        /**
         * Get the models cache
         */
        $modelsCache = $this->container->get('modelsCache');

        $exists = $modelsCache->has('my-cache');
        $this->assertTrue($exists);

        /**
         * Get the data now from the cache
         */
        $data = $modelsCache->get('my-cache');

        $this->assertEquals(1, count($data));

        $record = $data[0];
        $this->assertEquals(1, $record->obj_id);
        $this->assertEquals('random data', $record->obj_name);
    }

    /**
     * @issue 16696
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-02-01
     *
     * @group mysql
     */
    public function testMvcModelFindWithCacheLifetimeFromCacheService(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);

        $options = [
            'defaultSerializer' => 'Json',
            'lifetime'          => 2,
            'prefix'            => 'data-',
        ];

        /**
         * Models Cache setup. Lifetime is 2 seconds
         */
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);
        $adapter           = $adapterFactory->newInstance('apcu', $options);
        $cache             = new Cache($adapter);

        $this->container->setShared('modelsCache', $cache);

        /**
         * Get the records (should cache the resultset)
         */
        $data = Objects::find(
            [
                'cache' => [
                    'key' => 'my-cache',
                ],
            ]
        );

        $this->assertEquals(1, count($data));

        $record = $data[0];
        $this->assertEquals(1, $record->obj_id);
        $this->assertEquals('random data', $record->obj_name);

        /**
         * Get the models cache
         */
        $modelsCache = $this->container->get('modelsCache');

        $exists = $modelsCache->has('my-cache');
        $this->assertTrue($exists);

        /**
         * Wait for 3 seconds for the cache to expire
         */
        sleep(3);

        /**
         * Get the data now from the cache - expired
         */
        $data = $modelsCache->get('my-cache');
        $this->assertNull($data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-05-10
     *
     * @group mysql
     */
    public function testMvcModelFindWithCacheException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            "Cache service must be an object implementing " .
            "Phalcon\Cache\CacheInterface"
        );

        $options = [
            'storageDir' => outputDir(),
            'lifetime'   => 172800,
            'prefix'     => 'data-',
        ];

        // Models Cache setup
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);
        $adapter           = $adapterFactory->newInstance('stream', $options);

        $this->container->setShared('modelsCache', $adapter);

        Objects::find(
            [
                'cache' => [
                    'key' => 'my-cache',
                ],
            ]
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-06-30
     *
     * @group mysql
     */
    public function testMvcModelFindWithSpecificColumn(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);
        $migration->insert(2, 'random data 2', 1);
        $migration->insert(4, 'random data 4', 1);

        /**
         * Get the records (should cache the resultset)
         */
        $data = Objects::find(
            [
                'columns'    => 'obj_id',
                'conditions' => 'obj_id IN ({ids:array})',
                'bind'       => ['ids' => [1, 2, 3]],
            ]
        );

        $this->assertEquals(2, count($data));
        $this->assertEquals(1, $data[0]->obj_id);
        $this->assertEquals(2, $data[1]->obj_id);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-08-02
     *
     * @group mysql
     */
    public function testMvcModelFindWithCacheOptionsLifetimePriorityOverCacheService(): void
    {
        $connection = self::getConnection();
        $migration  = new ObjectsMigration($connection);
        $migration->insert(1, 'random data', 1);

        $options = [
            'defaultSerializer' => 'Json',
            'lifetime'          => 2,
            'prefix'            => 'data-',
        ];

        /**
         * Models Cache setup. Adapter's lifetime is 2 seconds
         */
        $serializerFactory = new SerializerFactory();
        $adapterFactory    = new AdapterFactory($serializerFactory);
        $adapter           = $adapterFactory->newInstance('apcu', $options);
        $cache             = new Cache($adapter);

        $this->container->setShared('modelsCache', $cache);

        /**
         * Find records with lifetime 5 sec
         */
        $data = Objects::find(
            [
                'cache' => [
                    'key'      => 'my-cache',
                    'lifetime' => 5,
                ],
            ]
        );

        $this->assertEquals(1, count($data));

        $record = $data[0];
        $this->assertEquals(1, $record->obj_id);
        $this->assertEquals('random data', $record->obj_name);

        /**
         * Get the models cache
         */
        $modelsCache = $this->container->get('modelsCache');

        $exists = $modelsCache->has('my-cache');
        $this->assertTrue($exists);

        /**
         * Wait for 3 seconds - cache should still be there (lifetime is 5 sec)
         */
        sleep(3);

        $data = $modelsCache->get('my-cache');
        $this->assertNotNull($data);

        /**
         * Wait extra 3 seconds - now cache should be expired (total 6 > 5 sec)
         */
        sleep(3);

        $data = $modelsCache->get('my-cache');
        $this->assertNull($data);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16350
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-23
     *
     * @group mysql
     */
    public function testMvcModelFindWithRawValueBind(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, null, 1, 'raw-value-one', 100, '2000-01-01 00:00:00');
        $migration->insert(2, null, 1, 'raw-value-two', 200, '2000-06-01 00:00:00');
        $migration->insert(3, null, 0, 'raw-value-three', 50, '2000-01-01 00:00:00');

        $invoices = Invoices::find(
            [
                'conditions' => 'inv_created_at <= :date: AND inv_status_flag = :status:',
                'bind'       => [
                    'date'   => new RawValue('NOW()'),
                    'status' => 1,
                ],
            ]
        );

        $this->assertNotNull($invoices);
        $this->assertCount(2, $invoices);
    }
}
