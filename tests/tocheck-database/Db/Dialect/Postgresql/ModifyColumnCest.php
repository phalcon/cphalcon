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
use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class ModifyColumnCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: modifyColumn()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getModifyColumnFixtures
     */
    public function dbDialectPostgresqlModifyColumn(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Postgresql - modifyColumn()');

        $columns  = $this->getColumns();
        $schema   = $example[0];
        $to       = $columns[$example[1]];
        $from     = $columns[$example[2]] ?? null;
        $expected = $example[3];

        $dialect = new Postgresql();

        $actual = $dialect->modifyColumn(
            'table',
            $schema,
            $to,
            $from
        );

        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: modifyColumn() - bug 13012
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-01-20
     * @issue  https://github.com/phalcon/cphalcon/issues/13012
     */
    public function testModifyColumn13012(IntegrationTester $I)
    {
        $oldColumn = new Column(
            'old',
            [
                'type' => Column::TYPE_VARCHAR,
            ]
        );

        $newColumn = new Column(
            'new',
            [
                'type' => Column::TYPE_VARCHAR,
            ]
        );

        $dialect = new Postgresql();

        $actual = $dialect->modifyColumn(
            'table',
            'database',
            $newColumn,
            $oldColumn
        );

        $I->assertEquals(
            'ALTER TABLE "database"."table" RENAME COLUMN "old" TO "new";',
            $actual
        );
    }

    protected function getModifyColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column1";' .
                'ALTER TABLE "table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);',
            ],
            [
                'schema',
                'column1',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column1";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column1" TYPE CHARACTER VARYING(10);',
            ],
            [
                '',
                'column2',
                'column1',
                'ALTER TABLE "table" RENAME COLUMN "column1" TO "column2";' .
                'ALTER TABLE "table" ALTER COLUMN "column2" TYPE INT;',
            ],
            [
                'schema',
                'column2',
                'column1',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column1" TO "column2";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column2" TYPE INT;',
            ],
            [
                '',
                'column3',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column3";' .
                'ALTER TABLE "table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);' .
                'ALTER TABLE "table" ALTER COLUMN "column3" SET NOT NULL;',
            ],
            [
                'schema',
                'column3',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column3";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column3" TYPE NUMERIC(10,2);' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column3" SET NOT NULL;',
            ],
            [
                '',
                'column4',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column4";' .
                'ALTER TABLE "table" ALTER COLUMN "column4" TYPE CHARACTER(100);' .
                'ALTER TABLE "table" ALTER COLUMN "column4" SET NOT NULL;',
            ],
            [
                'schema',
                'column4',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column4";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column4" TYPE CHARACTER(100);' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column4" SET NOT NULL;',
            ],
            [
                '',
                'column5',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column5";' .
                'ALTER TABLE "table" ALTER COLUMN "column5" TYPE DATE;' .
                'ALTER TABLE "table" ALTER COLUMN "column5" SET NOT NULL;',
            ],
            [
                'schema',
                'column5',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column5";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column5" TYPE DATE;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column5" SET NOT NULL;',
            ],
            [
                '',
                'column6',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column6";' .
                'ALTER TABLE "table" ALTER COLUMN "column6" TYPE TIMESTAMP;' .
                'ALTER TABLE "table" ALTER COLUMN "column6" SET NOT NULL;',
            ],
            [
                'schema',
                'column6',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column6";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column6" TYPE TIMESTAMP;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column6" SET NOT NULL;',
            ],
            [
                '',
                'column7',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column7";' .
                'ALTER TABLE "table" ALTER COLUMN "column7" TYPE TEXT;' .
                'ALTER TABLE "table" ALTER COLUMN "column7" SET NOT NULL;',
            ],
            [
                'schema',
                'column7',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column7";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column7" TYPE TEXT;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column7" SET NOT NULL;',
            ],
            [
                '',
                'column8',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column8";' .
                'ALTER TABLE "table" ALTER COLUMN "column8" TYPE FLOAT;' .
                'ALTER TABLE "table" ALTER COLUMN "column8" SET NOT NULL;',
            ],
            [
                'schema',
                'column8',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column8";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column8" TYPE FLOAT;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column8" SET NOT NULL;',
            ],
            [
                '',
                'column9',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column9";' .
                'ALTER TABLE "table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);' .
                'ALTER TABLE "table" ALTER COLUMN "column9" SET DEFAULT \'column9\'',
            ],
            [
                'schema',
                'column9',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column9";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column9" TYPE CHARACTER VARYING(10);' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column9" SET DEFAULT \'column9\'',
            ],
            [
                '',
                'column10',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column10";' .
                'ALTER TABLE "table" ALTER COLUMN "column10" SET DEFAULT 10',
            ],
            [
                'schema',
                'column10',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column10";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column10" SET DEFAULT 10',
            ],
            [
                '',
                'column11',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column11";' .
                'ALTER TABLE "table" ALTER COLUMN "column11" TYPE BIGINT;',
            ],
            [
                'schema',
                'column11',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column11";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column11" TYPE BIGINT;',
            ],
            [
                '',
                'column12',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column12";' .
                'ALTER TABLE "table" ALTER COLUMN "column12" TYPE ENUM(\'A\', \'B\', \'C\');' .
                'ALTER TABLE "table" ALTER COLUMN "column12" SET NOT NULL;' .
                'ALTER TABLE "table" ALTER COLUMN "column12" SET DEFAULT \'A\'',
            ],
            [
                'schema',
                'column12',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column12";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column12" TYPE ENUM(\'A\', \'B\', \'C\');' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET NOT NULL;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column12" SET DEFAULT \'A\'',
            ],
            [
                '',
                'column13',
                'column2',
                'ALTER TABLE "table" RENAME COLUMN "column2" TO "column13";' .
                'ALTER TABLE "table" ALTER COLUMN "column13" TYPE TIMESTAMP;' .
                'ALTER TABLE "table" ALTER COLUMN "column13" SET NOT NULL;' .
                'ALTER TABLE "table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP',
            ],
            [
                'schema',
                'column13',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column13";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" TYPE TIMESTAMP;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET NOT NULL;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP',
            ],
            [
                'schema',
                'column25',
                'column2',
                'ALTER TABLE "schema"."table" RENAME COLUMN "column2" TO "column13";' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" TYPE TIMESTAMP;' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET NOT NULL;' .
                'COMMENT ON COLUMN "schema"."table"."column13" is \'test\';' .
                'ALTER TABLE "schema"."table" ALTER COLUMN "column13" SET DEFAULT CURRENT_TIMESTAMP',
            ],
        ];
    }
}
