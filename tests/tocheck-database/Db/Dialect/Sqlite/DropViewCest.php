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

class DropViewCest
{
    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: dropView()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getDropViewFixtures
     */
    public function dbDialectSqliteDropView(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - dropView()');

        $schema   = $example[0];
        $ifExists = $example[1];
        $expected = $example[2];

        $dialect = new Sqlite();

        $actual = $dialect->dropView(
            'test_view',
            $schema,
            $ifExists
        );

        $I->assertTrue(is_string($actual));

        $I->assertEquals($expected, $actual);
    }

    protected function getDropViewFixtures(): array
    {
        return [
            ['', false, 'DROP VIEW "test_view"'],
            ['', true, 'DROP VIEW IF EXISTS "test_view"'],
            ['schema', false, 'DROP VIEW "schema"."test_view"'],
            ['schema', true, 'DROP VIEW IF EXISTS "schema"."test_view"'],
        ];
    }
}
