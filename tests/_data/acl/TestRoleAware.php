<?php

namespace Phalcon\Test\Acl;

use Phalcon\Acl\RoleAware;

/**
 * TestRoleAware
 * Resource class for \Phalcon\Acl\Resource component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Wojciech Slawski <jurigag@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class TestRoleAware implements RoleAware
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
    public function __construct($id, $roleName)
    {
        $this->id = $id;
        $this->roleName = $roleName;
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
