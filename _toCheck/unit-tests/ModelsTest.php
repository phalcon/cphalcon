<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file LICENSE.txt.                             |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

use Phalcon\Mvc\Model\Message as ModelMessage;
use PHPUnit\Framework\TestCase;

class Issue_1534 extends \Phalcon\Mvc\Model
{
}

class ModelsTest extends TestCase
{

    public function __construct()
    {
        spl_autoload_register([$this, 'modelsAutoloader']);
    }

    public function __destruct()
    {
        spl_autoload_unregister([$this, 'modelsAutoloader']);
    }

    public function tearDown()
    {
        Phalcon\Mvc\Model::setup([
            'phqlLiterals' => true,
        ]);
    }

    public function modelsAutoloader($className)
    {
        if (file_exists('unit-tests/models/' . $className . '.php')) {
            require 'unit-tests/models/' . $className . '.php';
        }
    }

    public function testModelsMysql()
    {
        require 'unit-tests/config.db.php';
        if (empty($configMysql)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $di = $this->_getDI(function () {
            require 'unit-tests/config.db.php';
            $db = new Phalcon\Db\Adapter\Pdo\Mysql($configMysql);
            return $db;
        });

        $this->_executeTestsNormal($di);
        $this->_executeTestsRenamed($di);

        $this->issue1534($di);
        $this->issue886($di);
        $this->issue11253($di);
    }

    protected function _getDI($dbService)
    {

        Phalcon\DI::reset();

        $di = new Phalcon\DI();

        $di->set('modelsManager', function () {
            return new Phalcon\Mvc\Model\Manager();
        });

        $di->set('modelsMetadata', function () {
            return new Phalcon\Mvc\Model\Metadata\Memory();
        });

        $di->set('db', $dbService, true);

        return $di;
    }

    protected function _executeTestsNormal($di)
    {

        $this->_prepareDb($di->getShared('db'));

        //Count tests
        $this->assertEquals(People::count(), Personas::count());

        $params = [];
        $this->assertEquals(People::count($params), Personas::count($params));

        $params = ["estado='I'"];
        $this->assertEquals(People::count($params), Personas::count($params));

        $params = "estado='I'";
        $this->assertEquals(People::count($params), Personas::count($params));

        $params = ["conditions" => "estado='I'"];
        $this->assertEquals(People::count($params), Personas::count($params));

        //Find first
        $people = People::findFirst();
        $this->assertInternalType('object', $people);
        $this->assertInstanceOf('People', $people);

        $persona = Personas::findFirst();
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $people = People::findFirst("estado='I'");
        $this->assertInternalType('object', $people);

        $persona = Personas::findFirst("estado='I'");
        $this->assertInternalType('object', $persona);

        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $people  = People::findFirst(["estado='I'"]);
        $persona = Personas::findFirst(["estado='I'"]);
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $params  = ["conditions" => "estado='I'"];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $params  = ["conditions" => "estado='A'", "order" => "nombres"];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $params  = ["estado='A'", "order" => "nombres DESC", "limit" => 30];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $params  = ["estado=?1", "bind" => [1 => 'A'], "order" => "nombres DESC", "limit" => 30];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $params  = ["estado=:estado:", "bind" => ["estado" => 'A'], "order" => "nombres DESC", "limit" => 30];
        $people  = People::findFirst($params);
        $persona = Personas::findFirst($params);
        $this->assertEquals($people->nombres, $persona->nombres);
        $this->assertEquals($people->estado, $persona->estado);

        $robot = Robots::findFirst(1);
        $this->assertInstanceOf('Robots', $robot);

        //Find tests
        $personas = Personas::find();
        $people   = People::find();
        $this->assertCount(count($personas), $people);

        $personas = Personas::find("estado='I'");
        $people   = People::find("estado='I'");
        $this->assertCount(count($personas), $people);

        $personas = Personas::find(["estado='I'"]);
        $people   = People::find(["estado='I'"]);
        $this->assertCount(count($personas), $people);

        $personas = Personas::find(["estado='A'", "order" => "nombres"]);
        $people   = People::find(["estado='A'", "order" => "nombres"]);
        $this->assertCount(count($personas), $people);

        $personas = Personas::find(["estado='A'", "order" => "nombres", "limit" => 100]);
        $people   = People::find(["estado='A'", "order" => "nombres", "limit" => 100]);
        $this->assertCount(count($personas), $people);

        $params   = ["estado=?1", "bind" => [1 => "A"], "order" => "nombres", "limit" => 100];
        $personas = Personas::find($params);
        $people   = People::find($params);
        $this->assertCount(count($personas), $people);

        $params   = ["estado=:estado:", "bind" => ["estado" => "A"], "order" => "nombres", "limit" => 100];
        $personas = Personas::find($params);
        $people   = People::find($params);
        $this->assertCount(count($personas), $people);

        $number  = 0;
        $peoples = Personas::find(["conditions" => "estado='A'", "order" => "nombres", "limit" => 20]);
        foreach ($peoples as $people) {
            $number++;
        }
        $this->assertEquals($number, 20);

        $persona         = new Personas();
        $persona->cedula = 'CELL' . mt_rand(0, 999999);
        $this->assertFalse($persona->save());

        //Messages
        $this->assertCount(3, $persona->getMessages());

        $messages = [
            0 => ModelMessage::__set_state([
                '_type'    => 'PresenceOf',
                '_message' => 'tipo_documento_id is required',
                '_field'   => 'tipo_documento_id',
                '_code'    => 0,
            ]),
            1 => ModelMessage::__set_state([
                '_type'    => 'PresenceOf',
                '_message' => 'cupo is required',
                '_field'   => 'cupo',
                '_code'    => 0,
            ]),
            2 => ModelMessage::__set_state([
                '_type'    => 'PresenceOf',
                '_message' => 'estado is required',
                '_field'   => 'estado',
                '_code'    => 0,
            ]),
        ];
        $this->assertEquals($persona->getMessages(), $messages);

        //Save
        $persona                    = new Personas();
        $persona->cedula            = 'CELL' . mt_rand(0, 999999);
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'LOST';
        $persona->telefono          = '1';
        $persona->cupo              = 20000;
        $persona->estado            = 'A';
        $this->assertTrue($persona->save());

        $persona                    = new Personas();
        $persona->cedula            = 'CELL' . mt_rand(0, 999999);
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'LOST LOST';
        $persona->telefono          = '2';
        $persona->cupo              = 0;
        $persona->estado            = 'X';
        $this->assertTrue($persona->save());

        //Check correct save
        $persona = Personas::findFirst(["estado='X'"]);
        $this->assertNotEquals($persona, false);
        $this->assertEquals($persona->nombres, 'LOST LOST');
        $this->assertEquals($persona->estado, 'X');

        //Update
        $persona->cupo     = 150000;
        $persona->telefono = '123';
        $this->assertTrue($persona->update());

        //Checking correct update
        $persona = Personas::findFirst(["estado='X'"]);
        $this->assertNotEquals($persona, false);
        $this->assertEquals($persona->cupo, 150000);
        $this->assertEquals($persona->telefono, '123');

        //Update
        $persona->assign([
            'nombres'  => 'LOST UPDATE',
            'telefono' => '2121',
        ]);
        $this->assertTrue($persona->update());

        //Checking correct update
        $persona = Personas::findFirst(["estado='X'"]);
        $this->assertNotEquals($persona, false);
        $this->assertEquals($persona->nombres, 'LOST UPDATE');
        $this->assertEquals($persona->telefono, '2121');

        //Create
        $persona                    = new Personas();
        $persona->cedula            = 'CELL' . mt_rand(0, 999999);
        $persona->tipo_documento_id = 1;
        $persona->nombres           = 'LOST CREATE';
        $persona->telefono          = '1';
        $persona->cupo              = 21000;
        $persona->estado            = 'A';
        $this->assertTrue($persona->create());

        $persona = new Personas();
        $persona->assign([
            'cedula'            => 'CELL' . mt_rand(0, 999999),
            'tipo_documento_id' => 1,
            'nombres'           => 'LOST CREATE',
            'telefono'          => '1',
            'cupo'              => 21000,
            'estado'            => 'A',
        ]);
        $this->assertTrue($persona->create());

        //Grouping
        $difEstados = People::count(["distinct" => "estado"]);
        $this->assertEquals($difEstados, 3);

        $group = People::count(["group" => "estado"]);
        $this->assertCount(3, $group);

        //Deleting
        $before = People::count();
        $this->assertTrue($persona->delete());
        $this->assertEquals($before - 1, People::count());

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

        $this->assertEquals($persona->toArray(), $expected);

        // Issue 1701
        $expected = [
            'nombres' => 'LOST CREATE',
            'cupo'    => 21000,
            'estado'  => 'A',
        ];
        $this->assertEquals($persona->toArray(['nombres', 'cupo', 'estado']), $expected);

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
        $this->assertEquals($persona->toArray(['nombres', 'cupo', 'estado']), []);//db fields names
        $this->assertEquals($persona->toArray(['navnes', 'kredit', 'status']), $expected);//mapped fields names


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
        $this->assertEquals($personaData, $persona->toArray());

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

        $this->assertEquals($expected, $persona->toArray());
    }

    protected function _prepareDb($db)
    {
        $db->delete("personas", "estado='X'");
        $db->delete("personas", "cedula LIKE 'CELL%'");
    }

    protected function _executeTestsRenamed($di)
    {

        $this->_prepareDb($di->getShared('db'));

        $params = [];
        $this->assertGreaterThan(0, Personers::count($params));

        $params = ["status = 'I'"];
        $this->assertGreaterThan(0, Personers::count($params));

        $params = "status='I'";
        $this->assertGreaterThan(0, Personers::count($params));

        $params = ["conditions" => "status='I'"];
        $this->assertGreaterThan(0, Personers::count($params));

        //Find first
        $personer = Personers::findFirst();
        $this->assertInternalType('object', $personer);
        $this->assertInstanceOf('Personers', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $personer = Personers::findFirst("status = 'I'");
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $personer = Personers::findFirst(["status='I'"]);
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $params   = ["conditions" => "status='I'"];
        $personer = Personers::findFirst($params);
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $params   = ["conditions" => "status='A'", "order" => "navnes"];
        $personer = Personers::findFirst($params);
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $params   = ["status='A'", "order" => "navnes DESC", "limit" => 30];
        $personer = Personers::findFirst($params);
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $params   = ["status=?1", "bind" => [1 => 'A'], "order" => "navnes DESC", "limit" => 30];
        $personer = Personers::findFirst($params);
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $params   = ["status=:status:", "bind" => ["status" => 'A'], "order" => "navnes DESC", "limit" => 30];
        $personer = Personers::findFirst($params);
        $this->assertInternalType('object', $personer);
        $this->assertTrue(isset($personer->navnes));
        $this->assertTrue(isset($personer->status));

        $robotter = Robotters::findFirst(1);
        $this->assertInstanceOf('Robotters', $robotter);

        //Find tests
        $personers = Personers::find();
        $this->assertGreaterThan(0, count($personers));

        $personers = Personers::find("status='I'");
        $this->assertGreaterThan(0, count($personers));

        $personers = Personers::find(["status='I'"]);
        $this->assertGreaterThan(0, count($personers));

        $personers = Personers::find(["status='I'", "order" => "navnes"]);
        $this->assertGreaterThan(0, count($personers));

        $params    = ["status='I'", "order" => "navnes", "limit" => 100];
        $personers = Personers::find($params);
        $this->assertGreaterThan(0, count($personers));

        $params    = ["status=?1", "bind" => [1 => "A"], "order" => "navnes", "limit" => 100];
        $personers = Personers::find($params);
        $this->assertGreaterThan(0, count($personers));

        $params    = ["status=:status:", "bind" => ['status' => "A"], "order" => "navnes", "limit" => 100];
        $personers = Personers::find($params);
        $this->assertGreaterThan(0, count($personers));

        //Traverse the cursor
        $number    = 0;
        $personers = Personers::find(["conditions" => "status='A'", "order" => "navnes", "limit" => 20]);
        foreach ($personers as $personer) {
            $number++;
        }
        $this->assertEquals($number, 20);

        $personer           = new Personers();
        $personer->borgerId = 'CELL' . mt_rand(0, 999999);
        $this->assertFalse($personer->save());

        //Messages
        $this->assertEquals(count($personer->getMessages()), 3);

        $messages = [
            0 => ModelMessage::__set_state([
                '_type'    => 'PresenceOf',
                '_message' => 'slagBorgerId is required',
                '_field'   => 'slagBorgerId',
                '_code'    => 0,
            ]),
            1 => ModelMessage::__set_state([
                '_type'    => 'PresenceOf',
                '_message' => 'kredit is required',
                '_field'   => 'kredit',
                '_code'    => 0,
            ]),
            2 => ModelMessage::__set_state([
                '_type'    => 'PresenceOf',
                '_message' => 'status is required',
                '_field'   => 'status',
                '_code'    => 0,
            ]),
        ];
        $this->assertEquals($personer->getMessages(), $messages);

        //Save
        $personer               = new Personers();
        $personer->borgerId     = 'CELL' . mt_rand(0, 999999);
        $personer->slagBorgerId = 1;
        $personer->navnes       = 'LOST';
        $personer->telefon      = '1';
        $personer->kredit       = 20000;
        $personer->status       = 'A';
        $this->assertTrue($personer->save());

        $personer               = new Personers();
        $personer->borgerId     = 'CELL' . mt_rand(0, 999999);
        $personer->slagBorgerId = 1;
        $personer->navnes       = 'LOST LOST';
        $personer->telefon      = '2';
        $personer->kredit       = 0;
        $personer->status       = 'X';
        $this->assertTrue($personer->save());

        //Check correct save
        $personer = Personers::findFirst(["status='X'"]);
        $this->assertNotEquals($personer, false);
        $this->assertEquals($personer->navnes, 'LOST LOST');
        $this->assertEquals($personer->status, 'X');

        //Update
        $personer->kredit  = 150000;
        $personer->telefon = '123';
        $this->assertTrue($personer->update());

        //Checking correct update
        $personer = Personers::findFirst(["status='X'"]);
        $this->assertNotEquals($personer, false);
        $this->assertEquals($personer->kredit, 150000);
        $this->assertEquals($personer->telefon, '123');

        //Update
        $personer->assign([
            'navnes'  => 'LOST UPDATE',
            'telefon' => '2121',
        ]);
        $this->assertTrue($personer->update());

        //Checking correct update
        $personer = Personers::findFirst(["status='X'"]);
        $this->assertNotEquals($personer, false);
        $this->assertEquals($personer->navnes, 'LOST UPDATE');
        $this->assertEquals($personer->telefon, '2121');

        //Create
        $personer               = new Personers();
        $personer->borgerId     = 'CELL' . mt_rand(0, 999999);
        $personer->slagBorgerId = 1;
        $personer->navnes       = 'LOST CREATE';
        $personer->telefon      = '2';
        $personer->kredit       = 21000;
        $personer->status       = 'A';
        $this->assertTrue($personer->save());

        $personer = new Personers();
        $personer->assign([
            'borgerId'     => 'CELL' . mt_rand(0, 999999),
            'slagBorgerId' => 1,
            'navnes'       => 'LOST CREATE',
            'telefon'      => '1',
            'kredit'       => 21000,
            'status'       => 'A',
        ]);
        $this->assertTrue($personer->create());

        //Deleting
        $before = Personers::count();
        $this->assertTrue($personer->delete());
        $this->assertEquals($before - 1, Personers::count());

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
        $this->assertEquals($personer->toArray(), $expected);

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
        $this->assertEquals($personerData, $personer->toArray());
    }

    protected function issue1534($di)
    {
        $db = $di->getShared('db');
        $this->_prepareDb($di->getShared('db'));

        $this->assertTrue($db->delete('issue_1534'));

        $product            = new Issue_1534();
        $product->language  = new \Phalcon\Db\RawValue('default(language)');
        $product->language2 = new \Phalcon\Db\RawValue('default(language2)');
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = new \Phalcon\Db\RawValue('default');
        $product->sort      = new \Phalcon\Db\RawValue('default');
        $this->assertTrue($product->save());
        $this->assertEquals(1, Issue_1534::count());

        $entry = Issue_1534::findFirst();
        $this->assertEquals('bb', $entry->language);
        $this->assertEquals('bb', $entry->language2);
        $this->assertEquals('0', $entry->sort);
        $this->assertNull($entry->brand);

        $this->assertTrue($entry->delete());

        $product            = new Issue_1534();
        $product->language  = 'en';
        $product->language2 = 'en';
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = 'brand';
        $product->sort      = 1;
        $this->assertTrue($product->save());
        $this->assertEquals(1, Issue_1534::count());

        $entry        = Issue_1534::findFirst();
        $entry->brand = new \Phalcon\Db\RawValue('default');
        $entry->sort  = new \Phalcon\Db\RawValue('default');
        $this->assertTrue($entry->save());
        $this->assertEquals(1, Issue_1534::count());

        $entry = Issue_1534::findFirst();
        $this->assertEquals('0', $entry->sort);
        $this->assertNull($entry->brand);

        $entry->language2 = new \Phalcon\Db\RawValue('default(language)');
        $this->assertTrue($entry->save());
        $this->assertEquals(1, Issue_1534::count());

        $entry = Issue_1534::findFirst();
        $this->assertEquals('bb', $entry->language2);
        $this->assertEquals('0', $entry->sort);
        $this->assertNull($entry->brand);
        $entry->delete();

        //test subject of Issue - setting RawValue('default')
        $product            = new Issue_1534();
        $product->language  = new \Phalcon\Db\RawValue('default');
        $product->language2 = new \Phalcon\Db\RawValue('default');
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = 'brand';
        $product->sort      = 1;
        $this->assertTrue($product->save());
        $this->assertEquals(1, Issue_1534::count());


        $entry = Issue_1534::findFirst();
        $this->assertEquals('bb', $entry->language);
        $this->assertEquals('bb', $entry->language2);

        $entry->language2 = 'en';
        $this->assertTrue($entry->save());

        $entry = Issue_1534::findFirst();
        $this->assertEquals('en', $entry->language2);

        $entry->language2 = new \Phalcon\Db\RawValue('default');
        $this->assertTrue($entry->save());

        $entry = Issue_1534::findFirst();
        $this->assertEquals('bb', $entry->language2);


        $this->assertTrue($db->delete('issue_1534'));
    }

    protected function issue886($di)
    {
        $this->_prepareDb($di->getShared('db'));

        Phalcon\Mvc\Model::setup([
            'phqlLiterals' => false,
        ]);

        $people = People::findFirst();
        $this->assertInternalType('object', $people);
        $this->assertInstanceOf('People', $people);
    }

    protected function issue11253($di)
    {
        $db = $di->getShared('db');
        $this->_prepareDb($di->getShared('db'));

        $child      = new Childs();
        $child->for = '1';
        $child->create();

        $child        = new Childs();
        $child->group = '1';
        $child->create();

        $children = Childs::findByFor(1);
        $children = Childs::findByGroup(1);
    }

    public function ytestModelsPostgresql()
    {
        require 'unit-tests/config.db.php';
        if (empty($configPostgresql)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $di = $this->_getDI(function () {
            require 'unit-tests/config.db.php';
            return new Phalcon\Db\Adapter\Pdo\Postgresql($configPostgresql);
        });

        $this->_executeTestsNormal($di);
        $this->_executeTestsRenamed($di);

        $this->issue886($di);
    }

    public function testModelsSqlite()
    {
        require 'unit-tests/config.db.php';
        if (empty($configSqlite)) {
            $this->markTestSkipped("Skipped");
            return;
        }

        $di = $this->_getDI(function () {
            require 'unit-tests/config.db.php';
            return new Phalcon\Db\Adapter\Pdo\Sqlite($configSqlite);
        });

        $this->_executeTestsNormal($di);
        $this->_executeTestsRenamed($di);

        $this->issue886($di);
    }

    public function testIssue10371()
    {
        $this->assertContains('addBehavior', get_class_methods('Phalcon\Mvc\Model'));
    }
}
