<?php

namespace Phalcon\Test\Unit\Db\Dialect\Helper;

use Phalcon\Db\DialectInterface;
use Phalcon\Test\Fixtures\Traits\DialectTrait;
use UnitTester;

class DialectBase
{
    use DialectTrait;

    protected $adapter = 'Mysql';


    /**
     * Tests Dialect::createView
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testCreateView(UnitTester $I)
    {
        $data = $this->getCreateViewFixtures();
        foreach ($data as $item) {
            $definition = $item[0];
            $schema     = $item[1];
            $expected   = $item[2];
            $dialect    = $this->getDialectObject();
            $actual     = $dialect->createView('test_view', $definition, $schema);

            $I->assertTrue(is_string($actual));
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::describeColumns
     *
     * @param UnitTester $I
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDescribeColumns(UnitTester $I)
    {
        $data = $this->getDescribeColumnsFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];

            $dialect  = $this->getDialectObject();
            $actual   = $dialect->describeColumns('table', $schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @param UnitTester $I
     */
    public function testDescribeIndexes(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::describeReferences
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDescribeReferences(UnitTester $I)
    {
        $data = $this->getDescribeReferencesFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];

            $dialect  = $this->getDialectObject();
            $actual   = $dialect->describeReferences('table', $schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropColumn
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropColumn(UnitTester $I)
    {
        $data = $this->getDropColumnFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $column   = $item[1];
            $expected = $item[2];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->dropColumn('table', $schema, $column);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropForeignKey
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropForeignKey(UnitTester $I)
    {
        $data = $this->getDropForeignKeyFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $key      = $item[1];
            $expected = $item[2];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->dropForeignKey('table', $schema, $key);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropIndex
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropIndex(UnitTester $I)
    {
        $data = $this->getDropIndexFixtures();
        foreach ($data as $item) {
            $schema     = $item[0];
            $index      = $item[1];
            $expected   = $item[2];
            $dialect    = $this->getDialectObject();
            $actual     = $dialect->dropIndex('table', $schema, $index);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropPrimaryKey
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropPrimaryKey(UnitTester $I)
    {
        $data = $this->getDropPrimaryKeyFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->dropPrimaryKey('table', $schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropTable
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropTable(UnitTester $I)
    {
        $data = $this->getDropTableFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $ifExists = $item[1];
            $expected = $item[2];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->dropTable('table', $schema, $ifExists);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropView
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropView(UnitTester $I)
    {
        $data = $this->getDropViewFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $ifExists = $item[1];
            $expected = $item[2];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->dropView('test_view', $schema, $ifExists);

            $I->assertTrue(is_string($actual));
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @param UnitTester $I
     */
    public function testForUpdate(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::getColumnDefinition
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testGetColumnDefinition(UnitTester $I)
    {
        $data = $this->getColumnDefinitionFixtures();
        foreach ($data as $item) {
            $column   = $item[0];
            $expected = $item[1];
            $columns  = $this->getColumns();
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->getColumnDefinition($columns[$column]);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::getColumnList
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testGetColumnList(UnitTester $I)
    {
        $data = $this->getColumnListFixtures();
        foreach ($data as $item) {
            $columns  = $item[0];
            $expected = $item[1];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->getColumnList($columns);

            $I->assertTrue(is_string($actual));
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @param UnitTester $I
     */
    public function testLimit(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * @param UnitTester $I
     */
    public function testListTables(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::listViews
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testListViews(UnitTester $I)
    {
        $data = $this->getListViewFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->listViews($schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::modifyColumn
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testModifyColumn(UnitTester $I)
    {
        $data = $this->getModifyColumnFixtures();
        foreach ($data as $item) {
            $columns    = $this->getColumns();
            $schema     = $item[0];
            $to         = $columns[$item[1]];
            $from       = $columns[$item[2]] ?? null;
            $expected   = $item[3];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->modifyColumn('table', $schema, $to, $from);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::modifyColumn
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-01-20
     * @issue  https://github.com/phalcon/cphalcon/issues/13012
     */
    public function testModifyColumn13012(UnitTester $I)
    {
        list($oldColumn, $newColumn) = $this->getModifyColumnFixtures13012();

        $dialect  = $this->getDialectObject();
        $expected = $this->getModifyColumnSql();
        $actual   = $dialect->modifyColumn('table', 'database', $newColumn, $oldColumn);
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::releaseSavepoint
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testReleaseSavepoint(UnitTester $I)
    {
        $dialect  = $this->getDialectObject();
        $expected = $this->getReleaseSavepointSql();
        $actual   = $dialect->releaseSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::rollbackSavepoint
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testRollbackSavepoint(UnitTester $I)
    {
        $dialect  = $this->getDialectObject();
        $expected = $this->getRollbackSavepointSql();
        $actual   = $dialect->rollbackSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    /**
     * @param UnitTester $I
     */
    public function testSelect(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * @param UnitTester $I
     */
    public function testSharedLock(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::supportsReleaseSavepoints
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testSupportsReleaseSavepoints(UnitTester $I)
    {
        $dialect  = $this->getDialectObject();
        $actual   = $dialect->supportsReleaseSavepoints();

        $I->assertTrue($actual);
    }

    /**
     * Tests Dialect::supportsSavepoints
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testSupportsSavepoints(UnitTester $I)
    {
        $dialect  = $this->getDialectObject();
        $actual   = $dialect->supportsSavepoints();

        $I->assertTrue($actual);
    }

    /**
     * Tests Dialect::tableExists
     *
     * @param UnitTester $I
     */
    public function testTableExists(UnitTester $I)
    {
        $data = $this->getTableExistsFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->tableExists('table', $schema);

            $I->assertTrue(is_string($actual));
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @param UnitTester $I
     */
    public function testTableOptions(UnitTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::truncateTable
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testTruncateTable(UnitTester $I)
    {
        $data = $this->getTruncateTableFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->truncateTable('table', $schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::viewExists
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testViewExists(UnitTester $I)
    {
        $data = $this->getViewExistsFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->viewExists('view', $schema);

            $I->assertTrue(is_string($actual));
            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Returns the object for the dialect
     *
     * @return DialectInterface
     */
    protected function getDialectObject(): DialectInterface
    {
        $class = sprintf('Phalcon\Db\Dialect\%s', $this->adapter);

        return new $class();
    }
}
