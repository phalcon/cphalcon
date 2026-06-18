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

namespace Phalcon\Tests\Database\DataMapper\Pdo\Connection;

use Phalcon\DataMapper\Pdo\Connection;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use PHPUnit\Framework\Attributes\Group;

use function date;
use function str_replace;
use function uniqid;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class LastInsertIdTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-01-25
     */
    public function testDMPdoConnectionLastInsertId(): void
    {
        /** @var Connection $connection */
        $connection = self::getDataMapperConnection();
        $migration  = new InvoicesMigration(self::getConnection());
        $migration->clear();

        $title    = uniqid('inv-');
        $template = 'insert into co_invoices (inv_cst_id, inv_status_flag, '
            . 'inv_title, inv_total, inv_created_at) values ('
            . '1, 1, \'%title%\', %total%, \'%now%\')';

        $sql = str_replace(
            [
                '%title%',
                '%total%',
                '%now%',
            ],
            [
                $title,
                102,
                date('Y-m-d H:i:s'),
            ],
            $template
        );

        $result = $connection->exec($sql);
        $this->assertEquals(1, $result);

        $actual   = $connection->lastInsertId();
        $expected = $connection->fetchValue(
            'select inv_id from co_invoices where inv_title = \'' . $title . '\''
        );
        $this->assertEquals($expected, $actual);
    }
}
