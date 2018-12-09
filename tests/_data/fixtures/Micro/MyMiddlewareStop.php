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

use Phalcon\Mvc\Micro\MiddlewareInterface;

class MyMiddlewareStop implements MiddlewareInterface
{
    protected $_number = 0;

    public function call(\Phalcon\Mvc\Micro $application)
    {
        $application->stop();
        $this->_number++;
    }

    public function getNumber()
    {
        return $this->_number;
    }
}
