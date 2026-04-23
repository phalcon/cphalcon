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

namespace Phalcon\Tests\Unit\Support\HelperFactory;

use Phalcon\Support\HelperFactory;
use Phalcon\Tests\AbstractUnitTestCase;

final class CallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperFactoryCall(): void
    {
        $factory = new HelperFactory();

        $source = 'Phalcon';
        $expected = 7;
        $actual = $factory->len($source);
        $this->assertSame($expected, $actual);
    }
}
