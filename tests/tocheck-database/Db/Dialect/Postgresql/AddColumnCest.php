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
use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class AddColumnCest
{
    use DialectTrait;

    /**
     * Tests Dialect::addColumn
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getAddColumnFixtures
     */
    public function dbDialectPostgresqlAddColumn(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Postgresql - addColumn()");

        $schema   = $example[0];
        $column   = $example[1];
        $expected = $example[2];
        $columns  = $this->getColumns();
        $dialect  = new Postgresql();
        $actual   = $dialect->addColumn(
            'table',
            $schema,
            $columns[$column]
        );

        $I->assertEquals($expected, $actual);
    }

    protected function getAddColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'ALTER TABLE "table" ADD COLUMN "column1" CHARACTER VARYING(10) NOT NULL',
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE "schema"."table" ADD COLUMN "column1" CHARACTER VARYING(10) NOT NULL',
            ],
            [
                '',
                'column2',
                'ALTER TABLE "table" ADD COLUMN "column2" INT NULL',
            ],
            [
                'schema',
                'column2',
                'ALTER TABLE "schema"."table" ADD COLUMN "column2" INT NULL',
            ],
            [
                '',
                'column3',
                'ALTER TABLE "table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL',
            ],
            [
                'schema',
                'column3',
                'ALTER TABLE "schema"."table" ADD COLUMN "column3" NUMERIC(10,2) NOT NULL',
            ],
            [
                '',
                'column4',
                'ALTER TABLE "table" ADD COLUMN "column4" CHARACTER(100) NOT NULL',
            ],
            [
                'schema',
                'column4',
                'ALTER TABLE "schema"."table" ADD COLUMN "column4" CHARACTER(100) NOT NULL',
            ],
            [
                '',
                'column5',
                'ALTER TABLE "table" ADD COLUMN "column5" DATE NOT NULL',
            ],
            [
                'schema',
                'column5',
                'ALTER TABLE "schema"."table" ADD COLUMN "column5" DATE NOT NULL',
            ],
            [
                '',
                'column6',
                'ALTER TABLE "table" ADD COLUMN "column6" TIMESTAMP NOT NULL',
            ],
            [
                'schema',
                'column6',
                'ALTER TABLE "schema"."table" ADD COLUMN "column6" TIMESTAMP NOT NULL',
            ],
            [
                '',
                'column7',
                'ALTER TABLE "table" ADD COLUMN "column7" TEXT NOT NULL',
            ],
            [
                'schema',
                'column7',
                'ALTER TABLE "schema"."table" ADD COLUMN "column7" TEXT NOT NULL',
            ],
            [
                '',
                'column8',
                'ALTER TABLE "table" ADD COLUMN "column8" FLOAT NOT NULL',
            ],
            [
                'schema',
                'column8',
                'ALTER TABLE "schema"."table" ADD COLUMN "column8" FLOAT NOT NULL',
            ],
            [
                '',
                'column9',
                'ALTER TABLE "table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT \'column9\' NOT NULL',
            ],
            [
                'schema',
                'column9',
                'ALTER TABLE "schema"."table" ADD COLUMN "column9" CHARACTER VARYING(10) DEFAULT \'column9\' NOT NULL',
            ],
            [
                '',
                'column10',
                'ALTER TABLE "table" ADD COLUMN "column10" INT DEFAULT 10 NULL',
            ],
            [
                'schema',
                'column10',
                'ALTER TABLE "schema"."table" ADD COLUMN "column10" INT DEFAULT 10 NULL',
            ],
            [
                '',
                'column11',
                'ALTER TABLE "table" ADD COLUMN "column11" BIGINT NULL',
            ],
            [
                'schema',
                'column11',
                'ALTER TABLE "schema"."table" ADD COLUMN "column11" BIGINT NULL',
            ],
            [
                '',
                'column12',
                'ALTER TABLE "table" ADD COLUMN "column12" ENUM(\'A\', \'B\', \'C\') DEFAULT \'A\' NOT NULL',
            ],
            [
                'schema',
                'column12',
                'ALTER TABLE "schema"."table" ADD COLUMN "column12" ENUM(\'A\', \'B\', \'C\') DEFAULT \'A\' NOT NULL',
            ],
            [
                '',
                'column13',
                'ALTER TABLE "table" ADD COLUMN "column13" TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
            [
                'schema',
                'column13',
                'ALTER TABLE "schema"."table" ADD COLUMN "column13" TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL',
            ],
        ];
    }
}
