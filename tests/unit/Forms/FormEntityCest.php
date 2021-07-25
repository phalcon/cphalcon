<?php
namespace Phalcon\Test\Unit\Forms;

use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Test\Models\Products;
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
    public function isValidEntity(UnitTester $I)
    {
        $I->wantToTest('Phalcon\Forms\Form  - isValid()');

        $validator = new Validation();
        $validator->add('prd_name', new Max(['max' => 15]));

        $product = new Products();

        $form = new Form($product);
        $form->setValidation($validator);
        $name = new Text('prd_name');
        $form->add($name);

        $isValid = $form->isValid(['prd_name' => "Nikodem Tomlinson"]); //normal this is from _POST

        $I->assertFalse($isValid);

        //Validation.zep line 456 is called, so the isValid method calls validate and sets the same entity as the form
        $I->assertNotNull($validator->getEntity());
        $I->assertEquals($product->prd_name, $validator->getEntity()->prd_name);
    }

}
