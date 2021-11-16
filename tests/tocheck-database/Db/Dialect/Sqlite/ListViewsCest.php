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

class ListViewsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: listViews()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getListViewFixtures
     */
    public function dbDialectSqliteListViews(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - listViews()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Sqlite();

        $actual = $dialect->listViews($schema);

        $I->assertEquals($expected, $actual);
    }

    protected function getListViewFixtures(): array
    {
        return [
            [
                '',
                "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name",
            ],
            [
                'schema',
                "SELECT tbl_name FROM sqlite_master WHERE type = 'view' ORDER BY tbl_name",
            ],
        ];
    }
}
