<?php

namespace Phalcon\Test\Unit\Db\Dialect;

use Helper\DialectTrait;
use Phalcon\Db\Exception;
use Phalcon\Db\Dialect\Sqlite;
use Helper\Dialect\SqliteTrait;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\Dialect\SqliteTest
 * Tests the \Phalcon\Db\Dialect\Sqlite component
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
class SqliteTest extends UnitTest
{
    use DialectTrait, SqliteTrait;

    /**
     * Tests Sqlite::getColumnList
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function columnList()
    {
        $this->specify(
            'The getColumnList method does not return correct list of columns with escaped identifiers',
            function ($columns, $expected) {
                $dialect = new Sqlite();

                expect($dialect->getColumnList($columns))->equals($expected);
            },
            [
                'examples' => $this->getColumnList()
            ]
        );
    }

    /**
     * Tests Sqlite::getColumnDefinition
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function columnDefinition()
    {
        $this->specify(
            'Unable to get the column name in Sqlite',
            function ($column, $expected) {
                $dialect = new Sqlite();
                $columns = $this->getColumns();

                expect($dialect->getColumnDefinition($columns[$column]))->equals($expected);
            },
            [
                'examples' => $this->getColumnDefinition()
            ]
        );
    }

    /**
     * Tests Sqlite::addColumn
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function addColumns()
    {
        $this->specify(
            'The SQL generated to add a column to a table is invalid',
            function ($schema, $column, $expected) {
                $dialect = new Sqlite();
                $columns = $this->getColumns();

                expect($dialect->addColumn('table', $schema, $columns[$column]))->equals($expected);
            },
            [
                'examples' => $this->getAddColumns()
            ]
        );
    }

    /**
     * Tests Sqlite::modifyColumn
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function modifyColumn()
    {
        $this->specify(
            'The SQL generated to modify a column in a table is invalid',
            function () {
                $dialect = new Sqlite();
                $columns = $this->getColumns();

                $dialect->modifyColumn('table', null, $columns['column1']);
            },
            [
                'throws' => [Exception::class, 'Altering a DB column is not supported by SQLite']
            ]
        );
    }

    /**
     * Tests Sqlite::dropColumn
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropColumn()
    {
        $this->specify(
            'The SQL generated to modify a column in a table is invalid',
            function () {
                $dialect = new Sqlite();

                $dialect->dropColumn('table', null, 'column1');
            },
            [
                'throws' => [Exception::class, 'Dropping DB column is not supported by SQLite']
            ]
        );
    }

    /**
     * Tests Sqlite::dropTable
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropTable()
    {
        $this->specify(
            'The SQL generated to drop a table is invalid',
            function ($schema, $ifExists, $expected) {
                $dialect = new Sqlite();

                expect($dialect->dropTable('table', $schema, $ifExists))->equals($expected);
            },
            [
                'examples' => $this->getDropTable()
            ]
        );
    }

    /**
     * Tests Sqlite::truncateTable
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function truncateTable()
    {
        $this->specify(
            'The SQL generated to drop a table is invalid',
            function ($schema, $expected) {
                $dialect = new Sqlite();

                expect($dialect->truncateTable('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getTruncateTable()
            ]
        );
    }

    /**
     * Tests Sqlite::addIndex
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function addIndex()
    {
        $this->specify(
            'The SQL generated to add an index to a table is incorrect',
            function ($schema, $index, $expected) {
                $dialect = new Sqlite();
                $indexes = $this->getIndexes();

                expect($dialect->addIndex('table', $schema, $indexes[$index]))->equals($expected);
            },
            [
                'examples' => $this->getAddIndex()
            ]
        );
    }

    /**
     * Tests Sqlite::dropIndex
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropIndex()
    {
        $this->specify(
            'The SQL generated to delete an index from a table is incorrect',
            function ($schema, $index, $expected) {
                $dialect = new Sqlite();

                expect($dialect->dropIndex('table', $schema, $index))->equals($expected);
            },
            [
                'examples' => $this->getDropIndex()
            ]
        );
    }

    /**
     * Tests Sqlite::addPrimaryKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function addPrimaryKey()
    {
        $this->specify(
            'The SQL generated to add the primary key to a table is incorrect',
            function () {
                $dialect = new Sqlite();
                $indexes = $this->getIndexes();

                $dialect->addPrimaryKey('table', null, $indexes['PRIMARY']);
            },
            ['throws' => [
                    Exception::class,
                    'Adding a primary key after table has been created is not supported by SQLite'
                ],
            ]
        );
    }

    /**
     * Tests Sqlite::dropPrimaryKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropPrimaryKey()
    {
        $this->specify(
            'The SQL generated to delete primary key from a table is incorrect',
            function () {
                $dialect = new Sqlite();

                $dialect->dropPrimaryKey('table', null);
            },
            ['throws' => [
                    Exception::class,
                    'Removing a primary key after table has been created is not supported by SQLite'
                ],
            ]
        );
    }

    /**
     * Tests Sqlite::addForeignKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function addForeignKey()
    {
        $this->specify(
            'The SQL generated to add an index to a table is incorrect',
            function () {
                $dialect = new Sqlite();
                $references = $this->getReferences();

                $dialect->addForeignKey('table', null, $references['fk1']);
            },
            ['throws' => [
                    Exception::class,
                    'Adding a foreign key constraint to an existing table is not supported by SQLite'
                ],
            ]
        );
    }

    /**
     * Tests Sqlite::dropForeignKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropForeignKey()
    {
        $this->specify(
            'The SQL generated to delete a foreign key from a table is incorrect',
            function () {
                $dialect = new Sqlite();

                $dialect->dropForeignKey('table', null, 'fk1');
            },
            ['throws' => [
                    Exception::class,
                    'Dropping a foreign key constraint is not supported by SQLite'
                ],
            ]
        );
    }

    /**
     * Tests Sqlite::createView
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function createView()
    {
        $this->specify(
            'The SQL generated to create a view is incorrect',
            function ($definition, $schema, $expected) {
                $dialect = new Sqlite();

                expect($dialect->createView('test_view', $definition, $schema))->equals($expected);
            },
            [
                'examples' => $this->getCreateView()
            ]
        );
    }

    /**
     * Tests Sqlite::dropView
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropView()
    {
        $this->specify(
            'The SQL generated to drop a view is incorrect',
            function ($schema, $ifExists, $expected) {
                $dialect = new Sqlite();

                expect($dialect->dropView('test_view', $schema, $ifExists))->equals($expected);
            },
            [
                'examples' => $this->getDropView()
            ]
        );
    }

    /**
     * Tests Sqlite::listViews
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function listViews()
    {
        $this->specify(
            'The SQL generated to list all views of a schema or user is incorrect',
            function ($schema, $expected) {
                $dialect = new Sqlite();

                expect($dialect->listViews($schema))->equals($expected);
            },
            [
                'examples' => $this->getListViews()
            ]
        );
    }

    /**
     * Tests Sqlite::viewExists
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function viewExists()
    {
        $this->specify(
            'The SQL generated to check existence of view is incorrect',
            function ($schema, $expected) {
                $dialect = new Sqlite();

                expect($dialect->viewExists('view', $schema))->equals($expected);
            },
            [
                'examples' => $this->getViewExists()
            ]
        );
    }

    /**
     * Tests Sqlite::describeColumns
     *
     * @test
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function describeColumns()
    {
        $this->specify(
            'The SQL generated to describe a table is incorrect',
            function ($schema, $expected) {
                $dialect = new Sqlite();

                expect($dialect->describeColumns('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDescribeColumns()
            ]
        );
    }

    /**
     * Tests Sqlite::createSavepoint
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function createSavepoint()
    {
        $this->specify(
            'The SQL generated to create a new savepoint is incorrect',
            function () {
                $dialect = new Sqlite();

                expect($dialect->createSavepoint('PH_SAVEPOINT_1'))->equals('SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Sqlite::releaseSavepoint
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function releaseSavepoint()
    {
        $this->specify(
            'The SQL generated to release a savepoint is incorrect',
            function () {
                $dialect = new Sqlite();
                expect($dialect->releaseSavepoint('PH_SAVEPOINT_1'))->equals('RELEASE SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Sqlite::rollbackSavepoint
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function rollbackSavepoint()
    {
        $this->specify(
            'The SQL generated to rollback a savepoint is incorrect',
            function () {
                $dialect = new Sqlite();
                expect($dialect->rollbackSavepoint('PH_SAVEPOINT_1'))->equals('ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Sqlite::supportsSavepoints
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function supportsSavepoints()
    {
        $this->specify(
            'The platform does not support savepoints',
            function () {
                $dialect = new Sqlite();
                expect($dialect->supportsSavepoints())->true();
            }
        );
    }

    /**
     * Tests Sqlite::supportsReleaseSavepoints
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function supportsReleaseSavepoints()
    {
        $this->specify(
            'The platform does not support releasing savepoints',
            function () {
                $dialect = new Sqlite();
                expect($dialect->supportsReleaseSavepoints())->true();
            }
        );
    }

    /**
     * Tests Sqlite::describeReferences
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function describeReferences()
    {
        $this->specify(
            'The SQL generated to describe references is incorrect',
            function ($schema, $expected) {
                $dialect = new Sqlite();

                expect($dialect->describeReferences('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDescribeReferences()
            ]
        );
    }

    /**
     * Tests Sqlite::createTable
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function createTable()
    {
        $this->specify(
            'The SQL generated to create a table is incorrect',
            function ($schema, $definition, $expected) {
                $dialect = new Sqlite();

                expect($dialect->createTable('table', $schema, $definition))->equals($expected);
            },
            [
                'examples' => $this->getCreateTable()
            ]
        );
    }
}
