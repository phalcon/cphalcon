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

namespace Phalcon\Tests\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use PDOException;
use Phalcon\Db\Adapter\Pdo\Mysql;

class ListTablesCest
{
    /**
     * @var Mysql
     */
    protected $connection;

    public function _before(IntegrationTester $I)
    {
        try {
            $this->connection = new Mysql(
                [
                    'host'     => env('DATA_MYSQL_HOST'),
                    'username' => env('DATA_MYSQL_USER'),
                    'password' => env('DATA_MYSQL_PASS'),
                    'dbname'   => env('DATA_MYSQL_NAME'),
                    'port'     => env('DATA_MYSQL_PORT'),
                    'charset'  => env('DATA_MYSQL_CHARSET'),
                ]
            );
        } catch (PDOException $e) {
            $I->skipTest(
                'Unable to connect to the database: ' . $e->getMessage()
            );
        }
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: listTables()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-08-03
     */
    public function dbAdapterPdoMysqlListTables(IntegrationTester $I)
    {
        $I->wantToTest('Db\Adapter\Pdo\Mysql - listTables()');

        $expected = [
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
            'tiny_int_test',
            'tipo_documento',
            'users',
        ];


        $I->assertEquals(
            $expected,
            $this->connection->listTables()
        );


        $dbName = env('DATA_MYSQL_NAME', 'phalcon_test');

        $I->assertEquals(
            $expected,
            $this->connection->listTables($dbName)
        );
    }
}
