<?php

namespace Phalcon\Test\Acl;

use Phalcon\Acl\ResourceAware;
use Phalcon\Acl\RoleAware;

/**
 * TestRoleResourceAware
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
class TestRoleResourceAware implements RoleAware, ResourceAware
{
    /**
     * @var int
     */
    protected $user;

    /**
     * @var string
     */
    protected $resourceName;

    /**
     * @var string
     */
    protected $roleName;

    /**
     * @param $user
     * @param $resourceName
     * @param $roleName
     */
    public function __construct($user, $resourceName, $roleName)
    {
        $this->user = $user;
        $this->resourceName = $resourceName;
        $this->roleName = $roleName;
    }

    /**
     * @return string
     */
    public function getResourceName()
    {
        return $this->resourceName;
    }

    /**
     * @return string
     */
    public function getRoleName()
    {
        return $this->roleName;
    }

    /**
     * @return int
     */
    public function getUser()
    {
        return $this->user;
    }
}
