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

use Phalcon\Config\Config;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
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
        $data    = $this->getPostgresqlData();
        $options = new Config($data);

        $this->runTests(Postgresql::class, $options, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group pgsql
     */
    public function testDbAdapterPdoFactoryLoadPgsqlArray(): void
    {
        $data = $this->getPostgresqlData();

        $this->runTests(Postgresql::class, $data, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryLoadSqlite(): void
    {
        $data    = $this->getSqliteData();
        $options = new Config($data);

        $this->runTests(Sqlite::class, $options, $data);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     *
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryLoadSqliteArray(): void
    {
        $data = $this->getSqliteData();

        $this->runTests(Sqlite::class, $data, $data);
    }

    private function getPostgresqlData(): array
    {
        return [
            'adapter' => 'postgresql',
            'options' => [
                'host'     => env('DATA_POSTGRES_HOST'),
                'username' => env('DATA_POSTGRES_USER'),
                'password' => env('DATA_POSTGRES_PASS'),
                'dbname'   => env('DATA_POSTGRES_NAME'),
                'port'     => (int) env('DATA_POSTGRES_PORT'),
            ],
        ];
    }

    private function getSqliteData(): array
    {
        return [
            'adapter' => 'sqlite',
            'options' => [
                'dbname' => env('DATA_SQLITE_NAME'),
            ],
        ];
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
