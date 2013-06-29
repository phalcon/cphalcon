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

class ConfigTest extends PHPUnit_Framework_TestCase
{

	private $_config = array(
		"phalcon" => array(
			"baseuri" => "/phalcon/"
		),
		"models" => array(
			"metadata" => "memory"
		),
		"database" => array(
			"adapter" => "mysql",
			"host" => "localhost",
			"username" => "user",
			"password" => "passwd",
			"name" => "demo"
		),
		"test" => array(
			"parent" => array(
				"property" => 1,
			),
			"parent" => array(
				"property2" => "yeah"
			)
		)
	);

	private function _compareConfig($c, $config)
	{
		foreach ($c as $k => $v) {
			$this->assertTrue(isset($config->$k));
			if (is_array($v)) {
				if (isset($config->$k)) {
					foreach ($v as $kk => $vv) {
						$this->assertTrue(isset($config->$k->$kk));
						if (isset($config->$k->$kk)) {
							if (is_array($vv)) {
								foreach ($vv as $kkk => $vvv) {
									if (isset($config->$k->$kk->$kkk)) {
										$this->assertTrue(isset($config->$k->$kk->$kkk));
										$this->assertEquals($vvv, $config->$k->$kk->$kkk);
									}
								}
							} else {
								$this->assertEquals($vv, $config->$k->$kk);
							}
						}
					}
				}
			}
		}
		return true;
	}

	public function testIniConfig()
	{
		$config = new Phalcon\Config\Adapter\Ini('unit-tests/config/config.ini');
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}

	public function testStandarConfig()
	{
		$config = new Phalcon\Config($this->_config);
		$this->_compareConfig($this->_config, $config);
	}

	public function testStandardConfigSimpleArray()
	{

		$expectedConfig = Phalcon\Config::__set_state(array(
			'database' => Phalcon\Config::__set_state(array(
				'adapter' => 'Mysql',
				'host' => 'localhost',
				'username' => 'scott',
				'password' => 'cheetah',
				'name' => 'test_db',
			)),
			'other' => array(
				0 => 1,
				1 => 2,
				2 => 3,
				3 => 4,
			),
		));

		$settings = array(
			"database" => array(
				"adapter"  => "Mysql",
				"host"     => "localhost",
				"username" => "scott",
				"password" => "cheetah",
				"name"     => "test_db",
			),
			"other" => array(1, 2, 3, 4)
		);
		$config = new Phalcon\Config($settings);

		$this->assertEquals($config, $expectedConfig);
	}

	public function testConfigMerge()
	{

		$config1 = new Phalcon\Config(array(
			"controllersDir" => "../x/y/z",
			"modelsDir" => "../x/y/z",
			"database" => array(
				"adapter"  => "Mysql",
				"host"     => "localhost",
				"username" => "scott",
				"password" => "cheetah",
				"name"     => "test_db",
				"charset" => array(
					"primary" => "utf8"
				),
				"alternatives" => array(
					"primary" => "latin1",
					"second" => "latin1"
				)
			),
		));

		$config2 = new Phalcon\Config(array(
			"modelsDir" => "../x/y/z",
			"database" => array(
				"adapter"  => "Postgresql",
				"host"     => "localhost",
				"username" => "peter",
				"options" => array(
					"case" => "lower"
				),
				"alternatives" => array(
					"primary" => "swedish",
					"third" => "american"
				)
			),
		));

		$config1->merge($config2);

		$expected = Phalcon\Config::__set_state(array(
			'controllersDir' => '../x/y/z',
			'modelsDir' => '../x/y/z',
			'database' => Phalcon\Config::__set_state(array(
				'adapter' => 'Postgresql',
				'host' => 'localhost',
				'username' => 'peter',
				'password' => 'cheetah',
				'name' => 'test_db',
				'charset' => Phalcon\Config::__set_state(array(
					'primary' => 'utf8',
				)),
				'alternatives' => Phalcon\Config::__set_state(array(
					'primary' => 'swedish',
					'second' => 'latin1',
					'third' => 'american',
				)),
				'options' => Phalcon\Config::__set_state(array(
					'case' => 'lower',
				)),
			)),
		));

		$this->assertEquals($config1, $expected);

	}


	public function testIssue731()
	{
		// Code path AAA, B, AE, B
		$a = new Phalcon\Config(array('aaa' => array('b' => 2, 'c' => 3)));
		$b = new Phalcon\Config(array('aaa' => array('a' => 10, 'c' => 30, 'd' => 40)));
		$c = array('aaa' => array('b' => 2, 'c' => 30, 'a' => 10, 'd' => 40));
		$a->merge($b);
		$this->assertEquals($a->toArray(), $c);

		// Code path AAB
		$a = new Phalcon\Config(array('aab' => (object)array('n' => 'm')));
		$b = new Phalcon\Config(array('aab' => array('x' => 'y')));
		$c = array('aab' => array('x' => 'y'));
		$a->merge($b);
		$this->assertEquals($a->toArray(), $c);

		//Code path AB
		$a = new Phalcon\Config(array('ab' => array('b' => 1, 'c' => 2)));
		$b = new Phalcon\Config(array('ab' => array(0 => -10, 'c' => 20, 'd' => 30)));
		$c = array('ab' => array(0 => -10, 'c' => 2, 'd' => 30, 'b' => 1));
		$b->merge($a);
		$this->assertEquals($b->toArray(), $c);

		// Code path AC
		$a = new Phalcon\Config(array('ac' => array('b' => 1, 'c' => 2)));
		$b = new Phalcon\Config(array('ac' => array(0 => -10, 'c' => 20, 'd' => 30)));
		$c = array('ac' => array(0 => -10, 'c' => 20, 'd' => 30, 'b' => 1));
		$a->merge($b);
		$this->assertEquals($a->toArray(), $c);

		// Code path AD
		$a = new Phalcon\Config(array('ad' => array(0 => 1, 1 => 2, 2 => 3)));
		$b = new Phalcon\Config(array('ad' => array(1 => 20, 3 => 40)));
		$c = array('ad' => array(0 => 1, 1 => 20, 2 => 3, 3 => 40));
		$a->merge($b);
		$this->assertEquals($a->toArray(), $c);
	}
}
