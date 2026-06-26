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

use PDO;
use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class JoinTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectJoinInner(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_INNER, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "INNER JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectJoinLeft(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_LEFT, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "LEFT JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectJoinNatural(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_NATURAL, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "NATURAL JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectJoinRight(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join($select::JOIN_RIGHT, 'co_customers', 'inv_cst_id = cst_id')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "RIGHT JOIN co_customers ON inv_cst_id = cst_id";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectJoinWithBind(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->join(
                $select::JOIN_LEFT,
                'co_customers',
                'inv_cst_id = cst_id AND cst_status_flag = ',
                1
            )
            ->appendJoin(' AND cst_name LIKE ', '%john%')
        ;

        $expected = "SELECT * FROM co_invoices "
            . "LEFT JOIN co_customers ON inv_cst_id = cst_id "
            . "AND cst_status_flag = :__1__ AND cst_name LIKE :__2__";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);

        $expected = [
            '__1__' => [1, PDO::PARAM_INT],
            '__2__' => ['%john%', PDO::PARAM_STR],
        ];
        $actual   = $select->getBindValues();
        $this->assertEquals($expected, $actual);
    }
}
