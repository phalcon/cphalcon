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

class AddPrimaryKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addPrimaryKey()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function testAddPrimaryKey(UnitTester $I)
    {
        $data = $this->getAddPrimaryKeyFixtures();
        foreach ($data as $item) {
            $schema    = $item[0];
            $reference = $item[1];
            $expected  = $item[2];
            $dialect   = $this->getDialectMysql();
            $indexes   = $this->getIndexes();
            $actual    = $dialect->addPrimaryKey('table', $schema, $indexes[$reference]);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    protected function getAddPrimaryKeyFixtures(): array
    {
        return [
            ['', 'PRIMARY', 'ALTER TABLE `table` ADD PRIMARY KEY (`column3`)'],
            ['schema', 'PRIMARY', 'ALTER TABLE `schema`.`table` ADD PRIMARY KEY (`column3`)'],
        ];
    }
}
