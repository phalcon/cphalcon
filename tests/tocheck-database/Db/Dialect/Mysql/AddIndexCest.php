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

class AddIndexCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addIndex()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @dataProvider getAddIndexFixtures
     */
    public function dbDialectMysqlAddIndex(IntegrationTester $I, Example $example)
    {
        $I->wantToTest("Db\Dialect\Mysql - addIndex()");

        $schema   = $example[0];
        $index    = $example[1];
        $expected = $example[2];

        $dialect = new Mysql();
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
                'ALTER TABLE `table` ADD INDEX `index1` (`column1`)',
            ],
            [
                'schema',
                'index1',
                'ALTER TABLE `schema`.`table` ADD INDEX `index1` (`column1`)',
            ],
            [
                '',
                'index2',
                'ALTER TABLE `table` ADD INDEX `index2` (`column1`, `column2`)',
            ],
            [
                'schema',
                'index2',
                'ALTER TABLE `schema`.`table` ADD INDEX `index2` (`column1`, `column2`)',
            ],
            [
                '',
                'PRIMARY',
                'ALTER TABLE `table` ADD INDEX `PRIMARY` (`column3`)',
            ],
            [
                'schema',
                'PRIMARY',
                'ALTER TABLE `schema`.`table` ADD INDEX `PRIMARY` (`column3`)',
            ],
            [
                '',
                'index4',
                'ALTER TABLE `table` ADD UNIQUE INDEX `index4` (`column4`)',
            ],
            [
                'schema',
                'index4',
                'ALTER TABLE `schema`.`table` ADD UNIQUE INDEX `index4` (`column4`)',
            ],
        ];
    }
}
