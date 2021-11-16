<?php

namespace Phalcon\Tests\Integration\Mvc\Model;

use IntegrationTester;
use Phalcon\Db\RawValue;
use Phalcon\Messages\Message as ModelMessage;
use Phalcon\Mvc\Model;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Childs;
use Phalcon\Tests\Models\I1534;
use Phalcon\Tests\Models\Parts2;
use Phalcon\Tests\Models\People;
use Phalcon\Tests\Models\Personas;
use Phalcon\Tests\Models\Personers;
use Phalcon\Tests\Models\Robots;
use Phalcon\Tests\Models\Robotters;
use function is_object;

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

        $this->container['db']->close();
    }

    public function testModelsMysql(IntegrationTester $I)
    {
        $this->setDiMysql();

        $this->executeTestsNormal($I);

        $this->issue1534($I);
        $this->issue886($I);
        $this->issue11253($I);
    }

    private function executeTestsNormal(IntegrationTester $I)
    {
        $this->prepareDb();

        // Issue 1314
        $parts = new Parts2();

        $parts->save();


        // Issue 1506
        $persona = Personas::findFirst(
            [
                'columns' => 'nombres, telefono, estado',
                "nombres = 'LOST CREATE'",
            ]
        );

        $expected = [
            'nombres'  => 'LOST CREATE',
            'telefono' => '1',
            'estado'   => 'A',
        ];

        $I->assertEquals(
            $expected,
            $persona->toArray()
        );
    }

    private function prepareDb()
    {
        $db = $this->container->get('db');

        $db->delete('personas', "estado='X'");
        $db->delete('personas', "cedula LIKE 'CELL%'");
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

        $I->assertTrue(
            $product->save()
        );

        $I->assertEquals(1, I1534::count());

        $entry = I1534::findFirst();
        $I->assertEquals('bb', $entry->language);
        $I->assertEquals('bb', $entry->language2);
        $I->assertEquals('0', $entry->sort);
        $I->assertNull($entry->brand);

        $I->assertTrue(
            $entry->delete()
        );

        $product = new I1534();

        $product->language  = 'en';
        $product->language2 = 'en';
        $product->name      = 'foo';
        $product->slug      = 'bar';
        $product->brand     = 'brand';
        $product->sort      = 1;

        $I->assertTrue(
            $product->save()
        );

        $I->assertEquals(1, I1534::count());

        $entry = I1534::findFirst();

        $entry->brand = new RawValue('default');
        $entry->sort  = new RawValue('default');

        $I->assertTrue(
            $entry->save()
        );

        $I->assertEquals(1, I1534::count());

        $entry = I1534::findFirst();

        $I->assertEquals('0', $entry->sort);

        $I->assertNull($entry->brand);

        $entry->language2 = new RawValue('default(language)');

        $I->assertTrue(
            $entry->save()
        );

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

        $I->assertTrue(
            $product->save()
        );

        $I->assertEquals(1, I1534::count());


        $entry = I1534::findFirst();
        $I->assertEquals('bb', $entry->language);
        $I->assertEquals('bb', $entry->language2);

        $entry->language2 = 'en';

        $I->assertTrue(
            $entry->save()
        );


        $entry = I1534::findFirst();

        $I->assertEquals('en', $entry->language2);


        $entry->language2 = new RawValue('default');

        $I->assertTrue(
            $entry->save()
        );


        $entry = I1534::findFirst();

        $I->assertEquals('bb', $entry->language2);


        $I->assertTrue(
            $db->delete('issue_1534')
        );
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

        $I->assertTrue(is_object($people));

        $I->assertInstanceOf(
            \Phalcon\Tests\Models\People::class,
            $people
        );

        Model::setup(
            [
                'phqlLiterals' => false,
            ]
        );
    }

    private function issue11253(IntegrationTester $I)
    {
        $this->prepareDb();


        $child = new Childs();

        $child->for = '1';

        $child->create();


        $child = new Childs();

        $child->group = '1';

        $child->create();


        $children = Childs::findByFor(1);
        $children = Childs::findByGroup(1);
    }
}
