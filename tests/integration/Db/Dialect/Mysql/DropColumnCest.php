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

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DialectTrait;

class DropColumnCest
{
    use DialectTrait;

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: dropColumn()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     *
     * @dataProvider getDropColumnFixtures
     */
    public function dbDialectMysqlDropColumn(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Db\Dialect\Mysql - dropColumn()');

        $schema   = $example[0];
        $column   = $example[1];
        $expected = $example[2];

        $dialect = $this->getDialectMysql();

        $actual = $dialect->dropColumn('table', $schema, $column);

        $I->assertEquals($expected, $actual);
    }

    protected function getDropColumnFixtures(): array
    {
        return [
            [
                '',
                'column1',
                'ALTER TABLE `table` DROP COLUMN `column1`',
            ],
            [
                'schema',
                'column1',
                'ALTER TABLE `schema`.`table` DROP COLUMN `column1`',
            ],
        ];
    }
}
