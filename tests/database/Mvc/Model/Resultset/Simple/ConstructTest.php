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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Simple;

use PDO;
use Phalcon\Mvc\Model\Resultset\Simple;
use Phalcon\Storage\Exception;
use Phalcon\Support\Helper\Str\DirFromFile;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;

use function cacheModelsDir;

/**
 *
 * @group phql
 */
final class ConstructTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        try {
            $this->setNewFactoryDefault();
        } catch (Exception $e) {
            $this->fail($e->getMessage());
        }

        $this->setDatabase();
        $this->setDiService('modelsCacheStream');

        /** @var PDO $connection */
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 0, 'Invoice One');
        $migration->insert(2, 1, 0, 'Invoice Two');
        $migration->insert(3, 1, 0, 'Invoice Three');

        // Clean up any leftover cache files from previous runs
        $this->cleanCacheKey('test-resultset');
    }

    /**
     * @return void
     */
    public function tearDown(): void
    {
        $this->cleanCacheKey('test-resultset');
        $this->tearDownDatabase();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-27
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelResultsetSimpleConstructCompletePhql(): void
    {
        $cache   = $this->getService('modelsCache');
        $manager = $this->getService('modelsManager');

        $dirFromFile = new DirFromFile();
        $filePath    = cacheModelsDir() . 'ph-strm/' . $dirFromFile('test-resultset');

        $invoices = $manager->executeQuery('SELECT * FROM ' . Invoices::class);

        $this->assertInstanceOf(Simple::class, $invoices);
        $this->assertCount(3, $invoices);
        $this->assertEquals(3, $invoices->count());

        $cache->set('test-resultset', $invoices);

        $this->assertTrue(
            file_exists($filePath . 'test-resultset')
        );

        $invoices = $cache->get('test-resultset');

        $this->assertInstanceOf(Simple::class, $invoices);
        $this->assertCount(3, $invoices);
        $this->assertEquals(3, $invoices->count());

        $this->assertTrue(
            $cache->clear()
        );

        $this->assertFalse(
            file_exists($filePath . 'test-resultset')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-27
     *
     * @group mysql
     * @group sqlite
     */
    public function testMvcModelResultsetSimpleConstructIncompletePhql(): void
    {
        $cache   = $this->getService('modelsCache');
        $manager = $this->getService('modelsManager');

        $dirFromFile = new DirFromFile();
        $filePath    = cacheModelsDir() . 'ph-strm/' . $dirFromFile('test-resultset');

        $invoices = $manager->executeQuery('SELECT inv_id FROM ' . Invoices::class);

        $this->assertInstanceOf(Simple::class, $invoices);
        $this->assertCount(3, $invoices);
        $this->assertEquals(3, $invoices->count());

        $cache->set('test-resultset', $invoices);

        $this->assertTrue(
            file_exists($filePath . 'test-resultset')
        );

        $invoices = $cache->get('test-resultset');

        $this->assertInstanceOf(Simple::class, $invoices);
        $this->assertCount(3, $invoices);
        $this->assertEquals(3, $invoices->count());

        $cache->delete('test-resultset');

        $this->assertFalse(
            file_exists($filePath . 'test-resultset')
        );
    }

    /**
     * Removes the stream cache file for a given cache key.
     *
     * @param string $key
     *
     * @return void
     */
    private function cleanCacheKey(string $key): void
    {
        $dirFromFile = new DirFromFile();
        $filePath    = cacheModelsDir() . 'ph-strm/' . $dirFromFile($key) . $key;

        $this->safeDeleteFile($filePath);
    }
}
