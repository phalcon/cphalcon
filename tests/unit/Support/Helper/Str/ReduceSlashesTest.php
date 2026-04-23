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

use Phalcon\Support\Helper\Str\ReduceSlashes;
use Phalcon\Tests\AbstractUnitTestCase;

final class ReduceSlashesTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperStrReduceSlashes(): void
    {
        $object = new ReduceSlashes();

        $expected = 'app/controllers/IndexController';
        $actual = $object('app/controllers//IndexController');
        $this->assertSame($expected, $actual);

        $expected = 'http://foo/bar/baz/buz';
        $actual = $object('http://foo//bar/baz/buz');
        $this->assertSame($expected, $actual);

        $expected = 'php://memory';
        $actual = $object('php://memory');
        $this->assertSame($expected, $actual);

        $expected = 'http/https';
        $actual = $object('http//https');
        $this->assertSame($expected, $actual);
    }
}
