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

class DescribeColumnsCest
{
    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: describeColumns()
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/12536
     * @issue  https://github.com/phalcon/cphalcon/issues/11359
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getDescribeColumnsFixtures
     */
    public function dbDialectPostgresqlDescribeColumns(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - describeColumns()');

        $schema   = $example[0];
        $expected = $example[1];

        $dialect = new Postgresql();

        $actual = $dialect->describeColumns(
            'table',
            $schema
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getDescribeColumnsFixtures(): array
    {
        return [
            [
                'schema.name.with.dots',
                'SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, ' .
                'c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, ' .
                'c.numeric_scale AS NumericScale, c.is_nullable AS Null, ' .
                "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, " .
                "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' " .
                "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, " .
                'c.column_default FROM information_schema.columns c ' .
                'LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema ' .
                'FROM information_schema.table_constraints tc ' .
                'INNER JOIN information_schema.key_column_usage kcu on ' .
                '(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name ' .
                "and kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc " .
                'ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND ' .
                "c.table_name=pkc.table_name) WHERE c.table_schema='schema.name.with.dots' AND " .
                "c.table_name='table' ORDER BY c.ordinal_position",
            ],
            [
                null,
                'SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, ' .
                'c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, ' .
                'c.numeric_scale AS NumericScale, c.is_nullable AS Null, ' .
                "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, " .
                "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' " .
                "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, " .
                'c.column_default FROM information_schema.columns c ' .
                'LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema ' .
                'FROM information_schema.table_constraints tc ' .
                'INNER JOIN information_schema.key_column_usage kcu on ' .
                '(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and ' .
                "kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc " .
                'ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND ' .
                "c.table_name=pkc.table_name) WHERE c.table_schema='public' AND c.table_name='table' " .
                'ORDER BY c.ordinal_position',
            ],
            [
                'schema',
                'SELECT DISTINCT c.column_name AS Field, c.data_type AS Type, ' .
                'c.character_maximum_length AS Size, c.numeric_precision AS NumericSize, ' .
                'c.numeric_scale AS NumericScale, c.is_nullable AS Null, ' .
                "CASE WHEN pkc.column_name NOTNULL THEN 'PRI' ELSE '' END AS Key, " .
                "CASE WHEN c.data_type LIKE '%int%' AND c.column_default LIKE '%nextval%' " .
                "THEN 'auto_increment' ELSE '' END AS Extra, c.ordinal_position AS Position, " .
                'c.column_default FROM information_schema.columns c ' .
                'LEFT JOIN ( SELECT kcu.column_name, kcu.table_name, kcu.table_schema ' .
                'FROM information_schema.table_constraints tc ' .
                'INNER JOIN information_schema.key_column_usage kcu on ' .
                '(kcu.constraint_name = tc.constraint_name and kcu.table_name=tc.table_name and ' .
                "kcu.table_schema=tc.table_schema) WHERE tc.constraint_type='PRIMARY KEY') pkc " .
                'ON (c.column_name=pkc.column_name AND c.table_schema = pkc.table_schema AND ' .
                "c.table_name=pkc.table_name) WHERE c.table_schema='schema' AND c.table_name='table' " .
                'ORDER BY c.ordinal_position',
            ],
        ];
    }
}
