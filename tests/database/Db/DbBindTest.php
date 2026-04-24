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

namespace Phalcon\Tests\Database\Db;

use Phalcon\Db\Column;
use Phalcon\Db\RawValue;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

final class DbBindTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Db :: convertBoundParams()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbBindConvertParams(): void
    {
        $db = $this->getService('db');

        $params = $db->convertBoundParams(
            'a=?0',
            [
                0 => 100,
            ]
        );

        $expected = [
            'sql'    => 'a=?',
            'params' => [
                0 => 100,
            ],
        ];
        $this->assertEquals($expected, $params);


        $params = $db->convertBoundParams(
            'a=?0',
            [
                0 => 100,
                1 => 50,
            ]
        );

        $expected = [
            'sql'    => 'a=?',
            'params' => [
                0 => 100,
            ],
        ];
        $this->assertEquals($expected, $params);


        $params = $db->convertBoundParams(
            'a=?1 AND b = ?0',
            [
                1 => 50,
                0 => 25,
            ]
        );

        $expected = [
            'sql'    => 'a=? AND b = ?',
            'params' => [
                0 => 50,
                1 => 25,
            ],
        ];
        $this->assertEquals($expected, $params);


        $params = $db->convertBoundParams(
            'a=?1 AND b = ?0',
            [
                1 => 25.10,
                0 => '25.10',
            ]
        );

        $expected = [
            'sql'    => 'a=? AND b = ?',
            'params' => [
                0 => '25.10',
                1 => 25.10,
            ],
        ];
        $this->assertEquals($expected, $params);


        $params = $db->convertBoundParams(
            'a=?1 AND b = ?0 AND c > :c: AND d = ?3',
            [
                'c' => 1000,
                1   => 'some-name',
                0   => 15,
                3   => 400,
            ]
        );

        $expected = [
            'sql'    => 'a=? AND b = ? AND c > ? AND d = ?',
            'params' => [
                0 => 'some-name',
                1 => 15,
                2 => 1000,
                3 => 400,
            ],
        ];
        $this->assertEquals($expected, $params);
    }

    /**
     * Tests Phalcon\Db :: execute() / insert() / update() with bind types
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     * @group  mysql
     * @group sqlite
     */
    public function testDbBindByType(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);

        $db = $this->getService('db');

        $success = $db->execute(
            'INSERT INTO co_invoices(inv_id, inv_cst_id, inv_status_flag, inv_title, inv_total)'
            . ' VALUES (' . $db->getDefaultIdValue() . ', ?, ?, ?, ?)',
            [1, 1, 'LOL 1', 100.00],
            [
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_DECIMAL,
            ]
        );
        $this->assertTrue($success);


        $success = $db->execute(
            'UPDATE co_invoices SET inv_title = ?, inv_status_flag = ?',
            ['LOL 11', 2],
            [
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_INT,
            ]
        );
        $this->assertTrue($success);


        $success = $db->execute(
            'DELETE FROM co_invoices WHERE inv_status_flag = ?',
            [2],
            [
                Column::BIND_PARAM_INT,
            ]
        );
        $this->assertTrue($success);


        $success = $db->insert(
            'co_invoices',
            [
                $db->getDefaultIdValue(),
                1,
                1,
                'LOL 1',
                100.00,
                null,
            ],
            null,
            [
                Column::BIND_SKIP,
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_DECIMAL,
                Column::BIND_SKIP,
            ]
        );
        $this->assertTrue($success);


        $success = $db->insert(
            'co_invoices',
            [1, 2, 'LOL 2', 200.00],
            ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total'],
            [
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_DECIMAL,
            ]
        );
        $this->assertTrue($success);


        $success = $db->insert(
            'co_invoices',
            [1, 3, 'LOL 3', 300.00],
            ['inv_cst_id', 'inv_status_flag', 'inv_title', 'inv_total'],
            [
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_INT,
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_DECIMAL,
            ]
        );
        $this->assertTrue($success);


        $success = $db->insert(
            'co_invoices',
            [
                new RawValue('current_date'),
                4,
            ],
            ['inv_title', 'inv_status_flag'],
            [
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_INT,
            ]
        );
        $this->assertTrue($success);


        $success = $db->update(
            'co_invoices',
            ['inv_title', 'inv_status_flag'],
            ['LOL 1000', 9],
            'inv_status_flag = 2',
            [
                Column::BIND_PARAM_STR,
                Column::BIND_PARAM_INT,
            ]
        );
        $this->assertTrue($success);


        $success = $db->update(
            'co_invoices',
            ['inv_title'],
            ['LOL 3000'],
            'inv_status_flag = 9',
            [
                Column::BIND_PARAM_STR,
            ]
        );
        $this->assertTrue($success);


        $success = $db->update(
            'co_invoices',
            ['inv_title'],
            [
                new RawValue('current_date'),
            ],
            'inv_status_flag = 9',
            [
                Column::BIND_PARAM_STR,
            ]
        );
        $this->assertTrue($success);
    }
}
