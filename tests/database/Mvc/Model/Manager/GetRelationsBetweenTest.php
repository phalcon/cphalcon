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

namespace Phalcon\Tests\Database\Mvc\Model\Manager;

use Phalcon\Mvc\Model\Manager;
use Phalcon\Mvc\Model\RelationInterface;
use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\Customers;
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetRelationsBetweenTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getRelationsBetween()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerGetRelationsBetween(): void
    {
        $manager = new Manager();
        $manager->setDI($this->container);

        $invoice = new Invoices();

        $manager->addBelongsTo($invoice, 'inv_cst_id', Customers::class, 'cst_id', ['alias' => 'customer']);

        $relations = $manager->getRelationsBetween(Invoices::class, Customers::class);

        $this->assertIsArray($relations);
        $this->assertCount(1, $relations);
        $this->assertInstanceOf(RelationInterface::class, $relations[0]);

        // No relationship registered between these two models.
        $this->assertFalse($manager->getRelationsBetween(Invoices::class, Products::class));
    }
}
