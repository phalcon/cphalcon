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

namespace Phalcon\Tests\Unit\Support\HelperFactory;

use Phalcon\Support\HelperFactory;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use stdClass;
use TypeError;

final class CallTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testSupportHelperFactoryCall(): void
    {
        $factory = new HelperFactory();

        $source   = 'Phalcon';
        $expected = 7;
        $actual   = $factory->len($source);
        $this->assertSame($expected, $actual);
    }

    /**
     * A helper with no __invoke() throws the TypeError of
     * call_user_func_array().
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testSupportHelperFactoryCallNotCallable(): void
    {
        $factory = new HelperFactory(['custom' => stdClass::class]);

        $this->expectException(TypeError::class);
        $this->expectExceptionMessage(
            'call_user_func_array(): Argument #1 ($callback) must be a valid callback, '
            . 'class stdClass does not have a method "__invoke"'
        );

        $factory->custom('5');
    }
}
