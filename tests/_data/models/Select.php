<?php

namespace Phalcon\Test\Models;

use Phalcon\Mvc\Model;

/**
 * \Phalcon\Test\Models\Select.php
 * Select model class
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Models
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Select extends Model
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
