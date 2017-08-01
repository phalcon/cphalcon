<?php

namespace Phalcon\Test\Collections;

use Phalcon\Mvc\Collection;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\Exclusionin;
use Phalcon\Validation\Validator\Inclusionin;
use Phalcon\Validation\Validator\PresenceOf;
use Phalcon\Validation\Validator\Regex;
use Phalcon\Validation\Validator\StringLength;
use Phalcon\Validation\Validator\Uniqueness;

class People extends Collection
{
    public function validation()
    {
        $validator = new Validation();

        $validator->add(
            "created_at",
            new PresenceOf()
        );

        $validator->add(
            "email",
            new StringLength(
                [
                    'min'   => '7',
                    'max'   => '50',
                ]
            )
        );

        $validator->add(
            "email",
            new Email()
        );

        $validator->add(
            "status",
            new Exclusionin(
                [
                    'domain' => ['P', 'I', 'w'],
                ]
            )
        );

        $validator->add(
            "status",
            new Inclusionin(
                [
                    'domain' => ['A', 'y', 'Z'],
                ]
            )
        );

        $validator->add(
            "status",
            new Regex(
                [
                    'pattern' => '/[A-Z]/',
                ]
            )
        );

        return $this->validate($validator);
    }
}
