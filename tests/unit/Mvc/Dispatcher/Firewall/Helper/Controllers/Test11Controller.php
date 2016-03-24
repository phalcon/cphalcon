<?php

namespace Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\Controllers;

use Phalcon\Mvc\Controller;

/**
 * \Phalcon\Test\Unit\Mvc\Dispatcher\Firewall\Helper\Test11Controller
 * Helper controller for firewall tests
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @author    Wojciech Ślawski <jurigag@gmail.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class Test11Controller extends Controller
{
	/**
	 * @Allow("ROLE1")
	 */
	public function firstRoleAction()
	{
		return "allowed";
	}

	/**
	 * @Deny("ROLE1")
	 */
	public function secondRoleAction()
	{
		return "allowed";
	}
	
	/**
	 * @Allow({"ROLE1","ROLE2"})
	 */
	public function firstArrayAction()
	{
		return "allowed";
	}

	/**
	 * @Deny({"ROLE1","ROLE2"})
	 */
	public function secondArrayAction()
	{
		return "allowed";
	}

	/**
	 * @Allow()
	 */
	public function allowEveryoneAction()
	{
		return "allowed";
	}

	/**
	 * @Deny()
	 */
	public function denyEveryoneAction()
	{
		return "allowed";
	}
}
