<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Database\DataMapper\Pdo\Connection;

use DatabaseTester;
use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Test\Fixtures\Migrations\InvoicesMigration;

use function date;
use function str_replace;
use function uniqid;

class LastInsertIdCest
{
    /**
     * Database Tests Phalcon\DataMapper\Pdo\Connection :: lastInsertId()
     *
     * @since  2020-01-25
     */
    public function dMPdoConnectionLastInsertId(DatabaseTester $I)
    {
        $I->wantToTest('DataMapper\Pdo\Connection - lastInsertId()');

        /** @var Connection $connection */
        $connection = $I->getDataMapperConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->clear();

        $template = 'insert into co_invoices (inv_id, inv_cst_id, inv_status_flag, '
            . 'inv_title, inv_total, inv_created_at) values ('
            . '%id%, 1, 1, "%title%", %total%, "%now%")';

        $sql = str_replace(
            [
                '%id%',
                '%title%',
                '%total%',
                '%now%',
            ],
            [
                2,
                uniqid(),
                102,
                date('Y-m-d H:i:s'),
            ],
            $template
        );

        $result = $connection->exec($sql);
        $I->assertEquals(1, $result);
        $I->assertEquals(2, $connection->lastInsertId());
    }
}
