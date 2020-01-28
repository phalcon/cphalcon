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
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class GetColumnDefinitionCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: getColumnDefinition()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getColumnDefinitionFixtures
     */
    public function dbDialectPostgresqlGetColumnDefinition(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - getColumnDefinition()');

        $column   = $example[0];
        $expected = $example[1];

        $columns = $this->getColumns();

        $dialect = new Postgresql();

        $actual = $dialect->getColumnDefinition(
            $columns[$column]
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getColumnDefinitionFixtures(): array
    {
        return [
            ['column1', 'CHARACTER VARYING(10)'],
            ['column2', 'INT'],
            ['column3', 'NUMERIC(10,2)'],
            ['column4', 'CHARACTER(100)'],
            ['column5', 'DATE'],
            ['column6', 'TIMESTAMP'],
            ['column7', 'TEXT'],
            ['column8', 'FLOAT'],
            ['column9', 'CHARACTER VARYING(10)'],
            ['column10', 'INT'],
            ['column11', 'BIGINT'],
            ['column12', "ENUM('A', 'B', 'C')"],
            ['column13', 'TIMESTAMP'],
            ['column21', 'BIGSERIAL'],
            ['column22', 'BIGINT'],
            ['column23', 'SERIAL'],
        ];
    }
}
