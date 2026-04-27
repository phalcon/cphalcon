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

namespace Phalcon\Tests\Database\Db\Adapter\PdoFactory;

use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\FactoryTrait;

use function array_intersect_assoc;

final class LoadTest extends AbstractDatabaseTestCase
{
    use FactoryTrait;

    public function setUp(): void
    {
        $this->init();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group mysql
     */
    public function testDbAdapterPdoFactoryLoadMysql(): void
    {
        $options = $this->config->database;
        $data    = $options->toArray();

        $this->runTests(Mysql::class, $options, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group mysql
     */
    public function testDbAdapterPdoFactoryLoadMysqlArray(): void
    {
        $options = $this->arrayConfig['database'];
        $data    = $options;

        $this->runTests(Mysql::class, $options, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group pgsql
     */
    public function testDbAdapterPdoFactoryLoadPgsql(): void
    {
        $this->markTestSkipped('Need implementation');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group pgsql
     */
    public function testDbAdapterPdoFactoryLoadPgsqlArray(): void
    {
        $this->markTestSkipped('Need implementation');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryLoadSqlite(): void
    {
        $this->markTestSkipped('Need implementation');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group mysql
     */
    public function testDbAdapterPdoFactoryLoadSqliteArray(): void
    {
        $this->markTestSkipped('Need implementation');
    }

    /**
     * @param mixed $options
     * @param array $data
     */
    private function runTests(string $class, mixed $options, array $data): void
    {
        $factory = new PdoFactory();
        $adapter = $factory->load($options);

        $this->assertInstanceOf($class, $adapter);

        $expected = array_intersect_assoc(
            $adapter->getDescriptor(),
            $data['options']
        );

        $this->assertEquals($expected, $adapter->getDescriptor());
    }
}
