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
final class ExistsHasOneThroughTest extends AbstractDatabaseTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author Balázs Németh <https://github.com/zsilbi>
     * @since  2019-11-02
     */
    public function testMvcModelManagerExistsHasOneThrough(): void
    {
        $manager = $this->container->getShared('modelsManager');

        $this->assertFalse(
            $manager->existsHasOneThrough(
                OrdersRelations::class,
                ProductsRelations::class
            )
        );

        $this->assertTrue(
            $manager->existsHasOneThrough(
                ProductsRelations::class,
                OrdersRelations::class
            )
        );
    }
}
