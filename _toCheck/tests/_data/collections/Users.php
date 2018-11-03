<?php

namespace Phalcon\Test\Collections;

use Phalcon\Mvc\Collection;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\ExclusionIn;
use Phalcon\Validation\Validator\InclusionIn;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\Validator\Uniqueness;

class Users extends Collection
{
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
