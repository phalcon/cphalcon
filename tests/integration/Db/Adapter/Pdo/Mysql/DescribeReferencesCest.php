<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Adapter\Pdo\Mysql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\Db\MysqlTrait;
use Phalcon\Test\Fixtures\Traits\DiTrait;

/**
 * Class DescribeReferencesCest
 */
class DescribeReferencesCest
{
    use DiTrait;
    use MysqlTrait;

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeReferences()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeReferences(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeReferences()");
        $table    = 'dialect_table_intermediate';
        $expected = $this->getExpectedReferences();
        $I->assertEquals($expected, $this->connection->describeReferences($table));
        $I->assertEquals($expected, $this->connection->describeReferences($table, $this->getSchemaName()));
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Mysql :: describeReferences() - count
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function dbAdapterPdoMysqlDescribeReferencesCount(IntegrationTester $I)
    {
        $I->wantToTest("Db\Adapter\Pdo\Mysql - describeReferences() - count");
        $table            = 'dialect_table_intermediate';
        $directReferences = $this->connection->describeReferences($table);
        $schemaReferences = $this->connection->describeReferences($table, $this->getSchemaName());
        $I->assertEquals($directReferences, $schemaReferences);
        $I->assertEquals(2, count($directReferences));
        $I->assertEquals(2, count($schemaReferences));

        /** @var Reference $reference */
        foreach ($directReferences as $reference) {
            $I->assertEquals(1, count($reference->getColumns()));
        }
    }
}
