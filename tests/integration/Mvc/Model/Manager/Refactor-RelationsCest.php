<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Mvc\Model\Query;

use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Relations\RelationsParts;
use Phalcon\Test\Models\Relations\RelationsRobots;
use Phalcon\Test\Models\Relations\RelationsRobotsParts;

class RelationsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function relationsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->runBelongsTo($I);
        $this->runHasMany($I);
    }

    private function runBelongsTo(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $I->assertFalse($manager->existsBelongsTo(RelationsRobots::class, RelationsRobotsParts::class));
        $I->assertFalse($manager->existsBelongsTo(RelationsParts::class, RelationsRobotsParts::class));

        $I->assertTrue($manager->existsBelongsTo(RelationsRobotsParts::class, RelationsRobots::class));
        $I->assertTrue($manager->existsBelongsTo(RelationsRobotsParts::class, RelationsParts::class));
    }

    private function runHasMany(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $I->assertFalse($manager->existsHasMany(RelationsRobotsParts::class, RelationsRobots::class));
        $I->assertFalse($manager->existsHasMany(RelationsRobotsParts::class, RelationsParts::class));

        $I->assertTrue($manager->existsHasMany(RelationsRobots::class, RelationsRobotsParts::class));
        $I->assertTrue($manager->existsHasMany(RelationsParts::class, RelationsRobotsParts::class));
    }

    public function relationsPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->runBelongsTo($I);
        $this->runHasMany($I);
    }

    public function relationsSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $this->runBelongsTo($I);
        $this->runHasMany($I);
    }

    private function runHasManyToMany(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $I->assertFalse($manager->existsHasManyToMany(RelationsParts::class, RelationsRobots::class));
        $I->assertTrue($manager->existsHasManyToMany(RelationsRobots::class, RelationsParts::class));
    }
}
