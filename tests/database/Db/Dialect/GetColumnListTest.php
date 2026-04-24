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

namespace Phalcon\Tests\Database\Db\Dialect;

use Phalcon\Db\Dialect\Mysql;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class GetColumnListTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getMysqlData(): array
    {
        return [
            [
                ['column1', 'column2', 'column3'],
                '`column1`, `column2`, `column3`',
            ],
            [
                ['foo'],
                '`foo`',
            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect\Mysql :: getColumnList
     *
     * @dataProvider getMysqlData
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2017-02-26
     *
     * @group mysql
     * @group sqlite
     */
    public function testDbDialectMysqlGetColumnList(
        array $columns,
        string $expected
    ): void {
        $dialect = new Mysql();
        $actual  = $dialect->getColumnList($columns);

        $this->assertIsString($actual);
        $this->assertSame($expected, $actual);
    }
}
