<?php

namespace Phalcon\Test\Unit\Db\Dialect;

use Helper\DialectTrait;
use Phalcon\Test\Module\UnitTest;
use Phalcon\Db\Dialect\Postgresql;
use Helper\Dialect\PostgresqlTrait;

/**
 * \Phalcon\Test\Unit\Db\Dialect\PostgresqlTest
 * Tests the \Phalcon\Db\Dialect\Postgresql component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Db\Dialect
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class PostgresqlTest extends UnitTest
{
    use DialectTrait, PostgresqlTrait;

    /**
     * Tests Postgresql::getColumnList
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testColumnList()
    {
        $this->specify(
            'The getColumnList method does not return correct list of columns with escaped identifiers',
            function ($columns, $expected) {
                $dialect = new Postgresql();

                expect($dialect->getColumnList($columns))->equals($expected);
            },
            [
                'examples' => $this->getColumnList()
            ]
        );
    }

    /**
     * Tests Postgresql::getColumnDefinition
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testColumnDefinition()
    {
        $this->specify(
            'Unable to get the column name in PostgreSQL',
            function ($column, $expected) {
                $dialect = new Postgresql();
                $columns = $this->getColumns();

                expect($dialect->getColumnDefinition($columns[$column]))->equals($expected);
            },
            [
                'examples' => $this->getColumnDefinition()
            ]
        );
    }

    /**
     * Tests Postgresql::addColumn
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testAddColumns()
    {
        $this->specify(
            'The SQL generated to add a column to a table is invalid',
            function ($schema, $column, $expected) {
                $dialect = new Postgresql();
                $columns = $this->getColumns();

                expect($dialect->addColumn('table', $schema, $columns[$column]))->equals($expected);
            },
            [
                'examples' => $this->getAddColumns()
            ]
        );
    }

    /**
     * Tests Postgresql::dropTable
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDropTable()
    {
        $this->specify(
            'The SQL generated to drop a table is invalid',
            function ($schema, $ifExists, $expected) {
                $dialect = new Postgresql();

                expect($dialect->dropTable('table', $schema, $ifExists))->equals($expected);
            },
            [
                'examples' => $this->getDropTable()
            ]
        );
    }

    /**
     * Tests Postgresql::truncateTable
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testTruncateTable()
    {
        $this->specify(
            'The SQL generated to drop a table is invalid',
            function ($schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->truncateTable('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getTruncateTable()
            ]
        );
    }

    /**
     * Tests Postgresql::dropColumn
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDropColumn()
    {
        $this->specify(
            'The SQL generated to delete a column from a table is invalid',
            function ($schema, $column, $expected) {
                $dialect = new Postgresql();

                expect($dialect->dropColumn('table', $schema, $column))->equals($expected);
            },
            [
                'examples' => $this->getDropColumn()
            ]
        );
    }

    /**
     * Tests Postgresql::modifyColumn
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testModifyColumn()
    {
        $this->specify(
            'The SQL generated to modify a column in a table is invalid',
            function ($schema, $to, $fom, $expected) {
                $dialect = new Postgresql();
                $columns = $this->getColumns();

                expect($dialect->modifyColumn('table', $schema, $columns[$to], $columns[$fom]))->equals($expected);
            },
            [
                'examples' => $this->getModifyColumn()
            ]
        );
    }

    /**
     * Tests Postgresql::addIndex
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testAddIndex()
    {
        $this->specify(
            'The SQL generated to add an index to a table is incorrect',
            function ($schema, $index, $expected) {
                $dialect = new Postgresql();
                $indexes = $this->getIndexes();

                expect($dialect->addIndex('table', $schema, $indexes[$index]))->equals($expected);
            },
            [
                'examples' => $this->getAddIndex()
            ]
        );
    }

    /**
     * Tests Postgresql::dropIndex
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDropIndex()
    {
        $this->specify(
            'The SQL generated to delete an index from a table is incorrect',
            function ($schema, $index, $expected) {
                $dialect = new Postgresql();

                expect($dialect->dropIndex('table', $schema, $index))->equals($expected);
            },
            [
                'examples' => $this->getDropIndex()
            ]
        );
    }

    /**
     * Tests Postgresql::addPrimaryKey
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testAddPrimaryKey()
    {
        $this->specify(
            'The SQL generated to add the primary key to a table is incorrect',
            function ($schema, $index, $expected) {
                $dialect = new Postgresql();
                $indexes = $this->getIndexes();

                expect($dialect->addPrimaryKey('table', $schema, $indexes[$index]))->equals($expected);
            },
            [
                'examples' => $this->getAddPrimaryKey()
            ]
        );
    }

    /**
     * Tests Postgresql::dropPrimaryKey
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDropPrimaryKey()
    {
        $this->specify(
            'The SQL generated to delete primary key from a table is incorrect',
            function ($schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->dropPrimaryKey('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDropPrimaryKey()
            ]
        );
    }

    /**
     * Tests Postgresql::addForeignKey
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testAddForeignKey()
    {
        $this->specify(
            'The SQL generated to add an index to a table is incorrect',
            function ($schema, $reference, $expected) {
                $dialect = new Postgresql();
                $references = $this->getReferences();

                expect($dialect->addForeignKey('table', $schema, $references[$reference]))->equals($expected);
            },
            [
                'examples' => $this->getAddForeignKey()
            ]
        );
    }

    /**
     * Tests Postgresql::dropForeignKey
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDropForeignKey()
    {
        $this->specify(
            'The SQL generated to delete a foreign key from a table is incorrect',
            function ($schema, $key, $expected) {
                $dialect = new Postgresql();

                expect($dialect->dropForeignKey('table', $schema, $key))->equals($expected);
            },
            [
                'examples' => $this->getDropForeignKey()
            ]
        );
    }

    /**
     * Tests Postgresql::createView
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testCreateView()
    {
        $this->specify(
            'The SQL generated to create a view is incorrect',
            function ($definition, $schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->createView('test_view', $definition, $schema))->equals($expected);
            },
            [
                'examples' => $this->getCreateView()
            ]
        );
    }

    /**
     * Tests Postgresql::dropView
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDropView()
    {
        $this->specify(
            'The SQL generated to drop a view is incorrect',
            function ($schema, $ifExists, $expected) {
                $dialect = new Postgresql();

                expect($dialect->dropView('test_view', $schema, $ifExists))->equals($expected);
            },
            [
                'examples' => $this->getDropView()
            ]
        );
    }

    /**
     * Tests Postgresql::viewExists
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-02
     */
    public function testViewExists()
    {
        $this->specify(
            'The SQL generated to check existence of view is incorrect',
            function ($schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->viewExists('view', $schema))->equals($expected);
            },
            [
                'examples' => $this->getViewExists()
            ]
        );
    }

    /**
     * Tests Postgresql::listViews
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testListViews()
    {
        $this->specify(
            'The SQL generated to list all views of a schema or user is incorrect',
            function ($schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->listViews($schema))->equals($expected);
            },
            [
                'examples' => $this->getListViews()
            ]
        );
    }

    /**
     * Tests Postgresql::describeColumns
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testDescribeColumns()
    {
        $this->specify(
            'The SQL generated to describe a table is incorrect',
            function ($schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->describeColumns('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDescribeColumns()
            ]
        );
    }

    /**
     * Tests Postgresql::createSavepoint
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testCreateSavepoint()
    {
        $this->specify(
            'The SQL generated to create a new savepoint is incorrect',
            function () {
                $dialect = new Postgresql();

                expect($dialect->createSavepoint('PH_SAVEPOINT_1'))->equals('SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Postgresql::releaseSavepoint
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testReleaseSavepoint()
    {
        $this->specify(
            'The SQL generated to release a savepoint is incorrect',
            function () {
                $dialect = new Postgresql();
                expect($dialect->releaseSavepoint('PH_SAVEPOINT_1'))->equals('RELEASE SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Postgresql::rollbackSavepoint
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testRollbackSavepoint()
    {
        $this->specify(
            'The SQL generated to rollback a savepoint is incorrect',
            function () {
                $dialect = new Postgresql();
                expect($dialect->rollbackSavepoint('PH_SAVEPOINT_1'))->equals('ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Postgresql::supportsSavepoints
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testSupportsSavepoints()
    {
        $this->specify(
            'The platform does not support savepoints',
            function () {
                $dialect = new Postgresql();
                expect($dialect->supportsSavepoints())->true();
            }
        );
    }

    /**
     * Tests Postgresql::supportsReleaseSavepoints
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testSupportsReleaseSavepoints()
    {
        $this->specify(
            'The platform does not support releasing savepoints',
            function () {
                $dialect = new Postgresql();
                expect($dialect->supportsReleaseSavepoints())->true();
            }
        );
    }

    /**
     * Tests Postgresql::describeReferences
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-10-02
     */
    public function testDescribeReferences()
    {
        $this->specify(
            'The SQL generated to describe references is incorrect',
            function ($schema, $expected) {
                $dialect = new Postgresql();

                expect($dialect->describeReferences('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDescribeReferences()
            ]
        );
    }

    /**
     * Tests Postgresql::createTable
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2016-09-30
     */
    public function testCreateTable()
    {
        $this->specify(
            'The SQL generated to create a table is incorrect',
            function ($schema, $definition, $expected) {
                $dialect = new Postgresql();

                expect($dialect->createTable('table', $schema, $definition))->equals($expected);
            },
            [
                'examples' => $this->getCreateTable()
            ]
        );
    }
}
