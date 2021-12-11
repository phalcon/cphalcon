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
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Tests\Fixtures\Traits\DiTrait;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Filter\Validation\Validator\Regex;

class GetMessagesCest
{
    /**
     * Tests Form::getMessages()
     *
     * @author Mohamad Rostami <rostami@outlook.com>
     * @issue  https://github.com/phalcon/cphalcon/issues/13294
     */
    public function testGetElementMessagesFromForm(IntegrationTester $I)
    {
        // First element
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

        $form    = new Form();
        $address = new Text('address');

        $form->add($telephone);
        $form->add($address);

        $form->setValidation($customValidation);

        $actual = $form->isValid(
            [
                'address' => 'hello',
            ]
        );

        $I->assertFalse($actual);

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

        $I->assertEquals(
            $expected,
            $form->getMessages()
        );
    }
}
