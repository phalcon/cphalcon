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
use \PhalconTest\Acl\Adapter as PhTAdapter;

class Memory extends PhTAdapter
{
    public function __construct()
    {
        $this->adapter = new PhAdapter();
    }

    public function __desctruct()
    {
        unset($this->adapter);
    }
    public function addRole($role, $accessInherits = null)
	{
        return $this->adapter->addRole($role, $accessInherits);
    }

	public function addInherit($roleName, $roleToInherit)
	{
        return $this->adapter->addInherit($roleName, $roleToInherit);
	}

	public function isRole($roleName)
	{
        return $this->adapter->isRole($roleName);
	}

	public function isResource($resourceName)
	{
        return $this->adapter->isResource($resourceName);
	}

	public function addResource($resourceValue, $accessList)
	{
        return $this->adapter->addResource($resourceValue, $accessList);
	}

	public function addResourceAccess($resourceName, $accessList)
	{
        return $this->adapter->addResourceAccess($resourceName, $accessList);
	}

	public function dropResourceAccess($resourceName, $accessList)
	{
        $this->adapter->dropResourceAccess($resourceName, $accessList);
    }

	public function allow($roleName, $resourceName, $access)
	{
        $this->adapter->allow($roleName, $resourceName, $access);
    }

	public function deny($roleName, $resourceName, $access)
	{
        $this->adapter->deny($roleName, $resourceName, $access);
    }

	public function isAllowed($roleName, $resourceName, $access)
	{
        return $this->adapter->isAllowed($roleName, $resourceName, $access);
	}

	public function getRoles()
    {
        return $this->adapter->getRoles();
	}

	public function getResources()
    {
        return $this->adapter->getResources();
	}
}
