<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Db\Dialect\Sqlite;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class AddIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: addIndex()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectSqliteAddIndex(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Sqlite - addIndex()");
        $data = $this->getAddIndexFixtures();
        foreach ($data as $item) {
            $schema   = $item[0];
            $index    = $item[1];
            $expected = $item[2];
            $dialect  = $this->getDialectSqlite();
            $indexes  = $this->getIndexes();
            $actual   = $dialect->addIndex('table', $schema, $indexes[$index]);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    protected function getAddIndexFixtures()
    {
        return [
            ['', 'index1', 'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1', 'CREATE INDEX "schema"."index1" ON "table" ("column1")'],
            ['', 'index2', 'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2', 'CREATE INDEX "schema"."index2" ON "table" ("column1", "column2")'],
        ];
    }
}
