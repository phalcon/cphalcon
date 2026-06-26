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

namespace Phalcon\Tests\Database\DataMapper\Query\Select;

use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class WhereTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectOrWhereBind(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->appendWhere('inv_total > ', 100)
            ->orWhere("inv_status_flag = :status")
            ->bindValue('status', 1)
        ;

        $expected = "SELECT * FROM co_invoices "
            . "WHERE inv_total > :__1__ "
            . "OR inv_status_flag = :status";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);

        $expected = [
            '__1__'  => [100, 1],
            'status' => [1, 1],
        ];
        $actual   = $select->getBindValues();
        $this->assertEquals($expected, $actual);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectWhere(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->where('inv_id > ', 1)
        ;

        $expected = "SELECT * FROM co_invoices WHERE inv_id > :__1__";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);

        $expected = [
            '__1__' => [1, 1],
        ];
        $actual   = $select->getBindValues();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectWhereBind(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->where('inv_id > 1')
            ->andWhere('inv_total > :total')
            ->andWhere('inv_cst_id IN ', [1, 2, 3])
            ->appendWhere(' AND inv_status_flag = ' . $select->bindInline(1))
            ->bindValue('total', 100)
        ;

        $expected = "SELECT * FROM co_invoices "
            . "WHERE inv_id > 1 AND inv_total > :total "
            . "AND inv_cst_id IN (:__1__, :__2__, :__3__) "
            . "AND inv_status_flag = :__4__";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);

        $expected = [
            '__1__' => [1, 1],
            '__2__' => [2, 1],
            '__3__' => [3, 1],
            '__4__' => [1, 1],
            'total' => [100, 1],
        ];
        $actual   = $select->getBindValues();
        $this->assertEquals($expected, $actual);
    }
}
