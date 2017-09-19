<?php

namespace Phalcon\Test\Models\Validation;

use Phalcon\Mvc\Model;
use Phalcon\Validation;
use Phalcon\Mvc\Model\Message;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\Uniqueness;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\InclusionIn;
use Phalcon\Validation\Validator\ExclusionIn;
use Phalcon\Validation\Validator\StringLength;

/**
 * \Phalcon\Test\Models\Validation\Subscriptores
 *
 * @property int id
 * @property string email
 * @property string created_at
 * @property string status
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Models\Validation
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Subscriptores extends Model
{
    public function beforeValidation()
    {
        if ($this->email == 'marina@hotmail.com') {
            $this->appendMessage(new Message('Sorry Marina, but you are not allowed here'));

            return false;
        }

        return true;
    }

    public function beforeDelete()
    {
        if ($this->email == 'fuego@hotmail.com') {
            $this->appendMessage(new Message('Sorry this cannot be deleted'));

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
            ->add('status', new Regex(['pattern' => '/[A-Z]/']));

        return $this->validate($validator);
    }
}
