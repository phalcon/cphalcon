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

namespace Phalcon\Tests\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;

class DropTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropTable()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getDropTableFixtures
     */
    public function dbDialectSqliteDropTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - dropTable()');

        $schema   = $example[0];
        $ifExists = $example[1];
        $expected = $example[2];

        $dialect = new Sqlite();

        $actual = $dialect->dropTable('table', $schema, $ifExists);

        $I->assertEquals($expected, $actual);
    }

    protected function getDropTableFixtures(): array
    {
        return [
            [
                '',
                true,
                'DROP TABLE IF EXISTS "table"',
            ],
            [
                'schema',
                true,
                'DROP TABLE IF EXISTS "schema"."table"',
            ],
            [
                '',
                false,
                'DROP TABLE "table"',
            ],
            [
                'schema',
                false,
                'DROP TABLE "schema"."table"',
            ],
        ];
    }
}
