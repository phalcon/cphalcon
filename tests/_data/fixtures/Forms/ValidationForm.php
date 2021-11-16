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

namespace Phalcon\Tests\Fixtures\Forms;

use Phalcon\Forms\Element\Email;
use Phalcon\Forms\Element\Text;
use Phalcon\Forms\Element\TextArea;
use Phalcon\Forms\Form;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\StringLength;

class ValidationForm extends Form
{
    public function initialize($entity = null, $options = null)
    {
        // Full Name
        $validators = [
            new PresenceOf(
                [
                    'message'      => 'your :field is required',
                    'cancelOnFail' => true,
                ]
            ),
            new StringLength(
                [
                    'max'            => 20,
                    'messageMaximum' => ':field too long',
                    'min'            => 2,
                    'messageMinimum' => ':field too short',
                ]
            ),
        ];
        $field      = new Text('fullname');

        $field->addValidators($validators);

        $this->add($field);

        // Email
        $field = new Email(
            'email',
            []
        );

        $validators = [
            new PresenceOf(
                [
                    'message' => 'valid :field is required',
                ]
            ),
        ];

        $field->addValidators($validators);

        $this->add($field);

        // Subject
        $field      = new Text('subject');
        $validators = [
            new PresenceOf(
                [
                    'message' => 'your :field is required',
                ]
            ),
        ];

        $field->addValidators($validators);

        $this->add($field);

        // Message
        $field      = new TextArea('message');
        $validators = [
            new PresenceOf(
                [
                    'message'      => 'Your message is required',
                    'cancelOnFail' => true,
                ]
            ),
            new StringLength(
                [
                    'max'            => 300,
                    'messageMaximum' => "your message can't be longer than 300 characters",
                    'min'            => 4,
                    'messageMinimum' => 'Tell us what we can do for you',
                ]
            ),
        ];

        $field->addValidators($validators);

        $this->add($field);
    }
}
