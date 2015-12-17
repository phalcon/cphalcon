<?php
/**
 * Created by PhpStorm.
 * User: Wojtek
 * Date: 2015-12-16
 * Time: 23:39
 */

namespace Phalcon\Tests\unit\Phalcon\Acl\Helper;

use Phalcon\Acl\Roleable;

/**
 * Class TestRoleable for AclMemoryTest::testAclAllowFunction
 * @package Phalcon\Tests\unit\Phalcon\Acl\Helper
 * @author Wojciech Slawski <jurigag@gmail.com>
 * @since  2015-12-16
 */
class TestRoleable implements Roleable
{
    /**
     * @var int
     */
    protected $id;
    /**
     * @var string
     */
    protected $roleName;

    /**
     * @param $id
     * @param $roleName
     */
    public function __construct($id,$roleName)
    {
        $this->id=$id;
        $this->roleName=$roleName;
    }

    /**
     * @return int
     */
    public function getId()
    {
        return $this->id;
    }

    /**
     * @return string
     */
    public function getRoleName()
    {
        return $this->roleName;
    }
}
