<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

/**
 * SomeComponent class
 */
class SomeComponent
{
    public $someProperty;

    public function __construct($value)
    {
        $this->someProperty = $value;
    }
}
