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
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;

class GetAttributesCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiService('escaper');
        $this->setDiService('url');
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(
            Tag::XHTML5
        );
    }

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

        $I->assertTrue(
            method_exists($form, 'getAttributes')
        );
    }

    /**
     * Test form attributes
     */
    public function testAttributes(IntegrationTester $I)
    {
        $form = new Form();

        // Form implements AttributeInterface
        $I->assertInstanceOf(
            AttributesInterface::class,
            $form
        );


        // Empty attributes
        $I->assertCount(
            0,
            $form->getAttributes()
        );


        // Set an attribute
        $form->getAttributes()->set('attr', 'value');

        $I->assertCount(
            1,
            $form->getAttributes()
        );


        // Check has attribute
        $I->assertTrue(
            $form->getAttributes()->has('attr')
        );

        $I->assertFalse(
            $form->getAttributes()->has('fake-attr')
        );

        $I->assertFalse(
            $form->getAttributes()->has('non exists attr')
        );


        // Render an attribute
        $I->assertEquals(
            ' attr="value"',
            $form->getAttributes()->render()
        );


        // Reset attributes
        $form->getAttributes()->clear();

        $I->assertCount(
            0,
            $form->getAttributes()
        );

        // Set multi attributes
        $form->getAttributes()->init(
            [
                'attr1' => 'value1',
                'attr2' => 'value2',
                'attr3' => 'value3',
            ]
        )
        ;

        $I->assertCount(
            3,
            $form->getAttributes()
        );


        // Render multi attributes
        $I->assertEquals(
            ' attr1="value1" attr2="value2" attr3="value3"',
            $form->getAttributes()->render()
        );


        // Get an attribute
        $I->assertEquals(
            'value2',
            $form->getAttributes()->get('attr2')
        );


        // Test action attribute
        $form->setAction('/some-url');

        $I->assertEquals(
            '/some-url',
            $form->getAction()
        );

        $I->assertEquals(
            '/some-url',
            $form->getAttributes()->get('action')
        );

        $I->assertEquals(
            ' action="/some-url" attr1="value1" attr2="value2" attr3="value3"',
            $form->getAttributes()->render()
        );


        // Remove an attribute
        $form->getAttributes()->remove('attr2');

        $I->assertFalse(
            $form->getAttributes()->has('attr2'),
            'Remove an attribute'
        );

        $I->assertCount(
            3,
            $form->getAttributes()
        );


        // Delete a nonexistent attribute
        $form->getAttributes()->remove('attr2');

        $I->assertFalse(
            $form->getAttributes()->has('attr2')
        );

        // Render multi attributes again
        $I->assertEquals(
            ' action="/some-url" attr1="value1" attr3="value3"',
            $form->getAttributes()->render()
        );


        // Reset attributes
        $form->getAttributes()->clear();

        $I->assertCount(
            0,
            $form->getAttributes()
        );


        // Exception on non exists attribute
        $I->assertNull(
            $form->getAttributes()->get('non exists')
        );
    }
}
