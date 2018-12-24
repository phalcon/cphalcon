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

class AddForeignKeyCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: addForeignKey()
     *
     * @param IntegrationTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2017-02-26
     */
    public function dbDialectMysqlAddForeignKey(IntegrationTester $I)
    {
        $I->wantToTest("Db\Dialect\Mysql - addForeignKey()");
        $data = $this->getAddForeignKeyFixtures();
        foreach ($data as $item) {
            $schema     = $item[0];
            $reference  = $item[1];
            $expected   = $item[2];
            $dialect    = $this->getDialectMysql();
            $references = $this->getReferences();
            $actual     = $dialect->addForeignKey('table', $schema, $references[$reference]);

            $I->assertEquals($expected, $actual);
        }
    }

    /**
     * @return array
     */
    protected function getAddForeignKeyFixtures(): array
    {
        return [
            [
                '',
                'fk1',
                'ALTER TABLE `table` ADD CONSTRAINT `fk1` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)',
            ],
            [
                'schema',
                'fk1',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk1` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`)',
            ],
            [
                '',
                'fk2',
                'ALTER TABLE `table` ADD CONSTRAINT `fk2` ' .
                'FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)',
            ],
            [
                'schema',
                'fk2',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk2` ' .
                'FOREIGN KEY (`column3`, `column4`) REFERENCES `ref_table`(`column5`, `column6`)',
            ],
            [
                '',
                'fk3',
                'ALTER TABLE `table` ADD CONSTRAINT `fk3` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE',
            ],
            [
                'schema',
                'fk3',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk3` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE',
            ],
            [
                '',
                'fk4',
                'ALTER TABLE `table` ADD CONSTRAINT `fk4` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON UPDATE SET NULL',
            ],
            [
                'schema',
                'fk4',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk4` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON UPDATE SET NULL',
            ],
            [
                '',
                'fk5',
                'ALTER TABLE `table` ADD CONSTRAINT `fk5` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE ON UPDATE NO ACTION',
            ],
            [
                'schema',
                'fk5',
                'ALTER TABLE `schema`.`table` ADD CONSTRAINT `fk5` ' .
                'FOREIGN KEY (`column1`) REFERENCES `ref_table`(`column2`) ' .
                'ON DELETE CASCADE ON UPDATE NO ACTION',
            ],
        ];
    }
}
