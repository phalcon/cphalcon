<?php

namespace Phalcon\Test\Unit\Mvc\Model\Manager;

use Phalcon\Di;
use Helper\ModelTrait;
use Phalcon\Test\Module\UnitTest;
use Helper\Db\Connection\MysqlFactory;
use Helper\Db\Connection\SqliteFactory;
use Helper\Db\Connection\PostgresqlFactory;
use Phalcon\Test\Models\Relations\RelationsParts;
use Phalcon\Test\Models\Relations\RelationsRobots;
use Phalcon\Test\Models\Relations\RelationsRobotsParts;

class RelationsTest extends UnitTest
{
    use ModelTrait;

    /** @test */
    public function shouldDetectBelogsToRelations()
    {
        $this->specify(
            'Models manager detects belongsTo relationships wronng',
            function ($connection) {
                $manager = $this->setUpConnectionAwareModelsManager($connection);

                expect($manager->existsBelongsTo(RelationsRobots::class, RelationsRobotsParts::class))->false();
                expect($manager->existsBelongsTo(RelationsParts::class, RelationsRobotsParts::class))->false();

                expect($manager->existsBelongsTo(RelationsRobotsParts::class, RelationsRobots::class))->true();
                expect($manager->existsBelongsTo(RelationsRobotsParts::class, RelationsParts::class))->true();
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /** @test */
    public function shouldDetectHasManyRelations()
    {
        $this->specify(
            'Models manager detects hasMany relationships wronng',
            function ($connection) {
                $manager = $this->setUpConnectionAwareModelsManager($connection);

                expect($manager->existsHasMany(RelationsRobotsParts::class, RelationsRobots::class))->false();
                expect($manager->existsHasMany(RelationsRobotsParts::class, RelationsParts::class))->false();

                expect($manager->existsHasMany(RelationsRobots::class, RelationsRobotsParts::class))->true();
                expect($manager->existsHasMany(RelationsParts::class, RelationsRobotsParts::class))->true();
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /** @test */
    public function shouldDetectHasManyToManyRelations()
    {
        $this->specify(
            'Models manager detects hasManyToMany relationships wronng',
            function ($connection) {
                $manager = $this->setUpConnectionAwareModelsManager($connection);

                expect($manager->existsHasManyToMany(RelationsParts::class, RelationsRobots::class))->false();
                expect($manager->existsHasManyToMany(RelationsRobots::class, RelationsParts::class))->true();
            },
            ['examples' => $this->connectionProvider()]
        );
    }

    /**
     * @param string $connection
     * @return \Phalcon\Mvc\Model\Manager
     */
    protected function setUpConnectionAwareModelsManager($connection)
    {
        $factory = new $connection();
        $this->setUpModelsManager($factory->createConnection());

        $di = Di::getDefault();

        return $di->getShared('modelsManager');
    }

    protected function connectionProvider()
    {
        return [
            [MysqlFactory::class],
            [SqliteFactory::class],
            [PostgresqlFactory::class],
        ];
    }
}
