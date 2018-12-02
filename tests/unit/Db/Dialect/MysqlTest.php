<?php

namespace Phalcon\Test\Unit\Db\Dialect;

use Phalcon\Db\Column;
use Helper\DialectTrait;
use Phalcon\Db\Dialect\Mysql;
use Helper\Dialect\MysqlTrait;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Db\Dialect\MysqlTest
 * Tests the \Phalcon\Db\Dialect\Mysql component
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
class MysqlTest extends UnitTest
{
    use DialectTrait, MysqlTrait;

    /**
     * Tests Mysql::getColumnList
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
                $dialect = new Mysql();

                expect($dialect->getColumnList($columns))->equals($expected);
            },
            [
                'examples' => $this->getColumnList()
            ]
        );
    }

    /**
     * Tests Mysql::getColumnDefinition
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function columnDefinition()
    {
        $this->specify(
            'Unable to get the column name in Mysql',
            function ($column, $expected) {
                $dialect = new Mysql();
                $columns = $this->getColumns();

                expect($dialect->getColumnDefinition($columns[$column]))->equals($expected);
            },
            [
                'examples' => $this->getColumnDefinition()
            ]
        );
    }

    /**
     * Tests Mysql::addColumn
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
                $dialect = new Mysql();
                $columns = $this->getColumns();

                expect($dialect->addColumn('table', $schema, $columns[$column]))->equals($expected);
            },
            [
                'examples' => $this->getAddColumns()
            ]
        );
    }

    /**
     * Tests Mysql::dropTable
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
                $dialect = new Mysql();

                expect($dialect->dropTable('table', $schema, $ifExists))->equals($expected);
            },
            [
                'examples' => $this->getDropTable()
            ]
        );
    }

    /**
     * Tests Mysql::truncateTable
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
                $dialect = new Mysql();

                expect($dialect->truncateTable('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getTruncateTable()
            ]
        );
    }

    /**
     * Tests Mysql::dropColumn
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropColumn()
    {
        $this->specify(
            'The SQL generated to delete a column from a table is invalid',
            function ($schema, $column, $expected) {
                $dialect = new Mysql();

                expect($dialect->dropColumn('table', $schema, $column))->equals($expected);
            },
            [
                'examples' => $this->getDropColumn()
            ]
        );
    }

    /**
     * Tests Mysql::modifyColumn
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function modifyColumn()
    {
        $this->specify(
            'The SQL generated to modify a column in a table is invalid',
            function ($schema, $to, $expected) {
                $dialect = new Mysql();
                $columns = $this->getColumns();

                expect($dialect->modifyColumn('table', $schema, $columns[$to]))->equals($expected);
            },
            [
                'examples' => $this->getModifyColumn()
            ]
        );
    }

    /**
     * Tests Mysql::addIndex
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
                $dialect = new Mysql();
                $indexes = $this->getIndexes();

                expect($dialect->addIndex('table', $schema, $indexes[$index]))->equals($expected);
            },
            [
                'examples' => $this->getAddIndex()
            ]
        );
    }

    /**
     * Tests Mysql::dropIndex
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
                $dialect = new Mysql();

                expect($dialect->dropIndex('table', $schema, $index))->equals($expected);
            },
            [
                'examples' => $this->getDropIndex()
            ]
        );
    }

    /**
     * Tests Mysql::addPrimaryKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function addPrimaryKey()
    {
        $this->specify(
            'The SQL generated to add the primary key to a table is incorrect',
            function ($schema, $index, $expected) {
                $dialect = new Mysql();
                $indexes = $this->getIndexes();

                expect($dialect->addPrimaryKey('table', $schema, $indexes[$index]))->equals($expected);
            },
            [
                'examples' => $this->getAddPrimaryKey()
            ]
        );
    }

    /**
     * Tests Mysql::dropPrimaryKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropPrimaryKey()
    {
        $this->specify(
            'The SQL generated to delete primary key from a table is incorrect',
            function ($schema, $expected) {
                $dialect = new Mysql();

                expect($dialect->dropPrimaryKey('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDropPrimaryKey()
            ]
        );
    }

    /**
     * Tests Mysql::addForeignKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function addForeignKey()
    {
        $this->specify(
            'The SQL generated to add an index to a table is incorrect',
            function ($schema, $reference, $expected) {
                $dialect = new Mysql();
                $references = $this->getReferences();

                expect($dialect->addForeignKey('table', $schema, $references[$reference]))->equals($expected);
            },
            [
                'examples' => $this->getAddForeignKey()
            ]
        );
    }

    /**
     * Tests Mysql::dropForeignKey
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function dropForeignKey()
    {
        $this->specify(
            'The SQL generated to delete a foreign key from a table is incorrect',
            function ($schema, $key, $expected) {
                $dialect = new Mysql();

                expect($dialect->dropForeignKey('table', $schema, $key))->equals($expected);
            },
            [
                'examples' => $this->getDropForeignKey()
            ]
        );
    }

    /**
     * Tests Mysql::createView
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
                $dialect = new Mysql();

                expect($dialect->createView('test_view', $definition, $schema))->equals($expected);
            },
            [
                'examples' => $this->getCreateView()
            ]
        );
    }

    /**
     * Tests Mysql::dropView
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
                $dialect = new Mysql();

                expect($dialect->dropView('test_view', $schema, $ifExists))->equals($expected);
            },
            [
                'examples' => $this->getDropView()
            ]
        );
    }

    /**
     * Tests Mysql::listViews
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
                $dialect = new Mysql();

                expect($dialect->listViews($schema))->equals($expected);
            },
            [
                'examples' => $this->getListViews()
            ]
        );
    }

    /**
     * Tests Mysql::viewExists
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
                $dialect = new Mysql();

                expect($dialect->viewExists('view', $schema))->equals($expected);
            },
            [
                'examples' => $this->getViewExists()
            ]
        );
    }

    /**
     * Tests Mysql::describeColumns
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
                $dialect = new Mysql();

                expect($dialect->describeColumns('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDescribeColumns()
            ]
        );
    }

    /**
     * Tests Mysql::createSavepoint
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
                $dialect = new Mysql();

                expect($dialect->createSavepoint('PH_SAVEPOINT_1'))->equals('SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Mysql::releaseSavepoint
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
                $dialect = new Mysql();
                expect($dialect->releaseSavepoint('PH_SAVEPOINT_1'))->equals('RELEASE SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Mysql::rollbackSavepoint
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
                $dialect = new Mysql();
                expect($dialect->rollbackSavepoint('PH_SAVEPOINT_1'))->equals('ROLLBACK TO SAVEPOINT PH_SAVEPOINT_1');
            }
        );
    }

    /**
     * Tests Mysql::supportsSavepoints
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
                $dialect = new Mysql();
                expect($dialect->supportsSavepoints())->true();
            }
        );
    }

    /**
     * Tests Mysql::supportsReleaseSavepoints
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
                $dialect = new Mysql();
                expect($dialect->supportsReleaseSavepoints())->true();
            }
        );
    }

    /**
     * Tests Mysql::describeReferences
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
                $dialect = new Mysql();

                expect($dialect->describeReferences('table', $schema))->equals($expected);
            },
            [
                'examples' => $this->getDescribeReferences()
            ]
        );
    }

    /**
     * Tests Mysql::createTable
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
                $dialect = new Mysql();

                expect($dialect->createTable('table', $schema, $definition))->equals($expected);
            },
            [
                'examples' => $this->getCreateTable()
            ]
        );
    }

    /**
     * Tests Mysql::modifyColumn
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-01-20
     * @issue  https://github.com/phalcon/cphalcon/issues/13012
     */
    public function shouldRenameColumn()
    {
        $this->specify(
            "Can't rename a Column using MySQL Dialect",
            function () {
                $dialect = new Mysql();

                $oldColumn = new Column('old', ['type' => Column::TYPE_VARCHAR]);
                $newColumn = new Column('new', ['type' => Column::TYPE_VARCHAR]);

                expect($dialect->modifyColumn('table', 'database', $newColumn, $oldColumn))
                    ->equals('ALTER TABLE `database`.`table` CHANGE COLUMN `old` `new` VARCHAR(0) NULL');
            }
        );
    }
}
