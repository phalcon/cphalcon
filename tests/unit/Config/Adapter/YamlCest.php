<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Config\Adapter\Yaml;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use UnitTester;

class YamlCest extends ConfigBase
{
    /**
     * executed before each test
     */
    public function _before(UnitTester $I, $scenario)
    {
        if (!extension_loaded('yaml')) {
            $scenario->skip('Warning: yaml extension is not loaded');
        }
    }

    /**
     * Tests Yaml config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testYamlConfig(UnitTester $I)
    {
        $config = new Yaml(PATH_DATA . 'config/config.yml');
        $this->compareConfig($I, $this->config, $config);
    }

    /**
     * Tests Yaml config callbacks
     *
     * @author Ivan Zubok <chi_no@ukr.net>
     * @since  2014-11-12
     */
    public function testYamlConfigCallback(UnitTester $I)
    {
        define('CALLBACK_APPROOT', dirname(__DIR__));
        $config = new Yaml(
            PATH_DATA . 'config/callbacks.yml',
            [
                '!decrypt' => function ($value) {
                    return hash('sha256', $value);
                },
                '!approot' => function ($value) {
                    return CALLBACK_APPROOT . $value;
                },
            ]
        );

        $expected = CALLBACK_APPROOT . '/app/controllers/';
        $actual   = $config->application->controllersDir;
        $I->assertEquals($expected, $actual);

        $expected = '9f7030891b235f3e06c4bff74ae9dc1b9b59d4f2e4e6fd94eeb2b91caee5d223';
        $actual   = $config->database->password;
        $I->assertEquals($expected, $actual);
    }
}
