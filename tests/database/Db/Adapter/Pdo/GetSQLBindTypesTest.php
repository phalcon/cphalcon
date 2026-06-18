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

use Phalcon\Db\Column;
use Phalcon\Events\Manager;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

final class GetSQLBindTypesTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: getSQLBindTypes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     */
    #[Group('mysql')]
    #[Group('pgsql')]
    #[Group('sqlite')]
    public function testDbAdapterPdoGetSQLBindTypes(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');
        $db->setEventsManager(new Manager());

        new InvoicesMigration($connection);

        $bindTypes = [Column::BIND_PARAM_INT];
        $db->query(
            'SELECT inv_id FROM co_invoices WHERE inv_id = ?',
            [1],
            $bindTypes
        );

        $this->assertSame($bindTypes, $db->getSQLBindTypes());
    }
}
