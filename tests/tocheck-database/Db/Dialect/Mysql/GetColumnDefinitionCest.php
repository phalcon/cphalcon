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

namespace Phalcon\Tests\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class GetColumnDefinitionCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: getColumnDefinition()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getColumnDefinitionFixtures
     */
    public function dbDialectMysqlGetColumnDefinition(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - getColumnDefinition()');

        $column   = $example[0];
        $expected = $example[1];

        $columns = $this->getColumns();

        $dialect = new Mysql();

        $actual = $dialect->getColumnDefinition(
            $columns[$column]
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getColumnDefinitionFixtures(): array
    {
        return [
            ['column1', 'VARCHAR(10)'],
            ['column2', 'INT(18) UNSIGNED'],
            ['column3', 'DECIMAL(10,2)'],
            ['column4', 'CHAR(100)'],
            ['column5', 'DATE'],
            ['column6', 'DATETIME'],
            ['column7', 'TEXT'],
            ['column8', 'FLOAT(10,2)'],
            ['column9', 'VARCHAR(10)'],
            ['column10', 'INT(18) UNSIGNED'],
            ['column11', 'BIGINT(20) UNSIGNED'],
            ['column12', 'ENUM("A", "B", "C")'],
            ['column13', 'TIMESTAMP'],
            ['column19', 'DOUBLE'],
            ['column20', 'DOUBLE UNSIGNED'],
            ['column24', 'FLOAT'],
        ];
    }
}
