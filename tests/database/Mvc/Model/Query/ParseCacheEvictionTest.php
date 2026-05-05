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

use PDO;
use Phalcon\Mvc\Model\Query;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use ReflectionProperty;

use function count;

/**
 * @issue  https://github.com/phalcon/cphalcon/issues/16955
 *
 * @group phql
 */
final class ParseCacheEvictionTest extends AbstractDatabaseTestCase
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
     * Tests that internalPhqlCache evicts oldest entries when exceeding 1024.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryParseCacheEviction(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        Query::clean();

        $initialCache = $this->getStaticCacheCount();

        $this->assertSame(
            0,
            $initialCache,
            'Cache should be empty after clean()'
        );

        $uniqueConditions = 1100;
        for ($i = 1; $i <= $uniqueConditions; $i++) {
            $migration->insert($i, null, 0, 'title-' . $i);

            Invoices::findFirst(
                [
                    'conditions' => 'inv_id = ' . $i,
                ]
            );
        }

        $cacheCount = $this->getStaticCacheCount();

        $this->assertLessThan(
            $uniqueConditions,
            $cacheCount,
            'Cache count (' . $cacheCount . ') should be less than unique queries (' . $uniqueConditions . ')'
        );

        $this->assertLessThanOrEqual(
            1025,
            $cacheCount,
            'Cache count (' . $cacheCount . ') should not exceed 1025 (1024 threshold + 1 new entry)'
        );

        Query::clean();
    }

    /**
     * Tests that cache eviction preserves the most recent entries.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-05
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testMvcModelQueryParseCacheEvictionPreservesRecentEntries(): void
    {
        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        Query::clean();

        for ($i = 1; $i <= 1100; $i++) {
            $migration->insert($i, null, 0, 'title-' . $i);
        }

        for ($i = 1; $i <= 1100; $i++) {
            Invoices::findFirst(
                [
                    'conditions' => 'inv_id = ' . $i,
                ]
            );
        }

        $cacheKeys   = $this->getStaticCacheKeys();
        $cacheCount  = count($cacheKeys);
        $lastKey     = end($cacheKeys);

        $this->assertGreaterThan(
            0,
            $lastKey,
            'Last cache key should be a valid ID from the most recent entries'
        );

        $this->assertLessThanOrEqual(
            1025,
            $cacheCount,
            'Cache should be capped near 1024 entries'
        );

        Query::clean();
    }

    private function getStaticCacheCount(): int
    {
        return count($this->getStaticCache());
    }

    private function getStaticCacheKeys(): array
    {
        $cache = $this->getStaticCache();

        return $cache !== null ? array_keys($cache) : [];
    }

    private function getStaticCache(): ?array
    {
        $ref = new ReflectionProperty(Query::class, 'internalPhqlCache');
        $ref->setAccessible(true);

        return $ref->getValue();
    }
}
