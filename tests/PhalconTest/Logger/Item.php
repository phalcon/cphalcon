<?php
/**
 * Item.php
 * \PhalconTest\Logger\Item
 *
 * Logger\Item proxy class
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace PhalconTest\Logger;

use \Phalcon\Logger\Item as PhItem;

class Item
{
    protected $item = null;

    public function __construct($message, $type, $time = 0, $context = null)
    {
        $this->item = new PhItem($message, $type, $time, $context);
    }

    public function __desctruct()
    {
        unset($this->item);
    }

    protected function getType()
    {
        return $this->item->getType();
    }

    protected function getMessage()
    {
        return $this->item->getMessage();
    }

    protected function getTime()
    {
        return $this->item->getTime();
    }

    protected function getContext()
    {
        return $this->item->getContext();
    }
}
