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

namespace Phalcon\Tests\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Form;
use Phalcon\Html\Attributes\AttributesInterface;

use function method_exists;

class GetAttributesCest
{
    /**
     * Tests Phalcon\Forms\Form :: getAttributes()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-11
     */
    public function formsFormGetAttributes(IntegrationTester $I)
    {
        $I->wantToTest('Forms\Form - getAttributes()');

        $form = new Form();

        $actual = method_exists($form, 'getAttributes');
        $I->assertTrue($actual);

        // Form implements AttributeInterface
        $class = AttributesInterface::class;
        $I->assertInstanceOf($class, $form);


        // Empty attributes
        $expected = 0;
        $actual   = $form->getAttributes();
        $I->assertCount($expected, $actual);

        // Set an attribute
        $form->getAttributes()->set('attr', 'value');

        $expected = 1;
        $actual   = $form->getAttributes();
        $I->assertCount($expected, $actual);


        // Check has
        $actual = $form->getAttributes()->has('attr');
        $I->assertTrue($actual);

        $actual = $form->getAttributes()->has('fake-attr');
        $I->assertFalse($actual);

        $actual = $form->getAttributes()->has('non exists attr');
        $I->assertFalse($actual);

        // Render an attribute
        $expected = 'attr="value" ';
        $actual   = $form->getAttributes()->render();
        $I->assertEquals($expected, $actual);

        // Reset attributes
        $form->getAttributes()->clear();

        $expected = 0;
        $actual   = $form->getAttributes();
        $I->assertCount($expected, $actual);

        // Set multi attributes
        $form->getAttributes()->init(
            [
                'attr1' => 'value1',
                'attr2' => 'value2',
                'attr3' => 'value3',
            ]
        )
        ;

        $expected = 3;
        $actual   = $form->getAttributes();
        $I->assertCount($expected, $actual);

        // Render multi attributes
        $expected = 'attr1="value1" attr2="value2" attr3="value3" ';
        $actual   = $form->getAttributes()->render();
        $I->assertEquals($expected, $actual);

        // Get an attribute
        $expected = 'value2';
        $actual   = $form->getAttributes()->get('attr2');
        $I->assertEquals($expected, $actual);

        // Test action attribute
        $form->setAction('/some-url');

        $expected = '/some-url';
        $actual   = $form->getAction();
        $I->assertEquals($expected, $actual);

        $expected = '/some-url';
        $actual   = $form->getAttributes()->get('action');
        $I->assertEquals($expected, $actual);

        $expected = 'action="/some-url" attr1="value1" attr2="value2" attr3="value3" ';
        $actual   = $form->getAttributes()->render();
        $I->assertEquals($expected, $actual);

        // Remove an attribute
        $form->getAttributes()->remove('attr2');

        $actual = $form->getAttributes()->has('attr2');
        $I->assertFalse($actual);

        $expected = 3;
        $actual   = $form->getAttributes();
        $I->assertCount($expected, $actual);

        // Delete a nonexistent attribute
        $form->getAttributes()->remove('attr2');

        $actual = $form->getAttributes()->has('attr2');
        $I->assertFalse($actual);

        // Render multi attributes again
        $expected = 'action="/some-url" attr1="value1" attr3="value3" ';
        $actual   = $form->getAttributes()->render();
        $I->assertEquals($expected, $actual);

        // Reset attributes
        $form->getAttributes()->clear();

        $expected = 0;
        $actual   = $form->getAttributes();
        $I->assertCount($expected, $actual);

        // Exception on non exists attribute
        $actual = $form->getAttributes()->get('non exists');
        $I->assertNull($actual);
    }
}
