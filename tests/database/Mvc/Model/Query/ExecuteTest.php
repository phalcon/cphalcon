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

namespace Phalcon\Tests\Database\Mvc\Model\Query;

use Phalcon\Mvc\Model\ResultsetInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ExecuteTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();

        $migration = new InvoicesMigration(self::getConnection());
        $migration->insert(1, 1, 0, 'Title 1');
        $migration->insert(2, 2, 1, 'Title 2');
    }

    /**
     * Tests Phalcon\Mvc\Model\Query :: execute()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryExecute(): void
    {
        $manager = $this->container->get('modelsManager');

        $query  = $manager->createQuery('SELECT * FROM ' . Invoices::class);
        $result = $query->execute();

        $this->assertInstanceOf(ResultsetInterface::class, $result);
        $this->assertSame(2, $result->count());
    }
}
