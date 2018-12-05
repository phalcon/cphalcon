<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Controllers\Micro\Collections;

class PersonasController
{
    protected $entered = 0;

    public function index()
    {
        $this->entered++;
    }

    public function edit($number)
    {
        $this->entered += $number;
    }

    public function getEntered()
    {
        return $this->entered;
    }
}
