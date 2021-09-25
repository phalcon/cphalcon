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

namespace Phalcon\Tests\Integration\Mvc\Model\Manager;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Relations\RelationsParts;
use Phalcon\Tests\Models\Relations\RelationsRobots;

class ExistsHasManyToManyCest
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
     * Tests Phalcon\Mvc\Model\Manager :: existsHasManyToMany()
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     *
     * @dataProvider adaptersProvider
     */
    public function mvcModelManagerExistsHasManyToMany(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model\Manager - existsHasManyToMany()');

        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $manager = $this->container->getShared('modelsManager');

        $I->assertFalse(
            $manager->existsHasManyToMany(
                RelationsParts::class,
                RelationsRobots::class
            )
        );

        $I->assertTrue(
            $manager->existsHasManyToMany(
                RelationsRobots::class,
                RelationsParts::class
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
