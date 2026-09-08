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

namespace Phalcon\Tests\Database\Mvc\Model\Resultset\Complex;

use Phalcon\Mvc\Model\Resultset\Complex;
use Phalcon\Mvc\Model\Row;
use Phalcon\Support\Helper\Str\DirFromFile;
use Phalcon\Talon\Talon;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Database\Mvc\Model\Resultset\ResultsetFixtureTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('phql')]
final class ConstructTest extends AbstractDatabaseTestCase
{
    use ResultsetFixtureTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
        $this->setDiService('modelsCacheStream');
        $this->seedResultsetFixture();

        $this->cleanCacheKey('test-resultset-complex');
    }

    protected function tearDown(): void
    {
        $this->cleanCacheKey('test-resultset-complex');

        parent::tearDown();
    }

    /**
     * A joined query builds a Complex resultset whose records are rows.
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexConstruct(): void
    {
        $resultset = $this->getResultset('complex');

        $this->assertInstanceOf(Complex::class, $resultset);
        $this->assertCount(4, $resultset);

        $resultset->rewind();

        $this->assertInstanceOf(Row::class, $resultset->current());
    }

    /**
     * A resultset read back from the cache still gives its records away - the
     * scenario of the report, where the second page load saw an empty array.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/17574
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-09-07
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testMvcModelResultsetComplexConstructFromCache(): void
    {
        $cache = $this->getService('modelsCache');

        $cache->set('test-resultset-complex', $this->getResultset('complex'));

        $cached = $cache->get('test-resultset-complex');

        $this->assertInstanceOf(Complex::class, $cached);
        $this->assertCount(4, $cached);
        $this->assertCount(4, $cached->toArray());
    }

    /**
     * Removes the stream cache file for a given cache key.
     */
    private function cleanCacheKey(string $key): void
    {
        $dirFromFile = new DirFromFile();
        $filePath    = Talon::settings()->outputPath('tests/cache/models/ph-strm/' . $dirFromFile($key) . $key);

        $this->safeDeleteFile($filePath);
    }
}
