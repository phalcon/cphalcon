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

namespace Phalcon\Tests\Unit\Support\Helper\File;

use Phalcon\Support\Helper\File\Basename;
use Phalcon\Tests\AbstractUnitTestCase;
use PHPUnit\Framework\Attributes\DataProvider;

use function basename;

final class BasenameTest extends AbstractUnitTestCase
{
    /**
     * @return string[][]
     */
    public static function getAsciiExamples(): array
    {
        return [
            [
                '/etc/sudoers.d',
                '.d',
            ],
            [
                '/etc/sudoers.d',
                '',
            ],
            [
                '/etc/passwd',
                '',
            ],
            [
                '/etc/',
                '',
            ],
            [
                '.',
                '',
            ],
            [
                '/',
                '',
            ],
        ];
    }

    /**
     * @return string[][]
     */
    public static function getNonAsciiExamples(): array
    {
        return [
            [
                '/file/热爱中文.txt',
                '热爱中文.txt',
            ],
            [
                '/中文目录/热爱中文.txt',
                '热爱中文.txt',
            ],
            [
                '/myfolder/日本語のファイル名.txt',
                '日本語のファイル名.txt',
            ],
            [
                '/のファ/日本語のファイル名.txt',
                '日本語のファイル名.txt',
            ],
            [
                '/root/ελληνικά.txt',
                'ελληνικά.txt',
            ],
            [
                '/νικά/ελληνικά.txt',
                'ελληνικά.txt',
            ],
        ];
    }

    /**
     * @author       Ian Hu <hu2008yinxiang@163.com>
     * @since        2020-09-09
     */
    #[DataProvider('getNonAsciiExamples')]
    #[DataProvider('getNonAsciiExamples')]
    public function testSupportHelperFileBasenameNonASCII(
        string $path,
        string $expected,
    ): void {
        $object = new Basename();
        $actual = $object($path);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author       Ian Hu <hu2008yinxiang@163.com>
     * @since        2020-09-09
     */
    #[DataProvider('getAsciiExamples')]
    #[DataProvider('getAsciiExamples')]
    public function testSupportHelperFileBasenamePureASCII(
        string $path,
        string $suffix,
    ): void {
        $object = new Basename();

        $expected = basename($path, $suffix);
        $actual = $object($path, $suffix);
        $this->assertSame($expected, $actual);
    }
}
