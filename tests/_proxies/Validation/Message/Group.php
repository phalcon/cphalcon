<?php

namespace Phalcon\Test\Proxy\Validation\Message;

use Phalcon\Validation\MessageInterface;
use Phalcon\Validation\Message\Group as PhGroup;

/**
 * \Phalcon\Test\Proxy\Validation\Message\Group
 * A proxy class for \Phalcon\Validation\Message\Group component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Validation\Message
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Group extends PhGroup
{
    public function __construct($messages = null)
    {
        parent::__construct($messages);
    }

    public function offsetGet($index)
    {
        return parent::offsetGet($index);
    }

    public function offsetSet($index, $message)
    {
        parent::offsetSet($index, $message);
    }

    public function offsetExists($index)
    {
        return parent::offsetExists($index);
    }

    public function offsetUnset($index)
    {
        parent::offsetUnset($index);
    }

    public function appendMessage(MessageInterface $message)
    {
        parent::appendMessage($message);
    }

    public function appendMessages($messages)
    {
        parent::appendMessages($messages);
    }

    public function filter($fieldName)
    {
        return parent::filter($fieldName);
    }

    public function count()
    {
        return parent::count();
    }

    public function rewind()
    {
        parent::rewind();
    }

    public function current()
    {
        return parent::current();
    }

    public function key()
    {
        return parent::key();
    }

    public function next()
    {
        parent::next();
    }

    public function valid()
    {
        return parent::valid();
    }

    public static function __set_state($group)
    {
        return parent::__set_state($group);
    }
}
