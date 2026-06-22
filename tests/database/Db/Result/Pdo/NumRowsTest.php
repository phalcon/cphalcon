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

namespace Phalcon\Tests\Database\Db\Result\Pdo;

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class NumRowsTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Db\Result\Pdo :: numRows()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testDbResultPdoNumRows(): void
    {
        $connection = self::getConnection();
        $migration  = new InvoicesMigration($connection);
        $migration->insert(1, 1, 1, 'title 1', 101);
        $migration->insert(2, 1, 1, 'title 2', 102);
        $migration->insert(3, 1, 1, 'title 3', 103);
        $migration->insert(4, 1, 1, 'title 4', 104);
        $migration->insert(5, 1, 1, 'title 5', 105);

        $db     = $this->container->get('db');
        $result = $db->query('SELECT * FROM co_invoices');

        $this->assertEquals(5, $result->numRows());
    }
}
