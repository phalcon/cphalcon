<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Micro;

use Phalcon\Mvc\Micro;
use Phalcon\Mvc\Micro\MiddlewareInterface;

class MyMiddleware implements MiddlewareInterface
{
    protected $number = 0;

    public function call(Micro $application)
    {
        $this->number++;
    }

    public function getNumber()
    {
        return $this->number;
    }
}
