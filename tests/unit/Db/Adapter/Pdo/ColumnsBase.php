<?php

namespace Phalcon\Test\Unit\Db\Adapter\Pdo;

use Phalcon\Db\Column;
use Phalcon\Db\Index;
use Phalcon\Db\Reference;
use Phalcon\Db\Adapter\Pdo\Mysql;

class ColumnsBase
{
    protected $connection;

    protected $databaseName;

    /**
     * Test the `describeColumns`
     *
     * @param \UnitTester $I
     * @since 2018-10-26
     */
    public function checkColumns(\UnitTester $I)
    {
        $table = 'dialect_table';
        $expected = $this->getExpectedColumns();
        $I->assertEquals($expected, $this->connection->describeColumns($table));
        $I->assertEquals($expected, $this->connection->describeColumns($table, $this->databaseName));
    }

    /**
     * Test the `describeIndexes`
     *
     * @param \UnitTester $I
     * @since 2018-10-26
     */
    public function checkColumnIndexes(\UnitTester $I)
    {
        $table = 'dialect_table';
        $expected = $this->getExpectedIndexes();
        $I->assertEquals($expected, $this->connection->describeIndexes($table));
        $I->assertEquals($expected, $this->connection->describeIndexes($table, $this->databaseName));
    }

    /**
     * Test the `describeReferences` count
     *
     * @param \UnitTester $I
     * @since 2018-10-26
     */
    public function checkReferencesCount(\UnitTester $I)
    {
        $table      = 'dialect_table_intermediate';
        $references = $this->connection->describeReferences($table);
        $I->assertEquals(2, count($references));
        $references = $this->connection->describeReferences($table, $this->databaseName);
        $I->assertEquals(2, count($references));

        /** @var Reference $reference */
        foreach ($references as $reference) {
            $I->assertEquals(1, count($reference->getColumns()));
        }
    }

    /**
     * Test the `describeReferences`
     *
     * @param \UnitTester $I
     * @since 2018-10-26
     */
    public function checkReferences(\UnitTester $I)
    {
        $table    = 'dialect_table_intermediate';
        $expected = $this->getExpectedReferences();
        $I->assertEquals($expected, $this->connection->describeReferences($table));
        $I->assertEquals($expected, $this->connection->describeReferences($table, $this->databaseName));
    }
}
