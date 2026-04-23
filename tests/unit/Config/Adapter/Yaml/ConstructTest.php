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

namespace Phalcon\Tests\Unit\Config\Adapter\Yaml;

use Phalcon\Config\Adapter\Yaml;
use Phalcon\Config\Config;
use Phalcon\Config\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ConfigTrait;
use Phalcon\Tests\Unit\Config\Fake\Adapter\FakeYamlExtensionLoaded;
use Phalcon\Tests\Unit\Config\Fake\Adapter\FakeYamlParseFile;

use function basename;
use function hash;
use function supportDir;

final class ConstructTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @return void
     */
    public function setUp(): void
    {
        $this->checkExtensionIsLoaded('yaml');
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function testConfigAdapterYamlConstructCallbacks(): void
    {
        $baseDir = supportDir();

        $config = new Yaml(
            supportDir('assets/config/callbacks.yml'),
            [
                '!decrypt' => function ($value) {
                    return hash('sha256', $value);
                },
                '!approot' => function ($value) use ($baseDir) {
                    return $baseDir . $value;
                },
            ]
        );

        $expected = $baseDir . '/app/controllers/';
        $actual   = $config->application->controllersDir;
        $this->assertSame($expected, $actual);

        $expected = '9f7030891b235f3e06c4bff74ae9dc1b9b59d4f2e4e6fd94eeb2b91caee5d223';
        $actual   = $config->database->password;
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function testConfigAdapterYamlConstructExceptionLoaded(): void
    {
        $filePath = supportDir('assets/config/callbacks.yml');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Yaml extension is not loaded');

        (new FakeYamlExtensionLoaded($filePath));
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-21
     */
    public function testConfigAdapterYamlConstructExceptionParseFile(): void
    {
        $filePath = supportDir('assets/config/callbacks.yml');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Configuration file ' . basename($filePath) . ' can\'t be loaded'
        );

        (new FakeYamlParseFile($filePath));
    }

    /**
     * @author ucando.wen <ucando.wen@qq.com>
     * @since  2025-06-22
     */
    public function testConfigAdapterYamlConstructHandlesEmptyYaml(): void
    {
        $config = new Yaml(supportDir('assets/config/empty.yml'));

        $this->assertInstanceOf(Config::class, $config);
        $this->assertEquals([], $config->toArray());
    }
}
