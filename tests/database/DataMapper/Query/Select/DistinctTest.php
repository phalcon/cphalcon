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
final class DistinctTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectDistinct(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->distinct()
            ->from('co_invoices')
            ->columns(['inv_id', 'inc_cst_id'])
        ;

        $expected = "SELECT DISTINCT inv_id, inc_cst_id FROM co_invoices";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectDistinctTwice(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->distinct()
            ->distinct()
            ->from('co_invoices')
            ->columns(['inv_id', 'inc_cst_id'])
        ;

        $expected = "SELECT DISTINCT inv_id, inc_cst_id FROM co_invoices";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectDistinctUnset(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->distinct()
            ->distinct(false)
            ->from('co_invoices')
            ->columns(['inv_id', 'inc_cst_id'])
        ;

        $expected = "SELECT inv_id, inc_cst_id FROM co_invoices";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }
}
