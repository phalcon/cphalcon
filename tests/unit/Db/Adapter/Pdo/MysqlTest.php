<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

use Phalcon\Db;
use Phalcon\Db\Reference;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Db\Adapter\Pdo\Mysql;

/**
 * \Phalcon\Test\Unit\Db\Adapter\Pdo\MysqlTest
 * Tests the \Phalcon\Db\Adapter\Pdo\Mysql component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Db\Adapter\Pdo
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class MysqlTest extends UnitTest
{
    /**
     * @var Mysql
     */
    protected $connection;

    public function _before()
    {
        parent::_before();

        $this->connection = new Mysql([
            'host'     => TEST_DB_MYSQL_HOST,
            'username' => TEST_DB_MYSQL_USER,
            'password' => TEST_DB_MYSQL_PASSWD,
            'dbname'   => TEST_DB_MYSQL_NAME,
            'port'     => TEST_DB_MYSQL_PORT,
            'charset'  => TEST_DB_MYSQL_CHARSET,
        ]);
    }

    /**
     * Tests Mysql::listTables
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-08-03
     */
    public function testListTables()
    {
        $this->specify(
            'List all tables on a database does not return correct result',
            function () {
                $expected = [
                    'albums',
                    'artists',
                    'childs',
                    'customers',
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
                    'subscriptores',
                    'tipo_documento',
                    'users',
                ];

                expect($this->connection->listTables())->equals($expected);
                expect($this->connection->listTables(TEST_DB_MYSQL_NAME))->equals($expected);
            }
        );
    }

    /**
     * Tests Mysql::describeReferences
     *
     * @author Wojciechj Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function testDescribeReferencesColumnsCount()
    {
        $this->specify(
            'The table references list contains wrong number of columns',
            function () {
                $references = $this->connection->describeReferences('robots_parts', TEST_DB_MYSQL_NAME);
                expect($references)->count(2);
                expect($this->connection->describeReferences('robots_parts', null))->count(2);

                /** @var Reference $reference */
                foreach ($references as $reference) {
                    expect($reference->getColumns())->count(1);
                }
            }
        );
    }

    /**
     * Tests Mysql::escapeIdentifier
     *
     * @author Sid Roberts <sid@sidroberts.co.uk>
     * @since  2016-11-19
     */
    public function testEscapeIdentifier()
    {
        $this->specify(
            'Identifiers are not properly escaped',
            function ($identifier, $expected) {
                $escapedIdentifier = $this->connection->escapeIdentifier($identifier);

                expect($escapedIdentifier)->equals($expected);
            },
            [
                "examples" => [
                    [
                        "identifier" => "robots",
                        "expected"   => "`robots`",
                    ],
                    [
                        "identifier" => ["schema", "robots"],
                        "expected"   => "`schema`.`robots`",
                    ],
                    [
                        "identifier" => "`robots`",
                        "expected"   => "```robots```",
                    ],
                    [
                        "identifier" => ["`schema`", "rob`ots"],
                        "expected"   => "```schema```.`rob``ots`",
                    ],
                ]
            ]
        );
    }
}
