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

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class GetColumnDefinitionCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: getColumnDefinition()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getColumnDefinitionFixtures
     */
    public function dbDialectSqliteGetColumnDefinition(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Sqlite - getColumnDefinition()');

        $column   = $example[0];
        $expected = $example[1];

        $columns = $this->getColumns();

        $dialect = new Sqlite();

        $actual = $dialect->getColumnDefinition(
            $columns[$column]
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getColumnDefinitionFixtures(): array
    {
        return [
            ['column1', 'VARCHAR(10)'],
            ['column2', 'INTEGER'],
            ['column3', 'NUMERIC(10,2)'],
            ['column4', 'CHARACTER(100)'],
            ['column5', 'DATE'],
            ['column6', 'DATETIME'],
            ['column7', 'TEXT'],
            ['column8', 'FLOAT'],
            ['column9', 'VARCHAR(10)'],
            ['column10', 'INTEGER'],
            ['column13', 'TIMESTAMP'],
            ['column14', 'TINYBLOB'],
            ['column15', 'MEDIUMBLOB'],
            ['column16', 'BLOB'],
            ['column17', 'LONGBLOB'],
            ['column18', 'TINYINT'],
            ['column19', 'DOUBLE'],
            ['column20', 'DOUBLE UNSIGNED'],
        ];
    }
}
