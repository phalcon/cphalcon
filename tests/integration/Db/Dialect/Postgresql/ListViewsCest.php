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

namespace Phalcon\Test\Integration\Db\Dialect\Postgresql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql;

class ListViewsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: listViews()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     *
     * @dataProvider getListViewFixtures
     */
    public function dbDialectPostgresqlListViews(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - listViews()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->listViews($schema);

        $I->assertEquals($expected, $actual);
    }

    protected function getListViewFixtures(): array
    {
        return [
            [
                null,
                "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'public' ORDER BY view_name",
            ],
            [
                'schema',
                "SELECT viewname AS view_name FROM pg_views WHERE schemaname = 'schema' ORDER BY view_name",
            ],
        ];
    }
}
