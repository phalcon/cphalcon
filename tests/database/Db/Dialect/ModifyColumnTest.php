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

use Phalcon\Db\Column;
use Phalcon\Db\Dialect\Mysql;
use Phalcon\Db\Dialect\Postgresql;
use Phalcon\Db\Dialect\Sqlite;
use Phalcon\Tests\AbstractDatabaseTestCase;

final class ModifyColumnTest extends AbstractDatabaseTestCase
{
    /**
     * @return array[]
     */
    public static function getDialects(): array
    {
        return [
            [
                Mysql::class,
                'ALTER TABLE `schema`.`table` '
                . 'CHANGE COLUMN `field_old` `field_new` INT(20) NOT NULL '
                . 'AUTO_INCREMENT COMMENT \'This is a comment\' '
                . 'AFTER `field_primary`',
            ],
//            [
//                Postgresql::class,
//                '',
//            ],
//            [
//                Sqlite::class,
//                '',
//            ],
        ];
    }

    /**
     * @return array[]
     */
    public static function getDialectsSame(): array
    {
        return [
            [
                Mysql::class,
                'ALTER TABLE `schema`.`table` '
                . 'MODIFY `field_old` INT(20) NULL '
                . 'DEFAULT 13 AFTER `field_primary`',
            ],
//            [
//                Postgresql::class,
//                '',
//            ],
//            [
//                Sqlite::class,
//                '4',
//            ],
        ];
    }

    /**
     * Tests Phalcon\Db\Dialect :: modifyColumn
     *
     * @dataProvider getDialects
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectModifyColumn(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $columnOld = new Column(
            'field_old',
            [
                'type'          => Column::TYPE_INTEGER,
                'isNumeric'     => true,
                'size'          => 10,
                'scale'         => null,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => true,
                'after'         => null,
                'comment'       => null,
                'bindType'      => Column::BIND_PARAM_INT,
            ]
        );
        $columnNew = new Column(
            'field_new',
            [
                'type'          => Column::TYPE_INTEGER,
                'isNumeric'     => true,
                'size'          => 20,
                'scale'         => null,
                'default'       => null,
                'unsigned'      => false,
                'notNull'       => true,
                'autoIncrement' => true,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_primary',
                'comment'       => 'This is a comment',
                'bindType'      => Column::BIND_PARAM_INT,
            ]
        );

        $actual = $dialect->modifyColumn(
            'table',
            'schema',
            $columnNew,
            $columnOld
        );
        $this->assertSame($expected, $actual);
    }

    /**
     * Tests Phalcon\Db\Dialect :: modifyColumn
     *
     * @dataProvider getDialectsSame
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2020-01-20
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbDialectModifyColumnSame(
        string $dialectClass,
        string $expected
    ): void {
        /** @var Mysql $dialect */
        $dialect = new $dialectClass();

        $columnOld = new Column(
            'field_old',
            [
                'type'          => Column::TYPE_INTEGER,
                'isNumeric'     => true,
                'size'          => 20,
                'scale'         => null,
                'default'       => 13,
                'unsigned'      => false,
                'notNull'       => false,
                'autoIncrement' => false,
                'primary'       => false,
                'first'         => false,
                'after'         => 'field_primary',
                'comment'       => null,
                'bindType'      => Column::BIND_PARAM_INT,
            ]
        );
        $actual    = $dialect->modifyColumn(
            'table',
            'schema',
            $columnOld
        );
        $this->assertSame($expected, $actual);
    }
}
