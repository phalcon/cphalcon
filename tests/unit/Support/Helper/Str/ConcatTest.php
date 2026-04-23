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

use Phalcon\Support\Helper\Str\Concat;
use Phalcon\Tests\AbstractUnitTestCase;

final class ConcatTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrConcat(): void
    {
        $object = new Concat();

        // Test 1
        $actual = $object(
            '/',
            '/tmp/',
            '/folder_1/',
            '/folder_2',
            'folder_3/',
        );
        $expected = '/tmp/folder_1/folder_2/folder_3/';
        $this->assertSame($expected, $actual);

        // Test 2
        $actual = $object(
            '.',
            '@test.',
            '.test2.',
            '.test',
            '.34',
        );
        $expected = '@test.test2.test.34';
        $this->assertSame($expected, $actual);
    }
}
