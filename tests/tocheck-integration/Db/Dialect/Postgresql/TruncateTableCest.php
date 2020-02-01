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

namespace Phalcon\Test\Integration\Db\Dialect\Postgresql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql;

class TruncateTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: truncateTable()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getTruncateTableFixtures
     */
    public function dbDialectPostgresqlTruncateTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - truncateTable()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->truncateTable('table', $schema);

        $I->assertEquals($expected, $actual);
    }

    protected function getTruncateTableFixtures(): array
    {
        return [
            [
                '',
                'TRUNCATE TABLE "table"',
            ],
            [
                'schema',
                'TRUNCATE TABLE "schema"."table"',
            ],
        ];
    }
}
