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

class AddIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: addIndex()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getAddIndexFixtures
     */
    public function dbDialectPostgresqlAddIndex(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Postgresql - addIndex()");

        $schema   = $example[0];
        $index    = $example[1];
        $expected = $example[2];

        $dialect = new Postgresql();
        $indexes = $this->getIndexes();

        $actual = $dialect->addIndex('table', $schema, $indexes[$index]);

        $I->assertEquals($expected, $actual);
    }

    protected function getAddIndexFixtures(): array
    {
        return [
            [
                '',
                'index1',
                'CREATE INDEX "index1" ON "table" ("column1")',
            ],
            [
                'schema',
                'index1',
                'CREATE INDEX "index1" ON "schema"."table" ("column1")',
            ],
            [
                '',
                'index2',
                'CREATE INDEX "index2" ON "table" ("column1", "column2")',
            ],
            [
                'schema',
                'index2',
                'CREATE INDEX "index2" ON "schema"."table" ("column1", "column2")',
            ],
            [
                '',
                'PRIMARY',
                'ALTER TABLE "table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")',
            ],
            [
                'schema',
                'PRIMARY',
                'ALTER TABLE "schema"."table" ADD CONSTRAINT "table_PRIMARY" PRIMARY KEY ("column3")',
            ],
            [
                '',
                'index4',
                'CREATE UNIQUE INDEX "index4" ON "table" ("column4")',
            ],
            [
                'schema',
                'index4',
                'CREATE UNIQUE INDEX "index4" ON "schema"."table" ("column4")',
            ],
        ];
    }
}
