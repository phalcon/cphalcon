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

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->init();
    }

    /**
     * Tests Phalcon\Db\Adapter\PdoFactory :: load()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     * @group  mysql
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryLoad(): void
    {
        $options = $this->config->database;
        $data    = $options->toArray();

        $this->runTests($options, $data);
    }

    /**
     * Tests Phalcon\Db\Adapter\PdoFactory :: load() - array
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     * @group  mysql
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryLoadArray(): void
    {
        $options = $this->arrayConfig['database'];
        $data    = $options;

        $this->runTests($options, $data);
    }

    /**
     * @param mixed $options
     * @param array $data
     */
    private function runTests(mixed $options, array $data): void
    {
        $factory = new PdoFactory();
        $adapter = $factory->load($options);

        $this->assertInstanceOf(Mysql::class, $adapter);

        $expected = array_intersect_assoc(
            $adapter->getDescriptor(),
            $data['options']
        );

        $this->assertEquals($expected, $adapter->getDescriptor());
    }
}
