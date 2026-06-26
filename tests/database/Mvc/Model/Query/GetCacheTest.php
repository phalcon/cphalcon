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
use Phalcon\Cache\CacheInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetCacheTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $migration = new InvoicesMigration(self::getConnection());
        $migration->insert(1, 1, 0, 'Title 1');

        // A fresh in-memory cache implementing Phalcon\Cache\CacheInterface.
        $adapterFactory = new AdapterFactory(new SerializerFactory());
        $this->container->setShared(
            'modelsCache',
            new Cache($adapterFactory->newInstance('memory'))
        );
    }

    /**
     * getCache() exposes the cache service used to store a cached resultset.
     *
     * Tests Phalcon\Mvc\Model\Query :: getCache()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryGetCache(): void
    {
        $manager = $this->container->get('modelsManager');

        $query = $manager->createQuery('SELECT * FROM ' . Invoices::class);
        $query->cache(['key' => 'query-get-cache-test']);
        $query->execute();

        $this->assertInstanceOf(CacheInterface::class, $query->getCache());
    }
}
