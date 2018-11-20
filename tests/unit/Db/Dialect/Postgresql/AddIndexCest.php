<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect\Postgresql;

use Phalcon\Test\Fixtures\Traits\DialectTrait;
use UnitTester;

class AddIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Postgresql :: addIndex()
     *
     * @param UnitTester $I
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testAddIndex(UnitTester $I)
    {
        $data = $this->getAddIndexFixtures();
        foreach ($data as $item) {
            $schema     = $item[0];
            $index      = $item[1];
            $expected   = $item[2];
            $dialect    = $this->getDialectPostgresql();
            $indexes    = $this->getIndexes();
            $actual     = $dialect->addIndex('table', $schema, $indexes[$index]);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    protected function getAddIndexFixtures()
    {
        return [
            ['',       'index1',  'CREATE INDEX "index1" ON "table" ("column1")'],
            ['schema', 'index1',  'CREATE INDEX "index1" ON "schema"."table" ("column1")'],
            ['',       'index2',  'CREATE INDEX "index2" ON "table" ("column1", "column2")'],
            ['schema', 'index2',  'CREATE INDEX "index2" ON "schema"."table" ("column1", "column2")'],
            ['',       'PRIMARY', 'ALTER TABLE "table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")'],
            ['schema', 'PRIMARY', 'ALTER TABLE "schema"."table" ADD CONSTRAINT "PRIMARY" PRIMARY KEY ("column3")'],
            ['',       'index4',  'CREATE UNIQUE INDEX "index4" ON "table" ("column4")'],
            ['schema', 'index4',  'CREATE UNIQUE INDEX "index4" ON "schema"."table" ("column4")'],
        ];
    }
}
