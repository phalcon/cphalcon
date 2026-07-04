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

use Phalcon\Tests\AbstractDatabaseTestCase;
use Phalcon\Tests\Support\Models\OrdersProductsRelations;
use Phalcon\Tests\Support\Models\OrdersRelations;
use Phalcon\Tests\Support\Models\ProductsRelations;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ExistsBelongsToTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testMvcModelManagerExistsBelongsTo(): void
    {
        $manager = $this->container->getShared('modelsManager');

        $this->assertFalse(
            $manager->existsBelongsTo(
                OrdersRelations::class,
                OrdersProductsRelations::class
            )
        );

        $this->assertFalse(
            $manager->existsBelongsTo(
                ProductsRelations::class,
                OrdersProductsRelations::class
            )
        );

        $this->assertTrue(
            $manager->existsBelongsTo(
                OrdersProductsRelations::class,
                OrdersRelations::class
            )
        );

        $this->assertTrue(
            $manager->existsBelongsTo(
                OrdersProductsRelations::class,
                ProductsRelations::class
            )
        );
    }
}
