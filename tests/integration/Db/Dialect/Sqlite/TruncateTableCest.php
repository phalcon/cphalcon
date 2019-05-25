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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class TruncateTableCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: truncateTable()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     *
     * @dataProvider getTruncateTableFixtures
     */
    public function dbDialectSqliteTruncateTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - truncateTable()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = $this->getDialectSqlite();

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
