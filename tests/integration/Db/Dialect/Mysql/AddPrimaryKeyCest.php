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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class AddPrimaryKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addPrimaryKey()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectMysqlAddPrimaryKey(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - addPrimaryKey()");
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
