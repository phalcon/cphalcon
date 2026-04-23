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

namespace Phalcon\Tests\Unit\Config\Adapter\Ini;

use Phalcon\Config\Adapter\Ini;
use Phalcon\Config\Exception;
use Phalcon\Tests\AbstractUnitTestCase;
use Phalcon\Tests\Support\Traits\ConfigTrait;
use Phalcon\Tests\Unit\Config\Fake\Adapter\FakeIniParseFile;

use function basename;
use function define;
use function supportDir;

use const INI_SCANNER_NORMAL;

final class ConstructTest extends AbstractUnitTestCase
{
    use ConfigTrait;

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testConfigAdapterIniConstruct(): void
    {
        $this->config['database']['num1'] = false;
        $this->config['database']['num2'] = false;
        $this->config['database']['num3'] = false;
        $this->config['database']['num4'] = true;
        $this->config['database']['num5'] = true;
        $this->config['database']['num6'] = true;
        $this->config['database']['num7'] = null;
        $this->config['database']['num8'] = 123;
        $this->config['database']['num9'] = (float) 123.45;

        $config = $this->getConfig('Ini');

        $this->compareConfig($this->config, $config);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testConfigAdapterIniConstructConstants(): void
    {
        define('TEST_CONST', 'foo');

        $config = new Ini(
            supportDir('assets/config/config-with-constants.ini'),
            INI_SCANNER_NORMAL
        );

        $expected = [
            'test'    => 'foo',
            'path'    => 'foo/something/else',
            'section' => [
                'test'      => 'foo',
                'path'      => 'foo/another-thing/somewhere',
                'parent'    => [
                    'property'  => 'foo',
                    'property2' => 'foohello',
                ],
                'testArray' => [
                    'value1',
                    'value2',
                ],
            ],
        ];

        $actual = $config->toArray();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-10-26
     */
    public function testConfigAdapterIniConstructException(): void
    {
        $filePath = supportDir('assets/config/config-with-constants.ini');

        $this->expectException(Exception::class);
        $this->expectExceptionMessage(
            'Configuration file ' . basename($filePath) . ' cannot be loaded'
        );

        (new FakeIniParseFile($filePath));
    }
}
