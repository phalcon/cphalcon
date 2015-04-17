<?php

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

define('APPROOT', dirname(__DIR__));
define('CONFKEY', 'secret');

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
                "adapter" => "Mysql",
                "host" => "localhost",
                "username" => "scott",
                "password" => "cheetah",
                "name" => "test_db",
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
                "adapter" => "Mysql",
                "host" => "localhost",
                "username" => "scott",
                "password" => "cheetah",
                "name" => "test_db",
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
                "adapter" => "Postgresql",
                "host" => "localhost",
                "username" => "peter",
                "options" => array(
                    "case" => "lower",
//					PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
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
                    // todo: add support numeric keys as properties
//					(string)PDO::MYSQL_ATTR_INIT_COMMAND => 'SET NAMES utf8',
                )),
            )),
        ));

        $this->assertEquals($config1, $expected);

    }

    public function testConfigMergeArray()
    {

        $conf1 = array(
            "keys" => array(
                "scott",
                "cheetah",
            ),
        );

        $conf2 = array(
            "keys" => array(
                "peter",
            ),
        );

        $config1 = new Phalcon\Config($conf1);
        $config2 = new Phalcon\Config($conf2);
        $config1->merge($config2);

        $expected = Phalcon\Config::__set_state(array(
            'keys' => Phalcon\Config::__set_state(array(
                '0' => 'scott',
                '1' => 'cheetah',
                '2' => 'peter',
            )),
        ));

        $this->assertEquals($config1, $expected);

        $config1 = new Phalcon\Config($conf1);
        $config2 = new Phalcon\Config($conf2);
        $config2->merge($config1);

        $expected = Phalcon\Config::__set_state(array(
          'keys' => Phalcon\Config::__set_state(array(
                '0' => 'peter',
                '1' => 'scott',
                '2' => 'cheetah',
            )),
        ));

        $this->assertEquals($config2, $expected);

    }

    public function testConfigCount()
    {
        $config = new Phalcon\Config(array(
            "controllersDir" => "../x/y/z",
            "modelsDir" => "../x/y/z",
        ));

        $this->assertEquals(2, count($config));

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

    public function testYamlConfigCallback()
    {
        $config = new Phalcon\Config\Adapter\Yaml('unit-tests/config/config.yml', array(
            '!decrypt' => function ($value) {
                $crypt = new Phalcon\Crypt;
                return $crypt->setCipher('blowfish')->decryptBase64($value, CONFKEY);
            },
            '!approot' => function ($value) {
                return APPROOT . $value;
            }
        ));
        $this->assertTrue($this->_compareConfig($this->_config, $config));
    }

    public function testNumericConfig()
    {
		$config = new \Phalcon\Config(array("abc"));
		$this->assertEquals($config->{0}, "abc");
    }

    public function testChildArrayToConfigObject()
    {
		$config = new \Phalcon\Config(array('childsettings' => array('A', 'B', 'C')));
		$this->assertInstanceOf('Phalcon\Config', $config->childsettings);
    }
}
