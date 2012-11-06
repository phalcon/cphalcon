<?php

/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

class RestHandler
{

	protected $_access = 0;

	protected $_trace = array();

	public function find()
	{
		$this->_access++;
		$this->_trace[] = 'find';
	}

	public function save()
	{
		$this->_access++;
		$this->_trace[] = 'save';
	}

	public function getNumberAccess()
	{
		return $this->_access;
	}

	public function getTrace()
	{
		return $this->_trace;
	}

}

class MicroMvcTest extends PHPUnit_Framework_TestCase
{

	public function testMicroClass()
	{

		$handler = new RestHandler($this);

		$app = new Phalcon\Mvc\Micro();

		$app->get('/api/site', array($handler, 'find'));
		$app->post('/api/site/save', array($handler, 'save'));

		$_SERVER['REQUEST_METHOD'] = 'GET';
		$_GET['_url'] = '/api/site';

		$app->handle();

		$this->assertEquals($handler->getNumberAccess(), 1);
		$this->assertEquals($handler->getTrace(), array('find'));

		$_SERVER['REQUEST_METHOD'] = 'POST';
		$_GET['_url'] = '/api/site/save';

		$app->handle();

		$this->assertEquals($handler->getNumberAccess(), 2);
		$this->assertEquals($handler->getTrace(), array('find', 'save'));
	}

    /**
     * Tests the notFound
     *
     * @issue  T169
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-06
     */
    public function testMicroNotFound_T169()
    {
        $handler = new RestHandler($this);
        $app     = new \Phalcon\Mvc\Micro();

        $app->get('/api/site', array($handler, 'find'));
        $app->post('/api/site/save', array($handler, 'save'));

        $app->notFound(
            function () use ($app) {
                $app->response->setStatusCode(404, "Not Found")->sendHeaders();
                echo 'This is crazy, but this page was not found!';
            }
        );

        $_SERVER['REQUEST_METHOD'] = 'GET';
        $_GET['_url'] = '/fourohfour';

        $app->handle();

        $expected = 1;
        $actual   = $handler->getNumberAccess();

        $this->assertEquals(
            $expected,
            $actual,
            'getNumberAccess does not return correct results'
        );
    }
}