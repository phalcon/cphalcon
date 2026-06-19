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
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\DiTrait;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeCombinedValidator;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeEntityWithSetter;
use Phalcon\Tests\Unit\Filter\Validation\Fake\FakeEntityWithWriteAttribute;

final class ValidationCoverageTest extends AbstractUnitTestCase
{
    use DiTrait;

    public function setUp(): void
    {
        $this->setNewFactoryDefault();
    }

    public function tearDown(): void
    {
        Di::reset();
    }

    /**
     * Tests Phalcon\Filter\Validation :: __construct() - initialize() is called
     *
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
     * Tests Phalcon\Filter\Validation :: add() - AbstractCombinedFieldsValidator with array field
     *
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
     * Tests Phalcon\Filter\Validation :: bind() - entity with setter method
     *
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
     * Tests Phalcon\Filter\Validation :: bind() - entity with writeAttribute method
     *
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
     * Tests Phalcon\Filter\Validation :: validate() - combinedFieldsValidators loop
     *
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
     * Tests Phalcon\Filter\Validation :: validate() - beforeValidation returns false
     *
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
     * Tests Phalcon\Filter\Validation :: validate() - afterValidation is called
     *
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
     * Tests Phalcon\Filter\Validation :: validate() - non-object validator throws exception
     *
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

    /**
     * Tests Phalcon\Filter\Validation :: validate() - combinedFieldsValidators scope not array
     *
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
     * Tests Phalcon\Filter\Validation :: validate() - combinedFieldsValidators non-object validator
     *
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
     * Tests Phalcon\Filter\Validation :: validate() - combined validator with allowEmpty skips via continue
     * Covers preChecking() array-field return true (L694) and continue (L635)
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedAllowEmptySkips(): void
    {
        $validator = new FakeCombinedValidator(['allowEmpty' => true]);
        $validation = new Validation();
        $validation->add(['field1', 'field2'], $validator);

        $messages = $validation->validate(['field1' => '', 'field2' => '']);
        $this->assertCount(0, $messages, 'allowEmpty=true with empty fields skips combined validator');
    }

    /**
     * Tests Phalcon\Filter\Validation :: validate() - combined validator cancelOnFail breaks loop
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-01-01
     */
    public function testFilterValidationValidateCombinedCancelOnFailBreaks(): void
    {
        $validator = new class extends AbstractCombinedFieldsValidator {
            public function validate(Validation $validation, array | string $field): bool
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
}
