<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Db\Reference;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

class DescribeReferencesCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeReferences()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeReferences(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeReferences()");

        $table    = 'dialect_table_intermediate';
        $expected = $this->getExpectedReferences();

        $I->assertEquals(
            $expected,
            $this->connection->describeReferences($table)
        );

        $I->assertEquals(
            $expected,
            $this->connection->describeReferences(
                $table,
                $this->getSchemaName()
            )
        );
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeReferences() - count
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeReferencesCount(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeReferences() - count");

        $table = 'dialect_table_intermediate';

        $directReferences = $this->connection->describeReferences($table);

        $schemaReferences = $this->connection->describeReferences(
            $table,
            $this->getSchemaName()
        );

        $I->assertEquals($directReferences, $schemaReferences);

        $I->assertCount(2, $directReferences);
        $I->assertCount(2, $schemaReferences);

        /** @var Reference $reference */
        foreach ($directReferences as $reference) {
            $I->assertCount(
                1,
                $reference->getColumns()
            );
        }
    }

    /**
     * Tests Mysql::describeReferences
     *
     * @author Wojciechj Ślawski <jurigag@gmail.com>
     * @since  2016-09-28
     */
    public function testDescribeReferencesColumnsCount(IntegrationTester $I)
    {
        $actual = $this->connection->describeReferences(
            'robots_parts',
            env('DATA_MYSQL_NAME')
        );

        $I->assertCount(2, $actual);


        $I->assertCount(
            2,
            $this->connection->describeReferences('robots_parts', null)
        );


        $references = $actual;

        /** @var Reference $reference */
        foreach ($references as $reference) {
            $I->assertCount(
                1,
                $reference->getColumns()
            );
        }
    }
}
