<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Integration\Validation\Validator\Url;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Url;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Url :: validate() - single field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorUrlSingleField(IntegrationTester $I)
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
                    'Url',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['url' => 'x=1']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['url' => 'http://phalconphp.com']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Url :: validate() - multiple field
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorUrlMultipleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Url :: validate() - multiple field');
        $validation         = new Validation();
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
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'url'        => '://google.',
                'anotherUrl' => 'http://google.com',
            ]
        );
        $expected = 1;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['url'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(
            [
                'url'        => '://google.',
                'anotherUrl' => '://google.',
            ]
        );
        $expected = 2;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['url'];
        $actual   = $messages->offsetGet(0)->getMessage();
        $I->assertEquals($expected, $actual);

        $expected = $validationMessages['anotherUrl'];
        $actual   = $messages->offsetGet(1)->getMessage();
        $I->assertEquals($expected, $actual);
    }

    /**
     * Tests Phalcon\Validation\Validator\Url :: validate() - custom message
     *
     * @param IntegrationTester $I
     *
     * @author Wojciech Ślawski <jurigag@gmail.com>
     * @since  2016-06-05
     */
    public function validationValidatorUrlCustomMessage(IntegrationTester $I)
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

        $messages = $validation->validate([]);
        $expected = new Messages(
            [
                new Message(
                    'The url is not valid',
                    'url',
                    'Url',
                    0
                ),
            ]
        );
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['url' => 'x=1']);
        $actual   = $messages;
        $I->assertEquals($expected, $actual);

        $messages = $validation->validate(['url' => 'http://phalconphp.com']);
        $expected = 0;
        $actual   = $messages->count();
        $I->assertEquals($expected, $actual);
    }
}
