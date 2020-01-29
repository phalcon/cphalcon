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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;

class CreateViewCest
{
    /**
     * Tests Phalcon\Db\Dialect\Mysql :: createView()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getCreateViewFixtures
     */
    public function dbDialectMysqlCreateView(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - createView()');

        $definition = $example[0];
        $schema     = $example[1];
        $expected   = $example[2];

        $dialect = new Mysql();

        $actual = $dialect->createView(
            'test_view',
            $definition,
            $schema
        );

        $I->assertInternalType(
            'string',
            $actual
        );

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
                'CREATE VIEW `test_view` AS SELECT 1',
            ],

            [
                [
                    'sql' => 'SELECT 1',
                ],
                'schema',
                'CREATE VIEW `schema`.`test_view` AS SELECT 1',
            ],
        ];
    }
}
