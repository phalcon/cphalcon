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

namespace Phalcon\Tests\Integration\Db\Dialect\Postgresql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Postgresql;

class CreateViewCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: createView()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getCreateViewFixtures
     */
    public function dbDialectPostgresqlCreateView(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - createView()');

        $definition = $example[0];
        $schema     = $example[1];
        $expected   = $example[2];

        $dialect = new Postgresql();

        $actual = $dialect->createView(
            'test_view',
            $definition,
            $schema
        );

        $I->assertTrue(is_string($actual));

        $I->assertEquals($expected, $actual);
    }

    protected function getCreateViewFixtures(): array
    {
        return [
            [
                [
                    'sql' => 'SELECT 1',
                ],
                null,
                'CREATE VIEW "test_view" AS SELECT 1',
            ],

            [
                [
                    'sql' => 'SELECT 1',
                ],
                'schema',
                'CREATE VIEW "schema"."test_view" AS SELECT 1',
            ],
        ];
    }
}
