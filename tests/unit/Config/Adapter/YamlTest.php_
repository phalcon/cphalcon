<?php

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use Phalcon\Config\Adapter\Yaml;

/**
 * \Phalcon\Test\Unit\Config\Adapter\YamlTest
 * Tests the \Phalcon\Config\Adapter\Yaml component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Config\Adapter
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class YamlTest extends ConfigBase
{
    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        if (!extension_loaded('yaml')) {
            $this->markTestSkipped('Warning: yaml extension is not loaded');
        }
    }

    /**
     * Tests Yaml config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testYamlConfig()
    {
        $this->specify(
            "Comparison of configurations returned a not identical result",
            function () {
                $config = new Yaml(PATH_DATA . 'config/config.yml');
                $this->compareConfig($this->config, $config);
            }
        );
    }

    /**
     * Tests Yaml config callbacks
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-12
     */
    public function testYamlConfigCallback()
    {
        $this->specify(
            "Config's callbacks does not works properly",
            function () {
                define('CALLBACK_APPROOT', dirname(__DIR__));
                $config = new Yaml(PATH_DATA . 'config/callbacks.yml', [
                    '!decrypt' => function ($value) {
                        return hash('sha256', $value);
                    },
                    '!approot' => function ($value) {
                        return CALLBACK_APPROOT . $value;
                    }
                ]);

                expect($config->application->controllersDir)->equals(CALLBACK_APPROOT . '/app/controllers/');
                expect($config->database->password)->equals('9f7030891b235f3e06c4bff74ae9dc1b9b59d4f2e4e6fd94eeb2b91caee5d223');
            }
        );
    }
}
