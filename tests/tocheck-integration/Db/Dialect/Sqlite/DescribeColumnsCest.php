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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;

class DescribeColumnsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: describeColumns()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getDescribeColumnsFixtures
     */
    public function dbDialectSqliteDescribeColumns(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - describeColumns()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Sqlite();

        $actual = $dialect->describeColumns(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getDescribeColumnsFixtures(): array
    {
        return [
            [
                'schema.name.with.dots',
                "PRAGMA table_info('table')",
            ],
            [
                '',
                "PRAGMA table_info('table')",
            ],
            [
                'schema',
                "PRAGMA table_info('table')",
            ],
        ];
    }
}
