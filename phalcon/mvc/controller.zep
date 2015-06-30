
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc;

use Phalcon\Di\Injectable;
use Phalcon\DispatcherInterface;
use Phalcon\Http\Response\ResponseInterface;

/**
 * Phalcon\Mvc\Controller
 *
 * Every application controller should extend this class that encapsulates all the controller functionality
 *
 * The controllers provide the “flow” between models and views. Controllers are responsible
 * for processing the incoming requests from the web browser, interrogating the models for data,
 * and passing that data on to the views for presentation.
 *
 *<code>
 *<?php
 *
 *class PeopleController extends \Phalcon\Mvc\Controller
 *{
 *
 *  //This action will be executed by default
 *  public function indexAction()
 *  {
 *
 *  }
 *
 *  public function findAction()
 *  {
 *
 *  }
 *
 *  public function saveAction()
 *  {
 *   //Forwards flow to the index action
 *   return $this->dispatcher->forward(array('controller' => 'people', 'action' => 'index'));
 *  }
 *
 *}
 *
 *</code>
 */
abstract class Controller extends Injectable implements ControllerInterface
{

	/**
	 * Phalcon\Mvc\Controller constructor
	 */
	public final function __construct()
	{
		if method_exists(this, "onConstruct") {
			this->{"onConstruct"}();
		}
	}

	/**
	 * Redirect by HTTP to another action or URL

	 * This method is alias for Phalcon\Http\Response::redirect()
	 */
	public function redirect(var location, boolean externalRedirect = false, int statusCode = 302) -> <ResponseInterface>
	{
		var response;
		let response = this->getDI()->get("response");

		if !(response instanceof ResponseInterface) {
			throw new Exception("Service \"response\" must implement the interface \"Phalcon\Http\Response\ResponseInterface\"");
		}

		return response->redirect(location, externalRedirect, statusCode);
	}

	/**
	 * Forwards the execution flow to another controller/action
	 * Dispatchers are unique per module. Forwarding between modules is not allowed
	 *
	 * This method is alias for Phalcon\Dispatcher::forward()
	 */
	public function forward(array options) -> void
	{
		var dispatcher;
		let dispatcher = this->getDI()->get("dispatcher");

		if !(dispatcher instanceof DispatcherInterface) {
			throw new Exception("Service \"dispatcher\" must implement the interface \"Phalcon\DispatcherInterface\"");
		}

		dispatcher->forward(options);
	}
}
