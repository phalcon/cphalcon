<?php

namespace Helper\Traits;

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
        $this->config      = new Ini(PATH_DATA . "config/factory.ini", INI_SCANNER_NORMAL);
        $this->arrayConfig = $this->config->toArray();
    }
}
