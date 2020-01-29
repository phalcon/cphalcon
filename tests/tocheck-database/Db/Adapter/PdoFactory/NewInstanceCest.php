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

namespace Phalcon\Test\Integration\Db\Adapter\PdoFactory;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Adapter\Pdo\Mysql;
use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Adapter\Pdo\Sqlite;
use Phalcon\Db\Adapter\PdoFactory;

use function getOptionsPostgresql;
use function getOptionsSqlite;

class NewInstanceCest
{
    /**
     * Tests Phalcon\Db\Adapter\PdoFactory :: newInstance()
     *
     * @dataProvider getProviders
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-19
     */
    public function dbAdapterPdoFactoryNewInstance(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Adapter\PdoFactory - newInstance() - ' . $example[0]);

        $factory = new PdoFactory();
        $adapter = $factory->newInstance($example[1], $example[3]);

        $I->assertInstanceOf(
            $example[2],
            $adapter
        );
    }

    private function getProviders(): array
    {
        return [
            ['Mysql', 'mysql', Mysql::class, getOptionsMysql()],
            ['Postgresql', 'postgresql', Postgresql::class, getOptionsPostgresql()],
            ['Sqlite', 'sqlite', Sqlite::class, getOptionsSqlite()],
        ];
    }
}
