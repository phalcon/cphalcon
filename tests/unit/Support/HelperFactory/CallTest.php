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
use Phalcon\Tests\Support\Traits\ErrorHandlerTrait;
use stdClass;

final class CallTest extends AbstractUnitTestCase
{
    use ErrorHandlerTrait;

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
     * A helper with no __invoke() gives a warning and null, the same as
     * cphalcon.
     *
     * @issue  https://github.com/phalcon/phalcon/issues/808
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-11-15
     */
    public function testSupportHelperFactoryCallNotCallable(): void
    {
        $factory = new HelperFactory(['custom' => stdClass::class]);

        [$actual, $messages] = $this->collectErrors(
            static fn () => $factory->custom('5')
        );

        $this->assertNull($actual);
        $this->assertSame(['class stdClass does not have a method "__invoke"'], $messages);
    }
}
