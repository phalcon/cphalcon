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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength\Max;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;
use stdClass;

use function array_merge;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * Every combination of the "included" and "includedMaximum" options,
     * against a value that is exactly at the maximum length.
     *
     * @return array[]
     */
    public static function getExamplesIncluded(): array
    {
        return [
            // description, options, the boundary passes
            [
                'not set',
                [],
                true,
            ],
            [
                'included true',
                ['included' => true],
                true,
            ],
            [
                'included false',
                ['included' => false],
                false,
            ],
            [
                'includedMaximum true',
                ['includedMaximum' => true],
                true,
            ],
            [
                'includedMaximum false',
                ['includedMaximum' => false],
                false,
            ],
            [
                'included false has precedence',
                [
                    'included'        => false,
                    'includedMaximum' => true,
                ],
                false,
            ],
            [
                'included true has precedence',
                [
                    'included'        => true,
                    'includedMaximum' => false,
                ],
                true,
            ],
            [
                'included array',
                ['included' => ['name' => false]],
                false,
            ],
            [
                'includedMaximum array',
                ['includedMaximum' => ['name' => false]],
                false,
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17503
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-17
     */
    #[DataProvider('getExamplesIncluded')]
    public function testFilterValidationValidatorMaxIncludedOption(
        string $description,
        array $options,
        bool $boundaryPasses
    ): void {
        $validation = new Validation();
        $validation->add(
            'name',
            new Max(
                array_merge(['max' => 9], $options)
            )
        );

        // shorter than the maximum always passes
        $messages = $validation->validate(['name' => '12345678']);
        $this->assertSame(0, $messages->count(), $description);

        // exactly at the maximum
        $messages = $validation->validate(['name' => '123456789']);
        $this->assertSame(
            $boundaryPasses ? 0 : 1,
            $messages->count(),
            $description
        );

        // longer than the maximum always fails
        $messages = $validation->validate(['name' => '1234567890']);
        $this->assertSame(1, $messages->count(), $description);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorMaxOrEqualStringLengthValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Max(
                [
                    'max'      => 9,
                    'included' => true,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'short',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'name' => '1234567890',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => 'SomeValue123',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorMaxStringLengthValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new Max(
                [
                    'max' => 9,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => '12345678',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        // the maximum is inclusive by default
        $messages = $validation->validate(
            [
                'name' => '123456789',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
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
    public function testFilterValidationValidatorMaxValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Max(['allowEmpty' => true,]);
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
    public function testFilterValidationValidatorMaxValidateReturnValueBoundary(): void
    {
        $validation = new Validation();
        $validator  = new Max(
            [
                'max'      => 9,
                'included' => true,
            ]
        );
        $validation->add('name', $validator);

        $entity = new stdClass();

        // included = true: a value exactly at the maximum length passes
        $entity->name = '123456789';
        $validation->bind($entity, []);
        $this->assertTrue($validator->validate($validation, 'name'));

        // a value longer than the maximum fails
        $entity->name = '1234567890';
        $validation->bind($entity, []);
        $this->assertFalse($validator->validate($validation, 'name'));
    }
}
