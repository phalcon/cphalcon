<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Fixtures\Traits;

use function dataDir;
use function outputDir;
use Phalcon\Config\Config;
use Phalcon\Config\Adapter\Ini;

trait FactoryTrait
{
    protected $config;

    /**
     * @var array
     */
    protected $arrayConfig;

    /**
     * Initializes the main config
     */
    protected function init()
    {
        $configFile = dataDir('assets/config/factory.ini');

        $this->config = new Ini($configFile, INI_SCANNER_NORMAL);

        $this->arrayConfig = $this->config->toArray();
    }

    /**
     * Initializes the logger config - this is special because it is nested
     */
    protected function initLogger()
    {
        $options = [
            'logger' => [
                'name'     => 'my-logger',
                'adapters' => [
                    0 => [
                        'adapter' => 'stream',
                        'name'    => outputDir('tests/logs/factory.log'),

                    ],
                    1 => [
                        'adapter' => 'stream',
                        'name'    => outputDir('tests/logs/factory.log'),

                    ],
                ],
            ],
        ];

        $this->config = new Config($options);

        $this->arrayConfig = $this->config->toArray();
    }
}
