<?php

namespace Phalcon\Test\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Db\RawValue;
use Phalcon\Messages\Message as ModelMessage;
use Phalcon\Mvc\Model;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Childs;
use Phalcon\Test\Models\I1534;
use Phalcon\Test\Models\Parts2;
use Phalcon\Test\Models\People;
use Phalcon\Test\Models\Personas;
use Phalcon\Test\Models\Personers;
use Phalcon\Test\Models\Robots;
use Phalcon\Test\Models\Robotters;

class ModelsCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->setNewFactoryDefault();
    }

    public function _after(IntegrationTester $I)
    {
        Model::setup(
            [
                'phqlLiterals' => true,
            ]
        );
    }

    public function testModelsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);

        $this->issue1534($I);
        $this->issue886($I);
        $this->issue11253($I);
    }

    private function executeTestsNormal(IntegrationTester $I)
    {
        $this->prepareDb();

        //Count tests
        $I->assertEquals(People::count(), Personas::count());

        $params = [];
        $I->assertEquals(People::count($params), Personas::count($params));

        $params = ["estado='I'"];
        $I->assertEquals(People::count($params), Personas::count($params));

        $params = "estado='I'";
        $I->assertEquals(People::count($params), Personas::count($params));

        $params = ["conditions" => "estado='I'"];
        $I->assertEquals(People::count($params), Personas::count($params));

        //Find first
        $people = People::findFirst();
        $I->assertInternalType('object', $people);
        $I->assertInstanceOf('Phalcon\Test\Models\People', $people);

        $persona = Personas::findFirst();
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $people = People::findFirst("estado='I'");
        $I->assertInternalType('object', $people);

        $persona = Personas::findFirst("estado='I'");
        $I->assertInternalType('object', $persona);

        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $people  = People::findFirst(["estado='I'"]);
        $persona = Personas::findFirst(["estado='I'"]);
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $params  = ["conditions" => "estado='I'"];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $params  = ["conditions" => "estado='A'", "order" => "nombres"];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $params  = ["estado='A'", "order" => "nombres DESC", "limit" => 30];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $params  = ["estado=?1", "bind" => [1 => 'A'], "order" => "nombres DESC", "limit" => 30];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $params  = ["estado=:estado:", "bind" => ["estado" => 'A'], "order" => "nombres DESC", "limit" => 30];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $I->assertEquals($people->nombres, $persona->nombres);
        $I->assertEquals($people->estado, $persona->estado);

        $robot = Robots::findFirst(1);
        $I->assertInstanceOf('Phalcon\Test\Models\Robots', $robot);

        //Find tests
        $personas = Personas::find();
        $people   = People::find();
        $I->assertCount(count($personas), $people);

        $personas = Personas::find("estado='I'");
        $people   = People::find("estado='I'");
        $I->assertCount(count($personas), $people);

        $personas = Personas::find(["estado='I'"]);
        $people   = People::find(["estado='I'"]);
        $I->assertCount(count($personas), $people);

        $personas = Personas::find(["estado='A'", "order" => "nombres"]);
        $people   = People::find(["estado='A'", "order" => "nombres"]);
        $I->assertCount(count($personas), $people);

        $personas = Personas::find(["estado='A'", "order" => "nombres", "limit" => 100]);
        $people   = People::find(["estado='A'", "order" => "nombres", "limit" => 100]);
        $I->assertCount(count($personas), $people);

        $params   = ["estado=?1", "bind" => [1 => "A"], "order" => "nombres", "limit" => 100];
        $personas = Personas::find($params);
        $people   = People::find($params);
        $I->assertCount(count($personas), $people);

        $params   = ["estado=:estado:", "bind" => ["estado" => "A"], "order" => "nombres", "limit" => 100];
        $personas = Personas::find($params);
        $people   = People::find($params);
        $I->assertCount(count($personas), $people);

        $number  = 0;
        $peoples = Personas::find(["conditions" => "estado='A'", "order" => "nombres", "limit" => 20]);
        foreach ($peoples as $people) {
            $number++;
        }
        $I->assertEquals($number, 20);

        $persona         = new Personas();
        $persona->cedula = 'CELL' . mt_rand(0, 999999);
        $I->assertFalse($persona->save());

        //Messages
        $I->assertCount(3, $persona->getMessages());

        $messages = [
            0 => ModelMessage::__set_state([
                '_type'     => 'PresenceOf',
                '_message'  => 'tipo_documento_id is required',
                '_field'    => 'tipo_documento_id',
                '_code'     => 0,
                '_metaData' => []
            ]),
            1 => ModelMessage::__set_state([
                '_type'     => 'PresenceOf',
                '_message'  => 'cupo is required',
                '_field'    => 'cupo',
                '_code'     => 0,
                '_metaData' => []
            ]),
            2 => ModelMessage::__set_state([
                '_type'     => 'PresenceOf',
                '_message'  => 'estado is required',
                '_field'    => 'estado',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];
        $I->assertEquals($persona->getMessages(), $messages);

        //Save
        $persona                    = new Personas();
        $persona->cedula            = 'CELL' . mt_rand(0, 999999);
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'LOST';
        $persona->telefono          = '1';
        $persona->cupo              = 20000;
        $persona->estado            = 'A';
        $I->assertTrue($persona->save());

        $persona                    = new Personas();
        $persona->cedula            = 'CELL' . mt_rand(0, 999999);
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'LOST LOST';
        $persona->telefono          = '2';
        $persona->cupo              = 0;
        $persona->estado            = 'X';
        $I->assertTrue($persona->save());

        //Check correct save
        $persona = Personas::findFirst(["estado='X'"]);
        $I->assertNotEquals($persona, false);
        $I->assertEquals($persona->nombres, 'LOST LOST');
        $I->assertEquals($persona->estado, 'X');

        //Update
        $persona->cupo     = 150000;
        $persona->telefono = '123';
        $I->assertTrue($persona->update());

        //Checking correct update
        $persona = Personas::findFirst(["estado='X'"]);
        $I->assertNotEquals($persona, false);
        $I->assertEquals($persona->cupo, 150000);
        $I->assertEquals($persona->telefono, '123');

        //Update
        $persona->assign([
            'nombres'  => 'LOST UPDATE',
            'telefono' => '2121',
        ]);
        $I->assertTrue($persona->update());

        //Checking correct update
        $persona = Personas::findFirst(["estado='X'"]);
        $I->assertNotEquals($persona, false);
        $I->assertEquals($persona->nombres, 'LOST UPDATE');
        $I->assertEquals($persona->telefono, '2121');

        //Create
        $persona                    = new Personas();
        $persona->cedula            = 'CELL' . mt_rand(0, 999999);
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'LOST CREATE';
        $persona->telefono          = '1';
        $persona->cupo              = 21000;
        $persona->estado            = 'A';
        $I->assertTrue($persona->create());

        $persona = new Personas();
        $persona->assign([
            'cedula'            => 'CELL' . mt_rand(0, 999999),
            'tipo_documento_id' => 1,
            'nombres'           => 'LOST CREATE',
            'telefono'          => '1',
            'cupo'              => 21000,
            'estado'            => 'A',
        ]);
        $I->assertTrue($persona->create());

        //Grouping
        $difEstados = People::count(["distinct" => "estado"]);
        $I->assertEquals($difEstados, 3);

        $group = People::count(["group" => "estado"]);
        $I->assertCount(3, $group);

        //Deleting
        $before = People::count();
        $I->assertTrue($persona->delete());
        $I->assertEquals($before - 1, People::count());

        //Assign
        $persona = new Personas();

        $persona->assign([
            'tipo_documento_id' => 1,
            'nombres'           => 'LOST CREATE',
            'telefono'          => '1',
            'cupo'              => 21000,
            'estado'            => 'A',
            'notField'          => 'SOME VALUE',
        ]);

        $expected = [
            'cedula'            => null,
            'tipo_documento_id' => 1,
            'nombres'           => 'LOST CREATE',
            'telefono'          => '1',
            'direccion'         => null,
            'email'             => null,
            'fecha_nacimiento'  => null,
            'ciudad_id'         => null,
            'creado_at'         => null,
            'cupo'              => 21000,
            'estado'            => 'A',
        ];

        $I->assertEquals($persona->toArray(), $expected);

        // Issue 1701
        $expected = [
            'nombres' => 'LOST CREATE',
            'cupo'    => 21000,
            'estado'  => 'A',
        ];
        $I->assertEquals($persona->toArray(['nombres', 'cupo', 'estado']), $expected);

        //toArray with params must return only mapped fields if exists columnMap
        $persona = new Personers();
        $persona->assign([
            'slagBorgerId'    => 1,
            'navnes'          => 'LOST CREATE',
            'teletelefonfono' => '1',
            'kredit'          => 21000,
            'status'          => 'A',
            'notField'        => 'SOME VALUE',
        ]);
        $expected = [
            'navnes' => 'LOST CREATE',
            'kredit' => 21000,
            'status' => 'A',
        ];
        $I->assertEquals($persona->toArray(['nombres', 'cupo', 'estado']), []);//db fields names
        $I->assertEquals($persona->toArray(['navnes', 'kredit', 'status']), $expected);//mapped fields names


        //Refresh
        $persona = Personas::findFirst();

        $personaData = $persona->toArray();

        $persona->assign([
            'tipo_documento_id' => 1,
            'nombres'           => 'LOST CREATE',
            'telefono'          => '1',
            'cupo'              => 21000,
            'estado'            => 'A',
            'notField'          => 'SOME VALUE',
        ]);

        $persona->refresh();
        $I->assertEquals($personaData, $persona->toArray());

        // Issue 1314
        $parts = new Parts2();
        $parts->save();

        // Issue 1506
        $persona  = Personas::findFirst(['columns' => 'nombres, telefono, estado', "nombres = 'LOST CREATE'"]);
        $expected = [
            'nombres'  => 'LOST CREATE',
            'telefono' => '1',
            'estado'   => 'A',
        ];

        $I->assertEquals($expected, $persona->toArray());
    }

    private function prepareDb()
    {
        $db = $this->container->get('db');
        $db->delete("personas", "estado='X'");
        $db->delete("personas", "cedula LIKE 'CELL%'");
    }

    private function executeTestsRenamed(IntegrationTester $I)
    {
        $this->prepareDb();

        $params = [];
        $I->assertGreaterThan(0, Personers::count($params));

        $params = ["status = 'I'"];
        $I->assertGreaterThan(0, Personers::count($params));

        $params = "status='I'";
        $I->assertGreaterThan(0, Personers::count($params));

        $params = ["conditions" => "status='I'"];
        $I->assertGreaterThan(0, Personers::count($params));

        //Find first
        $personer = Personers::findFirst();
        $I->assertInternalType('object', $personer);
        $I->assertInstanceOf('Phalcon\Test\Models\Personers', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $personer = Personers::findFirst("status = 'I'");
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $personer = Personers::findFirst(["status='I'"]);
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $params   = ["conditions" => "status='I'"];
        $personer = Personers::findFirst($params);
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $params   = ["conditions" => "status='A'", "order" => "navnes"];
        $personer = Personers::findFirst($params);
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $params   = ["status='A'", "order" => "navnes DESC", "limit" => 30];
        $personer = Personers::findFirst($params);
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $params   = ["status=?1", "bind" => [1 => 'A'], "order" => "navnes DESC", "limit" => 30];
        $personer = Personers::findFirst($params);
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $params   = ["status=:status:", "bind" => ["status" => 'A'], "order" => "navnes DESC", "limit" => 30];
        $personer = Personers::findFirst($params);
        $I->assertInternalType('object', $personer);
        $I->assertTrue(isset($personer->navnes));
        $I->assertTrue(isset($personer->status));

        $robotter = Robotters::findFirst(1);
        $I->assertInstanceOf('Phalcon\Test\Models\Robotters', $robotter);

        //Find tests
        $personers = Personers::find();
        $I->assertGreaterThan(0, count($personers));

        $personers = Personers::find("status='I'");
        $I->assertGreaterThan(0, count($personers));

        $personers = Personers::find(["status='I'"]);
        $I->assertGreaterThan(0, count($personers));

        $personers = Personers::find(["status='I'", "order" => "navnes"]);
        $I->assertGreaterThan(0, count($personers));

        $params    = ["status='I'", "order" => "navnes", "limit" => 100];
        $personers = Personers::find($params);
        $I->assertGreaterThan(0, count($personers));

        $params    = ["status=?1", "bind" => [1 => "A"], "order" => "navnes", "limit" => 100];
        $personers = Personers::find($params);
        $I->assertGreaterThan(0, count($personers));

        $params    = ["status=:status:", "bind" => ['status' => "A"], "order" => "navnes", "limit" => 100];
        $personers = Personers::find($params);
        $I->assertGreaterThan(0, count($personers));

        //Traverse the cursor
        $number    = 0;
        $personers = Personers::find(["conditions" => "status='A'", "order" => "navnes", "limit" => 20]);
        foreach ($personers as $personer) {
            $number++;
        }
        $I->assertEquals($number, 20);

        $personer           = new Personers();
        $personer->borgerId = 'CELL' . mt_rand(0, 999999);
        $I->assertFalse($personer->save());

        //Messages
        $I->assertEquals(count($personer->getMessages()), 3);

        $messages = [
            0 => ModelMessage::__set_state([
                '_type'     => 'PresenceOf',
                '_message'  => 'slagBorgerId is required',
                '_field'    => 'slagBorgerId',
                '_code'     => 0,
                '_metaData' => []
            ]),
            1 => ModelMessage::__set_state([
                '_type'     => 'PresenceOf',
                '_message'  => 'kredit is required',
                '_field'    => 'kredit',
                '_code'     => 0,
                '_metaData' => []
            ]),
            2 => ModelMessage::__set_state([
                '_type'     => 'PresenceOf',
                '_message'  => 'status is required',
                '_field'    => 'status',
                '_code'     => 0,
                '_metaData' => []
            ]),
        ];
        $I->assertEquals($personer->getMessages(), $messages);

        //Save
        $personer               = new Personers();
        $personer->borgerId     = 'CELL' . mt_rand(0, 999999);
        $personer->slagBorgerId = 1;
        $personer->navnes       = 'LOST';
        $personer->telefon      = '1';
        $personer->kredit       = 20000;
        $personer->status       = 'A';
        $I->assertTrue($personer->save());

        $personer               = new Personers();
        $personer->borgerId     = 'CELL' . mt_rand(0, 999999);
        $personer->slagBorgerId = 1;
        $personer->navnes       = 'LOST LOST';
        $personer->telefon      = '2';
        $personer->kredit       = 0;
        $personer->status       = 'X';
        $I->assertTrue($personer->save());

        //Check correct save
        $personer = Personers::findFirst(["status='X'"]);
        $I->assertNotEquals($personer, false);
        $I->assertEquals($personer->navnes, 'LOST LOST');
        $I->assertEquals($personer->status, 'X');

        //Update
        $personer->kredit  = 150000;
        $personer->telefon = '123';
        $I->assertTrue($personer->update());

        //Checking correct update
        $personer = Personers::findFirst(["status='X'"]);
        $I->assertNotEquals($personer, false);
        $I->assertEquals($personer->kredit, 150000);
        $I->assertEquals($personer->telefon, '123');

        //Update
        $personer->assign([
            'navnes'  => 'LOST UPDATE',
            'telefon' => '2121',
        ]);
        $I->assertTrue($personer->update());

        //Checking correct update
        $personer = Personers::findFirst(["status='X'"]);
        $I->assertNotEquals($personer, false);
        $I->assertEquals($personer->navnes, 'LOST UPDATE');
        $I->assertEquals($personer->telefon, '2121');

        //Create
        $personer               = new Personers();
        $personer->borgerId     = 'CELL' . mt_rand(0, 999999);
        $personer->slagBorgerId = 1;
        $personer->navnes       = 'LOST CREATE';
        $personer->telefon      = '2';
        $personer->kredit       = 21000;
        $personer->status       = 'A';
        $I->assertTrue($personer->save());

        $personer = new Personers();
        $personer->assign([
            'borgerId'     => 'CELL' . mt_rand(0, 999999),
            'slagBorgerId' => 1,
            'navnes'       => 'LOST CREATE',
            'telefon'      => '1',
            'kredit'       => 21000,
            'status'       => 'A',
        ]);
        $I->assertTrue($personer->create());

        //Deleting
        $before = Personers::count();
        $I->assertTrue($personer->delete());
        $I->assertEquals($before - 1, Personers::count());

        //Assign
        $personer = new Personers();

        $personer->assign([
            'slagBorgerId' => 1,
            'navnes'       => 'LOST CREATE',
            'telefon'      => '1',
            'kredit'       => 21000,
            'status'       => 'A',
        ]);

        $expected = [
            'borgerId'        => null,
            'slagBorgerId'    => 1,
            'navnes'          => 'LOST CREATE',
            'telefon'         => '1',
            'adresse'         => null,
            'elektroniskPost' => null,
            'fodtDato'        => null,
            'fodebyId'        => null,
            'skabtPa'         => null,
            'kredit'          => 21000,
            'status'          => 'A',
        ];
        $I->assertEquals($personer->toArray(), $expected);

        //Refresh
        $personer     = Personers::findFirst();
        $personerData = $personer->toArray();

        $personer->assign([
            'slagBorgerId' => 1,
            'navnes'       => 'LOST CREATE',
            'telefon'      => '1',
            'kredit'       => 21000,
            'status'       => 'A',
        ]);

        $personer->refresh();
        $I->assertEquals($personerData, $personer->toArray());
    }

    private function issue1534(IntegrationTester $I)
    {
        $I->skipTest('TODO - Find where the table is');
        $this->prepareDb();
        $db = $this->container->get('db');
//        if (true === $db->tableExists('issue_1534')) {
//            $I->assertTrue($db->delete('issue_1534'));
//        }

        $product            = new I1534();
        $product->language  = new RawValue('default(language)');
        $product->language2 = new RawValue('default(language2)');
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = new RawValue('default');
        $product->sort      = new RawValue('default');
        $I->assertTrue($product->save());
        $I->assertEquals(1, I1534::count());

        $entry = I1534::findFirst();
        $I->assertEquals('bb', $entry->language);
        $I->assertEquals('bb', $entry->language2);
        $I->assertEquals('0', $entry->sort);
        $I->assertNull($entry->brand);

        $I->assertTrue($entry->delete());

        $product            = new I1534();
        $product->language  = 'en';
        $product->language2 = 'en';
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = 'brand';
        $product->sort      = 1;
        $I->assertTrue($product->save());
        $I->assertEquals(1, I1534::count());

        $entry        = I1534::findFirst();
        $entry->brand = new RawValue('default');
        $entry->sort  = new RawValue('default');
        $I->assertTrue($entry->save());
        $I->assertEquals(1, I1534::count());

        $entry = I1534::findFirst();
        $I->assertEquals('0', $entry->sort);
        $I->assertNull($entry->brand);

        $entry->language2 = new RawValue('default(language)');
        $I->assertTrue($entry->save());
        $I->assertEquals(1, I1534::count());

        $entry = I1534::findFirst();
        $I->assertEquals('bb', $entry->language2);
        $I->assertEquals('0', $entry->sort);
        $I->assertNull($entry->brand);
        $entry->delete();

        //test subject of Issue - setting RawValue('default')
        $product            = new I1534();
        $product->language  = new RawValue('default');
        $product->language2 = new RawValue('default');
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = 'brand';
        $product->sort      = 1;
        $I->assertTrue($product->save());
        $I->assertEquals(1, I1534::count());


        $entry = I1534::findFirst();
        $I->assertEquals('bb', $entry->language);
        $I->assertEquals('bb', $entry->language2);

        $entry->language2 = 'en';
        $I->assertTrue($entry->save());

        $entry = I1534::findFirst();
        $I->assertEquals('en', $entry->language2);

        $entry->language2 = new RawValue('default');
        $I->assertTrue($entry->save());

        $entry = I1534::findFirst();
        $I->assertEquals('bb', $entry->language2);


        $I->assertTrue($db->delete('issue_1534'));
    }

    private function issue886(IntegrationTester $I)
    {
        $this->prepareDb();

        Model::setup(
            [
                'phqlLiterals' => false,
            ]
        );

        $people = People::findFirst();
        $I->assertInternalType('object', $people);
        $I->assertInstanceOf('Phalcon\Test\Models\People', $people);

        Model::setup(
            [
                'phqlLiterals' => false,
            ]
        );
    }

    private function issue11253(IntegrationTester $I)
    {
        $this->prepareDb();

        $child      = new Childs();
        $child->for = '1';
        $child->create();

        $child        = new Childs();
        $child->group = '1';
        $child->create();

        $children = Childs::findByFor(1);
        $children = Childs::findByGroup(1);
    }

    public function testModelsPostgresql(IntegrationTester $I)
    {
        $this->setDiPostgresql();

        $this->executeTestsNormal($I);
        $this->executeTestsRenamed($I);
        $this->issue886($I);
    }

    public function testModelsSqlite(IntegrationTester $I)
    {
        $this->setDiSqlite();

        /**
         * @todo Check Sqlite - tests lock up
         */
//        $this->executeTestsNormal($I);
//        $this->executeTestsRenamed($I);
//        $this->issue886($I);
    }

    public function testIssue10371(IntegrationTester $I)
    {
        $I->assertContains('addBehavior', get_class_methods('Phalcon\Mvc\Model'));
    }
}
