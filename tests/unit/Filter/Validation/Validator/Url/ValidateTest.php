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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Url;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Url;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tests\AbstractUnitTestCase;
use stdClass;

use const FILTER_FLAG_PATH_REQUIRED;
use const FILTER_FLAG_QUERY_REQUIRED;

final class ValidateTest extends AbstractUnitTestCase
{
    public static function getExamples(): array
    {
        return [
            [
                FILTER_FLAG_PATH_REQUIRED,
                'phalcon.io',
            ],
            [
                FILTER_FLAG_QUERY_REQUIRED,
                'https://',
            ],
            [
                [
                    'flags' => [
                        FILTER_FLAG_PATH_REQUIRED,
                    ],
                ],
                'phalcon.io',
            ],
            [
                [
                    'flags' => [
                        FILTER_FLAG_QUERY_REQUIRED,
                    ],
                ],
                'https://',
            ],
            [
                [
                    'flags' => [
                        FILTER_FLAG_PATH_REQUIRED,
                        FILTER_FLAG_QUERY_REQUIRED,
                    ],
                ],
                'phalconphp',
            ],
        ];
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorUrlCustomMessage(): void
    {
        $validation = new Validation();

        $validation->add(
            'url',
            new Url(
                [
                    'message' => 'The url is not valid',
                ]
            )
        );

        $messages = $validation->validate(
            []
        );

        $expected = new Messages(
            [
                new Message(
                    'The url is not valid',
                    'url',
                    Url::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'x=1',
            ]
        );

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'https://phalcon.io',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-10
     */
    public function testFilterValidationValidatorUrlFlags(
        array | int $options,
        string $url
    ): void {
        $validation = new Validation();

        $validation->add(
            'url',
            new Url(
                [
                    'options' => $options,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'url' => $url,
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $expected = new Messages(
            [
                new Message(
                    'Field url must be a url',
                    'url',
                    Url::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorUrlMultipleField(): void
    {
        $validation = new Validation();

        $validationMessages = [
            'url'        => 'Url must be correct url.',
            'anotherUrl' => 'AnotherUrl must be correct url.',
        ];

        $validation->add(
            [
                'url',
                'anotherUrl',
            ],
            new Url(
                [
                    'message' => $validationMessages,
                ]
            )
        );

        $messages = $validation->validate(
            [
                'url'        => 'https://google.com',
                'anotherUrl' => 'https://google.com',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'url'        => '://google.',
                'anotherUrl' => 'https://google.com',
            ]
        );

        $this->assertSame(
            1,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['url'],
            $messages->offsetGet(0)->getMessage()
        );

        $messages = $validation->validate(
            [
                'url'        => '://google.',
                'anotherUrl' => '://google.',
            ]
        );

        $this->assertSame(
            2,
            $messages->count()
        );

        $this->assertSame(
            $validationMessages['url'],
            $messages->offsetGet(0)->getMessage()
        );

        $this->assertSame(
            $validationMessages['anotherUrl'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function testFilterValidationValidatorUrlSingleField(): void
    {
        $validation = new Validation();

        $validation->add('url', new Url());


        $messages = $validation->validate([]);

        $expected = new Messages(
            [
                new Message(
                    'Field url must be a url',
                    'url',
                    Url::class,
                    0
                ),
            ]
        );

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'x=1',
            ]
        );

        $this->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'https://phalcon.io',
            ]
        );

        $this->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function testFilterValidationValidatorUrlValidateEmpty(): void
    {
        $validation = new Validation();
        $validator  = new Url(['allowEmpty' => true,]);
        $validation->add('url', $validator);
        $entity      = new stdClass();
        $entity->url = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'url');
        $this->assertTrue($result);
    }
}
