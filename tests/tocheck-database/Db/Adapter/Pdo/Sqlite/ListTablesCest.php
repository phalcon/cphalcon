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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Sqlite;

use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class ListTablesCest
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
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: listTables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoSqliteListTables(IntegrationTester $I)
    {
        $connection = $this->getService('db');

        $expectedTables = [
            'COMPANY',
            'customers',
            'm2m_parts',
            'm2m_robots',
            'm2m_robots_parts',
            'parts',
            'personas',
            'personnes',
            'ph_select',
            'prueba',
            'robots',
            'robots_parts',
            'sqlite_sequence',
            'subscriptores',
            'table_with_string_field',
            'tipo_documento',
        ];

        $I->assertEquals(
            $expectedTables,
            $connection->listTables()
        );

        $I->assertEquals(
            $expectedTables,
            $connection->listTables('public')
        );
    }
}
