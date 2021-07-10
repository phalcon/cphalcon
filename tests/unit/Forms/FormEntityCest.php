<?php
namespace Phalcon\Test\Unit\Forms;

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Users;
use Phalcon\Validation;
use Phalcon\Validation\Validator\StringLength\Max;
use UnitTester;

class FormEntityCest
{

    use DiTrait;



    /**
     * Tests Phalcon\Forms\Form :: isValid()
     *
     * @author Stijn Leenknegt <stijn@diagro.be>
     * @since  2021-07-10
     */
    public function helperArrIsUnique(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Forms\Form  - isValid()');

        $validator = new Validation();
        $validator->add('name', new Max(['max' => 15]));

        $user = new Users();

        $form = new Form($user);
        $form->setValidation($validator);
        $name = new Text('name');
        $form->add($name);

        $isValid = $form->isValid(['name' => "Nikodem Tomlinson"]);

        $I->assertFalse($isValid);

        //Validation.zep line 456 is called, so the isValid method calls validate and sets the same entity as the form
        $I->assertNotNull($validator->getEntity());
        $I->assertEquals($user->name, $validator->getEntity()->name);
    }

}
