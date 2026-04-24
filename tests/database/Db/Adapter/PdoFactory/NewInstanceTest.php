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
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Adapter\PdoFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;

use function getOptionsMysql;
use function getOptionsPostgresql;
use function getOptionsSqlite;

final class NewInstanceTest extends AbstractDatabaseTestCase
{
    /**
     * Tests Phalcon\Db\Adapter\PdoFactory :: newInstance()
     *
     * @dataProvider getNewInstanceProvider
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-19
     * @group  mysql
     * @group sqlite
     */
    public function testDbAdapterPdoFactoryNewInstance(
        string $label,
        string $driver,
        string $expectedClass,
        array $options
    ): void {
        $factory = new PdoFactory();
        $adapter = $factory->newInstance($driver, $options);

        $this->assertInstanceOf($expectedClass, $adapter);
    }

    /**
     * @return array<array{0: string, 1: string, 2: string, 3: array}>
     */
    public static function getNewInstanceProvider(): array
    {
        return [
            ['Mysql', 'mysql', Mysql::class, getOptionsMysql()],
            ['Postgresql', 'postgresql', Postgresql::class, getOptionsPostgresql()],
            ['Sqlite', 'sqlite', Sqlite::class, getOptionsSqlite()],
        ];
    }
}
