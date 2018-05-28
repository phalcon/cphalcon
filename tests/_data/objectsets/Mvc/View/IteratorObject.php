<?php

/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-present Phalcon Team (https://phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Test\Objectsets\Mvc\View;

/**
 * Phalcon\Test\Objectsets\Mvc\View\IteratorObject
 *
 * @package Phalcon\Test\Objectsets\Mvc\View
 */
class IteratorObject implements \Iterator, \Countable
{
    private $_data = array();

    private $_pointer = 0;

    public function __construct($data)
    {
        $this->_data = $data;
    }

    public function count()
    {
        return count($this->_data);
    }

    public function current()
    {
        return $this->_data[$this->_pointer];
    }

    public function key()
    {
        return $this->_pointer;
    }

    public function next()
    {
        ++$this->_pointer;
    }

    public function rewind()
    {
        $this->_pointer = 0;
    }

    public function valid()
    {
        return $this->_pointer < count($this->_data);
    }
}
