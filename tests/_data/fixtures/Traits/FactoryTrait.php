<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use function dataFolder;
use Phalcon\Config\Adapter\Ini;

trait FactoryTrait
{
    protected $config;

    /**
     * @var array
     */
    protected $arrayConfig;

    protected function init()
    {
        $configFile = dataFolder("assets/config/factory.ini");
        $this->config      = new Ini($configFile, INI_SCANNER_NORMAL);
        $this->arrayConfig = $this->config->toArray();
    }
}
