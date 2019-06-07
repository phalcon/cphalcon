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

use Phalcon\Mvc\Collection;

class Robots extends Collection
{
    public $first_name;
    public $last_name;

    protected $protected_field;
    private $private_field;
}
