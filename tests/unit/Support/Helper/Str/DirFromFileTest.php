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

use Phalcon\Support\Helper\Str\DirFromFile;
use Phalcon\Tests\AbstractUnitTestCase;

final class DirFromFileTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrFolderFromFile(): void
    {
        $fileName = 'abcdef12345.jpg';
        $object = new DirFromFile();

        $expected = 'ab/cd/ef/12/3/';
        $actual = $object($fileName);
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrFolderFromFileEmptyString(): void
    {
        $fileName = '';
        $object = new DirFromFile();

        $expected = '/';
        $actual = $object($fileName);
        $this->assertSame($expected, $actual);
    }
}
