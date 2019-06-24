<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Mvc\Collections;

use Phalcon\Messages\Message;
use Phalcon\Mvc\Collection;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Numericality;

class Robots extends Collection
{
    public $first_name;
    public $last_name;
    public $version = 1;

    protected $protected_field = 42;
    private $private_field;

    public function validation()
    {
        $validation = new Validation;
        $validation->add("protected_field", new Numericality(
            [
                'message' => 'protected_field must be numeric'
            ]
        ));

        if ($this->version < 1) {
            $message = new Message("The version must be greater than 1", "version");
            $this->appendMessage($message);

            return false;
        }

        return $this->validate($validation);
    }

    /**
     * @return mixed
     */
    public function getProtectedField()
    {
        return $this->protected_field;
    }

    /**
     * @param mixed $protected_field
     */
    public function setProtectedField($protected_field): void
    {
        $this->protected_field = $protected_field;
    }

    /**
     * @return mixed
     */
    public function getPrivateField()
    {
        return $this->private_field;
    }

    /**
     * @param mixed $private_field
     */
    public function setPrivateField($private_field): void
    {
        $this->private_field = $private_field;
    }
}
