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

namespace Phalcon\Test\Integration\Db\Dialect\Mysql;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class AddPrimaryKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addPrimaryKey()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getAddPrimaryKeyFixtures
     */
    public function dbDialectMysqlAddPrimaryKey(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Mysql - addPrimaryKey()");

        $data = $this->getAddPrimaryKeyFixtures();

        $schema    = $example[0];
        $reference = $example[1];
        $expected  = $example[2];

        $dialect = new Mysql();

        $indexes = $this->getIndexes();

        $actual = $dialect->addPrimaryKey('table', $schema, $indexes[$reference]);

        $I->assertEquals($expected, $actual);
    }

    protected function getAddPrimaryKeyFixtures(): array
    {
        return [
            [
                '',
                'PRIMARY',
                'ALTER TABLE `table` ADD PRIMARY KEY (`column3`)',
            ],
            [
                'schema',
                'PRIMARY',
                'ALTER TABLE `schema`.`table` ADD PRIMARY KEY (`column3`)',
            ],
        ];
    }
}
