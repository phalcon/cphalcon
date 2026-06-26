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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Migrations\InvoicesMigration;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetSingleResultTest extends AbstractDatabaseTestCase
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
     * Tests Phalcon\Mvc\Model\Query :: getSingleResult()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelQueryGetSingleResult(): void
    {
        $manager = $this->container->get('modelsManager');

        $query  = $manager->createQuery(
            'SELECT * FROM ' . Invoices::class . ' WHERE inv_id = 1'
        );
        $result = $query->getSingleResult();

        $this->assertInstanceOf(Invoices::class, $result);
        $this->assertEquals(1, $result->inv_id);
    }
}
