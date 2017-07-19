<?php

namespace Phalcon\Test\Models\BodyParts;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\Head
 *
 * @copyright 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Radek Crlík <radekcrlik@gmail.com>
 * @package   Phalcon\Test\Models\BodyParts
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Head extends Model
{
    public $id;

    public function initialize()
    {
        $this->setSource('issue12071_head');
    }
}
