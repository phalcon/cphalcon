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

class DropTableCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: dropTable()
     *
     * @author       Sid Roberts <https://github.com/SidRoberts>
     * @since        2019-05-25
     *
     * @dataProvider getDropTableFixtures
     */
    public function dbDialectPostgresqlDropTable(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - dropTable()');

        $schema   = $example[0];
        $ifExists = $example[1];
        $expected = $example[2];

        $dialect = new Postgresql();

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
