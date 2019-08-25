<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Models;

use Phalcon\Messages\Message;
use Phalcon\Mvc\Model;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email as EmailValidator;
use Phalcon\Validation\Validator\ExclusionIn as ExclusionInValidator;
use Phalcon\Validation\Validator\InclusionIn as InclusionInValidator;
use Phalcon\Validation\Validator\PresenceOf as PresenceOfValidator;
use Phalcon\Validation\Validator\Regex as RegexValidator;
use Phalcon\Validation\Validator\StringLength as StringLengthValidator;
use Phalcon\Validation\Validator\Uniqueness as UniquenessValidator;

class Subscriptores extends Model
{
    public function beforeValidation()
    {
        if ($this->email == 'marina@hotmail.com') {
            $this->appendMessage(
                new Message('Sorry Marina, but you are not allowed here')
            );

            return false;
        }
    }

    public function beforeDelete()
    {
        if ($this->email == 'fuego@hotmail.com') {
            $this->appendMessage(
                new Message('Sorry this cannot be deleted')
            );

            return false;
        }
    }

    public function validation()
    {
        $validator = new Validation();

        $validator->add(
            'created_at',
            new PresenceOfValidator()
        );

        $validator->add(
            'email',
            new StringLengthValidator(
                [
                    'min' => '7',
                    'max' => '50',
                ]
            )
        );

        $validator->add(
            'email',
            new EmailValidator()
        );

        $validator->add(
            'status',
            new ExclusionInValidator(
                [
                    'domain' => ['X', 'Z'],
                ]
            )
        );

        $validator->add(
            'status',
            new InclusionInValidator(
                [
                    'domain' => ['P', 'I', 'w'],
                ]
            )
        );

        $validator->add(
            'email',
            new UniquenessValidator(
                [
                    'model' => $this,
                ]
            )
        );

        $validator->add(
            'status',
            new RegexValidator(
                [
                    'pattern' => '/[A-Z]/',
                ]
            )
        );

        return $this->validate($validator);
    }
}
