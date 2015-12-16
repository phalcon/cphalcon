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

class TestRoleable extends Model implements Roleable
{
    protected $id;
    protected $roleName;

    public function getId()
    {
        return $this->id;
    }

    public function getRoleName()
    {
        return $this->roleName;
    }
}