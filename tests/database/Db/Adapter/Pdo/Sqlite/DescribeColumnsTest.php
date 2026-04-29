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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo\Sqlite;

use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;

final class DescribeColumnsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    /**
     * Executed before each test
     *
     * @return void
     */
    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo\Sqlite :: describeColumns()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  sqlite
     */
    public function testDbAdapterPdoSqliteDescribeColumns(): void
    {
        $db = $this->container->get('db');

        $expected = $this->getExpectedColumnsSqlite();

        $this->assertEquals($expected, $db->describeColumns('co_invoices'));
        $this->assertEquals($expected, $db->describeColumns('co_invoices', 'main'));
    }

    /**
     * @return array<int, Column>
     */
    private function getExpectedColumnsSqlite(): array
    {
        return [
            0 => new Column(
                'inv_id',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => true,
                    'autoIncrement' => true,
                    'primary'       => true,
                    'first'         => true,
                    'after'         => '',
                    'bindType'      => 1,
                ]
            ),
            1 => new Column(
                'inv_cst_id',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'inv_id',
                    'bindType'      => 1,
                ]
            ),
            2 => new Column(
                'inv_status_flag',
                [
                    'type'          => 0,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'scale'         => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'inv_cst_id',
                    'bindType'      => 1,
                ]
            ),
            3 => new Column(
                'inv_title',
                [
                    'type'          => 6,
                    'isNumeric'     => false,
                    'size'          => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'inv_status_flag',
                    'bindType'      => 2,
                ]
            ),
            4 => new Column(
                'inv_total',
                [
                    'type'          => 7,
                    'isNumeric'     => true,
                    'size'          => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'inv_title',
                    'bindType'      => 32,
                ]
            ),
            5 => new Column(
                'inv_created_at',
                [
                    'type'          => 6,
                    'isNumeric'     => false,
                    'size'          => 0,
                    'default'       => null,
                    'unsigned'      => false,
                    'notNull'       => false,
                    'autoIncrement' => false,
                    'first'         => false,
                    'after'         => 'inv_total',
                    'bindType'      => 2,
                ]
            ),
        ];
    }
}
