<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo\Mysql;

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Adapter\Pdo\Mysql;

class TablesCest
{
    /**
     * @var Mysql
     */
    protected $connection;

    public function _before(\UnitTester $I)
    {
        try {
            $this->connection = new Mysql([
                'host'     => TEST_DB_MYSQL_HOST,
                'username' => TEST_DB_MYSQL_USER,
                'password' => TEST_DB_MYSQL_PASSWD,
                'dbname'   => TEST_DB_MYSQL_NAME,
                'port'     => TEST_DB_MYSQL_PORT,
                'charset'  => TEST_DB_MYSQL_CHARSET,
            ]);
        } catch (\PDOException $e) {
            throw new SkippedTestError("Unable to connect to the database: " . $e->getMessage());
        }
    }

    /**
     * Test the `listTables`
     *
     * @param \UnitTester $I
     * @since  2016-08-03
     */
    public function checkListTables(\UnitTester $I)
    {
        $expected = $this->getListTables();
        $I->assertEquals($expected, $this->connection->listTables());
        $I->assertEquals($expected, $this->connection->listTables(TEST_DB_MYSQL_NAME));
    }

    /**
     * Test the `tableExists`
     *
     * @param \UnitTester $I
     * @since 2018-10-26
     */
    public function checkTableExists(\UnitTester $I)
    {
        $table = 'dialect_table';
        $I->assertTrue($this->connection->tableExists($table));
        $I->assertFalse($this->connection->tableExists('unknown-table'));
        $I->assertTrue($this->connection->tableExists($table, TEST_DB_MYSQL_NAME));
        $I->assertFalse($this->connection->tableExists('unknown-table', 'unknown-db'));
    }

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
            'table_type' => 'BASE TABLE'
        ];

        $I->assertEquals($expected, $this->connection->tableOptions($table, TEST_DB_MYSQL_NAME));
    }

    /**
     * Returns the list of the tables in the database
     *
     * @return array
     */
    public function getListTables(): array
    {
        return [
            'albums',
            'artists',
            'childs',
            'customers',
            'dialect_table',
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
