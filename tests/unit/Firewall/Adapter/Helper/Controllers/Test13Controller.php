<?php

namespace Phalcon\Test\Unit\Firewall\Helper\Controllers;
use Phalcon\Mvc\Controller;

/**
 * 
 * \Phalcon\Test\Unit\Firewall\Helper\Test13Controller
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
 * 
 * @Deny()
 */
class Test13Controller extends Controller
{
	public function denyAction()
	{
		return "allowed";
	}
}
