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

namespace Phalcon\Tests\Unit\Config\ConfigFactory;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Adapter\Json;
use Phalcon\Config\Adapter\Php;
use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\ConfigFactory;
use Phalcon\Config\Exception;
use Phalcon\Tests\AbstractUnitTestCase;

use function supportDir;

final class NewInstanceTest extends AbstractUnitTestCase
{
    /**
     * @return array<array-key, array<string, string>>
     */
    public static function getExamples(): array
    {
        return [
            [
                'ini',
                supportDir('assets/config/config.ini'),
                Ini::class,
            ],
            [
                'json',
                supportDir('assets/config/config.json'),
                Json::class,
            ],
            [
                'php',
                supportDir('assets/config/config.php'),
                Php::class,
            ],
            [
                'yaml',
                supportDir('assets/config/config.yml'),
                Yaml::class,
            ],
        ];
    }

    /**
     * @dataProvider getExamples
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testConfigFactoryNewInstance(
        string $service,
        string $options,
        string $expected
    ): void {
        $factory = new ConfigFactory();
        $config  = $factory->newInstance($service, $options);

        $this->assertInstanceOf($expected, $config);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testConfigFactoryNewInstanceException(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage("Service unknown is not registered");

        $factory = new ConfigFactory();
        $factory->newInstance(
            "unknown",
            "config.php"
        );
    }
}
