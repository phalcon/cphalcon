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

class ExistsHasOneThroughCest
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
     * Tests Phalcon\Mvc\Model\Manager :: existsHasOneThrough()
     *
     * @author       Balázs Németh <https://github.com/zsilbi>
     * @since        2019-11-02
     *
     * @dataProvider adaptersProvider
     */
    public function mvcModelManagerExistsHasOneThrough(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Mvc\Model\Manager - existsHasOneThrough()');

        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $manager = $this->container->getShared('modelsManager');

        $I->assertFalse(
            $manager->existsHasOneThrough(
                RelationsRobots::class,
                RelationsParts::class
            )
        );

        $I->assertTrue(
            $manager->existsHasOneThrough(
                RelationsParts::class,
                RelationsRobots::class
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
