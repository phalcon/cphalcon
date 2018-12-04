<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Mysql;

use Helper\Db\Adapter\Pdo\MysqlTrait;
use Phalcon\Test\Unit\Db\Adapter\Pdo\TablesBase;

class TablesCest extends TablesBase
{
    use MysqlTrait;


    /**
     * Test the `tableOptions`
     *
     * @param \UnitTester $I
     * @since 2018-10-26
     */
    public function checkTableOptions(\UnitTester $I)
    {
        $table    = 'dialect_table';
        $expected = [
            'table_type'      => 'BASE TABLE',
            'auto_increment'  => '1',
            'engine'          => 'InnoDB',
            'table_collation' => 'utf8_general_ci',
            'table_type'      => 'BASE TABLE'
        ];

        $I->assertEquals($expected, $this->connection->tableOptions($table, $this->getDatabaseName()));
    }

    /**
     * Returns the list of the tables in the database
     *
     * @return array
     */
    protected function getListTables(): array
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
