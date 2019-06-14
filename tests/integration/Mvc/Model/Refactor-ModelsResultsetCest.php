<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use AppendIterator;
use IntegrationTester;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Models\Robots;

class ModelsResultsetCest
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

    public function testResultsetNormalMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $robots = Robots::find(
            [
                'order' => 'id',
            ]
        );

        $this->applyTests($I, $robots);
    }

    private function applyTests(IntegrationTester $I, $robots)
    {
        $I->skipTest('TODO - Check the counts');
        $I->assertCount(3, $robots);
        $I->assertEquals($robots->count(), 3);

        //Using a foreach
        $number = 0;
        foreach ($robots as $robot) {
            $I->assertEquals($robot->id, $number + 1);
            $number++;
        }
        $I->assertEquals($number, 3);

        //Using a while
        $number = 0;
        $robots->rewind();
        while ($robots->valid()) {
            $robot = $robots->current();
            $I->assertEquals($robot->id, $number + 1);
            $robots->next();
            $number++;
        }
        $I->assertEquals($number, 3);

        $robots->seek(1);
        $robots->valid();
        $robot = $robots->current();
        $I->assertEquals($robot->id, 2);

        $robot = $robots->getFirst();
        $I->assertEquals($robot->id, 1);

        $robot = $robots->getLast();
        $I->assertEquals($robot->id, 3);

        $robot = $robots[0];
        $I->assertEquals($robot->id, 1);

        $robot = $robots[2];
        $I->assertEquals($robot->id, 3);

        $I->assertFalse(isset($robots[4]));

        $filtered = $robots->filter(function ($robot) {
            if ($robot->id < 3) {
                return $robot;
            }
        });

        $I->assertCount(2, $filtered);
        $I->assertEquals($filtered[0]->id, 1);
        $I->assertEquals($filtered[1]->id, 2);
    }

    public function testResultsetNormalPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();

        $robots = Robots::find(['order' => 'id']);

        $this->applyTests($I, $robots);
    }

    public function testResultsetNormalSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $robots = Robots::find(['order' => 'id']);

        $this->applyTests($I, $robots);
    }

    public function testResultsetBindingMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $initialId = 0;
        $finalId   = 4;

        $robots = Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]);

        $this->applyTests($I, $robots);
    }

    public function testResultsetBindingPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();

        $initialId = 0;
        $finalId   = 4;

        $robots = Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]);

        $this->applyTests($I, $robots);
    }

    public function testResultsetBindingSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $initialId = 0;
        $finalId   = 4;

        $robots = Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]);

        $this->applyTests($I, $robots);
    }

    public function testSerializeNormalMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $data   = serialize(Robots::find(['order' => 'id']));
        $robots = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);

        $this->applyTests($I, $robots);
    }

    public function testSerializeNormalPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();

        $data   = serialize(Robots::find(['order' => 'id']));
        $robots = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);

        $this->applyTests($I, $robots);
    }

    public function testSerializeNormalSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $data   = serialize(Robots::find(['order' => 'id']));
        $robots = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);

        $this->applyTests($I, $robots);
    }

    public function testSerializeBindingsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $initialId = 0;
        $finalId   = 4;

        $data = serialize(Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]));

        $robots = unserialize($data);
        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);

        $this->applyTests($I, $robots);
    }

    public function testSerializeBindingsPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();

        $initialId = 0;
        $finalId   = 4;

        $data = serialize(Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]));

        $robots = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);

        $this->applyTests($I, $robots);
    }

    public function testSerializeBindingsSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $initialId = 0;
        $finalId   = 4;

        $data = serialize(Robots::find([
            'conditions' => 'id > :id1: and id < :id2:',
            'bind'       => ['id1' => $initialId, 'id2' => $finalId],
            'order'      => 'id',
        ]));

        $robots = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $robots);

        $this->applyTests($I, $robots);
    }

    public function testSerializeBigMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $data = serialize(Personas::find([
            'limit' => 33,
        ]));

        $personas = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $personas);

        $this->applyTestsBig($I, $personas);
    }

    private function applyTestsBig(IntegrationTester $I, $personas)
    {
        $I->assertCount(33, $personas);
        $I->assertEquals($personas->count(), 33);

        //Using a foreach
        $number = 0;
        foreach ($personas as $persona) {
            $number++;
        }
        $I->assertEquals($number, 33);

        //Using a while
        $number = 0;
        $personas->rewind();
        while ($personas->valid()) {
            $persona = $personas->current();
            $personas->next();
            $number++;
        }
        $I->assertEquals($number, 33);

        $personas->seek(1);
        $personas->valid();
        $persona = $personas->current();
        $I->assertInstanceOf(Personas::class, $persona);

        $persona = $personas->getFirst();
        $I->assertInstanceOf(Personas::class, $persona);

        $persona = $personas->getLast();
        $I->assertInstanceOf(Personas::class, $persona);

        $persona = $personas[0];
        $I->assertInstanceOf(Personas::class, $persona);

        $persona = $personas[2];
        $I->assertInstanceOf(Personas::class, $persona);

        $I->assertFalse(isset($personas[40]));
    }

    public function testSerializeBigPostgresql(IntegrationTester $I)
    {
        $this->setupPostgres();

        $data = serialize(Personas::find([
            'limit' => 33,
        ]));

        $personas = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $personas);

        $this->applyTestsBig($I, $personas);
    }

    public function testSerializeBigSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        $data = serialize(Personas::find([
            'limit' => 33,
        ]));

        $personas = unserialize($data);

        $I->assertInstanceOf(\Phalcon\Mvc\Model\Resultset\Simple::class, $personas);

        $this->applyTestsBig($I, $personas);
    }

    public function testResultsetNormalZero(IntegrationTester $I)
    {
        $this->setDiMysql();

        $robots = Robots::find('id > 1000');

        $I->assertCount(0, $robots);
        $I->assertEquals($robots->count(), 0);

        //Using a foreach
        $number = 0;
        foreach ($robots as $robot) {
            $number++;
        }
        $I->assertEquals($number, 0);

        //Using a while
        $number = 0;
        $robots->rewind();
        while ($robots->valid()) {
            $robots->next();
            $number++;
        }
        $I->assertEquals($number, 0);

        $robots->seek(1);
        $robots->valid();
        $robot = $robots->current();
        $I->assertNull($robot);

        $robot = $robots->getFirst();
        $I->assertNull($robot);

        $robot = $robots->getLast();
        $I->assertNull($robot);

        /**
         * @todo Check the code below
         */
//        try {
//            $robot = $robots[0];
//            $I->assertFalse(true);
//        } catch (Exception $e) {
//            $I->assertEquals($e->getMessage(), 'The index does not exist in the cursor');
//        }
//
//        try {
//            $robot = $robots[2];
//            $I->assertFalse(true);
//        } catch (Exception $e) {
//            $I->assertEquals($e->getMessage(), 'The index does not exist in the cursor');
//        }

        $I->assertFalse(isset($robots[0]));
    }

    public function testResultsetAppendIterator(IntegrationTester $I)
    {
        $this->setDiMysql();

        // see http://php.net/manual/en/appenditerator.construct.php
        $iterator      = new AppendIterator();
        $robots_first  = Robots::find(['limit' => 2]);
        $robots_second = Robots::find(['limit' => 1, 'offset' => 2]);

        $robots_first_0  = $robots_first[0];
        $robots_first_1  = $robots_first[1];
        $robots_second_0 = $robots_second[0];

        $iterator->append($robots_first);
        $iterator->append($robots_second);

        $iterator->rewind();
        $I->assertTrue($iterator->valid());
        $I->assertEquals($iterator->key(), 0);
        $I->assertEquals($iterator->getIteratorIndex(), 0);
        $I->assertInstanceOf(Robots::class, $iterator->current());
        $I->assertEquals($robots_first_0->name, $iterator->current()->name);

        $iterator->next();
        $I->assertTrue($iterator->valid());
        $I->assertEquals($iterator->key(), 1);
        $I->assertEquals($iterator->getIteratorIndex(), 0);
        $I->assertInstanceOf(Robots::class, $iterator->current());
        $I->assertEquals($robots_first_1->name, $iterator->current()->name);

        $iterator->next();
        $I->assertTrue($iterator->valid());
        $I->assertEquals($iterator->key(), 0);
        $I->assertEquals($iterator->getIteratorIndex(), 1);
        $I->assertInstanceOf(Robots::class, $iterator->current());
        $I->assertEquals($robots_second_0->name, $iterator->current()->name);

        $iterator->next();
        $I->assertFalse($iterator->valid());
    }

    public function testBigResultsetIteration(IntegrationTester $I)
    {
        $this->setDiSqlite();

        // Resultsets count > 25 use fetch for one row at a time
        $personas = Personas::find([
            'limit' => 33,
        ]);

        $I->assertCount(33, $personas);

        $I->assertInstanceOf(Personas::class, $personas->getLast());

        // take first object as reference
        $persona_first = $personas[0];
        $I->assertInstanceOf(Personas::class, $persona_first);

        // make sure objects are the same -> object was not recreared
        $I->assertSame($personas[0], $persona_first);
        $I->assertSame($personas->current(), $persona_first);
        $personas->rewind();
        $I->assertTrue($personas->valid());
        $I->assertSame($personas->current(), $persona_first);

        // second element
        $personas->next();
        $I->assertTrue($personas->valid());
        $persona_second = $personas->current();
        $I->assertSame($persona_second, $personas[1]);

        // move to last element
        $I->assertSame($personas->getLast(), $personas[32]);

        // invalid element
        $personas->seek(33);
        $I->assertFalse($personas->valid());
        $I->assertNull($personas->current());

        /**
         * @todo Check the code below
         */
//        try {
//            $persona = $personas[33];
//            $I->assertFalse(true);
//        } catch (Exception $e) {
//            $I->assertEquals($e->getMessage(), 'The index does not exist in the cursor');
//        }

        // roll-back-cursor -> query needs to be reexecuted
        // first object was now recreated... different instance, but equal content
        $I->assertNotSame($personas[0], $persona_first);
        $I->assertEquals($personas[0], $persona_first);
        $persona_first = $personas[0];

        // toArray also re-executes the query and invalidates internal pointer
        $array = $personas->toArray();
        $I->assertCount(33, $array);

        // internal query is re-executed again and set to first
        $I->assertNotSame($personas[0], $persona_first);
        $I->assertEquals($personas[0], $persona_first);

        // move to second element and validate
        $personas->next();
        $I->assertTrue($personas->valid());
        $I->assertInstanceOf(Personas::class, $personas[1]);
        $I->assertSame($personas->current(), $personas[1]);
        $I->assertEquals($persona_second, $personas[1]);

        // pick some random indices
        $I->assertInstanceOf(Personas::class, $personas[12]);
        $I->assertInstanceOf(Personas::class, $personas[23]);
        $I->assertInstanceOf(Personas::class, $personas[23]);
    }
}
