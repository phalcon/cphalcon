<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

use Phalcon\Db\Adapter\Pdo\Postgresql;
use Phalcon\Db\Reference;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\Adapter\Pdo\Postgresql
 * Tests the \Phalcon\Db\Adapter\Pdo\Postgresql component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 * @package   Phalcon\Test\Unit\Db\Adapter\Pdo
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PostgresqlTest extends UnitTest
{
    /**
     * @var Postgresql
     */
    protected $connection;

    public function _before()
    {
        parent::_before();

        $this->connection = new Postgresql([
            'host'     => TEST_DB_POSTGRESQL_HOST,
            'username' => TEST_DB_POSTGRESQL_USER,
            'password' => TEST_DB_POSTGRESQL_PASSWD,
            'dbname'   => TEST_DB_POSTGRESQL_NAME,
            'port'     => TEST_DB_POSTGRESQL_PORT,
            'schema'   => TEST_DB_POSTGRESQL_SCHEMA
        ]);
    }

    /**
     * Tests Postgresql::describeReferences
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function testDescribeReferencesColumnsCount()
    {
        $this->specify(
            'Postgresql::describeReferences return wrong number of columns in Phalcon\Db\Reference',
            function() {
                $references = $this->connection->describeReferences("robots_parts", TEST_DB_POSTGRESQL_NAME);
                /** @var Reference $reference */
                foreach($references as $reference) {
                    expect($reference->getColumns())->count(1);
                }
            }
        );
    }
}