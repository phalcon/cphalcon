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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function cacheDir;

/**
 *
 * @group phql
 */
final class CacheTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return string[][]
     */
    public static function getValidSerializers(): array
    {
        return [
            /**
             * @todo igbinary is throwing a seg fault in the docker environment
             */
            //            [
            //                'Igbinary',
            //            ],
            [
                'Msgpack',
            ],
            [
                'Php',
            ],
        ];
    }

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * @dataProvider getValidSerializers
     *
     * @issue
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2021-05-06
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelQueryCache(
        string $serializer
    ): void {
        (new InvoicesMigration(self::getConnection()));

        $this->container->set(
            'modelsCache',
            function () use ($serializer) {
                // services: modelsCache
                $lifetime          = 60; // 1 min
                $serializerFactory = new SerializerFactory();
                $adapterFactory    = new AdapterFactory($serializerFactory);

                $options = [
                    'defaultSerializer' => $serializer,
                    'lifetime'          => $lifetime,
                    'storageDir'        => cacheDir('mvcModelQueryCache'),
                ];

                $adapter = $adapterFactory->newInstance('stream', $options);
                $cache   = new Cache($adapter);

                return $cache;
            }
        );

        $cache            = $this->container->get('modelsCache');
        $cacheKey         = 'uniqkey' . $serializer;
        $options['cache'] = [
            'key'      => $cacheKey,
            'lifetime' => 50,
        ];

        /**
         * Find all the invoices - should be 0
         */
        $result   = Invoices::find($options);
        $expected = 0;
        $actual   = $result->count();
        $this->assertEquals($expected, $actual);

        /**
         * Add a new invoice
         */
        $newInvoice                  = new Invoices();
        $newInvoice->inv_cst_id      = 1;
        $newInvoice->inv_status_flag = Invoices::STATUS_PAID;
        $newInvoice->inv_title       = 'not cached invoice';
        $newInvoice->inv_total       = 100;
        $newInvoice->inv_created_at  = '2020-09-09 09:09:09';
        $newInvoice->save();

        /**
         * Find all the invoices (using cache). This should be 0 again
         */
        $result   = Invoices::find($options);
        $expected = 0;
        $actual   = $result->count();
        $this->assertEquals($expected, $actual);

        /**
         * Find all the invoices without cache - This should be 1
         */
        $result   = Invoices::find();
        $expected = 1;
        $actual   = $result->count();
        $this->assertEquals($expected, $actual);

        /**
         * Delete the cached entry and query again - This should be 1
         */
        $cache->delete($cacheKey);

        $result   = Invoices::find($options);
        $expected = 1;
        $actual   = $result->count();
        $this->assertEquals($expected, $actual);

        /**
         * Delete the temporary record
         */
        Invoices::findFirst("inv_status_flag = " . Invoices::STATUS_PAID)
                ->delete()
        ;

        /**
         * Query again with cache - This should be 1
         */
        $result   = Invoices::find($options);
        $expected = 1;
        $actual   = $result->count();
        $this->assertEquals($expected, $actual);

        /**
         * Query again without cache - This should be 0
         */
        $result   = Invoices::find();
        $expected = 0;
        $actual   = $result->count();
        $this->assertEquals($expected, $actual);

        /**
         * Delete the cache key
         */
        $cache->delete($cacheKey);
    }
}
