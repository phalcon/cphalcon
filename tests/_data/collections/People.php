<?php

namespace Phalcon\Test\Collections;

use Phalcon\Mvc\Collection;
use Phalcon\Mvc\Model\Validator\Email;
use Phalcon\Mvc\Model\Validator\Exclusionin;
use Phalcon\Mvc\Model\Validator\Inclusionin;
use Phalcon\Mvc\Model\Validator\PresenceOf;
use Phalcon\Mvc\Model\Validator\Regex;
use Phalcon\Mvc\Model\Validator\StringLength;
use Phalcon\Mvc\Model\Validator\Uniqueness;

class People extends Collection
{
    public function validation()
    {
        $this->validate(
            new PresenceOf(
                [
                    'field' => 'created_at',
                ]
            )
        );
        $this->validate(
            new StringLength(
                [
                    'field' => 'email',
                    'min'   => '7',
                    'max'   => '50',
                ]
            )
        );
        $this->validate(
            new Email(
                [
                    'field' => 'email',
                ]
            )
        );
        $this->validate(
            new Exclusionin(
                [
                    'field'  => 'status',
                    'domain' => ['P', 'I', 'w'],
                ]
            )
        );
        $this->validate(
            new Inclusionin(
                [
                    'field'  => 'status',
                    'domain' => ['A', 'y', 'Z'],
                ]
            )
        );
        $this->validate(
            new Regex(
                [
                    'field'   => 'status',
                    'pattern' => '/[A-Z]/',
                ]
            )
        );

        return $this->validationHasFailed() != true;
    }
}
