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

class TableExistsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: tableExists()
     *
     * @dataProvider getTableExistsFixtures
     */
    public function dbDialectPostgresqlTableExists(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - tableExists()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->tableExists(
            'table',
            $schema
        );

        $I->assertTrue(is_string($actual));

        $I->assertEquals($expected, $actual);
    }

    protected function getTableExistsFixtures(): array
    {
        return [
            [
                null,
                'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END ' .
                'FROM information_schema.tables ' .
                "WHERE table_schema = 'public' AND table_name='table'",
            ],
            [
                'schema',
                'SELECT CASE WHEN COUNT(*) > 0 THEN 1 ELSE 0 END ' .
                'FROM information_schema.tables ' .
                "WHERE table_schema = 'schema' AND table_name='table'",
            ],
        ];
    }
}
