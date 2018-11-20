<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect\Mysql;

use Phalcon\Test\Fixtures\Traits\DialectTrait;
use UnitTester;

class AddIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addIndex()
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
            $dialect    = $this->getDialectMysql();
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
            ['',       'index1',  'ALTER TABLE `table` ADD INDEX `index1` (`column1`)'],
            ['schema', 'index1',  'ALTER TABLE `schema`.`table` ADD INDEX `index1` (`column1`)'],
            ['',       'index2',  'ALTER TABLE `table` ADD INDEX `index2` (`column1`, `column2`)'],
            ['schema', 'index2',  'ALTER TABLE `schema`.`table` ADD INDEX `index2` (`column1`, `column2`)'],
            ['',       'PRIMARY', 'ALTER TABLE `table` ADD INDEX `PRIMARY` (`column3`)'],
            ['schema', 'PRIMARY', 'ALTER TABLE `schema`.`table` ADD INDEX `PRIMARY` (`column3`)'],
            ['',       'index4',  'ALTER TABLE `table` ADD UNIQUE INDEX `index4` (`column4`)'],
            ['schema', 'index4',  'ALTER TABLE `schema`.`table` ADD UNIQUE INDEX `index4` (`column4`)'],
        ];
    }
}
