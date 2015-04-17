<?php
/**
 * Select.php
 * \PhalconTest\Models\Select
 *
 * Select model class
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

namespace PhalconTest\Models;

use \Phalcon\Mvc\Model as PhModel;

class Select extends PhModel
{
    public function initialize()
    {
    }

    public function getSource()
    {
        return 'ph_select';
    }

    public function getId()
    {
        return $this->sel_id;
    }

    public function getName()
    {
        return $this->sel_name;
    }

    public function getText()
    {
        return $this->sel_text;
    }

    public function setId($id)
    {
        $this->sel_id = $id;
    }

    public function setName($name)
    {
        $this->sel_name = $name;
    }

    public function setText($text)
    {
        $this->sel_text = $text;
    }
}
