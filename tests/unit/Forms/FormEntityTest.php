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

namespace Phalcon\Tests\Unit\Forms;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Support\Settings;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Models\Products;
use Phalcon\Tests\Support\Traits\DiTrait;

final class FormEntityTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * @author noone-silent <lominum@protonmail.com>
     * @since  2024-05-01
     */
    public function testFormsFormBindDisabledStrictCheck(): void
    {
        $product = new Products();

        $this->assertFalse(property_exists($product, 'prd_not_exists'));

        $form = new Form($product);
        $form->setTagFactory($this->container->get("tag"));
        $dynamic = new Text('prd_not_exists');
        $form->add($dynamic);
        $exists = new Text('prd_name');
        $form->add($exists);
        $form->bind(['prd_name' => 'Test', 'prd_not_exists' => 'TestValue'], $product);

        $this->assertSame('Test', $product->prd_name);
        $this->assertSame('TestValue', $product->prd_not_exists);
    }

    /**
     * @author noone-silent <lominum@protonmail.com>
     * @since  2024-05-01
     */
    public function testFormsFormBindEnabledStrictCheck(): void
    {
        $product = new Products();

        $this->assertFalse(property_exists($product, 'prd_not_exists'));

        Settings::set('form.strict_entity_property_check', true);

        $form = new Form($product);
        $form->setTagFactory($this->container->get("tag"));
        $dynamic = new Text('prd_not_exists');
        $form->add($dynamic);
        $exists = new Text('prd_name');
        $form->add($exists);
        $form->bind(['prd_name' => 'Test', 'prd_not_exists' => 'TestValue'], $product);

        Settings::reset();

        $this->assertSame('Test', $product->prd_name);
        $this->assertFalse(property_exists($product, "prd_not_exists"));
    }

    /**
     * @author Stijn Leenknegt <stijn@diagro.be>
     * @since  2021-07-10
     */
    public function testFormsFormIsValidEntity(): void
    {
        $validator = new Validation();
        $validator->add('prd_name', new Max(['max' => 15]));

        $product = new Products();

        $form = new Form($product);
        $form->setTagFactory($this->container->get("tag"));
        $form->setValidation($validator);
        $name = new Text('prd_name');
        $form->add($name);

        $actual = $form->isValid(['prd_name' => "Nikodem Tomlinson"]);
        $this->assertFalse($actual);

        $this->assertNotNull($validator->getEntity());
        $this->assertSame($product->prd_name, $validator->getEntity()->prd_name);
    }
}
