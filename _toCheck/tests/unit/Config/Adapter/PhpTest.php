<?php

namespace Phalcon\Test\Unit\Config\Adapter;

use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use Phalcon\Config\Adapter\Php;

/**
 * \Phalcon\Test\Unit\Config\Adapter\PhpTest
 * Tests the \Phalcon\Config\Adapter\Php component
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
class PhpTest extends ConfigBase
{
    /**
     * Tests Php config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testPhpConfig()
    {
        $this->specify(
            "Comparison of configurations returned a not identical result",
            function () {
                $config = new Php(PATH_DATA . 'config/config.php');
                $this->compareConfig($this->config, $config);
            }
        );
    }
}
