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

namespace Phalcon\Tests\Database\DataMapper\Query\Insert;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\DataMapper\Query\QueryFactory;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use PHPUnit\Framework\Attributes\Group;

use function uniqid;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetLastInsertIdTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQueryInsertGetLastInsertId(): void
    {
        $connection     = self::getDataMapperConnection();
        $mockConnection = $this->getMockBuilder(Connection::class)
            ->setConstructorArgs(
                [
                    self::getDatabaseDsn(),
                    self::getDatabaseUsername(),
                    self::getDatabasePassword(),
                ]
            )
            ->onlyMethods(['lastInsertId'])
            ->getMock()
        ;
        $mockConnection->method('lastInsertId')->willReturn("12345");

        $factory = new QueryFactory();
        $insert  = $factory->newInsert($mockConnection);

        $name = uniqid('inv-');
        $insert
            ->into('co_invoices')
            ->columns(
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => $name,
                    'inv_total'       => 100.00,
                ]
            )
            ->set(
                'inv_created_at',
                self::getDatabaseNow($connection->getDriverName())
            )
        ;

        $invId = $insert->getLastInsertId();
        $this->assertEquals("12345", $invId);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-20
     */
    public function testDMQueryInsertGetLastInsertIdReal(): void
    {
        $connection = self::getDataMapperConnection();
        $factory    = new QueryFactory();
        $insert     = $factory->newInsert($connection);
        (new InvoicesMigration(self::getConnection()));

        $name = uniqid('inv-');
        $insert
            ->into('co_invoices')
            ->columns(
                [
                    'inv_cst_id'      => 1,
                    'inv_status_flag' => 1,
                    'inv_title'       => $name,
                    'inv_total'       => 100.00,
                ]
            )
            ->set(
                'inv_created_at',
                self::getDatabaseNow($connection->getDriverName())
            )
        ;

        $insert->perform();
        $invId = $insert->getLastInsertId();

        $sql           = 'SELECT inv_id '
            . 'FROM co_invoices '
            . "WHERE inv_title = '" . $name . "'";
        $result        = $connection->fetchOne($sql);
        $existingInvId = $result['inv_id'];

        $this->assertEquals($existingInvId, $invId);
    }
}
