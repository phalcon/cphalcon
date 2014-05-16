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

	public function testStandardConfig()
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

	public function testIniConfigDirective()
	{
		$config = new \Phalcon\Config\Adapter\Ini('unit-tests/config/directive.ini');
		$actual = $config->toArray();
		$expected = array(
			'test' => array(
				'parent' => array(
					'property' => 1,
					'property2' => 'yeah',
					'property3' => array('baseuri' => '/phalcon/'),
					'property4' => array(
						'models' => array('metadata' => 'memory'),
					),
					'property5' => array(
						'database' => array(
							'adapter' => 'mysql',
							'host' => 'localhost',
							'username' => 'user',
							'password' => 'passwd',
							'name' => 'demo'),
					),
					'property6' => array(
						'test' => array('a', 'b', 'c'),
					),
				),
			),
		);

		$this->assertEquals($actual, $expected);
	}

	public function testPhpConfig()
	{
		$config = new Phalcon\Config\Adapter\Php('unit-tests/config/config.php');
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}

	public function testJsonConfig()
	{
		$config = new Phalcon\Config\Adapter\Json('unit-tests/config/config.json');
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}

	public function testYamlConfig()
	{
		$config = new Phalcon\Config\Adapter\Yaml('unit-tests/config/config.yml');
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}
}
