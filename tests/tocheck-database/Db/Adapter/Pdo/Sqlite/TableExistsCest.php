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

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class TableExistsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiModelsManager();
        $this->setDiModelsMetadata();
        $this->setDiSqlite();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: tableExists()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteTableExists(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Sqlite - tableExists()');

        $connection = $this->getService('db');

        $I->assertTrue(
            $connection->tableExists('personas')
        );

        $I->assertFalse(
            $connection->tableExists('noexist')
        );

        $I->assertTrue(
            $connection->tableExists('personas', 'public')
        );

        $I->assertTrue(
            $connection->tableExists('personas', 'test')
        );
    }
}
