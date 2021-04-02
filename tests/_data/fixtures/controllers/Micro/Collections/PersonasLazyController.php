<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Test\Controllers\Micro\Collections;

class PersonasLazyController
{
    protected static $entered = 0;

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
