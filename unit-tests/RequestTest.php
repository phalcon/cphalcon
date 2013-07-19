<?php

/*
	+------------------------------------------------------------------------+
	| Phalcon Framework                                                      |
	+------------------------------------------------------------------------+
	| Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
	|          Vladimir Kolesnikov <vladimir@extrememember.com>              |
	+------------------------------------------------------------------------+
*/

class RequestTest extends PHPUnit_Framework_TestCase
{

	public function testHasFiles()
	{
		$request = new \Phalcon\Http\Request();

		$_FILES = array(
			'test' => array(
				'name'     => 'name',
				'type'     => 'text/plain',
				'size'     => 1,
				'tmp_name' => 'tmp_name',
				'error'    => 0,
			)
		);

		$this->assertEquals($request->hasFiles(false), 1);
		$this->assertEquals($request->hasFiles(true), 1);

		$_FILES = array(
			'test' => array(
				'name'     => array('name1', 'name2'),
				'type'     => array('text/plain', 'text/plain'),
				'size'     => array(1, 1),
				'tmp_name' => array('tmp_name1', 'tmp_name2'),
				'error'    => array(0, 0),
			)
		);

		$this->assertEquals($request->hasFiles(false), 2);
		$this->assertEquals($request->hasFiles(true), 2);

		$_FILES = array (
			'photo' => array(
				'name' => array(
					0 => '',
					1 => '',
					2 => array(0 => '', 1 => '', 2 => ''),
					3 => array(0 => ''),
					4 => array(
						0 => array(0 => ''),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => ''),
							),
						),
					),
				),
				'type' => array(
					0 => '',
					1 => '',
					2 => array(0 => '', 1 => '', 2 => ''),
					3 => array(0 => ''),
					4 => array(
						0 => array(0 => ''),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => ''),
							),
						),
					),
				),
				'tmp_name' => array(
					0 => '',
					1 => '',
					2 => array(0 => '', 1 => '', 2 => ''),
					3 => array(0 => ''),
					4 => array(
						0 => array(0 => ''),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => ''),
							),
						),
					),
				),
				'error' => array(
					0 => 4,
					1 => 4,
					2 => array(0 => 4, 1 => 4, 2 => 4),
					3 => array(0 => 4),
					4 => array(
						0 => array(0 => 4),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => 4),
							),
						),
					),
				),
				'size' => array(
					0 => 0,
					1 => 0,
					2 => array(0 => 0, 1 => 0, 2 => 0),
					3 => array(0 => 0),
					4 => array(
						0 => array(0 => 0),
					),
					5 => array(
						0 => array(
							0 => array(
								0 => array(0 => 0),
							),
						),
					),
				),
			),
			'test' => array(
				'name' => '',
				'type' => '',
				'tmp_name' => '',
				'error' => 4,
				'size' => 0,
			),
		);

		$this->assertEquals($request->hasFiles(false), 9);
		$this->assertEquals($request->hasFiles(true), 0);
	}

}
