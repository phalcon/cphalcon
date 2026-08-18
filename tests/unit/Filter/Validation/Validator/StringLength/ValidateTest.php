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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\StringLength;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\StringLength;
use Phalcon\Filter\Validation\Validator\StringLength\Max;
use Phalcon\Filter\Validation\Validator\StringLength\Min;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * The two boundaries of the container are independent of each other. The
     * options are given in both key orders, because the container reads them
     * while it loops over the options.
     *
     * @return array[]
     */
    public static function getExamplesIncluded(): array
    {
        return [
            // description, options, min boundary passes, max boundary passes
            [
                'not set',
                [
                    'min' => 3,
                    'max' => 9,
                ],
                true,
                true,
            ],
            [
                'included true',
                [
                    'min'      => 3,
                    'max'      => 9,
                    'included' => true,
                ],
                true,
                true,
            ],
            [
                'included false',
                [
                    'min'      => 3,
                    'max'      => 9,
                    'included' => false,
                ],
                false,
                false,
            ],
            [
                'includedMinimum false does not reach the maximum',
                [
                    'min'             => 3,
                    'max'             => 9,
                    'includedMinimum' => false,
                ],
                false,
                true,
            ],
            [
                'includedMaximum false does not reach the minimum',
                [
                    'min'             => 3,
                    'max'             => 9,
                    'includedMaximum' => false,
                ],
                true,
                false,
            ],
            [
                'includedMinimum false, max key first',
                [
                    'max'             => 9,
                    'min'             => 3,
                    'includedMinimum' => false,
                ],
                false,
                true,
            ],
            [
                'includedMaximum false, max key first',
                [
                    'max'             => 9,
                    'min'             => 3,
                    'includedMaximum' => false,
                ],
                true,
                false,
            ],
            [
                'both boundaries excluded',
                [
                    'min'             => 3,
                    'max'             => 9,
                    'includedMinimum' => false,
                    'includedMaximum' => false,
                ],
                false,
                false,
            ],
            [
                'included false has precedence',
                [
                    'min'             => 3,
                    'max'             => 9,
                    'included'        => false,
                    'includedMinimum' => true,
                    'includedMaximum' => true,
                ],
                false,
                false,
            ],
            [
                'included true has precedence',
                [
                    'min'             => 3,
                    'max'             => 9,
                    'included'        => true,
                    'includedMinimum' => false,
                    'includedMaximum' => false,
                ],
                true,
                true,
            ],
            // TODO #17503: re-enable once the Zephir defect is resolved. Passing
            // this options array straight from the data provider makes the
            // per-field array form resolve to inclusive instead of exclusive, so
            // the minimum boundary wrongly passes. The same options built as a
            // literal inside the test behave correctly. Reproducers and the
            // generated C are in
            // team/Planning/2026-08-17-zephir-typeof-array-reference-zval.md
            // [
            //     'includedMinimum array',
            //     [
            //         'min'             => 3,
            //         'max'             => 9,
            //         'includedMinimum' => ['name' => false],
            //     ],
            //     false,
            //     true,
            // ],
            [
                'includedMaximum array',
                [
                    'min'             => 3,
                    'max'             => 9,
                    'includedMaximum' => ['name' => false],
                ],
                true,
                false,
            ],
        ];
    }

    /**
     * A message given for one boundary does not reach the other boundary. The
     * boundary that has no message of its own keeps the default template.
     *
     * @return array[]
     */
    public static function getExamplesMessages(): array
    {
        return [
            // description, options, message below min, message above max
            [
                'no message',
                [
                    'min' => 3,
                    'max' => 9,
                ],
                'Field name must be at least 3 characters long',
                'Field name must not exceed 9 characters long',
            ],
            [
                'messageMinimum does not reach the maximum',
                [
                    'min'            => 3,
                    'max'            => 9,
                    'messageMinimum' => 'The name is too short',
                ],
                'The name is too short',
                'Field name must not exceed 9 characters long',
            ],
            [
                'messageMaximum does not reach the minimum',
                [
                    'min'            => 3,
                    'max'            => 9,
                    'messageMaximum' => 'The name is too long',
                ],
                'Field name must be at least 3 characters long',
                'The name is too long',
            ],
            [
                'messageMinimum, max key first',
                [
                    'max'            => 9,
                    'min'            => 3,
                    'messageMinimum' => 'The name is too short',
                ],
                'The name is too short',
                'Field name must not exceed 9 characters long',
            ],
            [
                'messageMaximum, max key first',
                [
                    'max'            => 9,
                    'min'            => 3,
                    'messageMaximum' => 'The name is too long',
                ],
                'Field name must be at least 3 characters long',
                'The name is too long',
            ],
            [
                'both messages',
                [
                    'min'            => 3,
                    'max'            => 9,
                    'messageMinimum' => 'The name is too short',
                    'messageMaximum' => 'The name is too long',
                ],
                'The name is too short',
                'The name is too long',
            ],
            [
                'message has precedence',
                [
                    'min'            => 3,
                    'max'            => 9,
                    'message'        => 'The name has a wrong length',
                    'messageMinimum' => 'The name is too short',
                    'messageMaximum' => 'The name is too long',
                ],
                'The name has a wrong length',
                'The name has a wrong length',
            ],
        ];
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17503
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-17
     */
    #[DataProvider('getExamplesIncluded')]
    public function testFilterValidationValidatorStringLengthIncludedOption(
        string $description,
        array $options,
        bool $minBoundaryPasses,
        bool $maxBoundaryPasses
    ): void {
        $validation = new Validation();
        $validation->add('name', new StringLength($options));

        // exactly at the minimum
        $messages = $validation->validate(['name' => '123']);
        $this->assertSame(
            $minBoundaryPasses ? 0 : 1,
            $messages->count(),
            $description
        );

        // exactly at the maximum
        $messages = $validation->validate(['name' => '123456789']);
        $this->assertSame(
            $maxBoundaryPasses ? 0 : 1,
            $messages->count(),
            $description
        );

        // between the two boundaries always passes
        $messages = $validation->validate(['name' => '12345']);
        $this->assertSame(0, $messages->count(), $description);
    }

    /**
     * @issue  https://github.com/phalcon/cphalcon/issues/17503
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-08-17
     */
    #[DataProvider('getExamplesMessages')]
    public function testFilterValidationValidatorStringLengthMessageOption(
        string $description,
        array $options,
        string $minimumMessage,
        string $maximumMessage
    ): void {
        $validation = new Validation();
        $validation->add('name', new StringLength($options));

        // shorter than the minimum
        $messages = $validation->validate(['name' => '12']);
        $this->assertSame(1, $messages->count(), $description);
        $this->assertSame(
            $minimumMessage,
            $messages->offsetGet(0)->getMessage(),
            $description
        );

        // longer than the maximum
        $messages = $validation->validate(['name' => '1234567890']);
        $this->assertSame(1, $messages->count(), $description);
        $this->assertSame(
            $maximumMessage,
            $messages->offsetGet(0)->getMessage(),
            $description
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-09
     */
    public function testFilterValidationValidatorStringLengthProcessValidatorOptions(): void
    {
        // Test generic 'message' option (covers processValidator L152)
        $validation = new Validation();
        $validation->add(
            'name',
            new StringLength(
                [
                    'max'     => 4,
                    'message' => 'Too long',
                ]
            )
        );

        $messages = $validation->validate(['name' => 'Toolong']);
        $this->assertSame(1, $messages->count());
        $this->assertSame('Too long', $messages[0]->getMessage());

        // Test generic 'included' option (covers processValidator L159)
        // included=true makes the boundary inclusive (> instead of >=), so max=4
        // allows exactly 4 chars; need 5 chars to trigger a failure
        $validation = new Validation();
        $validation->add(
            'name',
            new StringLength(
                [
                    'max'      => 4,
                    'included' => true,
                ]
            )
        );

        $messages = $validation->validate(['name' => 'Tests']);
        $this->assertSame(1, $messages->count());

        // Test specific 'includedMaximum' option (covers processValidator L161)
        $validation = new Validation();
        $validation->add(
            'name',
            new StringLength(
                [
                    'max'             => 4,
                    'includedMaximum' => true,
                ]
            )
        );

        $messages = $validation->validate(['name' => 'Tests']);
        $this->assertSame(1, $messages->count());
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-09
     */
    public function testFilterValidationValidatorStringLengthValidateMaximum(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new StringLength(
                [
                    'max' => 4,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'Joe',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $expected = new Messages(
            [
                new Message(
                    'Field name must not exceed 4 characters long',
                    'name',
                    Max::class,
                    0
                ),
            ]
        );

        $messages = $validation->validate(
            [
                'name' => 'Johannes',
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-09
     */
    public function testFilterValidationValidatorStringLengthValidateMaximumWithCustomMessage(): void
    {
        $validation = new Validation();

        $validation->add(
            'message',
            new StringLength(
                [
                    'max'            => 4,
                    'messageMaximum' => 'The message is too long',
                ]
            )
        );

        $messages = $validation->validate(
            [
                'message' => 'Pet',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $expected = new Messages(
            [
                new Message(
                    'The message is too long',
                    'message',
                    Max::class,
                    0
                ),
            ]
        );

        $messages = $validation->validate(
            [
                'message' => 'Validation',
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-09
     */
    public function testFilterValidationValidatorStringLengthValidateMinimum(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new StringLength(
                [
                    'min' => 3,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => 'Something',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $expected = new Messages(
            [
                new Message(
                    'Field name must be at least 3 characters long',
                    'name',
                    Min::class,
                    0
                ),
            ]
        );

        $messages = $validation->validate(
            [
                'name' => 'So',
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2013-03-09
     */
    public function testFilterValidationValidatorStringLengthValidateMinimumWithCustomMessage(): void
    {
        $validation = new Validation();

        $validation->add(
            'message',
            new StringLength(
                [
                    'min'            => 3,
                    'messageMinimum' => 'The message is too short',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'message' => 'Something',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $expected = new Messages(
            [
                new Message(
                    'The message is too short',
                    'message',
                    Min::class,
                    0
                ),
            ]
        );

        $messages = $validation->validate(
            [
                'message' => 'So',
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorStringLengthValidateMultipleFieldMultipleMinMax(): void
    {
        $validation = new Validation();

        $validationMinimumMessages = [
            'name' => 'Name length must be minimum 0.',
            'type' => 'Type length must be minimum 0.',
        ];

        $validationMaximumMessages = [
            'name' => 'Name length must be maximum 9.',
            'type' => 'Type length must be maximum 4.',
        ];

        $validation->add(
            [
                'name',
                'type',
            ],
            new StringLength(
                [
                    'min'            => [
                        'name' => 0,
                        'type' => 0,
                    ],
                    'max'            => [
                        'name' => 9,
                        'type' => 4,
                    ],
                    'messageMinimum' => $validationMinimumMessages,
                    'messageMaximum' => $validationMaximumMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => '12345678',
                'type' => '123',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
                'type' => '123',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMaximumMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name' => '12345678',
                'type' => '12345',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMaximumMessages['type'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
                'type' => '12345',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMaximumMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMaximumMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorStringLengthValidateMultipleFieldSingleMinMax(): void
    {
        $validation = new Validation();

        $validationMinimumMessages = [
            'name' => 'Name length must be minimum 0.',
            'type' => 'Type length must be minimum 0.',
        ];

        $validationMaximumMessages = [
            'name' => 'Name length must be maximum 9.',
            'type' => 'Type length must be maximum 9.',
        ];

        $validation->add(
            [
                'name',
                'type',
            ],
            new StringLength(
                [
                    'min'            => 0,
                    'max'            => 9,
                    'messageMinimum' => $validationMinimumMessages,
                    'messageMaximum' => $validationMaximumMessages,
                ]
            )
        );


        $messages = $validation->validate(
            [
                'name' => '1234',
                'type' => '1234',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
                'type' => '12345678',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMaximumMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );


        $messages = $validation->validate(
            [
                'name' => '1234567890',
                'type' => '1234567890',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMaximumMessages['name'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMaximumMessages['type'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorStringLengthValidateSingleField(): void
    {
        $validation = new Validation();

        $validation->add(
            'name',
            new StringLength(
                [
                    'min' => 3,
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
}
