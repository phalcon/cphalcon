<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Tests\Models\Validation;

use Phalcon\Messages\Message;
use Phalcon\Mvc\Model;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\ExclusionIn;
use Phalcon\Validation\Validator\InclusionIn;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\Validator\Uniqueness;

/**
 * @property int    id
 * @property string email
 * @property string created_at
 * @property string status
 */
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

        return true;
    }

    public function beforeDelete()
    {
        if ($this->email == 'fuego@hotmail.com') {
            $this->appendMessage(
                new Message('Sorry this cannot be deleted')
            );

            return false;
        }

        return true;
    }

    public function validation()
    {
        $validator = new Validation();

        $validator
            ->add('created_at', new PresenceOf())
            ->add('email', new StringLength(['min' => '7', 'max' => '50']))
            ->add('email', new Email())
            ->add('email', new Uniqueness())
            ->add('status', new ExclusionIn(['domain' => ['P', 'I', 'w']]))
            ->add('status', new InclusionIn(['domain' => ['A', 'y', 'Z']]))
            ->add('status', new Regex(['pattern' => '/[A-Z]/']))
        ;

        return $this->validate($validator);
    }
}
