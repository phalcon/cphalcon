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

use PDOStatement;
use Phalcon\Db\Column;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;

final class ExecutePreparedTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Adapter\Pdo :: executePrepared()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-05-18
     *
     * @group mysql
     * @group pgsql
     * @group sqlite
     */
    public function testDbAdapterPdoExecutePrepared(): void
    {
        $connection = self::getConnection();
        $db         = $this->container->get('db');

        $migration = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'prepared 1', 11.0);
        $migration->insert(2, 1, 1, 'prepared 2', 22.0);

        $stmt = $db->prepare('SELECT inv_title FROM co_invoices WHERE inv_id = ?');
        $result = $db->executePrepared(
            $stmt,
            [0 => 2],
            [0 => Column::BIND_PARAM_INT]
        );

        $this->assertInstanceOf(PDOStatement::class, $result);
        $row = $result->fetch();
        $this->assertSame('prepared 2', $row['inv_title']);
    }
}
