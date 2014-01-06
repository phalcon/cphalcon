<?php
/**
 * UnitTest.php
 * Config_UnitTest
 *
 * Tests the \Phalcon\Config component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @author    Vladimir Kolesnikov <vladimir@extrememember.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Config;

class UnitTest extends \Phalcon\Test\UnitTestCase
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
		$config = new \Phalcon\Config\Adapter\Ini(PATH_CONFIGS . '/config.ini');
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}

	public function testStandardConfig()
	{
		$config = new \Phalcon\Config($this->_config);
		$this->assertTrue($this->_compareConfig($this->_config, $config));
	}

	public function testStandardConfigSimpleArray()
	{
		$expected = \Phalcon\Config::__set_state(
			array(
				'database' => \Phalcon\Config::__set_state(
					array(
						'adapter' => 'Mysql',
						'host' => 'localhost',
						'username' => 'scott',
						'password' => 'cheetah',
						'name' => 'test_db',
					)
				),
				'other' => array(
					0 => 1,
					1 => 2,
					2 => 3,
					3 => 4,
				),
			)
		);

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

		$actual = new \Phalcon\Config($settings);

		$this->assertEquals($expected, $actual);
	}

	public function testConfigMerge()
	{
		$config1 = new \Phalcon\Config(
			array(
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
			)
		);

		$config2 = new \Phalcon\Config(
			array(
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
			)
		);

		$config1->merge($config2);

		$expected = \Phalcon\Config::__set_state(
			array(
				'controllersDir' => '../x/y/z',
				'modelsDir' => '../x/y/z',
				'database' => \Phalcon\Config::__set_state(
					array(
						'adapter' => 'Postgresql',
						'host' => 'localhost',
						'username' => 'peter',
						'password' => 'cheetah',
						'name' => 'test_db',
						'charset' => \Phalcon\Config::__set_state(array('primary' => 'utf8')),
						'alternatives' => \Phalcon\Config::__set_state(
							array(
								'primary' => 'swedish',
								'second' => 'latin1',
								'third' => 'american',
							)
						),
						'options' => \Phalcon\Config::__set_state(array('case' => 'lower')),
					)
				),
			)
		);

		$this->assertEquals($expected, $config1);
	}

	public function testIniConfigDirective()
	{
		$config = new \Phalcon\Config\Adapter\Ini(PATH_CONFIGS . '/directive.ini');
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
							'name' => 'demo'
						),
					),
					'property6' => array(
						'test' => array('a', 'b', 'c'),
					),
				),
			),
		);

		$this->assertEquals($expected, $actual);
	}
}
