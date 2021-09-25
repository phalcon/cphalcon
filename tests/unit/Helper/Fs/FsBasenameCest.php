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

namespace Phalcon\Tests\Unit\Helper\Fs;

use Phalcon\Helper\Fs;
use UnitTester;

class FsBasenameCest
{
    /**
     * Tests Phalcon\Helper\Fs :: basename()
     * with ASCII $uri it should be same as PHP's basename
     *
     * @author Ian Hu <hu2008yinxiang@163.com>
     * @since  2019-08-27
     */
    public function helperFsBasenamePureASCII(UnitTester $I)
    {
        $I->wantToTest('Helper\Fs - basename() with pure ASCII uri');
        $filePathAndSuffixes = [
            ["/etc/sudoers.d", ".d"],
            ["/etc/sudoers.d", ''],
            ['/etc/passwd', ''],
            ['/etc/', ''],
            ['.', ''],
            ['/', ''],
        ];

        foreach ($filePathAndSuffixes as $filePathAndSuffix) {
            [$filePath, $suffix] = $filePathAndSuffix;
            $I->assertEquals(
                basename($filePath, $suffix),
                Fs::basename($filePath, $suffix)
            );
        }
    }

    /**
     * Tests Phalcon\Helper\Fs :: basename()
     * with non-ASCII $uri support
     *
     * @author Ian Hu <hu2008yinxiang@163.com>
     * @since  2019-08-27
     */
    public function helperFsBasenameNonASCII(UnitTester $I)
    {
        $I->wantToTest('Helper\Fs - basename() with non-ASCII uri');
        $filePathAndExpects = [
            '/file/热爱中文.txt'          => '热爱中文.txt',
            '/中文目录/热爱中文.txt'          => '热爱中文.txt',
            '/myfolder/日本語のファイル名.txt' => '日本語のファイル名.txt',
            '/のファ/日本語のファイル名.txt'      => '日本語のファイル名.txt',
            '/root/ελληνικά.txt'      => 'ελληνικά.txt',
            '/νικά/ελληνικά.txt'      => 'ελληνικά.txt',
        ];
        foreach ($filePathAndExpects as $filePath => $expect) {
            $I->assertEquals(
                $expect,
                Fs::basename($filePath)
            );
        }
    }
}
