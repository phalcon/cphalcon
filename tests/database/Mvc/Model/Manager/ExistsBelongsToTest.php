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
use Phalcon\Tests\Support\Models\Relations\RelationsParts;
use Phalcon\Tests\Support\Models\Relations\RelationsRobots;
use Phalcon\Tests\Support\Models\Relations\RelationsRobotsParts;
use Phalcon\Tests\Support\Traits\DiTrait;

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
                RelationsRobots::class,
                RelationsRobotsParts::class
            )
        );

        $this->assertFalse(
            $manager->existsBelongsTo(
                RelationsParts::class,
                RelationsRobotsParts::class
            )
        );

        $this->assertTrue(
            $manager->existsBelongsTo(
                RelationsRobotsParts::class,
                RelationsRobots::class
            )
        );

        $this->assertTrue(
            $manager->existsBelongsTo(
                RelationsRobotsParts::class,
                RelationsParts::class
            )
        );
    }
}
