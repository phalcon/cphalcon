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

namespace Phalcon\Tests\Unit\Forms\Form;

use Phalcon\Filter\Filter;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Alnum;
use Phalcon\Filter\Validation\Validator\Numericality;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Forms\ValidationForm;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Forms\Fake\FakeFormAfterValidation;
use Phalcon\Tests\Unit\Forms\Fake\FakeFormBeforeValidation;
use stdClass;

final class IsValidTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    /**
     * Tests that bind() + isValid() without parameters correctly uses the
     * entity stored via bind() and that allowEmpty=[null,''] works for a
     * field absent from the submitted data.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15491
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     */
    public function testFormsFormIsValidAfterBindWithNullEntityProperty(): void
    {
        $entity       = new stdClass();
        $entity->name = null;

        $validator = new Alnum(['allowEmpty' => [null, '']]);
        $form      = new Form();
        $form->add((new Text('name'))->addValidators([$validator]));

        // bind with no 'name' key → entity property stays null
        $form->bind([], $entity);

        // isValid() without params → uses this->data={} and this->entity=$entity
        // getValue('name') → entity->name=null → in allowEmpty list → passes
        $this->assertTrue($form->isValid());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormIsValidAfterValidationCalled(): void
    {
        $form = new FakeFormAfterValidation();
        $form->add(new Text('name'));

        $form->isValid(['name' => 'test']);

        $this->assertTrue($form->afterCalled);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/16936
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-03-22
     */
    public function testFormsFormIsValidAppliesFiltersWithoutValidators(): void
    {
        $entity = new stdClass();

        $fieldNoValidator = new Text('test1');
        $fieldNoValidator->setFilters([Filter::FILTER_TRIM]);

        $fieldWithValidator = new Text('test2');
        $fieldWithValidator->setFilters([Filter::FILTER_TRIM]);
        $fieldWithValidator->addValidator(
            new Numericality(['allowEmpty' => true])
        );

        $form = new Form($entity);
        $form->add($fieldNoValidator);
        $form->add($fieldWithValidator);

        $data = [
            'test1' => '   ',
            'test2' => '   ',
        ];

        $result = $form->isValid($data, $entity);

        $this->assertTrue($result);
        $this->assertEquals('', $entity->test1);
        $this->assertEquals('', $entity->test2);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormIsValidBeforeValidationReturnsFalse(): void
    {
        $form = new FakeFormBeforeValidation();
        $form->add(new Text('name'));

        $actual = $form->isValid(['name' => 'test']);
        $this->assertFalse($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFormsFormIsValidNoElementsReturnsTrue(): void
    {
        $form   = new Form();
        $actual = $form->isValid([]);
        $this->assertTrue($actual);
    }

    /**
     * Tests that isValid() without parameters uses the entity stored at
     * construction time and that allowEmpty=[null,''] skips validation for
     * null and empty-string values even when the form is bound to an entity
     * whose property is null.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15491
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     */
    public function testFormsFormIsValidWithBoundEntityAndAllowEmptyArray(): void
    {
        $entity       = new stdClass();
        $entity->name = null;

        $validator = new Alnum(['allowEmpty' => [null, '']]);
        $form      = new Form($entity);
        $form->add((new Text('name'))->addValidators([$validator]));

        // null value → in allowEmpty list → skip validator → passes
        $this->assertTrue($form->isValid(['name' => null]));

        // empty string → in allowEmpty list → skip validator → passes
        $this->assertTrue($form->isValid(['name' => '']));

        // valid value → not in allowEmpty list → validator runs → passes
        $this->assertTrue($form->isValid(['name' => 'Acme']));

        // '0' → NOT in [null,''] → validator runs → Alnum passes '0'
        $this->assertTrue($form->isValid(['name' => '0']));
    }

    /**
     * Tests that isValid($data) without an entity parameter uses the entity
     * stored at construction time.
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/15491
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-22
     */
    public function testFormsFormIsValidWithDataUsesStoredEntity(): void
    {
        $entity       = new stdClass();
        $entity->name = null;

        $validator = new Alnum(['allowEmpty' => [null, '']]);
        $form      = new Form($entity);
        $form->add((new Text('name'))->addValidators([$validator]));

        // Pass data only, no entity → stored $entity should be used automatically
        $this->assertTrue($form->isValid(['name' => null]));
        $this->assertTrue($form->isValid(['name' => '']));
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/13149
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testFormsFormRemoveIsValidCancelOnFail(): void
    {
        $form = new ValidationForm();

        $data = [
            'fullname' => '',
            'email'    => '',
            'subject'  => '',
            'message'  => '',
        ];

        $actual = $form->isValid($data);
        $this->assertFalse($actual);

        /**
         * 6 validators in total
         */
        $messages = $form->getMessages();
        $this->assertCount(4, $messages);

        $data = [
            'fullname' => '',
            'email'    => 'team@phalcon.io',
            'subject'  => 'Some subject',
            'message'  => 'Some message',
        ];

        $actual = $form->isValid($data);
        $this->assertFalse($actual);

        $messages = $form->getMessages();
        $this->assertCount(1, $messages);

        $expected = new Messages(
            [
                new Message(
                    'your fullname is required',
                    'fullname',
                    PresenceOf::class
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/11500
     * @author Mohamad Rostami <rostami@outlook.com>
     */
    public function testMergeValidators(): void
    {
        $telephone = new Text('telephone');
        $telephone->addValidators(
            [
                new PresenceOf(
                    [
                        'message' => 'The telephone is required',
                    ]
                ),
            ]
        );

        $customValidation = new Validation();
        $customValidation->add(
            'telephone',
            new Regex(
                [
                    'pattern' => '/\+44 [0-9]+ [0-9]+/',
                    'message' => 'The telephone has an invalid format',
                ]
            )
        );

        $form = new Form();

        $address = new Text('address');

        $form->add($telephone);
        $form->add($address);

        $form->setValidation($customValidation);

        $this->assertFalse(
            $form->isValid(
                [
                    'address' => 'hello',
                ]
            )
        );

        $this->assertTrue(
            $form->get('telephone')->hasMessages()
        );

        $this->assertFalse(
            $form->get('address')->hasMessages()
        );


        $expected = new Messages(
            [
                new Message(
                    'The telephone has an invalid format',
                    'telephone',
                    Regex::class,
                    0
                ),
                new Message(
                    'The telephone is required',
                    'telephone',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $this->assertEquals(
            $expected,
            $form->get('telephone')->getMessages()
        );


        $expected = $form->getMessages();

        $this->assertEquals(
            $expected,
            $form->get('telephone')->getMessages()
        );


        $expected = new Messages();

        $this->assertEquals(
            $expected,
            $form->get('address')->getMessages()
        );
    }
}
