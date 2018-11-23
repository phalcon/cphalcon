<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Db\Dialect\Sqlite;

use Phalcon\Test\Fixtures\Traits\DialectTrait;
use UnitTester;

class AddPrimaryKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Sqlite :: addPrimaryKey()
     *
     * @param UnitTester $I
     *
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2017-02-26
     */
    public function testAddPrimaryKey(UnitTester $I)
    {
        $data = $this->getAddPrimaryKeyFixtures();
        foreach ($data as $item) {
            $schema    = $item[0];
            $reference = $item[1];
            $expected  = $item[2];
            $dialect   = $this->getDialectSqlite();
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
        return [];
    }
}
