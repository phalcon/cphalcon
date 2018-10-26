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

class ColumnsBase
{
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
        $I->assertEquals($expected, $this->connection->describeColumns($table, $this->getDatabaseName()));
    }

    public function checkColumnsAsObject(\UnitTester $I)
    {
        $columns         = $this->getColumns();
        $expectedColumns = $this->getExpectedColumns();

        foreach ($expectedColumns as $index => $column) {
            $I->assertEquals($columns[$index]['_columnName'], $column->getName());
            $I->assertEquals($columns[$index]['_type'], $column->getType());
            $I->assertEquals($columns[$index]['_isNumeric'], $column->isNumeric());
            $I->assertEquals($columns[$index]['_size'], $column->getSize());
            $I->assertEquals($columns[$index]['_scale'], $column->getScale());
            $I->assertEquals($columns[$index]['_notNull'], $column->isNotNull());
            $I->assertEquals($columns[$index]['_unsigned'], $column->isUnsigned());
        }
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
        $I->assertEquals($expected, $this->connection->describeIndexes($table, $this->getDatabaseName()));
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
        $references = $this->connection->describeReferences($table, $this->getDatabaseName());
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
        $I->assertEquals($expected, $this->connection->describeReferences($table, $this->getDatabaseName()));
    }
}
