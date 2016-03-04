<?php

namespace Phalcon\Test\Unit\Config\Helper;

use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Config\Helper\ConfigBase
 * Tests the Phalcon\Config component
 *
 * @copyright (c) 2011-2016 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Config\Helper
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ConfigBase extends UnitTest
{
    protected $config = [
        'phalcon' => [
            'baseuri' => '/phalcon/'
        ],
        'models' => [
            'metadata' => 'memory'
        ],
        'database' => [
            'adapter'  => 'mysql',
            'host'     => 'localhost',
            'username' => 'user',
            'password' => 'passwd',
            'name'     => 'demo'
        ],
        'test' => [
            'parent' => [
                'property' => 1,
                'property2' => 'yeah'
            ],
        ],
    ];

    protected function compareConfig($c, $config)
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
}
