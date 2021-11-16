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

namespace Phalcon\Tests\Integration\Db\Dialect\Sqlite;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\Fixtures\Traits\DialectTrait;

class AddIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: addIndex()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getAddIndexFixtures
     */
    public function dbDialectSqliteAddIndex(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Sqlite - addIndex()");

        $schema   = $example[0];
        $index    = $example[1];
        $expected = $example[2];

        $dialect = new Sqlite();
        $indexes = $this->getIndexes();

        $actual = $dialect->addIndex(
            'table',
            $schema,
            $indexes[$index]
        );

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
                'CREATE INDEX "schema"."index1" ON "table" ("column1")',
            ],
            [
                '',
                'index2',
                'CREATE INDEX "index2" ON "table" ("column1", "column2")',
            ],
            [
                'schema',
                'index2',
                'CREATE INDEX "schema"."index2" ON "table" ("column1", "column2")',
            ],
        ];
    }
}
