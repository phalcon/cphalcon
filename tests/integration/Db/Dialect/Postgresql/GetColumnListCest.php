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

class GetColumnListCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getColumnList()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getColumnListFixtures
     */
    public function dbDialectPostgresqlGetColumnList(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - getColumnList()');

        $columns  = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->getColumnList($columns);

        $I->assertInternalType(
            'string',
            $actual
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getColumnListFixtures(): array
    {
        return [
            [
                ['column1', 'column2', 'column3'],
                '"column1", "column2", "column3"',
            ],

            [
                ['foo'],
                '"foo"',
            ],
        ];
    }
}
