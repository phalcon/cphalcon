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

use Phalcon\Config\Adapter\Php;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use UnitTester;

class PhpCest extends ConfigBase
{
    /**
     * Tests Php config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testPhpConfig(UnitTester $I)
    {
        $config = new Php(PATH_DATA . 'assets/config/config.php');
        $this->compareConfig($I, $this->config, $config);
    }
}
