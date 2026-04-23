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

namespace Phalcon\Tests\Unit\Support\Helper\Str;

use Phalcon\Support\Helper\Str\DirSeparator;
use Phalcon\Tests\AbstractUnitTestCase;

use const PHP_OS_FAMILY;

final class DirSeparatorTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrFolderSeparator(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $object = new DirSeparator();

        $expected = '/home/phalcon/';
        $actual = $object('/home/phalcon');
        $this->assertSame($expected, $actual);

        $expected = '/home/phalcon/';
        $actual = $object('/home/phalcon//');
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrFolderSeparatorEmptyString(): void
    {
        if (PHP_OS_FAMILY === 'Windows') {
            $this->markTestSkipped('Need to fix Windows new lines...');
        }

        $fileName = '';
        $object = new DirSeparator();

        $expected = "/";
        $actual = $object($fileName);
        $this->assertSame($expected, $actual);
    }
}
