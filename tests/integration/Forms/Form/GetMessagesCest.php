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

namespace Phalcon\Test\Integration\Forms\Form;

use IntegrationTester;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Form;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Tag;
use Phalcon\Test\Fixtures\Traits\DiTrait;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;

class GetMessagesCest
{
    use DiTrait;

    public function _before(IntegrationTester $I)
    {
        $this->newDi();
        $this->setDiEscaper();
        $this->setDiUrl();
    }

    /**
     * executed after each test
     */
    public function _after(IntegrationTester $I)
    {
        // Setting the doctype to XHTML5 for other tests to run smoothly
        Tag::setDocType(Tag::XHTML5);
    }

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
