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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Min;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorMinOrEqualStringLengthValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Min(
                [
                    'min'      => 9,
                    'included' => true,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => '12345678',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorMinStringLengthValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Min(
                [
                    'min' => 9,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '123456789',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorMinValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Min(['allowEmpty' => true,]);
        $validation->add('name', $validator);
        $entity       = new stdClass();
        $entity->name = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'name');
        $this->assertTrue($result);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2024-01-01
     */
    public function testFilterValidationValidatorMinValidateReturnValueBoundary(): void
    {
        $validation = new Validation();
        $validator  = new Min(
            [
                'min'      => 9,
                'included' => true,
            ]
        );
        $validation->add('name', $validator);

        $entity = new stdClass();

        // included = true: a value exactly at the minimum length passes
        $entity->name = '123456789';
        $validation->bind($entity, []);
        $this->assertTrue($validator->validate($validation, 'name'));

        // a value shorter than the minimum fails
        $entity->name = '12345678';
        $validation->bind($entity, []);
        $this->assertFalse($validator->validate($validation, 'name'));
    }
}
