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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator\Url;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Exception;
use Phalcon\Filter\Validation\Validator\Url;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

use const FILTER_FLAG_PATH_REQUIRED;
use const FILTER_FLAG_QUERY_REQUIRED;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\Url :: validate() - empty
     *
     * @param IntegrationTester $I
     *
     * @return void
     * @throws Exception
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2023-08-03
     */
    public function filterValidationValidatorUrlValidateEmpty(IntegrationTester $I)
    {
        $I->wantToTest("Validation\Validator\Url - validate() - empty");

        $validation = new Validation();
        $validator  = new Url(['allowEmpty' => true,]);
        $validation->add('url', $validator);
        $entity = new stdClass();
        $entity->url = '';

        $validation->bind($entity, []);
        $result = $validator->validate($validation, 'url');
        $I->assertTrue($result);
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Url :: validate() - single field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorUrlSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Url :: validate() - single field');

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

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'x=1',
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'http://phalcon.io',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Url :: validate() - multiple field
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorUrlMultipleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Url :: validate() - multiple field');

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
                'url'        => 'http://google.com',
                'anotherUrl' => 'http://google.com',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );

        $messages = $validation->validate(
            [
                'url'        => '://google.',
                'anotherUrl' => 'http://google.com',
            ]
        );

        $I->assertSame(
            1,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['url'],
            $messages->offsetGet(0)->getMessage()
        );

        $messages = $validation->validate(
            [
                'url'        => '://google.',
                'anotherUrl' => '://google.',
            ]
        );

        $I->assertSame(
            2,
            $messages->count()
        );

        $I->assertSame(
            $validationMessages['url'],
            $messages->offsetGet(0)->getMessage()
        );

        $I->assertSame(
            $validationMessages['anotherUrl'],
            $messages->offsetGet(1)->getMessage()
        );
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Url :: validate() - custom message
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function filterValidationValidatorUrlCustomMessage(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Url :: validate() - custom message');

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

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'x=1',
            ]
        );

        $I->assertEquals($expected, $messages);


        $messages = $validation->validate(
            [
                'url' => 'http://phalcon.io',
            ]
        );

        $I->assertSame(
            0,
            $messages->count()
        );
    }

    /**
     * Tests Phalcon\Filter\Validation\Validator\Url :: validate() - flags
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2019-05-10
     */
    public function filterValidationValidatorUrlFlags(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Validation\Validator\Url :: validate() - options ' . $example[0]);

        $validation = new Validation();

        $validation->add(
            'url',
            new Url(
                [
                    'options' => $example[1],
                ]
            )
        );

        $messages = $validation->validate(
            [
                'url' => $example[2],
            ]
        );

        $I->assertSame(
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

        $I->assertEquals($expected, $messages);
    }

    private function getExamples(): array
    {
        return [
            [
                'path required no array',
                FILTER_FLAG_PATH_REQUIRED,
                'phalcon.io',
            ],
            [
                'query required no array',
                FILTER_FLAG_QUERY_REQUIRED,
                'https://',
            ],
            [
                'path required',
                [
                    'flags' => [
                        FILTER_FLAG_PATH_REQUIRED,
                    ],
                ],
                'phalcon.io',
            ],
            [
                'query required',
                [
                    'flags' => [
                        FILTER_FLAG_QUERY_REQUIRED,
                    ],
                ],
                'https://',
            ],
            [
                'query and path required',
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
}
