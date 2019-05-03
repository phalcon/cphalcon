<?php

namespace Phalcon\Test\Integration\Db\Dialect\Helper;

use Codeception\Example;
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
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2017-02-26
     *
     * @dataProvider getCreateViewFixtures
     */
    public function testCreateView(IntegrationTester $I, Example $example)
    {
        $definition = $example[0];
        $schema     = $example[1];
        $expected   = $example[2];

        $dialect = $this->getDialectObject();

        $actual = $dialect->createView(
            'test_view',
            $definition,
            $schema
        );

        $I->assertInternalType(
            'string',
            $actual
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Returns the object for the dialect
     */
    protected function getDialectObject(): DialectInterface
    {
        $class = sprintf(
            'Phalcon\Db\Dialect\%s',
            $this->adapter
        );

        return new $class();
    }

    /**
     * Tests Dialect::describeColumns
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     *
     * @author       Phalcon Team <team@phalconphp.com>
     * @since        2017-02-26
     *
     * @dataProvider getDescribeColumnsFixtures
     */
    public function testDescribeColumns(IntegrationTester $I, Example $example)
    {
        $schema   = $example[0];
        $expected = $example[1];

        $dialect = $this->getDialectObject();

        $actual = $dialect->describeColumns(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    public function testDescribeIndexes(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::describeReferences
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getDescribeReferencesFixtures
     */
    public function testDescribeReferences(IntegrationTester $I, Example $example)
    {
        $schema   = $example[0];
        $expected = $example[1];

        $dialect = $this->getDialectObject();

        $actual = $dialect->describeReferences(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::dropColumn
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropColumn(IntegrationTester $I)
    {
        $examples = $this->getDropColumnFixtures();

        foreach ($examples as $example) {
            $schema   = $example[0];
            $column   = $example[1];
            $expected = $example[2];

            $dialect = $this->getDialectObject();

            $actual = $dialect->dropColumn(
                'table',
                $schema,
                $column
            );

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropForeignKey
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropForeignKey(IntegrationTester $I)
    {
        $examples = $this->getDropForeignKeyFixtures();

        foreach ($examples as $example) {
            $schema   = $example[0];
            $key      = $example[1];
            $expected = $example[2];

            $dialect = $this->getDialectObject();

            $actual = $dialect->dropForeignKey(
                'table',
                $schema,
                $key
            );

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropIndex
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getDropIndexFixtures
     */
    public function testDropIndex(IntegrationTester $I, Example $example)
    {
        $schema   = $example[0];
        $index    = $example[1];
        $expected = $example[2];

        $dialect = $this->getDialectObject();

        $actual = $dialect->dropIndex(
            'table',
            $schema,
            $index
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::dropPrimaryKey
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testDropPrimaryKey(IntegrationTester $I)
    {
        $examples = $this->getDropPrimaryKeyFixtures();

        foreach ($examples as $example) {
            $schema   = $example[0];
            $expected = $example[1];

            $dialect = $this->getDialectObject();

            $actual = $dialect->dropPrimaryKey(
                'table',
                $schema
            );

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::dropTable
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getDropTableFixtures
     */
    public function testDropTable(IntegrationTester $I, Example $example)
    {
        $schema   = $example[0];
        $ifExists = $example[1];
        $expected = $example[2];

        $dialect = $this->getDialectObject();

        $actual = $dialect->dropTable(
            'table',
            $schema,
            $ifExists
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::dropView
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

            $dialect = $this->getDialectObject();

            $actual = $dialect->dropView(
                'test_view',
                $schema,
                $ifExists
            );

            $I->assertInternalType(
                'string',
                $actual
            );

            $I->assertEquals($expected, $actual);
        }
    }

    public function testForUpdate(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::getColumnDefinition
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getColumnDefinitionFixtures
     */
    public function testGetColumnDefinition(IntegrationTester $I, Example $example)
    {
        $column   = $example[0];
        $expected = $example[1];

        $columns = $this->getColumns();
        $dialect = $this->getDialectObject();

        $actual = $dialect->getColumnDefinition(
            $columns[$column]
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::getColumnList
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

            $dialect = $this->getDialectObject();

            $actual = $dialect->getColumnList($columns);

            $I->assertInternalType(
                'string',
                $actual
            );

            $I->assertEquals($expected, $actual);
        }
    }

    public function testLimit(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    public function testListTables(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::listViews
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

            $dialect = $this->getDialectObject();

            $actual = $dialect->listViews($schema);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::modifyColumn
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

            $actual = $dialect->modifyColumn(
                'table',
                $schema,
                $to,
                $from
            );

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * Tests Dialect::modifyColumn
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-01-20
     * @issue  https://github.com/phalcon/cphalcon/issues/13012
     */
    public function testModifyColumn13012(IntegrationTester $I)
    {
        list($oldColumn, $newColumn) = $this->getModifyColumnFixtures13012();

        $dialect = $this->getDialectObject();


        $expected = $this->getModifyColumnSql();

        $actual = $dialect->modifyColumn(
            'table',
            'database',
            $newColumn,
            $oldColumn
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::releaseSavepoint
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testReleaseSavepoint(IntegrationTester $I)
    {
        $dialect = $this->getDialectObject();

        $expected = $this->getReleaseSavepointSql();

        $actual = $dialect->releaseSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::rollbackSavepoint
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testRollbackSavepoint(IntegrationTester $I)
    {
        $dialect = $this->getDialectObject();

        $expected = $this->getRollbackSavepointSql();

        $actual = $dialect->rollbackSavepoint('PH_SAVEPOINT_1');

        $I->assertEquals($expected, $actual);
    }

    public function testSelect(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    public function testSharedLock(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::supportsReleaseSavepoints
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testSupportsReleaseSavepoints(IntegrationTester $I)
    {
        $dialect = $this->getDialectObject();

        $I->assertTrue(
            $dialect->supportsReleaseSavepoints()
        );
    }

    /**
     * Tests Dialect::supportsSavepoints
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testSupportsSavepoints(IntegrationTester $I)
    {
        $dialect = $this->getDialectObject();

        $I->assertTrue(
            $dialect->supportsSavepoints()
        );
    }

    /**
     * Tests Dialect::tableExists
     */
    public function testTableExists(IntegrationTester $I)
    {
        $data = $this->getTableExistsFixtures();

        foreach ($data as $item) {
            $schema   = $item[0];
            $expected = $item[1];

            $dialect = $this->getDialectObject();

            $actual = $dialect->tableExists(
                'table',
                $schema
            );

            $I->assertInternalType(
                'string',
                $actual
            );

            $I->assertEquals($expected, $actual);
        }
    }

    public function testTableOptions(IntegrationTester $I)
    {
        $I->skipTest('TODO: Write this test');
    }

    /**
     * Tests Dialect::truncateTable
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getTruncateTableFixtures
     */
    public function testTruncateTable(IntegrationTester $I, Example $example)
    {
        $schema   = $example[0];
        $expected = $example[1];

        $dialect = $this->getDialectObject();

        $actual = $dialect->truncateTable(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Dialect::viewExists
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

            $dialect = $this->getDialectObject();

            $actual = $dialect->viewExists(
                'view',
                $schema
            );

            $I->assertInternalType(
                'string',
                $actual
            );

            $I->assertEquals($expected, $actual);
        }
    }
}
