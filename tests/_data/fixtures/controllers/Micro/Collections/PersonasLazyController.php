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

class PersonasLazyController
{
    static protected $entered = 0;

    public static function getEntered()
    {
        return self::$entered;
    }

    public function index()
    {
        self::$entered++;
    }

    public function edit($number)
    {
        self::$entered += $number;
    }
}
