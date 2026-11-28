<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Benchmarks\Config;

use Phalcon\Config\Config;
use Phalcon\Di\Di;
use PhpBench\Attributes\BeforeMethods;
use RuntimeException;

#[BeforeMethods('setUp')]
final class ConfigBench
{
    private const DATA = [
        'app'      => [
            'baseUri'  => '/',
            'name'     => 'bench',
            'timezone' => 'UTC',
        ],
        'database' => [
            'adapter'  => 'mysql',
            'dbname'   => 'phalcon',
            'host'     => 'localhost',
            'options'  => [
                'charset' => 'utf8mb4',
            ],
            'password' => 'secret',
            'port'     => 3306,
            'username' => 'root',
        ],
        'services' => [
            'cache'   => 'memory',
            'logger'  => 'stream',
            'mailer'  => 'smtp',
            'queue'   => 'beanstalk',
            'session' => 'files',
        ],
    ];

    private Config $config;

    public function setUp(): void
    {
        Di::reset();

        $this->config = new Config(self::DATA);
    }

    /**
     * A new config from a nested array, as one request makes it: each
     * nested array becomes a Config object.
     */
    public function benchConstruct(): void
    {
        $config = new Config(self::DATA);

        $actual = $config->path('database.options.charset');
        if ('utf8mb4' !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }

    public function benchPath(): void
    {
        $actual = $this->config->path('database.host');

        if ('localhost' !== $actual) {
            throw new RuntimeException(sprintf('Unexpected value: %s', var_export($actual, true)));
        }
    }
}
