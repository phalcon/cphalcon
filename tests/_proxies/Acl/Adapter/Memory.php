<?php

namespace Phalcon\Test\Proxy\Acl\Adapter;

use Phalcon\Acl\Adapter\Memory as PhAdapter;

/**
 * \Phalcon\Test\Proxy\Acl\Adapter\Memory
 * Acl Adapter Memory proxy class for \Phalcon\Acl\Adapter\Memory
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Proxy\Acl\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
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

    public function allow($roleName, $resourceName, $access, $func = null)
    {
        parent::allow($roleName, $resourceName, $access, $func);
    }

    public function deny($roleName, $resourceName, $access, $func = null)
    {
        parent::deny($roleName, $resourceName, $access, $func);
    }

    public function isAllowed($roleName, $resourceName, $access, array $parameters = null)
    {
        return parent::isAllowed($roleName, $resourceName, $access, $parameters);
    }

    public function getRoles()
    {
        return parent::getRoles();
    }

    public function getResources()
    {
        return parent::getResources();
    }

    public function setNoArgumentsDefaultAction($defaultAccess)
    {
        parent::setNoArgumentsDefaultAction($defaultAccess);
    }

    public function getNoArgumentsDefaultAction()
    {
        return parent::getNoArgumentsDefaultAction();
    }
}
