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
use Phalcon\Tests\Support\Models\Invoices;
use Phalcon\Tests\Support\Models\InvoicesProducts;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class GetHasManyToManyTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->setDatabase();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: getHasManyToMany()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-06-22
     */
    public function testMvcModelManagerGetHasManyToMany(): void
    {
        $manager = new Manager();
        $manager->setDI($this->container);

        $invoice = new Invoices();

        $this->assertSame([], $manager->getHasManyToMany($invoice));

        $manager->addHasManyToMany(
            $invoice,
            'inv_id',
            InvoicesProducts::class,
            'inv_id',
            'prd_id',
            Products::class,
            'prd_id',
            ['alias' => 'products']
        );

        $relations = $manager->getHasManyToMany($invoice);

        $this->assertCount(1, $relations);
        $this->assertInstanceOf(RelationInterface::class, $relations[0]);
    }
}
