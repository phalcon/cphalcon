<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Database\Mvc\Model\Resultset;

use Phalcon\Cache\AdapterFactory;
use Phalcon\Cache\Cache;
use Phalcon\Events\Manager;
use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Storage\SerializerFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use PHPUnit\Framework\Attributes\DataProvider;
use PHPUnit\Framework\Attributes\Group;

use function uniqid;

#[Group('phql')]
final class SerializeTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->setDiService('phpSerializer');
        $this->seedResultsetFixture();
    }

    /**
     * The resultset shapes that a cached query returns, and their row count.
     *
     * @return array<string, array{0: string, 1: int}>
     */
    public static function getCachedExamples(): array
    {
        return [
            'simple'  => ['simple', 3],
            'complex' => ['complex', 4],
        ];
    }

    /**
     * Every resultset shape serializes to a non-empty string.
     *
     * @return array<string, array{0: string}>
     */
    public static function getExamples(): array
    {
        return [
            'simple'  => ['simple'],
            'complex' => ['complex'],
            'empty'   => ['empty'],
        ];
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getExamples')]
    public function testMvcModelResultsetSerialize(string $type): void
    {
        $resultset = $this->getResultset($type);

        $serialized = $resultset->serialize();

        $this->assertIsString($serialized);
        $this->assertNotEmpty($serialized);
    }

    /**
     * The serialized data of a resultset does not include its cache. A cache
     * that cannot be serialized (here, the events manager holds a closure;
     * the Redis adapter holds a connection) does not stop the resultset from
     * going into the cache. A resultset from the cache has no cache.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17766
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-21
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    #[DataProvider('getCachedExamples')]
    public function testMvcModelResultsetSerializeCacheNotIncluded(string $type, int $count): void
    {
        $eventsManager = new Manager();
        $eventsManager->attach(
            'cache',
            static function (): void {
            }
        );

        $cache = new Cache((new AdapterFactory(new SerializerFactory()))->newInstance('memory'));
        $cache->setEventsManager($eventsManager);
        $this->container->setShared('modelsCache', $cache);

        $key   = uniqid('resultset-');
        $fresh = $this->getCachedResultset($type, $key);

        $this->assertSame($cache, $fresh->getCache());
        $this->assertCount($count, $fresh);
        $this->assertNotEmpty($fresh->serialize());

        $cached = $this->getCachedResultset($type, $key);

        $this->assertNull($cached->getCache());
        $this->assertCount($count, $cached);
    }

    /**
     * Runs the query of the resultset shape with the cache key.
     */
    private function getCachedResultset(string $type, string $key): ResultsetInterface
    {
        if ('complex' === $type) {
            return Customers::query()
                ->columns(
                    [
                        Customers::class . '.*',
                        'invoice.*',
                    ]
                )
                ->leftJoin(
                    Invoices::class,
                    'invoice.inv_cst_id = ' . Customers::class . '.cst_id',
                    'invoice'
                )
                ->cache(['key' => $key])
                ->execute();
        }

        return Invoices::find(['cache' => ['key' => $key]]);
    }
}
