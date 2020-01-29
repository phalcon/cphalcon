<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Relations\Deles;
use Phalcon\Test\Models\Relations\M2MParts;
use Phalcon\Test\Models\Relations\M2MRobots;
use Phalcon\Test\Models\Relations\RelationsRobots;
use Phalcon\Test\Models\Relations\Robotters;
use Phalcon\Test\Models\Relations\RobottersDeles;

class ModelsRelationsCest
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
     * @dataProvider adaptersProvider
     */
    public function executeTestsNormal(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $I->skipTest('TODO - Check the relationships - new model classes needed');

        $robot = RelationsRobots::findFirst();

        $I->assertNotFalse($robot);


        $robotsParts = $robot->getRelationsRobotsParts();

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(3, $robotsParts);


        $parts = $robot->getRelationsParts();

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $parts
        );

        $I->assertCount(3, $parts);


        $partsCount = $robot->countRelationsParts();

        $I->assertEquals(3, $partsCount);


        /** Passing parameters to magic methods **/
        $robotsParts = $robot->getRelationsRobotsParts('parts_id = 1');

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(1, $robotsParts);


        /** Passing parameters to magic methods **/
        $parts = $robot->getRelationsParts('RelationsParts.id = 1');

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $parts
        );

        $I->assertCount(1, $parts);


        $robotsParts = $robot->getRelationsRobotsParts(
            [
                'parts_id > :parts_id:',
                'bind' => [
                    'parts_id' => 1,
                ],
            ]
        );

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(2, $robotsParts);

        $I->assertEquals(2, $robotsParts->getFirst()->parts_id);


        $parts = $robot->getRelationsParts(
            [
                'RelationsParts.id > :id:',
                'bind' => [
                    'id' => 1,
                ],
            ]
        );

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $parts
        );

        $I->assertCount(2, $parts);

        $I->assertEquals(2, $parts->getFirst()->id);


        $robotsParts = $robot->getRelationsRobotsParts(
            [
                'parts_id > :parts_id:',
                'bind'  => [
                    'parts_id' => 1,
                ],
                'order' => 'parts_id DESC',
            ]
        );

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(2, $robotsParts);

        $I->assertEquals(3, $robotsParts->getFirst()->parts_id);


        /** Magic counting */
        $number = $robot->countRelationsRobotsParts();

        $I->assertEquals(3, $number);


        $part = RelationsParts::findFirst();

        $I->assertNotFalse($part);


        $robotsParts = $part->getRelationsRobotsParts();

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(1, $robotsParts);


        $number = $part->countRelationsRobotsParts();

        $I->assertEquals(1, $number);


        $robotPart = RelationsRobotsParts::findFirst();

        $I->assertNotFalse($robotPart);


        $robot = $robotPart->getRelationsRobots();

        $I->assertInstanceOf(
            \RelationsRobots::class,
            $robot
        );


        $part = $robotPart->getRelationsParts();

        $I->assertInstanceOf(
            \RelationsParts::class,
            $part
        );


        /** Relations in namespaced models */
        $robot = Some\Robots::findFirst();

        $I->assertNotFalse($robot);


        $robotsParts = $robot->getRobotsParts();

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(3, $robotsParts);


        $robotsParts = $robot->getRobotsParts('parts_id = 1');

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(1, $robotsParts);


        $robotsParts = $robot->getRobotsParts(
            [
                'parts_id > :parts_id:',
                'bind'  => [
                    'parts_id' => 1,
                ],
                'order' => 'parts_id DESC',
            ]
        );

        $I->assertInstanceOf(
            \Phalcon\Mvc\Model\Resultset\Simple::class,
            $robotsParts
        );

        $I->assertCount(2, $robotsParts);

        $I->assertEquals(3, $robotsParts->getFirst()->parts_id);
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function executeTestsRenamed(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $manager = $this->container->getShared('modelsManager');

        $I->assertTrue(
            $manager->existsBelongsTo(
                RobottersDeles::class,
                Robotters::class
            )
        );

        $I->assertTrue(
            $manager->existsBelongsTo(
                RobottersDeles::class,
                Deles::class
            )
        );

        $I->assertTrue(
            $manager->existsHasMany(
                Robotters::class,
                RobottersDeles::class
            )
        );

        $I->assertTrue(
            $manager->existsHasMany(
                Deles::class,
                RobottersDeles::class
            )
        );


        $robotter = Robotters::findFirst();

        $I->assertNotFalse($robotter);


        /**
         * @todo Check this
         */
//        $robottersDeles = $robotter->getRobottersDeles();
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(3, $robottersDeles);
//
//        /** Passing parameters to magic methods **/
//        $robottersDeles = $robotter->getRobottersDeles("delesCode = 1");
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(1, $robottersDeles);
//
//        $robottersDeles = $robotter->getRobottersDeles([
//            "delesCode > :delesCode:",
//            "bind" => ["delesCode" => 1],
//        ]);
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(2, $robottersDeles);
//        $I->assertEquals($robottersDeles->getFirst()->delesCode, 2);
//
//        $robottersDeles = $robotter->getRobottersDeles([
//            "delesCode > :delesCode:",
//            "bind"  => ["delesCode" => 1],
//            "order" => "delesCode DESC",
//        ]);
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(2, $robottersDeles);
//        $I->assertEquals($robottersDeles->getFirst()->delesCode, 3);
//
//        /** Magic counting */
//        $number = $robotter->countRobottersDeles();
//        $I->assertEquals($number, 3);
//
//        $dele = Deles::findFirst();
//        $I->assertNotEquals($dele, false);
//
//        $robottersDeles = $dele->getRobottersDeles();
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(1, $robottersDeles);
//
//        $number = $dele->countRobottersDeles();
//        $I->assertEquals($number, 1);
//
//        $robotterDele = RobottersDeles::findFirst();
//        $I->assertNotEquals($robotterDele, false);
//
//        $robotter = $robotterDele->getRobotters();
//        $I->assertInstanceOf('Robotters', $robotter);
//
//        $dele = $robotterDele->getDeles();
//        $I->assertInstanceOf('Deles', $dele);
//
//        /** Relations in namespaced models */
//        $robotter = Some\Robotters::findFirst();
//        $I->assertNotEquals($robotter, false);
//
//        $robottersDeles = $robotter->getRobottersDeles();
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(3, $robottersDeles);
//
//        $robottersDeles = $robotter->getRobottersDeles("delesCode = 1");
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(1, $robottersDeles);
//
//        $robottersDeles = $robotter->getRobottersDeles([
//            "delesCode > :delesCode:",
//            "bind"  => ["delesCode" => 1],
//            "order" => "delesCode DESC",
//        ]);
//        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robottersDeles);
//        $I->assertCount(2, $robottersDeles);
//        $I->assertEquals($robottersDeles->getFirst()->delesCode, 3);
    }

    public function testIssue938Mysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->testIssue938($I);
    }

    public function testIssue938Sqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $I->skipTest('Check Sqlite - locking');

        $this->testIssue938($I);
    }

    private function testIssue938(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');
        $db      = $this->container->getShared('db');

        $I->assertTrue(
            $db->delete('m2m_robots_parts')
        );

        $I->assertTrue(
            $db->delete('m2m_parts')
        );

        $I->assertTrue(
            $db->delete('m2m_robots')
        );

        /**
         * @todo check this
         */
//        $success = $manager->existsHasManyToMany(M2MRobots::class, M2MParts::class);
//        $I->assertTrue($success);

        $robot       = new M2MRobots();
        $robot->name = 'M2M';

        $part1       = new M2MParts();
        $part1->name = 'Part 1';

        $part2       = new M2MParts();
        $part2->name = 'Part 2';

        $part3       = new M2MParts();
        $part3->name = 'Part 3';

        $part4       = new M2MParts();
        $part4->name = 'Part 4';

        $I->assertTrue(
            $part1->save()
        );

        $I->assertTrue(
            $part2->save()
        );

        /**
         * @todo Check this
         */
//        $robot->m2mparts = [$part1, $part2, $part3, $part4];
//
//        $I->assertTrue($robot->save());
//
//        $parts = M2MParts::find(['order' => 'id']);
//        $I->assertCount(4, $parts);
//
//        $rp = M2MRobotsParts::find(['order' => 'robots_id, parts_id']);
//        $I->assertCount(4, $rp);
//
//        for ($i = 0; $i < count($rp); ++$i) {
//            $I->assertEquals($parts[$i]->name, 'Part ' . ($i + 1));
//            $I->assertEquals($rp[$i]->parts_id, $parts[$i]->id);
//            $I->assertEquals($rp[$i]->robots_id, $robot->id);
//        }
    }

    /**
     * @dataProvider adaptersProvider
     */
    public function testIssue11042(IntegrationTester $I, Example $example)
    {
        $diFunction = 'setDi' . $example[0];

        $this->{$diFunction}();

        $robot = RelationsRobots::findFirst();

        $I->assertNotFalse($robot);

        $I->assertEquals(
            $robot::DIRTY_STATE_PERSISTENT,
            $robot->getDirtyState()
        );

        /**
         * @todo Check this
         */
//        $robotsParts = $robot->getRelationsRobotsParts();
//        $I->assertEquals($robot->getDirtyState(), $robot::DIRTY_STATE_PERSISTENT);
//        $I->assertInstanceOf('RelationsRobotsParts', $robotsParts->getFirst());

        $robot = RelationsRobots::findFirst();
        $I->assertNotFalse($robot);

        /**
         * @todo Check this
         */
//        $robotsParts = $robot->relationsRobotsParts;
//        $I->assertEquals($robot->getDirtyState(), $robot::DIRTY_STATE_PERSISTENT);
//        $I->assertInstanceOf('RelationsRobotsParts', $robotsParts->getFirst());
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
