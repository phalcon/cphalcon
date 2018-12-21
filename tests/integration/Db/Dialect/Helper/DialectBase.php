<?php

namespace Phalcon\Test\Integration\Db\Dialect\Helper;

use IntegrationTester;
use Phalcon\Db\DialectInterface;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class DialectBase
{
    use DialectTrait;

    protected $adapter = 'Mysql';


    /**
     * Tests Dialect::createView
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testCreateView(IntegrationTester $I)
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
     * Returns the object for the dialect
     *
     * @return DialectInterface
     */
    protected function getDialectObject(): DialectInterface
    {
        $class = sprintf('Phalcon\Db\Dialect\%s', $this->adapter);

        return new $class();
    }

    /**
     * Tests Dialect::describeColumns
     *
     * @param IntegrationTester $I
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDescribeColumns(IntegrationTester $I)
    {
        $data = $this->getDescribeColumnsFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];

            $dialect = $this->getDialectObject();
            $actual  = $dialect->describeColumns('table', $schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @param IntegrationTester $I
     */
    public function testDescribeIndexes(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::describeReferences
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDescribeReferences(IntegrationTester $I)
    {
        $data = $this->getDescribeReferencesFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];

            $dialect = $this->getDialectObject();
            $actual  = $dialect->describeReferences('table', $schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropColumn
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropColumn(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropForeignKey(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropIndex(IntegrationTester $I)
    {
        $data = $this->getDropIndexFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $index    = $item[1];
            $expected = $item[2];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->dropIndex('table', $schema, $index);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropPrimaryKey
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropPrimaryKey(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropTable(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropView(IntegrationTester $I)
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
     * @param IntegrationTester $I
     */
    public function testForUpdate(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::getColumnDefinition
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testGetColumnDefinition(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testGetColumnList(IntegrationTester $I)
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
     * @param IntegrationTester $I
     */
    public function testLimit(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * @param IntegrationTester $I
     */
    public function testListTables(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::listViews
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testListViews(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testModifyColumn(IntegrationTester $I)
    {
        $data = $this->getModifyColumnFixtures();
        foreach ($data as $item) {
            $columns  = $this->getColumns();
            $schema   = $item[0];
            $to       = $columns[$item[1]];
            $from     = $columns[$item[2]] ?? null;
            $expected = $item[3];
            $dialect  = $this->getDialectObject();
            $actual   = $dialect->modifyColumn('table', $schema, $to, $from);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::modifyColumn
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-01-20
     * @issue  https://github.com/phalcon/cphalcon/issues/13012
     */
    public function testModifyColumn13012(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testReleaseSavepoint(IntegrationTester $I)
    {
        $dialect  = $this->getDialectObject();
        $expected = $this->getReleaseSavepointSql();
        $actual   = $dialect->releaseSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::rollbackSavepoint
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testRollbackSavepoint(IntegrationTester $I)
    {
        $dialect  = $this->getDialectObject();
        $expected = $this->getRollbackSavepointSql();
        $actual   = $dialect->rollbackSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    /**
     * @param IntegrationTester $I
     */
    public function testSelect(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * @param IntegrationTester $I
     */
    public function testSharedLock(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::supportsReleaseSavepoints
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testSupportsReleaseSavepoints(IntegrationTester $I)
    {
        $dialect = $this->getDialectObject();
        $actual  = $dialect->supportsReleaseSavepoints();

        $I->assertTrue($actual);
    }

    /**
     * Tests Dialect::supportsSavepoints
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testSupportsSavepoints(IntegrationTester $I)
    {
        $dialect = $this->getDialectObject();
        $actual  = $dialect->supportsSavepoints();

        $I->assertTrue($actual);
    }

    /**
     * Tests Dialect::tableExists
     *
     * @param IntegrationTester $I
     */
    public function testTableExists(IntegrationTester $I)
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
     * @param IntegrationTester $I
     */
    public function testTableOptions(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::truncateTable
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testTruncateTable(IntegrationTester $I)
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
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testViewExists(IntegrationTester $I)
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
}
