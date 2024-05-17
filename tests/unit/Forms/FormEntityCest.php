<?php

namespace Phalcon\Tests\Unit\Forms;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Tests\Models\Products;
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

        $this->setNewFactoryDefault(); //create default DI

        $validator = new Validation();
        $validator->add('prd_name', new Max(['max' => 15]));

        $product = new Products();

        $form = new Form($product);
        $form->setTagFactory($this->container->get("tag"));
        $form->setValidation($validator);
        $name = new Text('prd_name');
        $form->add($name);

        /**
         * normal this is from _POST
         */
        $isValid = $form->isValid(['prd_name' => "Nikodem Tomlinson"]);

        $I->assertFalse($isValid);

        /**
         * Validation.zep line 456 is called, so the isValid method calls
         * validate and sets the same entity as the form
         */
        $I->assertNotNull($validator->getEntity());
        $I->assertSame($product->prd_name, $validator->getEntity()->prd_name);
    }

    /**
     * Tests Phalcon\Forms\Form :: bind()
     *
     * @author noone-silent <lominum@protonmail.com>
     * @since  2024-05-01
     */
    public function bindDisabledStrictCheck(UnitTester $I): void
    {
        $I->wantToTest('Phalcon\Forms\Form - bind() with disabled strict property check');

        $this->setNewFactoryDefault(); //create default DI

        $product = new Products();

        $I->assertFalse(property_exists($product, 'prd_not_exists'));

        $form = new Form($product);
        $form->setTagFactory($this->container->get("tag"));
        $dynamic = new Text('prd_not_exists');
        $form->add($dynamic);
        $exists = new Text('prd_name');
        $form->add($exists);
        $form->bind(['prd_name' => 'Test', 'prd_not_exists' => 'TestValue'], $product);

        $I->assertEquals('Test', $product->prd_name);
        $I->assertEquals('TestValue', $product->prd_not_exists);
    }

    /**
     * Tests Phalcon\Forms\Form :: bind()
     *
     * @author noone-silent <lominum@protonmail.com>
     * @since  2024-05-01
     */
    public function bindEnabledStrictCheck(UnitTester $I): void
    {
        $I->wantToTest('Phalcon\Forms\Form - bind() with enabled strict property check');

        $this->setNewFactoryDefault(); //create default DI

        $product = new Products();

        $I->assertFalse(property_exists($product, 'prd_not_exists'));

        // Set setting for GlobalsCest.php
        ini_set('phalcon.form.strict_entity_property_check', '1');

        $form = new Form($product);
        $form->setTagFactory($this->container->get("tag"));
        $dynamic = new Text('prd_not_exists');
        $form->add($dynamic);
        $exists = new Text('prd_name');
        $form->add($exists);
        $form->bind(['prd_name' => 'Test', 'prd_not_exists' => 'TestValue'], $product);

        // Reset setting for GlobalsCest.php
        ini_set('phalcon.form.strict_entity_property_check', '0');

        $I->assertEquals('Test', $product->prd_name);
        $I->assertFalse(property_exists($product, "prd_not_exists"));
    }
}
