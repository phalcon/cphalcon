<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class ListTablesCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: listTables()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlListTables(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - listTables()");
        $I->skipTest("Need implementation");
        $expected = $this->getListTables();
        $I->assertEquals($expected, $this->connection->listTables());
        $I->assertEquals($expected, $this->connection->listTables($this->getSchemaName()));
    }

    /**
     * Returns the list of the tables in the database
     *
     * @return array
     */
    private function getListTables(): array
    {
        return [
            'albums',
            'artists',
            'childs',
            'customers',
            'dialect_table',
            'dialect_table_intermediate',
            'dialect_table_remote',
            'foreign_key_child',
            'foreign_key_parent',
            'identityless_requests',
            'issue12071_body',
            'issue12071_head',
            'issue_11036',
            'issue_1534',
            'issue_2019',
            'm2m_parts',
            'm2m_robots',
            'm2m_robots_parts',
            'package_details',
            'packages',
            'parts',
            'personas',
            'personnes',
            'ph_select',
            'prueba',
            'robots',
            'robots_parts',
            'songs',
            'stats',
            'stock',
            'subscriptores',
            'table_with_string_field',
            'tipo_documento',
            'users',
        ];
    }
}
