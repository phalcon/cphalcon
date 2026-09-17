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
use Phalcon\Tests\Support\Fake\FakeDataMapperConnection;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class LimitOffsetTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectLimitOffset(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $select     = $factory->newSelect($connection);

        $select
            ->from('co_invoices')
            ->limit(10)
        ;

        $expected = "SELECT * FROM co_invoices LIMIT 10";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);

        $select->offset(50);

        $expected = "SELECT * FROM co_invoices LIMIT 10 OFFSET 50";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQuerySelectLimitOffsetMssql(): void
    {
        $connection     = self::getDataMapperConnection();
        $fakeConnection = new FakeDataMapperConnection(
            self::getDatabaseDsn(),
            self::getDatabaseUsername(),
            self::getDatabasePassword()
        );
        $fakeConnection->driverName = 'sqlsrv';

        $factory = new QueryFactory();
        $select  = $factory->newSelect($fakeConnection);

        $select
            ->from('co_invoices')
            ->limit(10)
        ;

        $expected = "SELECT TOP 10 * FROM co_invoices";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);

        $select->offset(50);

        $expected = "SELECT * FROM co_invoices "
            . "OFFSET 50 ROWS FETCH NEXT 10 ROWS ONLY";
        $actual   = $select->getStatement();
        $this->assertEquals($expected, $actual);
    }
}
