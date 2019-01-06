<?php

namespace Phalcon\Test\Integration\Mvc\Model;

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

    public function testModelsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
        $this->testIssue938($I);
        $this->testIssue11042($I);
    }

    private function executeTestsNormal(IntegrationTester $I)
    {
        $I->skipTest('TODO - Check the relationships - new model classes needed');
        $robot = RelationsRobots::findFirst();
        $I->assertNotEquals($robot, false);

        $robotsParts = $robot->getRelationsRobotsParts();
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(3, $robotsParts);

        $parts = $robot->getRelationsParts();
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $parts);
        $I->assertCount(3, $parts);

        $partsCount = $robot->countRelationsParts();
        $I->assertEquals(3, $partsCount);

        /** Passing parameters to magic methods **/
        $robotsParts = $robot->getRelationsRobotsParts("parts_id = 1");
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(1, $robotsParts);

        /** Passing parameters to magic methods **/
        $parts = $robot->getRelationsParts("RelationsParts.id = 1");
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $parts);
        $I->assertCount(1, $parts);

        $robotsParts = $robot->getRelationsRobotsParts([
            "parts_id > :parts_id:",
            "bind" => ["parts_id" => 1],
        ]);
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(2, $robotsParts);
        $I->assertEquals($robotsParts->getFirst()->parts_id, 2);

        $parts = $robot->getRelationsParts([
            "RelationsParts.id > :id:",
            "bind" => ["id" => 1],
        ]);
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $parts);
        $I->assertCount(2, $parts);
        $I->assertEquals($parts->getFirst()->id, 2);

        $robotsParts = $robot->getRelationsRobotsParts([
            "parts_id > :parts_id:",
            "bind"  => ["parts_id" => 1],
            "order" => "parts_id DESC",
        ]);
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(2, $robotsParts);
        $I->assertEquals($robotsParts->getFirst()->parts_id, 3);

        /** Magic counting */
        $number = $robot->countRelationsRobotsParts();
        $I->assertEquals($number, 3);

        $part = RelationsParts::findFirst();
        $I->assertNotEquals($part, false);

        $robotsParts = $part->getRelationsRobotsParts();
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(1, $robotsParts);

        $number = $part->countRelationsRobotsParts();
        $I->assertEquals($number, 1);

        $robotPart = RelationsRobotsParts::findFirst();
        $I->assertNotEquals($robotPart, false);

        $robot = $robotPart->getRelationsRobots();
        $I->assertInstanceOf('RelationsRobots', $robot);

        $part = $robotPart->getRelationsParts();
        $I->assertInstanceOf('RelationsParts', $part);

        /** Relations in namespaced models */
        $robot = Some\Robots::findFirst();
        $I->assertNotEquals($robot, false);

        $robotsParts = $robot->getRobotsParts();
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(3, $robotsParts);

        $robotsParts = $robot->getRobotsParts("parts_id = 1");
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(1, $robotsParts);

        $robotsParts = $robot->getRobotsParts([
            "parts_id > :parts_id:",
            "bind"  => ["parts_id" => 1],
            "order" => "parts_id DESC",
        ]);
        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robotsParts);
        $I->assertCount(2, $robotsParts);
        $I->assertEquals($robotsParts->getFirst()->parts_id, 3);
    }

    private function executeTestsRenamed(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');

        $success = $manager->existsBelongsTo(RobottersDeles::class, Robotters::class);
        $I->assertTrue($success);

        $success = $manager->existsBelongsTo(RobottersDeles::class, Deles::class);
        $I->assertTrue($success);

        $success = $manager->existsHasMany(Robotters::class, RobottersDeles::class);
        $I->assertTrue($success);

        $success = $manager->existsHasMany(Deles::class, RobottersDeles::class);
        $I->assertTrue($success);

        $robotter = Robotters::findFirst();
        $I->assertNotEquals($robotter, false);

        /**
         * @todo Check this
         */
//        $robottersDeles = $robotter->getRobottersDeles();
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
//        $I->assertCount(3, $robottersDeles);
//
//        /** Passing parameters to magic methods **/
//        $robottersDeles = $robotter->getRobottersDeles("delesCode = 1");
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
//        $I->assertCount(1, $robottersDeles);
//
//        $robottersDeles = $robotter->getRobottersDeles([
//            "delesCode > :delesCode:",
//            "bind" => ["delesCode" => 1],
//        ]);
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
//        $I->assertCount(2, $robottersDeles);
//        $I->assertEquals($robottersDeles->getFirst()->delesCode, 2);
//
//        $robottersDeles = $robotter->getRobottersDeles([
//            "delesCode > :delesCode:",
//            "bind"  => ["delesCode" => 1],
//            "order" => "delesCode DESC",
//        ]);
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
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
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
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
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
//        $I->assertCount(3, $robottersDeles);
//
//        $robottersDeles = $robotter->getRobottersDeles("delesCode = 1");
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
//        $I->assertCount(1, $robottersDeles);
//
//        $robottersDeles = $robotter->getRobottersDeles([
//            "delesCode > :delesCode:",
//            "bind"  => ["delesCode" => 1],
//            "order" => "delesCode DESC",
//        ]);
//        $I->assertInstanceOf('Phalcon\Mvc\Model\Resultset\Simple', $robottersDeles);
//        $I->assertCount(2, $robottersDeles);
//        $I->assertEquals($robottersDeles->getFirst()->delesCode, 3);
    }

    private function testIssue938(IntegrationTester $I)
    {
        $manager = $this->container->getShared('modelsManager');
        $db      = $this->container->getShared('db');

        $I->assertTrue($db->delete('m2m_robots_parts'));
        $I->assertTrue($db->delete('m2m_parts'));
        $I->assertTrue($db->delete('m2m_robots'));

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

        $I->assertTrue($part1->save());
        $I->assertTrue($part2->save());

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

    protected function testIssue11042(IntegrationTester $I)
    {
        $robot = RelationsRobots::findFirst();
        $I->assertNotEquals($robot, false);
        $I->assertEquals($robot->getDirtyState(), $robot::DIRTY_STATE_PERSISTENT);

        /**
         * @todo Check this
         */
//        $robotsParts = $robot->getRelationsRobotsParts();
//        $I->assertEquals($robot->getDirtyState(), $robot::DIRTY_STATE_PERSISTENT);
//        $I->assertInstanceOf('RelationsRobotsParts', $robotsParts->getFirst());

        $robot = RelationsRobots::findFirst();
        $I->assertNotEquals($robot, false);

        /**
         * @todo Check this
         */
//        $robotsParts = $robot->relationsRobotsParts;
//        $I->assertEquals($robot->getDirtyState(), $robot::DIRTY_STATE_PERSISTENT);
//        $I->assertInstanceOf('RelationsRobotsParts', $robotsParts->getFirst());
    }

    public function testModelsPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
        $this->testIssue11042($I);
    }

    public function testModelsSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
        $this->testIssue938($I);
        $this->testIssue11042($I);
    }
}
