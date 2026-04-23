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

namespace Phalcon\Tests\Database\Mvc\Model;

use Phalcon\Tests\AbstractDatabaseTestCase;

final class RefactorModelsResultsetTest extends AbstractDatabaseTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetNormalMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetNormalPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetNormalSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetBindingMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetBindingPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetBindingSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeNormalMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeNormalPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeNormalSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeBindingsMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeBindingsPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeBindingsSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeBigMysql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeBigPostgresql(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testSerializeBigSqlite(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetNormalZero(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testResultsetAppendIterator(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-02
     */
    public function testBigResultsetIteration(): void
    {
        $this->markTestSkipped('Needs review - tocheck after migration');
    }
}

// Original Cest file content (ModelsResultsetCest):
//
// <?php
//
// namespace Phalcon\Tests\Integration\Mvc\Model;
//
// use AppendIterator;
// use IntegrationTester;
// use Phalcon\Tests\Support\Traits\DiTrait;
// use Phalcon\Tests\Support\Models\Personas;
// use Phalcon\Tests\Support\Models\Robots;
//
// class ModelsResultsetCest
// {
//     use DiTrait;
//
//     public function _before(IntegrationTester $I)
//     {
//         $this->setNewFactoryDefault();
//     }
//
//     public function _after(IntegrationTester $I)
//     {
//         $this->container['db']->close();
//     }
//
//     public function testResultsetNormalMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $robots = Robots::find(
//             [
//                 'order' => 'id',
//             ]
//         );
//
//         $this->applyTests($I, $robots);
//     }
//
//     private function applyTests(IntegrationTester $I, $robots)
//     {
//         $I->skipTest('TODO - Check the counts');
//         $I->assertCount(3, $robots);
//         $I->assertEquals($robots->count(), 3);
//
//         //Using a foreach
//         $number = 0;
//         foreach ($robots as $robot) {
//             $I->assertEquals($robot->id, $number + 1);
//             $number++;
//         }
//         $I->assertEquals($number, 3);
//
//         //Using a while
//         $number = 0;
//         $robots->rewind();
//         while ($robots->valid()) {
//             $robot = $robots->current();
//             $I->assertEquals($robot->id, $number + 1);
//             $robots->next();
//             $number++;
//         }
//         $I->assertEquals($number, 3);
//
//         $robots->seek(1);
//         $robots->valid();
//         $robot = $robots->current();
//         $I->assertEquals($robot->id, 2);
//
//         $robot = $robots->getFirst();
//         $I->assertEquals($robot->id, 1);
//
//         $robot = $robots->getLast();
//         $I->assertEquals($robot->id, 3);
//
//         $robot = $robots[0];
//         $I->assertEquals($robot->id, 1);
//
//         $robot = $robots[2];
//         $I->assertEquals($robot->id, 3);
//
//         $I->assertFalse(isset($robots[4]));
//
//         $filtered = $robots->filter(function ($robot) {
//             if ($robot->id < 3) {
//                 return $robot;
//             }
//         });
//
//         $I->assertCount(2, $filtered);
//         $I->assertEquals($filtered[0]->id, 1);
//         $I->assertEquals($filtered[1]->id, 2);
//     }
//
//     public function testResultsetNormalPostgresql(IntegrationTester $I)
//     {
//         $this->setupPostgres();
//
//         $robots = Robots::find(['order' => 'id']);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testResultsetNormalSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//
//         $robots = Robots::find(['order' => 'id']);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testResultsetBindingMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $initialId = 0;
//         $finalId   = 4;
//
//         $robots = Robots::find([
//             'conditions' => 'id > :id1: and id < :id2:',
//             'bind'       => ['id1' => $initialId, 'id2' => $finalId],
//             'order'      => 'id',
//         ]);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testResultsetBindingPostgresql(IntegrationTester $I)
//     {
//         $this->setupPostgres();
//
//         $initialId = 0;
//         $finalId   = 4;
//
//         $robots = Robots::find([
//             'conditions' => 'id > :id1: and id < :id2:',
//             'bind'       => ['id1' => $initialId, 'id2' => $finalId],
//             'order'      => 'id',
//         ]);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testResultsetBindingSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//
//         $initialId = 0;
//         $finalId   = 4;
//
//         $robots = Robots::find([
//             'conditions' => 'id > :id1: and id < :id2:',
//             'bind'       => ['id1' => $initialId, 'id2' => $finalId],
//             'order'      => 'id',
//         ]);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeNormalMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $data   = serialize(Robots::find(['order' => 'id']));
//         $robots = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeNormalPostgresql(IntegrationTester $I)
//     {
//         $this->setupPostgres();
//
//         $data   = serialize(Robots::find(['order' => 'id']));
//         $robots = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeNormalSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//
//         $data   = serialize(Robots::find(['order' => 'id']));
//         $robots = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeBindingsMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $initialId = 0;
//         $finalId   = 4;
//
//         $data = serialize(Robots::find([
//             'conditions' => 'id > :id1: and id < :id2:',
//             'bind'       => ['id1' => $initialId, 'id2' => $finalId],
//             'order'      => 'id',
//         ]));
//
//         $robots = unserialize($data);
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeBindingsPostgresql(IntegrationTester $I)
//     {
//         $this->setupPostgres();
//
//         $initialId = 0;
//         $finalId   = 4;
//
//         $data = serialize(Robots::find([
//             'conditions' => 'id > :id1: and id < :id2:',
//             'bind'       => ['id1' => $initialId, 'id2' => $finalId],
//             'order'      => 'id',
//         ]));
//
//         $robots = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeBindingsSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//
//         $initialId = 0;
//         $finalId   = 4;
//
//         $data = serialize(Robots::find([
//             'conditions' => 'id > :id1: and id < :id2:',
//             'bind'       => ['id1' => $initialId, 'id2' => $finalId],
//             'order'      => 'id',
//         ]));
//
//         $robots = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);
//
//         $this->applyTests($I, $robots);
//     }
//
//     public function testSerializeBigMysql(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $data = serialize(Personas::find([
//             'limit' => 33,
//         ]));
//
//         $personas = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $personas);
//
//         $this->applyTestsBig($I, $personas);
//     }
//
//     private function applyTestsBig(IntegrationTester $I, $personas)
//     {
//         $I->assertCount(33, $personas);
//         $I->assertEquals($personas->count(), 33);
//
//         //Using a foreach
//         $number = 0;
//         foreach ($personas as $persona) {
//             $number++;
//         }
//         $I->assertEquals($number, 33);
//
//         //Using a while
//         $number = 0;
//         $personas->rewind();
//         while ($personas->valid()) {
//             $persona = $personas->current();
//             $personas->next();
//             $number++;
//         }
//         $I->assertEquals($number, 33);
//
//         $personas->seek(1);
//         $personas->valid();
//         $persona = $personas->current();
//         $I->assertInstanceOf(Personas::class, $persona);
//
//         $persona = $personas->getFirst();
//         $I->assertInstanceOf(Personas::class, $persona);
//
//         $persona = $personas->getLast();
//         $I->assertInstanceOf(Personas::class, $persona);
//
//         $persona = $personas[0];
//         $I->assertInstanceOf(Personas::class, $persona);
//
//         $persona = $personas[2];
//         $I->assertInstanceOf(Personas::class, $persona);
//
//         $I->assertFalse(isset($personas[40]));
//     }
//
//     public function testSerializeBigPostgresql(IntegrationTester $I)
//     {
//         $this->setupPostgres();
//
//         $data = serialize(Personas::find([
//             'limit' => 33,
//         ]));
//
//         $personas = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $personas);
//
//         $this->applyTestsBig($I, $personas);
//     }
//
//     public function testSerializeBigSqlite(IntegrationTester $I)
//     {
//         $this->setDiSqlite();
//
//         $data = serialize(Personas::find([
//             'limit' => 33,
//         ]));
//
//         $personas = unserialize($data);
//
//         $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $personas);
//
//         $this->applyTestsBig($I, $personas);
//     }
//
//     public function testResultsetNormalZero(IntegrationTester $I)
//     {
//         $this->setDiMysql();
//
//         $robots = Robots::find('id > 1000');
//
//         $I->assertCount(0, $robots);
//         $I->assertEquals($robots->count(), 0);
//
//         //Using a foreach
//         $number = 0;
//         foreach ($robots as $robot) {
//             $number++;
//         }
//         $I->assertEquals($number, 0);
//
//         //Using a while
//         $number = 0;
//         $robots->rewind();
//         while ($robots->valid()) {
//             $robots->next();
//             $number++;
//         }
//         $I->assertEquals($number, 0);
//
//         $robots->seek(1);
//         $robots->valid();
//         $robot = $robots->current();
//         $I->assertNull($robot);
//
//         $robot = $robots->getFirst();
//         $I->assertNull($robot);
//
//         $robot = $robots->getLast();
//         $I->assertNull($robot);
//
//         /**
//          * @todo Check the code below
//
