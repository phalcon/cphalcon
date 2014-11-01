<?php
/**
 * Memory.php
 * \PhalconTest\Acl\Adapter\Memory
 *
 * Acl Adapter Memory proxy class
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

namespace PhalconTest\Acl\Adapter;

use \Phalcon\Acl\Adapter\Memory as PhAdapter;

class Memory extends PhAdapter
{
    public function addRole($role, $accessInherits = null)
    {
        return parent::addRole($role, $accessInherits);
    }

    public function addInherit($roleName, $roleToInherit)
    {
        return parent::addInherit($roleName, $roleToInherit);
    }

    public function isRole($roleName)
    {
        return parent::isRole($roleName);
    }

    public function isResource($resourceName)
    {
        return parent::isResource($resourceName);
    }

    public function addResource($resourceValue, $accessList)
    {
        return parent::addResource($resourceValue, $accessList);
    }

    public function addResourceAccess($resourceName, $accessList)
    {
        return parent::addResourceAccess($resourceName, $accessList);
    }

    public function dropResourceAccess($resourceName, $accessList)
    {
        parent::dropResourceAccess($resourceName, $accessList);
    }

    public function allow($roleName, $resourceName, $access)
    {
        parent::allow($roleName, $resourceName, $access);
    }

    public function deny($roleName, $resourceName, $access)
    {
        parent::deny($roleName, $resourceName, $access);
    }

    public function isAllowed($roleName, $resourceName, $access)
    {
        return parent::isAllowed($roleName, $resourceName, $access);
    }

    public function getRoles()
    {
        return parent::getRoles();
    }

    public function getResources()
    {
        return parent::getResources();
    }
}
