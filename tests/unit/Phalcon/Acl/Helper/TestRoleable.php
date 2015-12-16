<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2015-12-16
 * Time: 23:39
 */

namespace Phalcon\Tests\unit\Phalcon\Acl\Helper;

use Phalcon\Acl\Roleable;
use Phalcon\Mvc\Model;

class TestRoleable implements Roleable
{
    protected $id;
    protected $roleName;

    public function __construct($id,$roleName)
    {
        $this->id=$id;
        $this->roleName=$roleName;
    }

    public function getId()
    {
        return $this->id;
    }

    public function getRoleName()
    {
        return $this->roleName;
    }
}