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

namespace Phalcon\Tests\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class DescribeReferencesCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: describeReferences()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getDescribeReferencesFixtures
     */
    public function dbDialectMysqlDescribeReferences(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - describeReferences()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Mysql();

        $actual = $dialect->describeReferences(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getDescribeReferencesFixtures(): array
    {
        return [
            [
                null,
                'SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, ' .
                'KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, ' .
                'KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, ' .
                'RC.UPDATE_RULE, RC.DELETE_RULE ' .
                'FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU ' .
                'LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ' .
                'ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND ' .
                'RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA ' .
                'WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ' .
                "KCU.CONSTRAINT_SCHEMA = DATABASE() AND KCU.TABLE_NAME = 'table'",
            ],

            [
                'schema',
                'SELECT DISTINCT KCU.TABLE_NAME, KCU.COLUMN_NAME, ' .
                'KCU.CONSTRAINT_NAME, KCU.REFERENCED_TABLE_SCHEMA, ' .
                'KCU.REFERENCED_TABLE_NAME, KCU.REFERENCED_COLUMN_NAME, ' .
                'RC.UPDATE_RULE, RC.DELETE_RULE ' .
                'FROM INFORMATION_SCHEMA.KEY_COLUMN_USAGE AS KCU ' .
                'LEFT JOIN INFORMATION_SCHEMA.REFERENTIAL_CONSTRAINTS AS RC ' .
                'ON RC.CONSTRAINT_NAME = KCU.CONSTRAINT_NAME AND ' .
                'RC.CONSTRAINT_SCHEMA = KCU.CONSTRAINT_SCHEMA ' .
                'WHERE KCU.REFERENCED_TABLE_NAME IS NOT NULL AND ' .
                "KCU.CONSTRAINT_SCHEMA = 'schema' AND KCU.TABLE_NAME = 'table'",
            ],
        ];
    }
}
