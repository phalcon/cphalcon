<?php

namespace Phalcon\Test\Unit\Factory\Helper;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Test\Module\UnitTest;

/**
 * Class FactoryBase
 * @package Phalcon\Test\unit\Factory\Helper
 */
abstract class FactoryBase extends UnitTest
{
    /**
     * @var Ini
     */
    protected $config;
    /**
     * @var array
     */
    protected $arrayConfig;

    protected function _before()
    {
        parent::_before();

        $this->config = new Ini(PATH_DATA."config/factory.ini", INI_SCANNER_NORMAL);
        $this->arrayConfig = $this->config->toArray();
    }
}
