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

namespace Phalcon\Test\Integration\Mvc\Model\Manager;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Relations\RelationsParts;
use Phalcon\Test\Models\Relations\RelationsRobots;
use Phalcon\Test\Models\Relations\RelationsRobotsParts;

class ExistsHasManyCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        $this->container['db']->close();
    }

    /**
     * Tests Phalcon\Mvc\Model\Manager :: existsHasMany()
     *
     * @dataProvider adaptersProvider
     */
    public function mvcModelManagerExistsHasMany(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model\Manager - existsHasMany()');

        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $manager = $this->container->getShared('modelsManager');

        $I->assertFalse(
            $manager->existsHasMany(
                RelationsRobotsParts::class,
                RelationsRobots::class
            )
        );

        $I->assertFalse(
            $manager->existsHasMany(
                RelationsRobotsParts::class,
                RelationsParts::class
            )
        );

        $I->assertTrue(
            $manager->existsHasMany(
                RelationsRobots::class,
                RelationsRobotsParts::class
            )
        );

        $I->assertTrue(
            $manager->existsHasMany(
                RelationsParts::class,
                RelationsRobotsParts::class
            )
        );
    }

    private function adaptersProvider(): array
    {
        return [
            [
                'Mysql',
            ],
            [
                'Postgresql',
            ],
            [
                'Sqlite',
            ],
        ];
    }
}
