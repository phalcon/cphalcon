<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Support\Traits;

use Phalcon\Config\Adapter\Grouped;
use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\Config;
use Phalcon\Talon\Talon;


trait ConfigTrait
{
    /**
     * @var array
     */
    protected array $config = [
        'phalcon'     => [
            'baseuri' => '/phalcon/',
        ],
        'models'      => [
            'metadata' => 'memory',
        ],
        'database'    => [
            'adapter'  => 'mysql',
            'host'     => 'localhost',
            'username' => 'user',
            'password' => 'passwd',
            'name'     => 'demo',
        ],
        'test'        => [
            'parent' => [
                'property'      => 1,
                'property2'     => 'yeah',
                'emptyProperty' => '',
            ],
        ],
        'issue-12725' => [
            'channel' => [
                'handlers' => [
                    0 => [
                        'name'           => 'stream',
                        'level'          => 'debug',
                        'fingersCrossed' => 'info',
                        'filename'       => 'channel.log',
                    ],
                    1 => [
                        'name'           => 'redis',
                        'level'          => 'debug',
                        'fingersCrossed' => 'info',
                    ],
                ],
            ],
        ],
    ];

    /**
     * @return array[]
     */
    public static function providerConfigAdapters(): array
    {
        return [
            [''],
            ['Grouped'],
            ['Ini'],
            ['Json'],
            ['Php'],
            ['Yaml'],
        ];
    }

    /**
     * @return array[]
     */
    public static function providerConfigAdaptersNotGrouped(): array
    {
        return [
            [''],
            ['Ini'],
            ['Json'],
            ['Php'],
            ['Yaml'],
        ];
    }

    /**
     * @param array  $actual
     * @param Config $expected
     *
     * @return void
     */
    private function compareConfig(array $actual, Config $expected): void
    {
        $this->assertEquals($expected->toArray(), $actual);

        foreach ($actual as $key => $value) {
            $this->assertTrue(isset($expected->$key));

            if (is_array($value)) {
                $this->compareConfig($value, $expected->$key);
            }
        }
    }

    /**
     * Returns a config object
     *
     * @param string $adapter
     *
     * @return Config|Ini|Json|Php|Yaml
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    private function getConfig(string $adapter = ''): Config|Ini|Json|Php|Yaml
    {
        switch ($adapter) {
            case 'Ini':
                return new Ini(
                    Talon::settings()->supportPath('assets/config/config.ini')
                );

            case 'Json':
                return new Json(
                    Talon::settings()->supportPath('assets/config/config.json')
                );

            case 'Php':
                return new Php(
                    Talon::settings()->supportPath('assets/config/config.php')
                );

            case 'Yaml':
                return new Yaml(
                    Talon::settings()->supportPath('assets/config/config.yml')
                );

            case 'Grouped':
                $config = [
                    Talon::settings()->supportPath('assets/config/config.php'),
                    [
                        'adapter'  => 'json',
                        'filePath' => Talon::settings()->supportPath('assets/config/config.json'),
                    ],
                    [
                        'adapter' => 'array',
                        'config'  => [
                            'test' => [
                                'property2' => 'something-else',
                            ],
                        ],
                    ],
                ];

                return new Grouped($config);

            default:
                return new Config($this->config);
        }
    }
}
