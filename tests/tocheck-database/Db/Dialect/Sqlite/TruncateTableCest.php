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

class TruncateTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: truncateTable()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getTruncateTableFixtures
     */
    public function dbDialectSqliteTruncateTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - truncateTable()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Sqlite();

        $actual = $dialect->truncateTable('table', $schema);

        $I->assertEquals($expected, $actual);
    }

    protected function getTruncateTableFixtures(): array
    {
        return [
            [
                '',
                'DELETE FROM "table"',
            ],
            [
                'schema',
                'DELETE FROM "schema"."table"',
            ],
        ];
    }
}
