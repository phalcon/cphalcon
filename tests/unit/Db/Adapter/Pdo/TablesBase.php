<?php

/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

class TablesBase
{
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
        $I->assertEquals($expected, $this->connection->listTables($this->getDatabaseName()));
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
        $I->assertTrue($this->connection->tableExists($table, $this->getDatabaseName()));
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
            'table_type'      => 'BASE TABLE'
        ];

        $I->assertEquals($expected, $this->connection->tableOptions($table, $this->getDatabaseName()));
    }
}
