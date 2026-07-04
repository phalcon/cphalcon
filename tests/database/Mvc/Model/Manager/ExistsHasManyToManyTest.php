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
use Phalcon\Tests\Support\Models\OrdersRelations;
use Phalcon\Tests\Support\Models\ProductsRelations;
use Phalcon\Tests\Support\Traits\DiTrait;
use PHPUnit\Framework\Attributes\Group;

#[Group('mysql')]
#[Group('pgsql')]
#[Group('sqlite')]
final class ExistsHasManyToManyTest extends AbstractDatabaseTestCase
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
    public function testMvcModelManagerExistsHasManyToMany(): void
    {
        $manager = $this->container->getShared('modelsManager');

        $this->assertFalse(
            $manager->existsHasManyToMany(
                ProductsRelations::class,
                OrdersRelations::class
            )
        );

        $this->assertTrue(
            $manager->existsHasManyToMany(
                OrdersRelations::class,
                ProductsRelations::class
            )
        );
    }
}
