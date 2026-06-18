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

namespace Phalcon\Tests\Database\Db\Adapter\Pdo;

use Phalcon\Db\Enum;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class InsertAsDictTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: insertAsDict()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoInsertAsDict(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        new InvoicesMigration($connection);

        $success = $db->insertAsDict(
            'co_invoices',
            [
                'inv_cst_id'      => 1,
                'inv_status_flag' => 5,
                'inv_title'       => 'InsertAsDict test',
                'inv_total'       => 333.33,
            ]
        );
        $this->assertTrue($success);

        $row = $db->fetchOne(
            'SELECT inv_cst_id, inv_status_flag, inv_title, inv_total '
            . 'FROM co_invoices WHERE inv_title = ?',
            Enum::FETCH_ASSOC,
            ['InsertAsDict test']
        );

        $this->assertNotEmpty($row);
        $this->assertSame(1, (int) $row['inv_cst_id']);
        $this->assertSame(5, (int) $row['inv_status_flag']);
        $this->assertSame('InsertAsDict test', $row['inv_title']);
        $this->assertSame(333.33, (float) $row['inv_total']);
    }
}
