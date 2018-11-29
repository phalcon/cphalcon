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

class RestHandler
{
    protected $_access = 0;

    protected $_trace = [];



    public function find()
    {
        $this->_access++;
        $this->_trace[] = "find";
    }

    public function save()
    {
        $this->_access++;
        $this->_trace[] = "save";
    }

    public function delete()
    {
        $this->_access++;
        $this->_trace[] = "delete";
    }

    public function getNumberAccess()
    {
        return $this->_access;
    }

    public function getTrace()
    {
        return $this->_trace;
    }
}
