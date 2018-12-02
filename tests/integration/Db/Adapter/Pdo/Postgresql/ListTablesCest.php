<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Postgresql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\PostgresqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class ListTablesCest
{
    use DiTrait;
    use PostgresqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Postgresql :: listTables()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoPostgresqlListTables(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Postgresql - listTables()");
        $expected = [
            'customers',
            'foreign_key_child',
            'foreign_key_parent',
            'images',
            'parts',
            'personas',
            'personnes',
            'ph_select',
            'prueba',
            'robots',
            'robots_parts',
            'subscriptores',
            'table_with_string_field',
            'tipo_documento',
        ];
        $actual = $this->connection->listTables();
        $I->assertEquals($expected, $actual);

        $actual = $this->connection->listTables(env('DATA_POSTGRES_SCHEMA', 'public'));
        $I->assertEquals($expected, $actual);
    }
}
