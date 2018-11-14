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

use Phalcon\Config\Adapter\Json;
use Phalcon\Test\Unit\Config\Helper\ConfigBase;
use UnitTester;

class JsonCest extends ConfigBase
{
    /**
     * Tests Json config
     *
     * @author Andres Gutierrez <andres@phalconphp.com>
     * @since  2012-08-18
     */
    public function testJsonConfig(UnitTester $I)
    {
        $config = new Json(PATH_DATA . 'assets/config/config.json');
        $this->compareConfig($I, $this->config, $config);
    }
}
