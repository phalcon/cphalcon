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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Di\Di;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\AbstractCombinedFieldsValidator;
use Phalcon\Filter\Validation\Exception as ValidationException;
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Filter\Validation\Validator\Url;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeCombinedValidator;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeEntityWithSetter;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeEntityWithWriteAttribute;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeUserEntity;

final class ValidationTest extends AbstractUnitTestCase
{
    use DiTrait;

    private Validation $validation;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
        $this->validation = new Validation();

        $this->validation->add(
            'name',
            new PresenceOf(
                [
                    'message' => 'Name cant be empty.',
                ]
            )
        );

        $this->validation->setFilters('name', 'trim');
    }

    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-30
     */
    public function testEmptyValues(): void
    {
        $validation = new Validation();

        $validation->setDI(
            $this->container
        );

        $validation
            ->add(
                'name',
                new Alpha(
                    [
                        'message' => 'The name is not valid',
                    ]
                )
            )
            ->add(
                'name',
                new PresenceOf(
                    [
                        'message' => 'The name is required',
                    ]
                )
            )
            ->add(
                'url',
                new Url(
                    [
                        'message'    => 'The url is not valid.',
                        'allowEmpty' => true,
                    ]
                )
            )
            ->add(
                'email',
                new Email(
                    [
                        'message'    => 'The email is not valid.',
                        'allowEmpty' => [null, false],
                    ]
                )
            )
        ;

        $messages = $validation->validate(
            [
                'name'  => '',
                'url'   => null,
                'email' => '',
            ]
        );

        $this->assertCount(2, $messages);


        $messages = $validation->validate(
            [
                'name'  => 'MyName',
                'url'   => '',
                'email' => '',
            ]
        );

        $this->assertCount(1, $messages);


        $messages = $validation->validate(
            [
                'name'  => 'MyName',
                'url'   => false,
                'email' => null,
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'name'  => 'MyName',
                'url'   => 0,
                'email' => 0,
            ]
        );

        $this->assertCount(1, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-26
     */
    public function testFilteringEntity(): void
    {
        $users = new FakeUserEntity();

        $users->assign(
            [
                'name' => 'SomeName      ',
            ]
        );

        $this->validation->validate(null, $users);

        $this->assertEquals(
            'SomeName',
            $users->name
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationAddCombinedValidator(): void
    {
        $validator  = new FakeCombinedValidator();
        $validation = new Validation();
        $validation->add(['field1', 'field2'], $validator);

        // combinedFieldsValidators should contain the validator
        $validators = $validation->getValidators();
        $this->assertEmpty($validators, 'No regular validators added');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationBindEntityWithSetter(): void
    {
        $entity = new FakeEntityWithSetter();
        $data   = ['name' => 'Leonidas'];

        $validation = new Validation();
        $validation->bind($entity, $data);

        $this->assertSame('Leonidas', $entity->getName(), 'Setter should have been called');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationBindEntityWithWriteAttribute(): void
    {
        $entity = new FakeEntityWithWriteAttribute();
        $data   = ['name' => 'Leonidas', 'city' => 'Sparta'];

        $validation = new Validation();
        $validation->bind($entity, $data);

        $this->assertSame(
            'Leonidas',
            $entity->readAttribute('name'),
            'writeAttribute should have been called'
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationConstructCallsInitialize(): void
    {
        $validation = new class extends Validation {
            public bool $initialized = false;

            public function initialize(): void
            {
                $this->initialized = true;
            }
        };

        $this->assertTrue($validation->initialized, 'initialize() should be called during __construct');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateAfterValidationCalled(): void
    {
        $validation = new class extends Validation {
            public bool $afterCalled = false;

            public function afterValidation(mixed $data, mixed $entity): void
            {
                $this->afterCalled = true;
            }
        };

        $validation->add('name', new PresenceOf());
        $validation->validate(['name' => 'Leonidas']);

        $this->assertTrue($validation->afterCalled, 'afterValidation should be called after validate()');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateBeforeValidationReturnsFalse(): void
    {
        $validation = new class extends Validation {
            public function beforeValidation(mixed $data, mixed $entity): bool
            {
                return false;
            }
        };

        $validation->add('name', new PresenceOf());
        $result = $validation->validate(['name' => '']);

        $this->assertFalse($result, 'beforeValidation returning false causes validate() to return false');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedAllowEmptySkips(): void
    {
        $validator  = new FakeCombinedValidator(['allowEmpty' => true]);
        $validation = new Validation();
        $validation->add(['field1', 'field2'], $validator);

        $messages = $validation->validate(['field1' => '', 'field2' => '']);
        $this->assertCount(0, $messages, 'allowEmpty=true with empty fields skips combined validator');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedCancelOnFailBreaks(): void
    {
        $validator = new class extends AbstractCombinedFieldsValidator {
            public function validate(Validation $validation, $field): bool
            {
                return false;
            }
        };
        $validator->setOption('cancelOnFail', true);

        $validation = new Validation();
        $validation->add(['field1', 'field2'], $validator);

        $messages = $validation->validate(['field1' => 'val', 'field2' => 'val']);
        $this->assertCount(0, $messages, 'cancelOnFail breaks loop; combined validator adds no messages');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedFieldsValidators(): void
    {
        $validator  = new FakeCombinedValidator();
        $validation = new Validation();
        $validation->add(['field1', 'field2'], $validator);

        $messages = $validation->validate(['field1' => 'value1', 'field2' => 'value2']);
        $this->assertCount(0, $messages, 'Combined validator returns true → no messages');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedScopeNotArrayThrows(): void
    {
        $validation = new class extends Validation {
            public function setInvalidCombinedScope(): void
            {
                $this->combinedFieldsValidators = ['not-an-array'];
            }
        };
        $validation->setInvalidCombinedScope();

        $this->expectException(ValidationException::class);
        $this->expectExceptionMessage('The validator scope is not valid');
        $validation->validate([]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedValidatorNotObjectThrows(): void
    {
        $validation = new class extends Validation {
            public function setNonObjectCombinedValidator(): void
            {
                $this->combinedFieldsValidators = [['field', 'not-an-object']];
            }
        };
        $validation->setNonObjectCombinedValidator();

        $this->expectException(ValidationException::class);
        $this->expectExceptionMessage('One of the validators is not valid');
        $validation->validate([]);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateNonObjectValidatorThrows(): void
    {
        $validation = new Validation();
        $validation->setValidators(['name' => ['not-a-validator-object']]);

        $this->expectException(ValidationException::class);
        $this->expectExceptionMessage('One of the validators is not valid');
        $validation->validate(['name' => 'value']);
    }

    public function testValidationFiltering(): void
    {
        $validation = new Validation();

        $validation->setDI(
            $this->container
        );

        $validation
            ->add(
                'name',
                new PresenceOf(
                    [
                        'message' => 'The name is required',
                    ]
                )
            )
            ->add(
                'email',
                new PresenceOf(
                    [
                        'message' => 'The email is required',
                    ]
                )
            )
        ;

        $validation->setFilters('name', 'trim');
        $validation->setFilters('email', 'trim');

        $messages = $validation->validate(
            [
                'name'  => '  ',
                'email' => '    ',
            ]
        );

        $this->assertCount(2, $messages);

        $filtered = $messages->filter('email');

        $expectedMessages = [
            new Message(
                'The email is required',
                'email',
                PresenceOf::class,
                0
            ),
        ];

        $this->assertEquals($filtered, $expectedMessages);
    }

    public function testValidationSetLabels(): void
    {
        $validation = new Validation();

        $validation->add(
            'email',
            new PresenceOf(
                [
                    'message' => 'The :field is required',
                ]
            )
        );

        $validation->add(
            'email',
            new Email(
                [
                    'message' => 'The :field must be email',
                    'label'   => 'E-mail',
                ]
            )
        );

        $validation->add(
            'firstname',
            new PresenceOf(
                [
                    'message' => 'The :field is required',
                ]
            )
        );

        $validation->add(
            'firstname',
            new StringLength(
                [
                    'min'            => 4,
                    'messageMinimum' => 'The :field is too short',
                ]
            )
        );

        $validation->setLabels(
            [
                'firstname' => 'First name',
            ]
        );

        $messages = $validation->validate(
            [
                'email'     => '',
                'firstname' => '',
            ]
        );

        $expectedMessages = new Messages(
            [
                new Message(
                    'The email is required',
                    'email',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The E-mail must be email',
                    'email',
                    Email::class,
                    0
                ),
                new Message(
                    'The First name is required',
                    'firstname',
                    PresenceOf::class,
                    0
                ),
                new Message(
                    'The First name is too short',
                    'firstname',
                    Min::class,
                    0
                ),
            ]
        );

        $this->assertEquals($messages, $expectedMessages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-09-26
     */
    public function testWithEntityAndFilter(): void
    {
        $users = new FakeUserEntity(
            [
                'name' => ' ',
            ]
        );

        $messages = $this->validation->validate(null, $users);

        $this->assertEquals(
            1,
            $messages->count()
        );

        $this->assertEquals(
            'Name cant be empty.',
            $messages->offsetGet(0)->getMessage()
        );

        $expectedMessages = new Messages(
            [
                new Message(
                    'Name cant be empty.',
                    'name',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $this->assertEquals($messages, $expectedMessages);
    }
}
